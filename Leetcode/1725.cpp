class Solution {
public:
    int getMaxLen(vector<int>& rectangle)
    {
        return min(rectangle[0], rectangle[1]);
    }
    
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int len = rectangles.size();
        int ret = 0, maxLen = 0;
        vector<int> square(len, 0);
        
        for(int i=0; i<len; ++i)
        {
            square[i] = getMaxLen(rectangles[i]);
            maxLen = max(maxLen, square[i]);
        }
        
        for(int i=0; i<len; ++i)
        {
            if(square[i] == maxLen)
            {
                ++ret;
            }
        }
        
        return ret;
    }
};