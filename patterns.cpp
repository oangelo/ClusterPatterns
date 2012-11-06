#include "patterns.h"
namespace patterns {
unsigned SecondaryDiagonalLength(PairsList  cluster) {
    unsigned max = 0;
    unsigned length;
    for(auto counter: cluster ){
        length = 1;
        bool exist = true;
        while(exist){
            exist = cluster.count({counter.first + length, counter.second + length});
            if(exist)
                length++;
        }
        if(length > 1 && length > max)
            max = length;
    }
    return(max);
}

unsigned MainDiagonalLength(PairsList  cluster) {
    unsigned max = 0;
    unsigned length;
    for(auto counter: cluster ){
        length = 1;
        bool exist = true;
        while(exist){
            exist = cluster.count({counter.first + length, counter.second - length});
            if(exist)
                length++;
        }
        if(length > 1 && length > max)
            max = length;
    }
    return(max);
}


unsigned VerticalLength(PairsList  cluster) {
    unsigned max = 0;
    unsigned length;
    for(auto counter: cluster ){
        length = 1;
        bool exist = true;
        while(exist){
            exist = cluster.count({counter.first + length, counter.second});
            if(exist)
                length++;
        }
        if(length > 1 && length > max)
            max = length;
    }
    return(max);
}

unsigned HorizontalLength(PairsList  cluster) {
    unsigned max = 0;
    unsigned length;
    for(auto &counter: cluster ){
        length = 1;
        bool exist = true;
        while(exist){
            exist = cluster.count({counter.first, counter.second + length});
            if(exist)
                length++;
        }
        if(length > 1 && length > max)
            max = length;
    }
    return(max);
}


PatternTypes ClusterType(const PairsList& cluster, double threshold, unsigned& length) {
    unsigned vertical(VerticalLength(cluster));
    unsigned horizontal(HorizontalLength(cluster));
    unsigned main_diagonal(MainDiagonalLength(cluster));
    unsigned secondary_diagonal(SecondaryDiagonalLength(cluster));
    if(main_diagonal > threshold * vertical)
        if(main_diagonal > threshold * horizontal)
            if(main_diagonal > threshold * secondary_diagonal) {
                length = main_diagonal;
                return t_main_diagonal;
            }
    if(secondary_diagonal > threshold * vertical)
        if(secondary_diagonal > threshold * horizontal)
            if(secondary_diagonal > threshold * main_diagonal) {
                length = secondary_diagonal;
                return t_secondary_diagonal;
            }
    if(horizontal > threshold * vertical)
        if(horizontal > threshold * secondary_diagonal)
            if(horizontal > threshold * main_diagonal) {
                length = horizontal;
                return t_horizontal;
            }
    if(vertical > threshold * horizontal)
        if(vertical > threshold * secondary_diagonal)
            if(vertical > threshold * main_diagonal) {
                length = vertical;
                return t_vertical;
            }

    return t_none; 
}

}
