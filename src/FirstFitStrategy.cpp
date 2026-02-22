#include "../include/FirstFitStrategy.h"

MemoryBlock* FirstFitStrategy::allocate(MemoryBlock* head, size_t size) {
    MemoryBlock* current = head;

    while (current != nullptr) {
        if (current->getStatus() == Status::FREE &&
            current->getSize() >= size) {
                return current;
        }
        current = current->getNext();
    }

    return nullptr; // No suitable block found
}