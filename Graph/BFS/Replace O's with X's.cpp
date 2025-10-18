// User function Template for C++

class Solution {
  public:
  
    void solve(vector<vector<char>>& mat , vector<vector<bool>> & visited , int i , int j){
        stack<pair<int,int>> st ;
        queue<pair<int,int>> q;
        st.push({ i , j });
        q.push({i , j});
        visited[i][j] = true ;
        
        bool find = 0;
        
        while(!q.empty()){
            pair<int ,int> p = q.front() ;
            int ith = p.first ;
            int jth = p.second ;
            q.pop();
            if (ith == 0 || jth == 0 || ith== mat.size()-1 || jth == mat[0].size()-1 ){
                find = 1;
            }
            
            int forI[] = {-1 , 0 , 1 , 0};
            int forJ[] = {0 , 1 , 0, -1};
            
            for (int i=0;i<4 ;i ++){
                int newI = forI[i] + ith ;
                int newJ = forJ[i] + jth ;
                
                if (newI >= 0 && newJ >= 0 && newI <= mat.size()-1 &&  newJ <= mat[0].size() - 1 && mat[newI][newJ] == 'O' && !visited[newI][newJ]){
                    st.push({newI , newJ});
                    q.push({newI , newJ});
                    
                    visited[newI][newJ] = true ;
                    
                }
            }
        }
        if (!find){
            while(!st.empty()){
                mat[st.top().first][st.top().second] = 'X';
                st.pop();
            }
        }
        return ;
    }
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        vector<vector<bool>> visited(mat.size() , vector<bool> (mat[0].size() , false));
        
        for (int i =0 ; i<mat.size() ; i++){
            for (int j=0;j<mat[0].size() ; j++){
                if (mat[i][j] == 'O' && !visited[i][j]){
                    solve(mat , visited , i , j );
                }
            }
        }
        return mat ; 
    }
};