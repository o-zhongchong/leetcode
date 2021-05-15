class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> ret(n, vector<char>(m, '.'));
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0, cnt=0; j<n; ++j)
            {
                if(box[i][j] == '#')
                {
                    box[i][j] = '.';
                    ++cnt;
                }
                else if(box[i][j] == '*')
                {
                    for(int k=0; k<cnt; ++k)
                    {
                        box[i][j-k-1] = '#';
                    }
                    
                    cnt = 0;
                    continue;
                }
                
                if(j == n-1)
                {
                    for(int k=0; k<cnt; ++k)
                    {
                        box[i][j-k] = '#';
                    }
                    
                    cnt = 0;
                }
            }
        }
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                ret[j][m-i-1] = box[i][j];
            }
        }
        
        return ret;
    }
};