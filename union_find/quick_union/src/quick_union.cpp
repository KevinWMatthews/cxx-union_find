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
    auto target = p;
    auto child = q;
    auto parent = ids.at(child);

    if (child == target)
    {
        // User asked if this element is connected to itself. It is.
        return true;
    }
    if (parent == child)
    {
        // This child is connected only to itself.
        return false;
    }
    else if (parent == target)
    {
        return true;
    }
    return is_connected(target, parent);
}

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
