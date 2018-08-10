#ifndef UNION_FIND_INCLUDED
#define UNION_FIND_INCLUDED

#include <cstddef>

class UnionFind
{
public:
    explicit UnionFind(size_t n_elements);
    bool is_connected(size_t p, size_t q);
};

#endif
