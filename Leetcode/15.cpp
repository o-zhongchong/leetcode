class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int len = (int)nums.size();
        for(int i=0; i<len; ++i)
            for(int j=0;j<len;++j)
                for(int k=0;k<len;++k)
                    if(i!=j && i!=k && j!=k && nums[i] + nums[j] + nums[k]==0)
                    {
                        vector<int> vec = {nums[i],nums[j],nums[k]};
                        sort(vec.begin(),vec.end());
                        bool is_exist = false;
                        for( auto node : ret)
                            if(node[0]==vec[0] && node[1]==vec[1] &&                                                 node[2]==vec[2])
                                is_exist=true;
                        if( !is_exist )
                            ret.push_back(vec);
                    }
        return ret;
    }
};