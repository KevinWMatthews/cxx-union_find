#include "weighted_quick_union.h"
#include <stdexcept>

using namespace std;

WeightedQuickUnion::WeightedQuickUnion(size_t n_elements)
{
    if (is_valid_size(n_elements) == false)
        throw domain_error("WeightedQuickUnion");

    size = n_elements;
}

bool WeightedQuickUnion::is_connected(size_t p, size_t q) const
{
    if (is_in_range(p) == false)
        throw out_of_range("WeightedQuickUnion::is_connected");
    if (is_in_range(q) == false)
        throw out_of_range("WeightedQuickUnion::is_connected");

    return p == q;
}
