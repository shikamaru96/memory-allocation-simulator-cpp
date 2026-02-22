#include <iostream>
#include "../include/MemoryManager.h"
#include "../include/FirstFitStrategy.h"

int main() {
    FirstFitStrategy strategy;
    MemoryManager manager(1024, &strategy);

    manager.allocate(200);
    manager.allocate(100);

    manager.printStatus();

    std::cout << "\nFreeing block at address 0\n";
    manager.free(0);

    manager.printStatus();

    return 0;
}