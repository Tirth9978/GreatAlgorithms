class Solution {
public:
    int maxScore(string s) {
        int count1 =0;
        int count0 =0;
        for (int i=1;i<s.size();i++){
            if (s[i]=='1'){
                count1++;
            }
        }
        if (s[0]=='0')count0++;
        int mx = count1 + count0;
        for (int i=1;i<s.size()-1;i++){
            if (s[i]=='0')count0++;
            else count1--;
            mx = max(count1+count0 , mx);
        }
        return mx;
    }
};
