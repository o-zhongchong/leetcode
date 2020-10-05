class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        
        if(len <= 0)
        {
            return 0;
        }
        else if(len == 1)
        {
            return nums[0];
        }
        
        int preRob, preNotRob;
        int ret1, ret2;
        
        preRob = preNotRob = 0;
        for(int i=0; i<len-1; ++i)
        {
            int rob = preNotRob + nums[i];
            int notRob = max(preNotRob, preRob);
            
            preRob = rob;
            preNotRob = notRob;
        }
        
        ret1 = preRob > preNotRob ? preRob : preNotRob;
        
        preRob = preNotRob = 0;
        for(int i=1; i<len; ++i)
        {
            int rob = preNotRob + nums[i];
            int notRob = max(preNotRob, preRob);
            
            preRob = rob;
            preNotRob = notRob;
        }
        
        ret2 = preRob > preNotRob ? preRob : preNotRob;
        
        return ret1 > ret2 ? ret1 : ret2;
    }
};