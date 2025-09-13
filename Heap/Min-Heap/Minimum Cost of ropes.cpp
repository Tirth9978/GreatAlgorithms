class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int , vector<int> , greater<int>> pq;
        
        for (auto x : arr){
            pq.push(x);
        }
        
        int cost = 0;
        
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            
            int b = pq.top();
            pq.pop();
            
            int sum = a + b ;
            cost+=sum;
            pq.push(sum);
        }
        return cost;
    }
};