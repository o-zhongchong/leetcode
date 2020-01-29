class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int target = 0;
        int len = (int)nums.size();
        if( len < 3 )
            return ret;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<len; ++i)
        {
            if( i > 0 && nums[i] == nums[i-1] )
                continue;
            int l=i+1, r=len-1;
            while(l<r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if( sum > target)
                    --r;
                else if( sum < target)
                    ++l;
                else
                {
                    ret.push_back(vector<int> {nums[i],nums[l],nums[r]});
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l-1])
                        ++l;
                    while (l < r && nums[r] == nums[r+1])
                        --r;  
                }
            }
        }
        return ret;
    }
};