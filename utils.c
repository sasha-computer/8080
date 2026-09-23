#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

// pc: program counter (steps)
// buffer: program buffer (pointer to starting memory address where program is loaded into memory)

int
program_hexdump(uint8_t* buffer, size_t* length) {
    size_t pc = 0;

    FILE* hexdump = fopen("resources/invaders.txt", "w");
    if (hexdump == NULL) {
        perror("Can not write to invaders.txt for hexdump");
        return 1;
    }

    while (pc < *length) {
        if (pc % 16 == 0) {
            fprintf(hexdump, "%07zX", pc);
        }
        fprintf(hexdump, "  %02X", buffer[pc]);

        if (pc % 16 == 15 || pc == *length - 1) {
            fprintf(hexdump, "\n");
        }
        pc++;
    }

    fclose(hexdump);
    free(buffer);
    printf("Wrote hexdump of program to resources/invaders.txt\n");
    return 0;
}

int
program_length(FILE* program, size_t* length) {
    if (fseek(program, 0, SEEK_END) != 0) {
        perror("Failed to seek program stream to end");
        return 1;
    }
    long end = ftell(program);
    if (end == -1L) {
        perror("ftell() failed");
        return 1;
    }

    if (fseek(program, 0, SEEK_SET) != 0) {
        perror("Failed to seek program stream to start");
        return 1;
    }

    *length = (size_t)end;
    return 0;
}

int
program_load(FILE* program, uint8_t* buffer, size_t* length) {
    if (program_length(program, length) != 0) {
        return 1;
    };

    printf("Program length in program_load is: %lu", *length);

    buffer = malloc(*length);
    if (buffer == NULL) {
        perror("malloc failed to allocate memory for buffer");
        return 1;
    }

    size_t bytes_read = fread(buffer, 1, *length, program);
    if (bytes_read != *length) {
        perror("For some reason, fread() didn't read the whole program...");
        free(buffer);
        return 1;
    }
    return 0;
}
