#include <bits/stdc++.h> 

int solve(vector<int> &heights , int index){
    if (index == 0){
        return 0;
    }

    int oneJump = solve(heights,index -1) +   abs(heights[index] - heights[index-1]);
    int twoJump = INT_MAX;
    if (index > 1){
        twoJump = solve(heights,index-2) +   abs(heights[index] - heights[index-2]);
        
    }
    return min(oneJump , twoJump);
}

int frogJump(int n, vector<int> &heights)
{
    if (n == 2){
        return abs(heights[0]- heights[1]);
    }
    return solve(heights , n-1);
}