#include "quick_union.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

QuickUnion::QuickUnion(size_t n_elements)
{
    if (n_elements == 0)
        throw domain_error("Union must have elements");

    ids.resize(n_elements);
    disconnect_all();
}

bool QuickUnion::is_connected(size_t p, size_t q) const
{
    if (p == q)
        return true;
    return false;
}

bool QuickUnion::connect(size_t p, size_t q)
{
    return true;
}

void QuickUnion::disconnect_all()
{
    size_t value = 0;
    generate(ids.begin(), ids.end(), [&value](){
        return value++;     // Increment after returning!
    });
}
