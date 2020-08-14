class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        int len = nums.size();
        
        for(int i = 0; i < len; ++i)
        {
            if(mymap.find(nums[i]) == mymap.end())
            {
                mymap.insert(make_pair(nums[i] ,i));
            }
            else
            {
                int j = mymap[nums[i]];
                
                if(abs(i - j) <= k)
                {
                    return true;
                }
                else
                {
                    mymap[nums[i]] = i;
                }
            }
        }
        
        return false;
    }
};