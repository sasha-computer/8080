#include <array>
#include <iostream>
using namespace std;

struct REGISTERS
{
    uint16_t pc;
    uint8_t r_i;
    uint8_t r_a = 0;
    uint8_t r_b = 0;
    uint8_t r_c = 0;
    uint8_t r_d = 0;
    uint8_t r_e = 0;
    uint8_t r_h = 0;
    uint8_t r_l = 0;
};

int main()
{
    // std::cout << "8080 Emulator Init" << std::endl;
    // boot();
    return 0;
}

int inc_pc()
{
    // uint8_t pc = 0; // return pc;
}

int load_program()
{
    // Place program's instructions into memory contiguously.
}

int read_memory(uint16_t addr)
{
    // TODO
}

int boot()
{
    array<uint8_t, 65536> mem = {0};
}
