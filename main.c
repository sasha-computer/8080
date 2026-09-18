#include <stdint.h>
#include <stdio.h>

typedef struct {
  uint8_t a, b, c, d, e, h, l;
  uint16_t sp, pc;
} CPU8080;

int main(void) {
  printf("Hello");
  return 0;
}
