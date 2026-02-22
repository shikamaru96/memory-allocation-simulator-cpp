#ifndef ALLOCATIONSTRATEGY_H
#define ALLOCATIONSTRATEGY_H

#include "MemoryBlock.h"

class AllocationStrategy {
public:
    virtual ~AllocationStrategy() = default;

    virtual MemoryBlock* allocate(MemoryBlock* head, size_t size) = 0;
};

#endif