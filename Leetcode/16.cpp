class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = (int)nums.size();
        if( len < 3 )
            return -1;
        int ret = nums[0] + nums[1] + nums[2];
        int min_diff = abs(ret-target);
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<len; ++i)
        {
            if( i > 0 && nums[i] == nums[i-1] )
                continue;
            int l=i+1, r=len-1;
            while(l<r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                int diff = abs(sum-target);

                if(  diff <= min_diff )
                {
                    ret = sum;
                    min_diff = diff;
                }
                
                if( sum > target)
                    --r;
                else if( sum < target)
                    ++l;
                else
                    return ret;
            }
        }
        return ret;
    }
};