class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapNums;
        unordered_map<int, int>::iterator search;
        int len = (int)nums.size();
        if(len < 2)
            return {};
        
        for(int i=0;i<len;++i)
        {
            search =  mapNums.find(target-nums[i]);
            if(search == mapNums.end())
                mapNums.insert(pair<int,int>(nums[i],i));
            else
            {
                return {i,search->second};
            }
        }
        return {};
    }
};