/*!
 * @file sc_map_key_range.hpp
 * @author Christian Amstutz
 * @date June 8, 2015
 *
 * @brief
 *
 */

/*
 *  Copyright (c) 2015 by Christian Amstutz
 */

#pragma once

#include "sc_map_key.hpp"

#include <string>
#include <functional>
#include <ostream>

//******************************************************************************
template <typename key_T>
class sc_map_key_range
{
public:
    typedef key_T key_type;

    virtual ~sc_map_key_range() {};

    virtual sc_map_key_range* clone() =0;

    virtual key_type first() const =0;
    virtual key_type last() const =0;

    virtual bool key_in_range(const key_type& key) const;
    virtual bool next_key(key_type& key) const =0;
};

//******************************************************************************

//******************************************************************************
template <typename key_T>
bool sc_map_key_range<key_T>::key_in_range(const key_type& key) const
{
    key_type range_key = first();
    do
    {
        if (range_key == key)
        {
            return true;
        }
    } while (next_key(range_key));

    return false;
}
