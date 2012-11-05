#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "gtest/gtest.h"


using namespace std;

#include "patterns.h"

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

