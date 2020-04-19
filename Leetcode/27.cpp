class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        
        for(int i=0; i<len; )
        {
            if(nums[i] == val)
            {
                cout<<nums[i]<<endl;
                nums.erase(nums.begin() + i);
                --len;
            }
            else
                ++i;
        }
        
        return len;
    }
};