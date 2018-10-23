#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char* filename = "test_file.txt";
  if (argc > 1) {
    filename = argv[1];
  }

  int file = open(filename, O_RDONLY);
  char* put_here = calloc(sizeof(char), 100);
  int bytes_read = read(file, put_here, 100);
  printf("we read %d bytes\n", bytes_read);
  printf("file contents: |%s|\n", put_here);
  free(put_here);
  close(file);

  file = open(filename, O_WRONLY);
  char* to_write = "No, I'm Billy!";
  int bytes_written = write(file, to_write, strlen(to_write));
  printf("we wrote %d bytes\n", bytes_written);
  close(file);

  file = open(filename, O_RDONLY);
  char* new_file_contents = calloc(sizeof(char), 500);
  read(file, new_file_contents, 500);
  printf("new file contents: |%s|\n", new_file_contents);
  free(new_file_contents);
  close(file);

  file = open(filename, O_WRONLY);
  char* orig = "Hi, I'm Billy!";
  write(file, orig, strlen(orig));
  close(file);

  file = open(filename, O_RDONLY);
  char* old_file_contents = calloc(sizeof(char), 500);
  read(file, old_file_contents, 500);
  printf("reset file contents: |%s|\n", old_file_contents);
  free(old_file_contents);
  close(file);

}
