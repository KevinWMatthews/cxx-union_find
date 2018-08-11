#include "quick_union.h"
#include <stdexcept>

using namespace std;

QuickUnion::QuickUnion(size_t n_elements)
{
    if (n_elements == 0)
        throw domain_error("Union must have elements");
}
