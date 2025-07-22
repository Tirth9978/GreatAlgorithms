// LeetCode Link : https://leetcode.com/problems/elimination-game/submissions/1707160014/?envType=problem-list-v2&envId=recursion

class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1){
            return 1;
        }
        
        return 2 * (n /2 + 1 - lastRemaining(n/2));
        
    }
};