#ifndef WEIGHTED_QUICK_UNION
#define WEIGHTED_QUICK_UNION

#include "union_find.h"

class WeightedQuickUnion : public UnionFind
{
public:
    explicit WeightedQuickUnion(size_t n_elements);
    bool is_connected(size_t p, size_t q) const { return false; }
    bool connect(size_t p, size_t q) { return false; }

};

#endif
