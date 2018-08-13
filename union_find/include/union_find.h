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
    void check_n_elements(size_t n_elements) const
    {
        if (n_elements == 0)
            throw std::domain_error("Union must have elements");
    }
};


#endif
