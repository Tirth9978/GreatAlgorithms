// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(A.size() , vector<int> (A[0].size() , 10e9));
        if (A[0][0] == 0) {
            return -1;
        }
        q.push({0 , {0 , 0}});
        
        while(!q.empty()) {
            int distance = q.front().first ;
            int x = q.front().second.first ;
            int y = q.front().second.second;
            q.pop();
            int forI[] = {-1,0,1,0};
            int forJ[] = {0,1,0,-1};
            
            if (x == X && y==Y) {
                return distance;
            }
            for (int i=0;i<4;i++) {
                int newI = x + forI[i];
                int newJ = y + forJ[i];
                if (newI >=0 && newI < A.size() && newJ >=0 && newJ < A[0].size() && distance +1 < dist[newI][newJ] && A[newI][newJ] != 0) {
                    dist[newI][newJ] = distance +1 ;
                    q.push({distance +1 , {newI,newJ}});
                }
                
            }
        }
        return -1;
    }
};