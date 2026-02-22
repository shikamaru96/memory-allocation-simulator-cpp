#include <iostream>
#include <sstream>
#include <string>

#include "../include/MemoryManager.h"
#include "../include/FirstFitStrategy.h"

int main() {
    FirstFitStrategy strategy;
    MemoryManager manager(1024, &strategy);

    std::string line;
    std::cout << "=== C++ Memory Manager Simulator ===\n";
    std::cout << "Commands:\n";
    std::cout << "allocate <size>\n";
    std::cout << "free <address>\n";
    std::cout << "defrag\n";
    std::cout << "status\n";
    std::cout << "exit\n\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);

        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if (command == "allocate") {
            size_t size;
            ss >> size;

            if (manager.allocate(size)) {
                std::cout << "Allocated " << size << " bytes.\n";
            } else {
                std::cout << "Allocation failed.\n";
            }
        }

        else if (command == "free") {
            size_t address;
            ss >> address;

            if (manager.free(address)) {
                std::cout << "Freed block at address " << address << ".\n";
            } else {
                std::cout << "Free failed.\n";
            }
        }

        else if (command == "defrag") {
            manager.defragment();
            std::cout << "Memory defragmented.\n";
        }

        else if (command == "status") {
            manager.printStatus();
        }

        else if (command == "exit") {
            std::cout << "Exiting...\n";
            break;
        }

        else {
            std::cout << "Unknown command.\n";
        }
    }

    return 0;
}