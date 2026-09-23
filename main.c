#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "hexdump.h"
#include "utils.h"

// pc: program counter (steps)
// pl: program length (bytes)
// pb: program buffer (pointer to starting memory address where program is loaded into memory)
size_t pc, pl = 0;
uint8_t* pb;

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
