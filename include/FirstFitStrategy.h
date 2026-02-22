#ifndef FIRSTFITSTRATEGY_H
#define FIRSTFITSTRATEGY_H

#include "AllocationStrategy.h"

class FirstFitStrategy : public AllocationStrategy {
public:
    MemoryBlock* allocate(MemoryBlock* head, size_t size) override;
};

#endif