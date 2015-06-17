/*!
 * @file sc_map_square_range.hpp
 * @author Christian Amstutz
 * @date June 9, 2015
 *
 * @brief
 *
 */

/*
 *  Copyright (c) 2015 by Christian Amstutz
 */

#pragma once

#include "../sc_map_regular/sc_map_regular_range.hpp"
#include "sc_map_square_key.hpp"

//******************************************************************************
class sc_map_square_range : public sc_map_regular_range<sc_map_square_key>
{
public:
    using sc_map_range::key_type;

    sc_map_square_range();
    sc_map_square_range(const key_type& start_key, const key_type& end_key);
    //sc_map_square_range(const sc_map_range<key_type>* base_range, const key_type& start_key, const key_type& end_key);
    virtual ~sc_map_square_range() {};

    virtual sc_map_square_range* clone() const;

    virtual bool next_key(key_type& key) const;

private:
    direction Y_dir;
    direction X_dir;
};
