class Solution {
public:
    int nextPos(vector<int>& nums, int n)
    {
        int len = nums.size();
        return ((n+ nums[n]) % len + len) % len;
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        int len = nums.size();
        
        for(int i=0; i<len; ++i)
        {
            int slow = i;
            int fast = nextPos(nums, i);
            
            while(nums[fast] * nums[i] > 0 && 
                  nums[nextPos(nums, fast)] * nums[i] > 0)
            {
                if(fast == slow)
                {
                    if(slow == nextPos(nums, slow))
                    {
                        break;
                    }
                    
                    return true;
                }
                
                slow = nextPos(nums, slow);
                fast = nextPos(nums, nextPos(nums, fast));
            }
        }
        
        return false;
    }
};