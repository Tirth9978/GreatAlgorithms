class Solution {
public:
    string reorganizeString(string s) {
        map<char , int> mp;

        for (auto x : s){
            mp[x] ++ ;
        }

        priority_queue<pair<int,char>> pq;

        for (auto x : mp){
            pq.push({x.second , x.first});
        }
        pair<int ,char> prev= {0 , 'T'};
        string ans ;
        while(!pq.empty()){
            pair<int ,char> top = pq.top();
            pq.pop();
            ans += top.second;

            if(prev.first > 0){
                pq.push(prev);
            }

            top.first -- ;
            prev = top;
        }
        if (ans.size() != s.size()){
            return "";
        }
        return ans ;
    }
};