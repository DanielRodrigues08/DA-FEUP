// By: Gonçalo Leão

#include "exercises.h"
#include <iostream>

bool changeMakingBF(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {
    /*std::cout << "Stock: ";
    for(int i = 0; i < n; i++){
        std::cout << Stock[i] << " ";
    }
    std::cout << std::endl;*/

    unsigned int compNumCoins = 0;
    int possibleSolution[99];
    bool first = true;
    for(int i = 0; i < n; i++)
        possibleSolution[i] = 0;

    while(true){
        int currentIndex = 0;

        while(possibleSolution[currentIndex] == Stock[currentIndex]){
            currentIndex++;
            if(currentIndex == n) break;
        }

        if(currentIndex == n) break;

        for(int i = 0; i < currentIndex; i++){
            possibleSolution[i] = 0;
        }

        possibleSolution[currentIndex]++;

        //std::cout << possibleSolution[0] << " " << possibleSolution[1] << " " << possibleSolution[2] << " " << possibleSolution[3] << std::endl ;

        unsigned int sumCoins = 0;
        unsigned int numCoins = 0;

        for(int i = 0; i < n; i++){
            sumCoins += possibleSolution[i] * C[i];
            numCoins += possibleSolution[i];
        }

        if(sumCoins == T &&  (first || numCoins < compNumCoins)){
            if(first) first = false;
            compNumCoins = numCoins;
            for(int i = 0; i < n; i++)
                usedCoins[i] = possibleSolution[i];
        }
    }

    return !first;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex3, hasBFChangeCanonical) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {1,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingBF(C,Stock,n,13,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    unsigned int Stock2[] = {1,2,4,2};
    EXPECT_EQ(changeMakingBF(C,Stock2,n,38,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 3);
    EXPECT_EQ(usedCoins[3], 2);
}

TEST(TP1_Ex3, hasBFChangeNonCanonical) {
    unsigned int C[] = {1,4,5};
    unsigned int Stock[] = {2,2,1};
    unsigned int n = 3;
    unsigned int usedCoins[3];

    EXPECT_EQ(changeMakingBF(C,Stock,n,6,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);

    EXPECT_EQ(changeMakingBF(C,Stock,n,8,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 2);
    EXPECT_EQ(usedCoins[2], 0);
}

TEST(TP1_Ex3, hasNoBFChange) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {0,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingBF(C,Stock,n,18,usedCoins), false);
    EXPECT_EQ(changeMakingBF(C,Stock,n,1,usedCoins), false);
}