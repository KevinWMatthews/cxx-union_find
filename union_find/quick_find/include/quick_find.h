#ifndef QUICK_FIND_INCLUDED
#define QUICK_FIND_INCLUDED

#include "union_find.h"
#include <vector>

class QuickFind : public UnionFind
{
public:
    explicit QuickFind(size_t n_elements);
    bool is_connected(size_t p, size_t q) const override;
    bool connect(size_t p, size_t q) override;
private:
    void disconnect_all();
    void merge_components(size_t new_id, size_t old_id);
    std::vector<size_t> ids;
};

#endif
