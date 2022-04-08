#include "exercises.h"

bool noOverlaps(const std::vector<Activity> &acts) {
    for(unsigned int i = 0; i < acts.size(); i++) {
        Activity A1 = acts.at(i);
        for(unsigned int j = i + 1; j < acts.size(); j++) {
            Activity A2 = acts.at(j);
            if(A1.overlaps(A2)) return false;
        }
    }
    return true;
}

bool Activity::operator==(const Activity &a2) const {
    return start == a2.start && finish == a2.finish;
}

bool Activity::overlaps(const Activity &a2) const {
    return (start < a2.finish) && (a2.start < finish);
}

bool aux(std::vector<Activity>& A, std::vector<Activity>& result, int counter){
    if(!noOverlaps(result)) return false;

    while(counter < A.size()){
        result.push_back(A[counter]);
        counter++;
        if(!aux(A, result, counter)){
            result.erase(--result.end());
        }
        else{
            return true;
        }
    }
    return true;

}


std::vector<Activity> activitySelectionBacktracking(std::vector<Activity> A) {
    std::vector<Activity> result;
    aux(A, result, 0);
    return result;
}

/// TESTS ///
#include <gtest/gtest.h>
#include <gmock/gmock.h>



TEST(TP2_Ex4, activityScheduling) {
    std::vector<Activity> A = {{10,20}, {30, 35}, {5, 15}, {10, 40}, {40, 50}};
    std::vector<Activity> V = activitySelectionBacktracking(A);
    EXPECT_EQ(V.size(), 3 );
    EXPECT_EQ(noOverlaps(V), true);
}