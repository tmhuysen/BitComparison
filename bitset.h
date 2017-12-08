//
// Created by Wulfix on 17/11/2017.
//

#ifndef HUBBARDCLEAN_BITSET_H
#define HUBBARDCLEAN_BITSET_H

#include <boost/dynamic_bitset.hpp>
#include <boost/math/special_functions.hpp>

/** Give the next bitset permutation in a lexicographical sense.
 *
 *      examples:
 *          011 -> 101
 *          101 -> 110
 *
 * Taken from (http://graphics.stanford.edu/~seander/bithacks.html#NextBitPermutation)
 * Credits: Dario Sneidermanis of Argentina, who provided this on November 28, 2009.
 */
boost::dynamic_bitset<> next_bitset_permutation(const boost::dynamic_bitset<>& v);
boost::dynamic_bitset<> next_bitset_permutation2(const boost::dynamic_bitset<>& v);
boost::dynamic_bitset<> next_bitset_permutation_full(const boost::dynamic_bitset<>& v);
boost::dynamic_bitset<> next_bitset_permutation_full2(const boost::dynamic_bitset<>& v);
boost::dynamic_bitset<> next_bitset_permutation_self(const boost::dynamic_bitset<>& v);
unsigned long next_bitset_permutation_long(unsigned long v);
void increment(boost::dynamic_bitset<>& bitset, unsigned int at=0);
void decrement(boost::dynamic_bitset<>& bitset);




#endif //HUBBARDCLEAN_BITSET_H
