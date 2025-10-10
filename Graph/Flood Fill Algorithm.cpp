class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size() , vector<bool> (image[0].size() , false));

        queue<pair<int,int>> q;
        q.push({sr,sc});
        int ini = image[sr][sc];
        visited[sr][sc] = true;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();

            if (image[p.first][p.second] == ini){
                image[p.first][p.second] = color;
            }

            int forI[] = {-1,0,1,0};
            int forJ[] = {0 , 1,0,-1};

            for (int k=0;k<4;k++){
                int i = p.first + forI[k];
                int j = p.second + forJ[k];
                if (i >=0 && i< image.size() && j>=0 && j < image[0].size() && !visited[i][j] && image[i][j] == ini){
                    q.push({i,j});
                    visited[i][j] = true;
                    image[i][j] = color;
                }
            }
        }    
        return image ;
    }
};