class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> color[3];
        
        int len = colors.size();
        for(int i=0; i<len; ++i)
        {
            int c = colors[i] - 1;
            color[c].push_back(i);
        }
        
        vector<int> res;
        for( auto &query:queries )
        {
            int target = query[0];
            int c = query[1] - 1;
            
            if( c >= 0 && c < 3 )
            {
                if(color[c].empty())
                {
                    res.push_back(-1);
                    continue;
                }
                
                int lower = 0;
                int upper = color[c].size() - 1;
                int mid = lower + (upper - lower)/2;
                int distance = -1;
               
                while( mid != lower )
                {
                    if( color[c][mid] == target)
                    {
                        distance = 0;
                        break;
                    }
                    
                    if(color[c][mid] > target )
                    {
                        upper = mid;
                    }
                    else if( color[c][mid] < target )
                    {
                        lower = mid;
                    }
                    mid = lower + (upper - lower)/2;
                }
                
                if( distance != -1)
                    res.push_back(distance);
                else
                {
                    int dis1 = abs(color[c][upper]-target);
                    int dis2 = abs(color[c][lower]-target);
                    if( dis1 < dis2)
                        res.push_back(dis1);
                    else
                        res.push_back(dis2);
                }
            }
            else
                res.push_back(-1);
        }
        return res;
    }
};