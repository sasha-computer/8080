#include <stdint.h>
#include <stdio.h>

int file_get_length(FILE *file, size_t *file_length);
int program_hexdump(uint8_t *program_bytes, size_t program_length);
int program_load(FILE *file, uint8_t **program_bytes, size_t *program_length);
