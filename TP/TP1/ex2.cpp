// By: Gonçalo Leão

#include "exercises.h"

int sumArray(int A[], unsigned int i, unsigned int j) {
    int sum = 0;
    for(unsigned int k = i; k != j+1; k++){
        sum += A[k];
    }
    return sum;
}

int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    int maxSum = 0;
    int temp;
    for(int jump = 1; jump != n-2 ; jump++) {
        for (int tempI = 0; tempI < n - jump; tempI++) {
            temp = sumArray(A, tempI, tempI+jump);
            if(temp > maxSum){
                i = tempI;
                j = tempI+jump;
                maxSum = temp;
            }
        }
    }

   return maxSum;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex2, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequence(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}