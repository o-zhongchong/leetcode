class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> product;
        int len = nums.size();
        int ret = 0;
        
        for(int i=0; i<len; ++i)
        {
            for(int j=i+1; j<len; ++j)
            {
                ++product[nums[i] * nums[j]];
            }
        }
        
        for(auto &i : product)
        {
            if(i.second >= 2)
            {
                ret += i.second * (i.second - 1) / 2; 
            }
        }
        
        return 8 * ret;
    }
};