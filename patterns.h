#ifndef PATTERNS_H
#define PATTERNS_H 

#include <iostream> 
#include "burn.h"

//##################### Diagonal ###########################
unsigned MainDiagonalLength(PairsList  cluster);
unsigned SecondaryDiagonalLength(PairsList  cluster);
//points that form diagonals lines
template<class Type>
std::vector<unsigned> PointsInDiagonal(Type data);
template<class Type>
std::vector<int> PointsInDiagonalDistances(Type data);


//##################### Vertical ##########################
unsigned VerticalLength(PairsList  cluster);
unsigned HorizontalLength(PairsList  cluster);
//points that form vertical lines
template<class Type>
std::vector<unsigned> PointsInVertical(Type data);

#include "patterns_template.cpp" 

#endif /* PATTERNS_H */
