#include "SimpleAllocator.h"
#include "assert.h"

SimpleAllocator::SimpleAllocator() { reset(); }

void *SimpleAllocator::alloc(size_t size)
{
    assert(nextFree + size <= sizeof(bytes));
    void *res = &bytes[nextFree];
    nextFree += size;

    return res;
}

void SimpleAllocator::reset() { nextFree = 0; }

void *operator new(size_t size, SimpleAllocator &p)
{
    return p.alloc(size);
}