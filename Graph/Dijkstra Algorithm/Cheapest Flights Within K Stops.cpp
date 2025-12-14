class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);

        for (int i =0;i<flights.size() ;i++) {
            graph[flights[i][0]].push_back({flights[i][1] , flights[i][2]});
        }

        queue<pair<int , pair<int ,int >>> q;
        vector<int> dist(n,1e9);
        dist[src] = 0;

        q.push({0 , {src , 0}}) ; 

        while(!q.empty()) {
            int stop = q.front().first ;
            int node = q.front().second.first ;
            int cost = q.front().second.second ;
            q.pop() ;


            if (stop > k) continue ;
            for (auto x : graph[node]) {
                int adjNode = x.first ;
                int NewCost = x.second ;

                if (cost + NewCost < dist[adjNode] && stop <= k) {
                    dist[adjNode] = cost + NewCost;
                    q.push({stop + 1  , {adjNode , dist[adjNode]}});
                }
            }
        }

        if (dist[dst] == 1e9) {
            return -1 ;
        }

        return dist[dst] ;
    }
};