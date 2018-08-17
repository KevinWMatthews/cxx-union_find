#ifndef WEIGHTED_QUICK_UNION
#define WEIGHTED_QUICK_UNION

#include "union_find.h"
#include <vector>

class WeightedQuickUnion : public UnionFind
{
public:
    explicit WeightedQuickUnion(size_t n_elements);
    bool is_connected(size_t p, size_t q) const;
    bool connect(size_t p, size_t q);
private:
    std::vector<size_t> ids;
    void disconnect_all();
};

#endif
