//
// Created by Wulfix on 17/11/2017.
//

#include "bitset.h"




/**
 * original
 */

//
boost::dynamic_bitset<> next_bitset_permutation(const boost::dynamic_bitset<>& v) {
    // find algorithms that works without converting to long (so we do not lose the benefit of processing a system with +128 sites).
    unsigned long v_ul = v.to_ulong();

    // t gets v's least significant 0 bits set to 1
    unsigned long t = v_ul | (v_ul - 1);
    // Next set to 1 the most significant bit to change and set to 0 the least significant ones,
    // and add the necessary 1 bits.
    unsigned long w = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v_ul) + 1));

    // Re-convert from ulong to boost::dynamic_bitset
    return boost::dynamic_bitset<> (v.size(), w);
}
/**
 *  -~t subsituted by t+1
 */
boost::dynamic_bitset<> next_bitset_permutation2(const boost::dynamic_bitset<>& v) {
    // find algorithms that works without converting to long (so we do not lose the benefit of processing a system with +128 sites).
    unsigned long v_ul = v.to_ulong();

    // t gets v's least significant 0 bits set to 1
    unsigned long t = v_ul | (v_ul - 1);
    // Next set to 1 the most significant bit to change and set to 0 the least significant ones,
    // and add the necessary 1 bits.
    unsigned long w = (t + 1) | (((~t & (t+1)) - 1) >> (v.find_first() + 1));

    // Re-convert from ulong to boost::dynamic_bitset
    return boost::dynamic_bitset<> (v.size(), w);
}
/**
 *  longs only
 */
unsigned long next_bitset_permutation_long( unsigned long v) {
    // find algorithms that works without converting to long (so we do not lose the benefit of processing a system with +128 sites).
    unsigned long v_ul = v;

    // t gets v's least significant 0 bits set to 1
    unsigned long t = v_ul | (v_ul - 1);
    // Next set to 1 the most significant bit to change and set to 0 the least significant ones,
    // and add the necessary 1 bits.
    unsigned long w = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v_ul) + 1));

    // Re-convert from ulong to boost::dynamic_bitset
    return  w;
}
/**
 * Bitsets only + example
 * lot of intermediates cause this to run extremely slow
 *
 * a = 10110010
 * b = 10110001
 * c = 10110011
 * d = 10110100
 * e = 01001100
 * f = 00000100
 * f = 00000011
 * f = 00000000
 * g = 10110100
 */


boost::dynamic_bitset<> next_bitset_permutation_full(const boost::dynamic_bitset<>& a) {
    //a = 10111100
    boost::dynamic_bitset<> b = a;
    decrement(b); // b = a-1 b=10111011
    boost::dynamic_bitset<> c = a | b; //c = 10111111
    boost::dynamic_bitset<> d = c;
    increment(d); // d= c+1 d=11000000
    boost::dynamic_bitset<> e = ~c; //e=01000000
    unsigned int shift = a.find_first()+1; //shift =3
    boost::dynamic_bitset<> f = e & d; //f=01000000
    decrement(f); //f = 00111111

    f >>= shift; //f = 00000111

    // Next set to 1 the most significant bit to change and set to 0 the least significant ones,
    // and add the necessary 1 bits.
    boost::dynamic_bitset<> g = d |f; //11000111
    return g;

}

/**
 * reduced intermediates
 */


boost::dynamic_bitset<> next_bitset_permutation_full2(const boost::dynamic_bitset<>& a) {
    //a = 10111100
    boost::dynamic_bitset<> b = a;
    decrement(b); // b = a-1 b=10111011
    boost::dynamic_bitset<> c = a | b; //c = 10111111
    boost::dynamic_bitset<> d = c;
    increment(d); // d= c+1 d=11000000
    unsigned int shift = a.find_first()+1; //shift =3
    boost::dynamic_bitset<> f = ~c & d; //f=01000000
    decrement(f); //f = 00111111

    f >>= shift; //f = 00000111

    // Next set to 1 the most significant bit to change and set to 0 the least significant ones,
    // and add the necessary 1 bits.
    boost::dynamic_bitset<> g = d |f; //11000111
    return g;

}
/**
 * other algorithm (selfmade)
 */

boost::dynamic_bitset<> next_bitset_permutation_self(const boost::dynamic_bitset<>& a) {
    boost::dynamic_bitset<> b = a;
    unsigned int index = b.find_first();
    unsigned int index2 =0;
    increment(b,index);
    index++;

    while(!b[index]){
        index++;
        index2++;
    }
    b[index2] = true;
    decrement(b);
    return b;

}
/*
 * auxiliary
 */
void increment(boost::dynamic_bitset<>& bitset, unsigned int at)
{
    for(int loop = at;loop < bitset.size(); loop++)
    {
        bitset[loop].flip();
        if(bitset[loop]){
            break;
        }
    }
}
/*
 * auxiliary
 */
void decrement(boost::dynamic_bitset<>& bitset)
{
    for(int loop = 0;loop < bitset.size(); loop++)
    {
        bitset[loop].flip();
        if(!bitset[loop]){
            break;
        }
    }
}

