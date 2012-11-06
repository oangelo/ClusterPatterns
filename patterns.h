#ifndef PATTERNS_H
#define PATTERNS_H 

#include <iostream> 
#include <string> 

#include "burn.h"

namespace patterns{

enum PatternTypes {t_main_diagonal, t_secondary_diagonal, t_horizontal, t_vertical, t_none};
//##################### Diagonal ###########################
unsigned MainDiagonalLength(PairsList  cluster);
unsigned SecondaryDiagonalLength(PairsList  cluster);
//##################### Vertical ##########################
unsigned VerticalLength(PairsList  cluster);
unsigned HorizontalLength(PairsList  cluster);

PatternTypes ClusterType(const PairsList& cluster, double threshold, unsigned& length);

template <class Type>
 class Patterns{
     public:
        Patterns(Type data, double threshold = 2.0);

        std::vector<PairsList> main_diagonal_cluster;
        std::vector<PairsList> secondary_diagonal_cluster;
        std::vector<PairsList> vertical_cluster;
        std::vector<PairsList> horizontal_cluster;
        std::vector<PairsList> rectangle_cluster;
        std::vector<PairsList> cross_cluster;
        std::vector<PairsList> unknown_cluster;
        std::vector<unsigned>  main_diagonal_length;
        std::vector<unsigned>  secondary_diagonal_length;
        std::vector<unsigned>  vertical_length;
        std::vector<unsigned>  horizontal_length;
};

}

#include "patterns_template.cpp" 

#endif /* PATTERNS_H */
