#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int
program_hexdump(uint8_t *program_bytes, size_t length) {
    size_t pc = 0;

    FILE *hexdump = fopen("resources/invaders.txt", "w");
    if (hexdump == NULL) {
        perror("Can not write to invaders.txt for hexdump");
        return 1;
    }

    while (pc < length) {
        if (pc % 16 == 0) {
            fprintf(hexdump, "%07zX", pc);
        }
        fprintf(hexdump, "  %02X", program_bytes[pc]);

        if (pc % 16 == 15 || pc == length - 1) {
            fprintf(hexdump, "\n");
        }
        pc++;
    }

    fclose(hexdump);
    printf("Wrote hexdump of program to resources/invaders.txt\n");
    return 0;
}

int
file_get_length(FILE *program, size_t *length) {
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
program_load(FILE *file, uint8_t **program_bytes, size_t *program_length) {
    uint8_t *bytes = NULL;
    size_t length = 0;

    if (file_get_length(file, &length) != 0) {
        return 1;
    };

    bytes = malloc(length);
    if (bytes == NULL) {
        perror("malloc failed to allocate memory for program");
        return 1;
    }

    size_t bytes_read = fread(bytes, 1, length, file);
    if (bytes_read != length) {
        perror("For some reason, fread() didn't read the whole program...");
        free(bytes);
        return 1;
    }
    *program_bytes = bytes;
    *program_length = length;
    return 0;
}
