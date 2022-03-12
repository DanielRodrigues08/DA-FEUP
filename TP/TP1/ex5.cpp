// By: Gonçalo Leão

#include "exercises.h"

unsigned int sumArray(unsigned int a[], unsigned int n) {
    unsigned int sum = 0;
    for(unsigned int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

#include <iostream>

bool isCanonical(unsigned int C[], unsigned int n) {
    unsigned stock[n], solutionBF[n], solutionGreedy[n];
    for(int i = C[2] + 2; i < C[n-2] + C[n-1]; i++){

        for(int j = 0; j < n ; j++){
            stock[j] = i;
        }

        if(changeMakingBF(C, stock, n, i, solutionBF) != changeMakingGreedy(C, stock, n, i, solutionGreedy)){
            return false;
        }

        for(int j = 0; j < n; j++){
            if(solutionGreedy[j] != solutionBF[j])
                return false;
        }
    }

    return true;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex5, canonicalTrue) {
    unsigned int C[] = {1,2,5};
    EXPECT_EQ(isCanonical(C,3), true);

    unsigned int C2[] = {1,2,5,10};
    EXPECT_EQ(isCanonical(C2,4), true);
}

TEST(TP1_Ex5, canonicalFalse) {
    unsigned int C[] = {1,4,5};
    EXPECT_EQ(isCanonical(C,3), true);
}