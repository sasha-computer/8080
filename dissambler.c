#include <stdint.h>
#include <stdio.h>

int
disassemble_instruction(size_t pc, uint8_t *program_bytes) {
    size_t instruction_length = 1;
    uint8_t op = program_bytes[pc];
    switch (op) {
    case 0x00:
        // No Op
        printf("NOP");
        break;
    case 0x01:
        // Load Register Pair Immediate
        // Load bytes 2, 3 into register pair BC: byte 3 -> B; byte 2 -> C;
        instruction_length = 3;
        printf("LXI B, %02x  %02x", program_bytes[pc + 2],
               program_bytes[pc + 1]); // Load Register Pair Immediate
        break;
    case 0x02:
        // Store Accumulator Indirect
        // Move contents of A to memory location stored in register pair BC
        printf("STAX B");
        break;
    case 0x03:
        // Increment Register Pair
        // The content of the register pair BC is incremented by one
        printf("INX B");
        break;
    case 0x04:
        // Increment Register
        // The content of register B is incremented by one
        printf("INR B");
        break;
    case 0x05:
        // Decrement Register
        // The content of register B is decremented by one
        printf("DCR B");
        break;
    case 0x06:
        // Move Immediate
        // Move the content of byte 2 to register B
        instruction_length = 2;
        printf("MVI B, %02x", program_bytes[pc + 1]);
        break;
    case 0x07:
        // Rotate Left
        // The content of A is rotated left one position
        printf("RLC");
        break;
    case 0x09:
        // Add Register Pair to H and L
        // HL = HL + BC
        printf("DAD B");
        break;
    case 0x0a:
        // Load Accumulator Indirect
        // Load the content of memory location stored in BC to A
        printf("LDAX B");
        break;
    case 0x0b:
        // Decrement Register Pair
        // The content of the register pair BC is decremented by one
        printf("DCX B");
        break;
    case 0x0c:
        // Increment Register
        // The content of register C is incremented by one
        printf("INR C");
        break;
    case 0x0d:
        // Decrement Register
        // The content of register C is decremented by one
        printf("DCR C");
        break;
    case 0x0e:
        // Move Immediate
        // Move the content of byte 2 to register C
        instruction_length = 2;
        printf("MVI C, %02x", program_bytes[pc + 1]);
        break;
    case 0x0f:
        // Rotate Right
        // The content of A is rotated right one position
        printf("RRC");
    case 0x11:
        // Load Register Pair Immediate
        // Load bytes 2, 3 into register pair DE: byte 3 -> D; byte 2 -> E;
        instruction_length = 3;
        printf("LXI D, %02x  %02x", program_bytes[pc + 2],
               program_bytes[pc + 1]); // Load Register Pair Immediate
        break;
    case 0x12:
        // Store Accumulator Indirect
        // Move contents of A to memory location stored in register pair DE
        printf("STAX D");
        break;
    case 0x13:
        // Increment Register Pair
        // The content of the register pair DE is incremented by one
        printf("INX D");
        break;
    case 0x14:
        // Increment Register
        // The content of register D is incremented by one
        printf("INR D");
        break;
    case 0x15:
        // Decrement Register
        // The content of register D is decremented by one
        printf("DCR D");
        break;
    case 0x16:
        // Move Immediate
        // Move the content of byte 2 to register D
        instruction_length = 2;
        printf("MVI D, %02x", program_bytes[pc + 1]);
        break;
    case 0x17:
        // Rotate Left Through Carry
        // The content of A is rotate left position through the CY flag.
        printf("RAL");
        break;
    case 0x19:
        // Add Register Pair to H and L
        // HL = HL + DE
        printf("DAD D");
        break;
    case 0x1a:
        // Load Accumulator Indirect
        // Load the content of memory location stored in DE to A
        printf("LDAX D");
        break;
    case 0x1b:
        // Decrement Register Pair
        // The content of the register pair DE is decremented by one
        printf("DCX D");
        break;
    case 0x1c:
        // Increment Register
        // The content of register E is incremented by one
        printf("INR E");
        break;
    case 0x1d:
        // Decrement Register
        // The content of register E is decremented by one
        printf("DCR E");
        break;
    case 0x1e:
        // Move Immediate
        // Move the content of byte 2 to register E
        instruction_length = 2;
        printf("MVI E, %02x", program_bytes[pc + 1]);
        break;
    case 0x1f:
        // Rotate Right Through Carry
        // The content of A is rotated right one position through the CY flag
        printf("RAR");
        break;

    case 0xc3:
        printf("JMP");
        break;
    default:
        break;
    }

    printf("\n");
    return instruction_length;
}

int
dissamble_program(size_t length, uint8_t *program_bytes) {
    size_t pc = 0;

    while (pc < length) {
        pc += disassemble_instruction(pc, program_bytes);
    }

    return 0;
}
