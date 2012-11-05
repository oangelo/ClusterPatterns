#include "patterns.h"

template<class Type>
std::vector<unsigned> PointsInDiagonal(Type data){
    unsigned color = 10;
    Type data_aux(data);
    std::vector<unsigned> length;
    for(unsigned j = 0; j < data.size(); j++)
        for(unsigned i = 0; i < data[0].size(); i++)
            if(data[i][j] == BLACK_DOT){
                    PairsList  cluster(Paint(data, i, j, color));
                    unsigned len = MainDiagonalLength(cluster);  
                    unsigned len_orth = SecondaryDiagonalLength(cluster);  
                    if( len > 1.5 * (len_orth + 1)) // cheking if it is a Diagonal
                        length.push_back(cluster.size());  
            }
     return(length);
}

template<class Type>
double MeanMainDiagonalLength(Type data){
    unsigned color(10);
    double sum(0);
    double counter(0);
    for(unsigned j(0); j < data.size(); j++)
        for(unsigned i(0); i < data.size(); i++)
            if(data[i][j] == BLACK_DOT){
                    PairsList  cluster(Paint(data, i, j, color));
                    unsigned len = MainDiagonalLength(cluster);  
                    unsigned len_orth = SecondaryDiagonalLength(cluster);  
                    if( len > 1.5 * (len_orth + 1)) {// cheking if it is a Diagonal
                        sum += len;  
                        ++counter;
                    }
            }
     return sum / counter;
}

template<class Type>
std::vector<int> PointsInDiagonalDistances(Type data){
    unsigned color = 10;
    std::vector<int> length;
    for(unsigned j = 0; j < data.size(); j++)
        for(unsigned i = 0; i < data[0].size(); i++)
            if(data[i][j] == BLACK_DOT){
                    unsigned len = MainDiagonalLength(Paint(data, i, j, color));  
                    if( len > 0 )
                        length.push_back(i-j);  
            }
     return(length);
}

template<class Type>
std::vector<unsigned> PointsInVertical(Type data){
    unsigned color = 10;
    std::vector<unsigned> length;
    for(unsigned j = 0; j < data.size(); j++)
        for(unsigned i = 0; i < data.size(); i++)
            if(data[i][j] == BLACK_DOT){
                    PairsList  cluster(Paint(data, i, j, color));
                    unsigned len_vertical = VerticalLength(cluster);  
                    unsigned len_horizontal = HorizontalLength(cluster);  
                    if( len_vertical > 1.5 * (len_horizontal + 1))
                        length.push_back(cluster.size());  
            }
     return(length);
}

