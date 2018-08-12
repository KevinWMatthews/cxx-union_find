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

size_t QuickUnion::get_root(size_t p) const
{
    auto child = p;
    auto parent = ids.at(child);
    while (parent != child)
    {
        child = parent;
        parent = ids.at(child);
    }
    return parent;
}

// Elements are connected if they share the same root.
bool QuickUnion::is_connected(size_t p, size_t q) const
{
    auto root_p = get_root(p);
    auto root_q = get_root(q);
    return root_p == root_q;
}

// We're storing items in a tree. Document this somehow.
bool QuickUnion::connect(size_t p, size_t q)
{
    auto parent = p;
    auto child = q;
    ids[child] = parent;
    return true;
}

void QuickUnion::disconnect_all()
{
    size_t value = 0;
    generate(ids.begin(), ids.end(), [&value](){
        return value++;     // Increment after returning!
    });
}
