#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include "MemoryBlock.h"
#include "AllocationStrategy.h"

class MemoryManager {
private:
    size_t totalSize;
    MemoryBlock* head;              // start of linked list
    AllocationStrategy* strategy;   // allow runtime strategy switching later

public:
    MemoryManager(size_t totalSize, AllocationStrategy* strategy);
    ~MemoryManager();       // destructor

    bool allocate(size_t size);
    bool free(size_t startAddress);

    void printStatus() const;

    void defragment();  
};

#endif