#ifndef MEMORYBLOCK_H
#define MEMORYBLOCK_H

#include <cstddef>  // for size_t

enum class Status {
    FREE,
    USED
};

class MemoryBlock {
private:
    size_t  size;
    size_t  startAddress;
    Status  status;
    MemoryBlock* next;

public:
    MemoryBlock(size_t size, size_t startAddress);

    size_t getSize() const;
    void setSize(size_t newSize);

    size_t getStartAddress() const;

    Status getStatus() const;
    void setStatus(Status newStatus);

    MemoryBlock* getNext() const;
    void setNext(MemoryBlock* nextBlock);
};

#endif