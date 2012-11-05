#include "math.h"
#include "../patterns.h"

/*
   vector<vector<unsigned>> data;
   data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
   data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
   data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
   data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
   data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
   data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
   data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
   data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
   data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
   data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
   */

/*
   for (int i = data.size() - 1; i >= 0 ; i--)
   {
   for (size_t j = 0; j < data.size(); ++j)
   std::cout << data[i][j] << " ";
   std::cout << std::endl;
   }
//*/

TEST(Burn_file, Burning)
{ 

    vector<vector<unsigned>> data;
    data.push_back({0, 0, 1, 1, 0, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 1, 0, 1, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 1, 0, 0, 1, 0, 0, 1, 0});
    data.push_back({0, 0, 1, 0, 0, 0, 1, 0, 1, 0});
    data.push_back({0, 0, 1, 0, 0, 0, 1, 0, 1, 0});
    data.push_back({1, 1, 1, 0, 0, 0, 1, 1, 1, 1});
    data.push_back({0, 0, 0, 0, 1, 0, 1, 0, 1, 0});
    data.push_back({0, 0, 0, 0, 1, 0, 1, 0, 1, 0});
    data.push_back({0, 0, 0, 1, 0, 0, 1, 0, 1, 0});
    data.push_back({0, 0, 0, 1, 1, 1, 1, 0, 0, 0});

    vector<vector<unsigned>> aux(data);
    Paint(aux, 5, 0, 2);

    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[0].size(); ++j) {
            if(data[i][j] == 1)
                EXPECT_EQ(aux[i][j], 2);
        }
    }
}

TEST(Patterns, SecondaryDiagonal)
{ 
    vector<vector<unsigned>> data;
    //Mai be seen that the matrix is inverted but is not
    //the first row is the last row!
    data.push_back({1, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    data.push_back({1, 1, 0, 0, 0, 0, 0, 0, 0, 0});
    data.push_back({0, 1, 1, 0, 0, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 1, 1, 0, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 1, 1, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 1, 1, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 0, 1, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

    auto diagonal(Burn(data, 0, 0));
    EXPECT_EQ(SecondaryDiagonalLength(diagonal), 6);
    EXPECT_EQ(MainDiagonalLength(diagonal), 0);
    EXPECT_EQ(VerticalLength(diagonal), 2);
    EXPECT_EQ(HorizontalLength(diagonal), 2);
}

TEST(Patterns, MainDiagonal)
{ 
    vector<vector<unsigned>> data;
    //Mai be seen that the matrix is inverted but is not
    //the first row is the last row!
    data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 1, 1});
    data.push_back({0, 0, 0, 0, 0, 0, 0, 1, 1, 1});
    data.push_back({0, 0, 0, 0, 0, 0, 1, 1, 1, 0});
    data.push_back({0, 0, 0, 0, 0, 1, 1, 1, 0, 0});
    data.push_back({0, 0, 0, 0, 1, 1, 1, 0, 0, 0});
    data.push_back({0, 0, 0, 1, 1, 1, 0, 0, 0, 0});
    data.push_back({0, 0, 1, 1, 1, 0, 0, 0, 0, 0});
    data.push_back({0, 1, 1, 1, 0, 0, 0, 0, 0, 0});
    data.push_back({1, 1, 1, 0, 0, 0, 0, 0, 0, 0});
    data.push_back({1, 1, 0, 0, 0, 0, 0, 0, 0, 0});

    auto diagonal(Burn(data, 9, 0));
    EXPECT_EQ(SecondaryDiagonalLength(diagonal), 2);
    EXPECT_EQ(MainDiagonalLength(diagonal), 10);
    EXPECT_EQ(VerticalLength(diagonal), 3);
    EXPECT_EQ(HorizontalLength(diagonal), 3);
}

TEST(Patterns, Horizontal)
{ 
    vector<vector<unsigned>> data;
    data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 1, 1, 1, 1, 0, 0, 0});
    data.push_back({1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
    data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

    auto diagonal(Burn(data, 5, 0));
    EXPECT_EQ(SecondaryDiagonalLength(diagonal), 2);
    EXPECT_EQ(MainDiagonalLength(diagonal), 2);
    EXPECT_EQ(VerticalLength(diagonal), 2);
    EXPECT_EQ(HorizontalLength(diagonal), 10);
}

TEST(Patterns, Vetical)
{ 
    vector<vector<unsigned>> data;
    data.push_back({0, 0, 0, 0, 1, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 1, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 1, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 1, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 1, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 1, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 1, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 1, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 1, 0, 0, 0, 0, 0});
    data.push_back({0, 0, 0, 0, 1, 0, 0, 0, 0, 0});

    auto diagonal(Burn(data, 5, 4));
    EXPECT_EQ(SecondaryDiagonalLength(diagonal), 0);
    EXPECT_EQ(MainDiagonalLength(diagonal), 0);
    EXPECT_EQ(VerticalLength(diagonal), 10);
    EXPECT_EQ(HorizontalLength(diagonal), 0);
}
