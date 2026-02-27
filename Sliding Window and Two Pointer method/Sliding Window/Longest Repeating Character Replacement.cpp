class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int ans = 0;
        map<char, int> mp;
        // int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            int maxF = 0;
            for (auto x : mp) {
                maxF = max(maxF, x.second);
            }
            int length = i - l + 1;
            while (length - maxF > k) {
                mp[s[l]]--;
                l++;
                for (auto x : mp) {
                    maxF = max(maxF, x.second);
                }
                length = i-l+1;
            }
            ans = max(length , ans);
        }
        return ans ;
    }
};