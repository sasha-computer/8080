#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "dissambler.h"
#include "utils.h"

// memory address of first byte of program stored in memory.
uint8_t *program_bytes;

// file length (bytes)
size_t program_length = 0;

int
main(void) {
    FILE *file = fopen("resources/invaders.hex", "rb");
    if (file == NULL) {
        perror("file didn't open for some reason.");
        return 1;
    }

    if (program_load(file, &program_bytes, &program_length) != 0) {
        fclose(file);
        return 1;
    }

    if (program_hexdump(program_bytes, program_length) != 0) {
        fclose(file);
        return 1;
    }
    //
    //     if (dissamble_file(buffer, &length) != 0) {
    //         fclose(file);
    //         return 1;
    //     }

    free(program_bytes);
    return 0;
}
