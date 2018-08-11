#include "union_find.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

UnionFind::UnionFind(size_t n_elements)
{
    if (n_elements == 0)
        throw domain_error("Union must have elements");

    id.resize(n_elements);
    disconnect_all();
}

bool UnionFind::is_connected(size_t p, size_t q)
{
    return id.at(p) == id.at(q);
}

bool UnionFind::connect(size_t p, size_t q)
{
    id[q] = p;
    return true;
}

void UnionFind::disconnect_all()
{
    size_t value = 0;
    generate(id.begin(), id.end(), [&value](){
        return value++;     // Increment after returning!
    });
}
