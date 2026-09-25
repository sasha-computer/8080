#include <stdint.h>
#include <stdio.h>

int dissamble_op(size_t pc, uint8_t *buffer);
int dissamble_program(uint8_t *buffer, size_t *length);
