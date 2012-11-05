#ifndef PATTERNS_H
#define PATTERNS_H 

#include <iostream> 
#include <string> 

#include "burn.h"


//##################### Diagonal ###########################
unsigned MainDiagonalLength(PairsList  cluster);
unsigned SecondaryDiagonalLength(PairsList  cluster);

//##################### Vertical ##########################
unsigned VerticalLength(PairsList  cluster);
unsigned HorizontalLength(PairsList  cluster);

std::string ClusterType(PairsList cluster);

template <class Type>
 class patterns{
     public:
        patterns(Type data);

        std::vector<PairsList> main_diagonals_cluster;
        std::vector<PairsList> secondary_diagonals_cluster;
        std::vector<PairsList> verticals_cluster;
        std::vector<PairsList> horizontal_cluster;
        std::vector<PairsList> rectangle_cluster;
        std::vector<PairsList> cross_cluster;
        std::vector<unsigned> main_diagonals_length;
        std::vector<unsigned> secondary_diagonals_length;
        std::vector<unsigned> vertical_length;
        std::vector<unsigned> horizontal_length;
};

#include "patterns_template.cpp" 

#endif /* PATTERNS_H */
