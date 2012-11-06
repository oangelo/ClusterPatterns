namespace patterns{

template<class Type> 
    Patterns<Type>::Patterns(Type data, double threshold): 
    main_diagonal_cluster(), secondary_diagonal_cluster(), vertical_cluster(),
    horizontal_cluster(), rectangle_cluster(), cross_cluster(), unknown_cluster(),
    main_diagonal_length(), secondary_diagonal_length(), vertical_length(), horizontal_length()
    {
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[0].size(); ++j) {
                if(data[i][j] == BLACK_DOT) {
                    auto cluster(Paint(data, i, j, WHITE_DOT));
                    unsigned length;
                    PatternTypes pattern_type(ClusterType(cluster, threshold , length));
                    bool identified = false;
                    if(pattern_type == t_main_diagonal){
                        main_diagonal_cluster.push_back(cluster);
                        main_diagonal_length.push_back(length);  
                        identified = true;
                    }
                    if(pattern_type == t_secondary_diagonal){
                        secondary_diagonal_cluster.push_back(cluster);
                        secondary_diagonal_length.push_back(length);  
                        identified = true;
                    }
                    if(pattern_type == t_horizontal){
                        horizontal_cluster.push_back(cluster);
                        horizontal_length.push_back(length);  
                        identified = true;
                    }
                    if(pattern_type == t_vertical){
                        vertical_cluster.push_back(cluster);
                        vertical_length.push_back(length);  
                        identified = true;
                    }
                    if(!identified)
                        unknown_cluster.push_back(cluster);
                }
            }
        }
    }

}
