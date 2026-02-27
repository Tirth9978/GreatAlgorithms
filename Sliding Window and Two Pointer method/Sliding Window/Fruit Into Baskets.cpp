class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l =0;
        int mx = 0;
        map<int,int> mp;

        for (int i=0;i<fruits.size();i++){
            mp[fruits[i]] ++ ;

            while(mp.size() > 2){
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;
            }
            mx = max(mx , i-l+1);
        }
        return mx;
    }
};