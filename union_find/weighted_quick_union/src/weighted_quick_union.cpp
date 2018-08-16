#include "weighted_quick_union.h"
#include <stdexcept>

using namespace std;

WeightedQuickUnion::WeightedQuickUnion(size_t n_elements)
{
    if (is_valid_size(n_elements) == false)
        throw domain_error("WeightedQuickUnion");
}
