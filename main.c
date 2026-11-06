#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
  // Open the file

  if (argc > 1) {
    for (int i = 0; i < argc; i++) {
      FILE *myfile;
      myfile = fopen(argv[i], "r");

      if (myfile == NULL) {
        printf("There was an error opening file");
        return 1;
      }

      // buffer memory allocation pointer
      char buffer[BUFFER_SIZE];
      size_t bytes_read;

      while ((bytes_read = fread(buffer, 1, sizeof(buffer), myfile)) > 0) {
        write(1, buffer, bytes_read);
      }

      fclose(myfile);
      
    }
    return 0;
  }

  return 0;
}