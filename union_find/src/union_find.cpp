#include "union_find.h"
#include <stdexcept>

using namespace std;

UnionFind::UnionFind(size_t n_elements)
{
    if (n_elements == 0)
        throw domain_error("Union must have elements");
}

bool UnionFind::is_connected(size_t p, size_t q)
{
    return false;
}
