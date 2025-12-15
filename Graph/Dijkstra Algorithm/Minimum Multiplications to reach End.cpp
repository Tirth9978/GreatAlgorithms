// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dist(100000 , 1e9);
        if (start == end) {
            return 0;
        }
        queue<pair<int,int>> q;
        q.push({ 0 , start}) ;
        dist[start] = 0;
        while(!q.empty()) {
            int node = q.front().second ;
            int steps = q.front().first ;
            q.pop();
            
            for (auto x : arr) {
                int num = (x * node) % 100000;
                
                    
                if (steps + 1 < dist[num]) {
                    dist[num] = steps + 1;
                    if (num == end) {
                        return steps + 1;
                    }
                    q.push({steps + 1 , num}); 
                }
            }
        }   
        return -1;
        
    }
};
