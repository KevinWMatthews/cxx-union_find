#include "weighted_quick_union.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

WeightedQuickUnion::WeightedQuickUnion(size_t n_elements)
{
    if (is_valid_size(n_elements) == false)
        throw domain_error("WeightedQuickUnion");

    size = n_elements;
    ids.resize(size);
    disconnect_all();
}

bool WeightedQuickUnion::is_connected(size_t p, size_t q) const
{
    if (is_in_range(p) == false)
        throw out_of_range("WeightedQuickUnion::is_connected");
    if (is_in_range(q) == false)
        throw out_of_range("WeightedQuickUnion::is_connected");

    auto root_p = get_root(p);
    auto root_q = get_root(q);

    return ids[root_p] == ids[root_q];
}

bool WeightedQuickUnion::connect(size_t p, size_t q)
{
    // To connect elements in a tree, connect their roots.
    // Elements can be their own root.
    auto root_p = get_root(p);
    auto root_q = get_root(q);
    ids[root_q] = root_p;

    return true;
}

size_t WeightedQuickUnion::get_root(size_t p) const
{
    return p;
}

void WeightedQuickUnion::disconnect_all()
{
    size_t value = 0;
    generate(ids.begin(), ids.end(), [&value](){
        return value++;     // Increment after returning!
    });
}
