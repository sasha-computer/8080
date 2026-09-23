#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "dissambler.h"
#include "utils.h"

// pc: program counter (steps)
// length: program length (bytes)
// buffer: program buffer (pointer to starting memory address where program is loaded into memory)
uint8_t* buffer;
size_t* length = 0;

int
main(void) {
    FILE* program = fopen("resources/invaders.hex", "rb");
    if (program == NULL) {
        perror("Program didn't open for some reason.");
        return 1;
    }

    if (program_load(program, buffer, length) != 0) {
        fclose(program);
        return 1;
    }

    // if (program_hexdump(buffer, length) != 0) {
    //     fclose(program);
    //     return 1;
    // }

    // if (dissamble_program(buffer, length) != 0) {
    //     fclose(program);
    //     return 1;
    // }

    return 0;
}
