class Solution {
public:
    int rob(vector<int>& nums) {
        int preRob = 0, preNotRob = 0;
        
        for(auto x : nums)
        {
            int rob = preNotRob + x;
            int notRob = preRob > preNotRob ? preRob : preNotRob;
            
            preRob = rob;
            preNotRob = notRob;
        }
        
        return preRob > preNotRob ? preRob : preNotRob;
    }
};