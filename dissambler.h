#include <stdint.h>
#include <stdio.h>

int dissamble_instruction(size_t pc, uint8_t *program_bytes);
int dissamble_program(size_t length, uint8_t *program_bytes);
