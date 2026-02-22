#include "../include/MemoryBlock.h"

MemoryBlock::MemoryBlock(size_t size, size_t address)
    : size(size), startAddress(address), status(Status::FREE), next(nullptr) {
    }

size_t MemoryBlock::getSize() const {
    return size;
}

void MemoryBlock::setSize(size_t newSize) {
    size = newSize;
}

size_t MemoryBlock::getStartAddress() const {
    return startAddress;
}

Status MemoryBlock::getStatus() const {
    return status;
}

void MemoryBlock::setStatus(Status newStatus) {
    status = newStatus;
}

MemoryBlock* MemoryBlock::getNext() const {
    return next;
}

void MemoryBlock::setNext(MemoryBlock* nextBlock) {
    next = nextBlock;
}