#include <iostream>
#include "../include/MemoryManager.h"

MemoryManager::MemoryManager(size_t totalSize, AllocationStrategy* strategy)
    : totalSize(totalSize), strategy(strategy)
{
    head = new MemoryBlock(totalSize, 0);
}

MemoryManager::~MemoryManager() {
    MemoryBlock* current = head;

    while (current != nullptr) {
        MemoryBlock* temp = current;
        current = current->getNext();
        delete temp;
    }
}

bool MemoryManager::allocate(size_t size) {
    MemoryBlock* block = strategy->allocate(head, size);

    if (block == nullptr) {
        return false;
    }

    // If exact size, just mark USED
    if (block->getSize() == size) {
        block->setStatus(Status::USED);
        return true;
    }

    // If larger, split block
    if (block->getSize() > size) {

        size_t remainingSize = block->getSize() - size;
        size_t newStart = block->getStartAddress() + size;

        MemoryBlock* newBlock = new MemoryBlock(remainingSize, newStart);
        newBlock->setNext(block->getNext());

        block->setSize(size);
        block->setStatus(Status::USED);
        block->setNext(newBlock);

        return true;
    }

    return false;
}

bool MemoryManager::free(size_t startAddress) {
    MemoryBlock* current = head;

    while (current != nullptr) {
        if (current->getStartAddress() == startAddress &&
            current->getStatus() == Status::USED) {

            current->setStatus(Status::FREE);
            return true;
        }
        current = current->getNext();
    }

    return false;
}

void MemoryManager::printStatus() const {
    MemoryBlock* current = head;

    while (current != nullptr) {
        std::cout << "Address: " << current->getStartAddress()
                  << " | Size: " << current->getSize()
                  << " | Status: "
                  << (current->getStatus() == Status::FREE ? "FREE" : "USED")
                  << std::endl;

        current = current->getNext();
    }
}

void MemoryManager::defragment() {
    MemoryBlock* current = head;

    while (current != nullptr && current->getNext() != nullptr) {

        MemoryBlock* nextBlock = current->getNext();

        if (current->getStatus() == Status::FREE &&
            nextBlock->getStatus() == Status::FREE) {

            // Merge sizes
            current->setSize(current->getSize() + nextBlock->getSize());

            // Skip next block
            current->setNext(nextBlock->getNext());

            delete nextBlock;

        } else {
            current = current->getNext();
        }
    }
}