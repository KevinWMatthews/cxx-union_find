#ifndef UNION_FIND_INCLUDED
#define UNION_FIND_INCLUDED

#include <cstddef>
#include <vector>

class UnionFind
{
    virtual bool is_connected(size_t p, size_t q) const = 0;
    virtual bool connect(size_t p, size_t q) = 0;
};

#endif
