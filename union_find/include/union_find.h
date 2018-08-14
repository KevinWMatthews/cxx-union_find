#ifndef UNION_FIND_INCLUDED
#define UNION_FIND_INCLUDED

#include <cstddef>
#include <vector>
#include <stdexcept>

class UnionFind
{
    virtual bool is_connected(size_t p, size_t q) const = 0;
    virtual bool connect(size_t p, size_t q) = 0;
protected:
    size_t size;

    bool is_valid_size(size_t n_elements) const
    {
        return n_elements > 0;
    }

    bool is_in_range(size_t p) const
    {
        return p < size;
    }
};


#endif
