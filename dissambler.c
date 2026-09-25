#include <stdint.h>
#include <stdio.h>

int
disassemble_op(uint8_t *buffer, size_t pc) {
    int op_bytes = 1;
    uint8_t *current_op = &buffer[pc];
    switch (*current_op) {
    case 0x00:
        printf("NOP");
        break;
    case 0x01:
        printf("LXI    B, %02x  %02x", current_op[2], current_op[1]);
        op_bytes = 3;
        break;
    case 0xc3:
        printf("JMP");
        break;
    }
    // TODO: it is possible it is not any of the instructions and somehow uses a
    // hex code OOB or something
    // TODO: gotta catch that
    printf("\n");
    return op_bytes;
}

int
dissamble_program(uint8_t *buffer, size_t *length) {
    size_t pc = 0;

    while (pc < *length) {
        disassemble_op(buffer, pc);
        pc++;
    }

    return 0;
}
