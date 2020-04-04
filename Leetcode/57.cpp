class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, 
        vector<int>&newInterval)
    {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> ret;
        
        sort(intervals.begin(), intervals.end(), Solution::comp);
        
        int len = intervals.size();
        for(int i=0; i<len; ++i)
        {
            if( ret.empty() )
            {
                ret.push_back(intervals[i]);
                continue;
            }

            int last = ret.size() -1;
            int x1 = ret[last][0];
            int y1 = ret[last][1];
            int x2 = intervals[i][0];
            int y2 = intervals[i][1];
            
            if( abs(y1-x1) + abs(y2-x2) >= abs(y2-x1) )
            {
                ret[last][1] = max(y1,y2);
            }
            else
            {
                ret.push_back(intervals[i]);
            }

        }
        
        return ret;
        
    }
    
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
};