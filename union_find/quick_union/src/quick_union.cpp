#include "quick_union.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

namespace
{

string exception_message(const char* function_name)
{
    return string("QuickUnion::" + string(function_name));
}

string exception_message(const char* function_name, const char* message)
{
    return string("QuickUnion::" + string(function_name) + ": " + message);
}

}

QuickUnion::QuickUnion(size_t n_elements)
{
    size = n_elements;
    check_n_elements(size);
    ids.resize(size);
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
    if (UnionFind::is_in_range(p) == false)
        throw out_of_range(exception_message(__func__, "argument p"));
    if (UnionFind::is_in_range(q) == false)
        throw out_of_range(exception_message(__func__, "argument q"));

    auto root_p = get_root(p);
    auto root_q = get_root(q);
    return root_p == root_q;
}

bool QuickUnion::connect(size_t p, size_t q)
{
    if (UnionFind::is_in_range(p) == false)
        throw out_of_range(exception_message(__func__, "argument p"));
    if (UnionFind::is_in_range(q) == false)
        throw out_of_range(exception_message(__func__, "argument q"));

    // To connect elements in a tree, connect their roos.
    // Elements can be their own root.
    auto root_p = get_root(p);
    auto root_q = get_root(q);
    ids[root_q] = root_p;
    return true;
}

void QuickUnion::disconnect_all()
{
    size_t value = 0;
    generate(ids.begin(), ids.end(), [&value](){
        return value++;     // Increment after returning!
    });
}
