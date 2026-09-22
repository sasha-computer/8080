#include <complex.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// pc: program counter (steps)
// pl: program length (bytes)
// pb: program buffer (pointer to memory address where program is loaded into memory)

size_t pc, pl = 0;
uint8_t* pb;

size_t
get_program_length(FILE* program) {
    if (fseek(program, 0, SEEK_END) != 0) {
        perror("Failed to seek to end");
        return -1L;
    }
    long pl = ftell(program);
    if (pl == -1L) {
        perror("ftell() failed");
        return -1L;
    }

    if (fseek(program, 0, SEEK_SET) != 0) {
        perror("Failed to seek to start");
        return -1L;
    }
    return (size_t)pl;
}

int
hexdump(void) {
    FILE* program = fopen("resources/invaders.hex", "rb");
    if (program == NULL) {
        perror("Program didn't open for some reason.");
        return 1;
    }
    size_t pl = get_program_length(program);
    if (pl == -1) {
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

// int
// disassemble_op(size_t idx, size_t pl, uint8_t* pb) {
//     int op_bytes = 1;
//     uint8_t* current_op = &pb[idx];
//     switch (*current_op) {
//         case 0x00: printf("NOP"); break;
//         case 0x01:
//             printf("LXI    B, %02x  %02x", current_op[2], current_op[1]);
//             op_bytes = 3;
//             break;
//         case 0xc3: printf("JMP"); break;
//     }
//     printf("\n");
//     return op_bytes;
// }

int
main(void) {
    hexdump();
    return 0;
}
