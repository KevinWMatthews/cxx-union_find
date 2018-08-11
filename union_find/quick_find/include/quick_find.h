#ifndef QUICK_FIND_INCLUDED
#define QUICK_FIND_INCLUDED

#include "union_find.h"

class QuickFind : public UnionFind
{
public:
    explicit QuickFind(size_t n_elements);
    bool is_connected(size_t p, size_t q) const;
    bool connect(size_t p, size_t q);
private:
    void disconnect_all();
    void merge_components(size_t new_id, size_t old_id);
    std::vector<size_t> id;
};

#endif
