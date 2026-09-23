#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

bool
get_file_length(FILE *file, size_t *length) {
    if (fseek(file, 0, SEEK_END) != 0) {
        perror("Failed to seek file stream to end");
        return false;
    }
    long end = ftell(file);
    if (end == -1L) {
        perror("ftell() failed");
        return false;
    }

    if (fseek(file, 0, SEEK_SET) != 0) {
        perror("Failed to seek file stream to start");
        return false;
    }

    *length = (size_t)end;
    
    return true;
}
