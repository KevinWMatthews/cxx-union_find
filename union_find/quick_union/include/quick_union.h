#ifndef QUICK_UNION_INCLUDED
#define QUICK_UNION_INCLUDED

#include "union_find.h"

class QuickUnion : public UnionFind
{
public:
    explicit QuickUnion(size_t n_elements);
    bool is_connected(size_t p, size_t q) const;
    bool connect(size_t p, size_t q);
};

#endif
