class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int len = adjacentPairs.size();
        unordered_map<int, vector<int>> neighbour;
        vector<int> ret;
        
        for(int i=0; i<len; ++i)
        {
            int a = adjacentPairs[i][0];
            int b = adjacentPairs[i][1];
            
            neighbour[a].push_back(b);
            neighbour[b].push_back(a);
        }
        
        for(auto &i : neighbour)
        {
            if(i.second.size() == 1)
            {
                ret.push_back(i.first);
                ret.push_back(i.second[0]);
                break;
            }
        }
        
        int total = ret.size();
        
        while(total - 1 < len)
        {
            int pre  = ret[total - 2];
            int tail = ret[total - 1];
            
            for(auto &i : neighbour[tail])
            {
                if(i != pre)
                {
                    ret.push_back(i);
                    ++total;
                    break;
                }
            }
        }
        
        return ret;
    }
};