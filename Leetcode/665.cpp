class Solution {
public:
    int checkNonDesc(vector<int> &nums)
    {
        int len = nums.size();
        
        for(int i=0; i<len-1; ++i)
        {
            if(nums[i] > nums[i+1])
            {
                return i;
            }
        }
        
        return -1;
    }
    
    bool checkPossibility(vector<int>& nums) {
        int pos = checkNonDesc(nums);
        
        if(-1 == pos)
        {
            return true;
        }
        
        int n1 = nums[pos];
        int n2 = nums[pos+1];
        
        nums[pos] = nums[pos+1] = n2;
        
        if(checkNonDesc(nums) == -1)
        {
            return true;
        }
        
        nums[pos] = nums[pos+1] = n1;
        
        if(checkNonDesc(nums) == -1)
        {
            return true;
        }
        
        return false;
    }
};