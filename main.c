#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
  // Open the file

  if (argc > 1) {
    for (int i = 1; i < argc; i++) {

      int myfile = open(argv[i], O_RDONLY);

      if (myfile == -1) {
        perror("There was an error opening file");
        return 1;
      }

      char buffer[BUFFER_SIZE];
      ssize_t bytes_read;

      while ((bytes_read = read(myfile, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytes_read);
      }

      close(myfile);

    }
    return 0;
  }

  return 0;
}