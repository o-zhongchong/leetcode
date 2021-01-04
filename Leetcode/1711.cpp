class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int len = deliciousness.size();
        
        if(len < 2)
        {
            return 0;
        }
        
        unordered_map<int, int> food;
        long long cnt = 0, sum = INT_MIN;
        
        for(int i=0; i<len; ++i)
        {
            if(deliciousness[i] > sum)
            {
                sum = deliciousness[i];
            }
            
            if(food.find(deliciousness[i]) == food.end())
            {
                food[deliciousness[i]] = 1;
            }
            else
            {
                ++food[deliciousness[i]];
            }
        }
        
        sum = pow(2, (int)(log(2*sum)/log(2)));
        
        while(sum > 0)
        {
            for(auto i : food)
            {
                int x = i.first;
                int y = sum - x;
                
                if(food.find(y) != food.end())
                {
                    if(x == y && food[x] > 1)
                    {
                        cnt += (long long)food[x] * (long long)(food[x] - 1) / 2;
                    }
                    else if(x != y && x < y)
                    {
                        cnt += food[x] * food[y];
                    }
                }
            }
            
            sum >>= 1;
        }
        
        return cnt  % (int)(1e9 + 7);
    }
};