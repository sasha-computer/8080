#include <stdint.h>
#include <stdio.h>

int program_hexdump(uint8_t* buffer, size_t* length);
int program_length(FILE* program, size_t* length);
int program_load(FILE* program, uint8_t* buffer, size_t* length);
