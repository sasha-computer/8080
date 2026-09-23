#include <stdio.h>
#include <stdlib.h>

#include "hexdump.h"
#include "utils.h"

// pc: program counter (steps)
// pl: program length (bytes)
// pb: program buffer (pointer to starting memory address where program is loaded into memory)
extern size_t pc, pl;
extern uint8_t* pb;

int
hexdump(void) {
    FILE* program = fopen("resources/invaders.hex", "rb");
    if (program == NULL) {
        perror("Program didn't open for some reason.");
        return 1;
    }
    bool ok = get_file_length(program, &pl);
    if (ok == false) {
        fclose(program);
        return 1;
    }

    pb = malloc(pl);
    if (pb == NULL) {
        perror("malloc failed to allocate memory for pb");
        fclose(program);
        return 1;
    }

    size_t bytes_read = fread(pb, 1, pl, program);
    if (bytes_read != pl) {
        perror("For some reason, fread() didn't read the whole program...");
        fclose(program);
        free(pb);
        return 1;
    }

    FILE* hexdump = fopen("resources/invaders.txt", "w");
    if (hexdump == NULL) {
        perror("Can not write to invaders.txt for hexdump");
        return 1;
    }

    while (pc < pl) {
        if (pc % 16 == 0) {
            fprintf(hexdump, "%07zX", pc);
        }
        fprintf(hexdump, "  %02X", pb[pc]);

        if (pc % 16 == 15 || pc == pl - 1) {
            fprintf(hexdump, "\n");
        }
        pc++;
    }

    fclose(hexdump);
    free(pb);
    printf("Closed program, hexdump and freed memory.");
    printf("Wrote hexdump to resources/invaders.txt");

    return 0;
}
