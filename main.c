#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *file = fopen("resources/invaders.hex", "rb");

  if (file == NULL) {
    printf("File didn't open for some reason.");
    return 1;
  } else {
    printf("The file opened for some reason.\n");

    // find the size of the file (bytes) by jumping to the end and back
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    uint8_t *file_contents = malloc(file_size);
    fread(file_contents, 1, file_size, file);

    printf("Length of file (bytes): %ld\n", file_size);
    printf("Number of Rows needed (16 bytes each row): %ld\n", file_size / 16);

    printf("hexdump -v");
    for (int i = 0; i < file_size; i++) {
      if (i % 16 != 0) {
        printf("%02X  ", file_contents[i]);
      } else {
        printf("\n%07X  %02X  ", i, file_contents[i]);
      }
    }

    fclose(file);
    free(file_contents);
  }
  return 0;
}
