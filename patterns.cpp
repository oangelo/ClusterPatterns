#include "patterns.h"

unsigned SecondaryDiagonalLength(PairsList  cluster){
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

unsigned MainDiagonalLength(PairsList  cluster){
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


unsigned VerticalLength(PairsList  cluster){
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

unsigned HorizontalLength(PairsList  cluster){
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

