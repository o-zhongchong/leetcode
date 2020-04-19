class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int len = height.size();
        
        if(len < 2)
            return -1;
        
        int i=0, j=len-1;
        while(i<j)
        {
            int area = abs(i-j) * min(height[i],height[j]);
            if(area > ret)
                ret = area;
            height[i]<height[j] ? ++i : --j;
        }
        
        return ret;
    }
};