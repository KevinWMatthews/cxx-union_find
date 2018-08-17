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
    size_t max_depth() const;
private:
    std::vector<size_t> ids;
    std::vector<size_t> depth;
    void disconnect_all();
    size_t get_root(size_t p) const;
};

#endif
