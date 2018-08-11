#include "quick_find.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

QuickFind::QuickFind(size_t n_elements)
{
    if (n_elements == 0)
        throw domain_error("Union must have elements");

    ids.resize(n_elements);
    disconnect_all();
}

bool QuickFind::is_connected(size_t p, size_t q) const
{
    return ids.at(p) == ids.at(q);
}

bool QuickFind::connect(size_t p, size_t q)
{
    merge_components(ids.at(p), ids.at(q));
    return true;
}

void QuickFind::merge_components(size_t new_id, size_t old_id)
{
    auto is_old_id = [old_id](auto this_id) {
        return this_id == old_id;
    };
    replace_if(ids.begin(), ids.end(), is_old_id, new_id);
}

void QuickFind::disconnect_all()
{
    size_t value = 0;
    generate(ids.begin(), ids.end(), [&value](){
        return value++;     // Increment after returning!
    });
}
