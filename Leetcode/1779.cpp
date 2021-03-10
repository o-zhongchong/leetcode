class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ret = -1;
        int min_dist = 0;
        int len = points.size();
        
        for(int i=0; i<len; ++i)
        {
            vector<int> point = points[i];
            
            if(point[0] == x || point[1] == y)
            {
                int dist = abs(point[0] - x) + abs(point[1] - y);
                
                if(ret == -1 || (ret != -1 && dist < min_dist))
                {
                    ret = i;
                    min_dist = dist;
                }
            }
        }
        
        return ret;
    }
};