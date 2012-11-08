#ifndef BURN_H
#define BURN_H 

#include <set>
#include <map>
#include <vector>
#include <numeric>
#include <algorithm>

namespace burn{
enum{WHITE_DOT = 0, BLACK_DOT = 1};
typedef std::set<std::pair<unsigned,unsigned> > PairsList; 

template<class Type>
PairsList Burn(Type data, unsigned i, unsigned j);
template<class Type>
PairsList Paint(Type& data, unsigned i, unsigned j, unsigned color);
}
#include "burn_template.cpp" 

#endif /* BURN_H */
