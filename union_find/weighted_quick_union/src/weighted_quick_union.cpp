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

    return ids[p] == ids[q];
}

bool WeightedQuickUnion::connect(size_t p, size_t q)
{
    ids[q] = p;
    return true;
}

void WeightedQuickUnion::disconnect_all()
{
    size_t value = 0;
    generate(ids.begin(), ids.end(), [&value](){
        return value++;     // Increment after returning!
    });
}
