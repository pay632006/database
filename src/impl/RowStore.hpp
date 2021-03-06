#pragma once

#include "dbms/Store.hpp"
#include "dbms/util.hpp"
#include <algorithm>
#include <vector>


namespace dbms {

namespace iterator {

template<bool C>
template<typename T>
std::conditional_t<rowstore_iterator<C>::is_const, const T&, T&>
rowstore_iterator<C>::get(std::size_t offset) const
{
    /* TODO 1.2.2 */
    dbms_unreachable("Not implemented.");
}

}

}
