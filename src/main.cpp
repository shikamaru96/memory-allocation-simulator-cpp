#include <iostream>
#include "../include/MemoryBlock.h"

int main() {
    MemoryBlock block(1024, 0);

    std::cout << "Block Size: " << block.getSize() << std::endl;
    std::cout << "Start Address: " << block.getStartAddress() << std::endl;

    if (block.getStatus() == Status::FREE) {
        std::cout << "Block is FREE" << std::endl;
    }

    return 0;
}