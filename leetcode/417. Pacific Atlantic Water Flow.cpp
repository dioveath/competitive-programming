// 417. Pacific Atlantic Water Flow


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        vector<vector<pair<bool, pair<bool, bool>>>> 
            dp(heights.size(), vector<pair<bool, pair<bool, bool>>>(heights[0].size()));
        
        int dir_x[4] = {1, -1, 0, 0};
        int dir_y[4] = {0, 0, 1, -1};

        for(int i = 0; i < dp.size(); i++){
            for(int j = 0; j < dp[0].size(); j++){
                if(dp[i][j].first) continue;
                queue<pair<int, int>> q({{i,j}});

                dp[i][j].first = true;
                
                while(!q.empty()){
                    int sz = q.size();
                    while(sz--){
                        pair<int, int> pos = q.front();
                        q.pop();
                        
                        for(int k = 0; k < 4; k++){
                            int dy = pos.first + dir_y[k];
                            int dx = pos.second + dir_x[k];

                            if(dx < 0 || dy < 0){
                                dp[pos.first][pos.second].second.first = true;
                                continue;
                            }
                            if(dx >= heights[0].size() || dy >= heights.size()) { 
			      dp[pos.first][pos.second].second.second = true;
                                continue; 
                            }

                            if(heights[pos.first][pos.second] < heights[dy][dx]) continue;

			    if(dp[dx][dy].first) {
			      if(dp[dx][dy].second.first)
				dp[pos.first][pos.second].second.first = true;
			      if(dp[dx][dy].second.second)
				dp[pos.first][pos.second].second.second = true;
			      continue;
			    }

                            q.push({dy, dx});
                        }
                    }
                }
                
                if(dp[i][j].second.first && dp[i][j].second.second) res.push_back({i, j});
            }
        }
        return res;
    }
    
    // bool can_visit()
};
