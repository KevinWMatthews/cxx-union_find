#include "quick_union.h"
#include <stdexcept>

using namespace std;

QuickUnion::QuickUnion(size_t n_elements)
{
    if (n_elements == 0)
        throw domain_error("Union must have elements");
}

bool QuickUnion::is_connected(size_t p, size_t q) const
{
    if (p == q)
        return true;
    return false;
}

bool QuickUnion::connect(size_t p, size_t q)
{
}
