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
    // Should we check that ids.at(q) == p?
    // Enforce direction to connections.
    auto parent = ids.at(p);
    if (parent == q)
    {
        return true;
    }
    else if (parent == p)
    {
        // Connected to ourselves only
        return false;
    }
    //TODO could check if parent > q if we enforce a connection direction
    return is_connected(parent, q);
}

bool QuickUnion::connect(size_t p, size_t q)
{
    ids[p] = ids.at(q);
    return true;
}

void QuickUnion::disconnect_all()
{
    size_t value = 0;
    generate(ids.begin(), ids.end(), [&value](){
        return value++;     // Increment after returning!
    });
}
