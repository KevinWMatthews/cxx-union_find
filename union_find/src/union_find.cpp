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

bool UnionFind::is_connected(size_t p, size_t q) const
{
    return id.at(p) == id.at(q);
}

bool UnionFind::connect(size_t p, size_t q)
{
    merge_components(id.at(p), id.at(q));
    return true;
}

void UnionFind::merge_components(size_t new_id, size_t old_id)
{
    auto is_old_id = [old_id](auto this_id) {
        return this_id == old_id;
    };
    replace_if(id.begin(), id.end(), is_old_id, new_id);
}

void UnionFind::disconnect_all()
{
    size_t value = 0;
    generate(id.begin(), id.end(), [&value](){
        return value++;     // Increment after returning!
    });
}
