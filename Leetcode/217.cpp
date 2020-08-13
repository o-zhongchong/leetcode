class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> myset;
        
        for(auto n : nums)
        {
            if(myset.find(n) == myset.end())
            {
                myset.insert(n);
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
};