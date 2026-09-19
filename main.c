#include <complex.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

long get_file_size(FILE *file) {
  if (fseek(file, 0, SEEK_END) != 0) {
    perror("Failed to seek to end");
    return -1L;
  }
  long file_size = ftell(file);
  if (file_size == -1L) {
    perror("ftell() failed");
    return -1L;
  }

  if (fseek(file, 0, SEEK_SET) != 0) {
    perror("Failed to seek to start");
    return -1L;
  }
  return file_size;
}

int get_file_contents() {}
int load_file_contents() {}

int main(void) {
  FILE *file = fopen("resources/invaders.hex", "rb");
  if (file == NULL) {
    perror("File didn't open for some reason.");
    return 1;
  }
  printf("The file opened for some reason.");
  long file_size = get_file_size(file);
  if (file_size == -1L) {
    fclose(file);
    return 1;
  }

  size_t buffer_size = (size_t)file_size;
  uint8_t *file_contents = malloc(buffer_size);
  if (file_contents == NULL) {
    perror("malloc failed to allocate memory for file_contents");
    fclose(file);
    return 1;
  }
  size_t bytes_read = fread(file_contents, 1, buffer_size, file);
  if (bytes_read != buffer_size) {
    perror("For some reason, fread() didn't read the whole file...");
    fclose(file);
    free(file_contents);
    return 1;
  }

  for (size_t i = 0; i < buffer_size; i++) {
    if (i % 16 == 0) {
      printf("\n%07zX", i);
    }
    printf("  %02X", file_contents[i]);
  }

  fclose(file);
  free(file_contents);
  return 0;
}
