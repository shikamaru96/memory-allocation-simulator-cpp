#include <iostream>
#include "../include/MemoryManager.h"
#include "../include/FirstFitStrategy.h"

int main() {
    FirstFitStrategy strategy;
    MemoryManager manager(1024, &strategy);

    std::cout << "Allocating 200...\n";
    manager.allocate(200);

    std::cout << "Allocating 100...\n";
    manager.allocate(100);

    std::cout << "\nMemory Status After Allocation:\n";
    manager.printStatus();

    std::cout << "\nFreeing block at address 0...\n";
    manager.free(0);

    std::cout << "Freeing block at address 200...\n";
    manager.free(200);

    std::cout << "\nMemory Status Before Defragmentation:\n";
    manager.printStatus();

    std::cout << "\nDefragmenting...\n";
    manager.defragment();

    std::cout << "\nMemory Status After Defragmentation:\n";
    manager.printStatus();

    return 0;
}