#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    int a = 0;
    int b = 0;

    for (int i=1;i<n;i++){
        int oneJump = b + abs(heights[i] - heights[i-1]);
        int twoJump = INT_MAX;

        if (i > 1){
            twoJump = a + abs(heights[i] - heights[i-2]);
        }

        a = b;
        b = min(twoJump , oneJump);
    }
    return b;
}