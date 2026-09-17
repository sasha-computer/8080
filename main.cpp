#include <array>
#include <iostream>

int main() {
    // std::cout << "8080 Emulator Init" << std::endl;
    boot();
    return 0;
}

int inc_pc() {

    // uint8_t pc = 0;
    // return pc;
}

int load_program() {
    // Place program's instructions into memory contiguously.


}

int boot() {
    // pc: program counter
    // ir: instruction register
    // ar: accumulator register
    // Xr: X register
    uint8_t pc = 0;
    uint8_t ir = 0;
    uint8_t ar = 0;
    uint8_t br = 0;
    uint8_t cr = 0;
    uint8_t dr = 0;
    uint8_t er = 0;
    uint8_t hr = 0;
    uint8_t lr = 0;
    
    std::array<uint8_t, 65536> mem = { 0 };
}
