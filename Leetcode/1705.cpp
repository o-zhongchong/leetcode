class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int len = apples.size();
        map<int,int> minheap;
        int ret = 0, i = 0;
        
        for(i=0; i<len; ++i)
        {
            if(apples[i] != 0 )
            {
                if(minheap.find(i + days[i]) == minheap.end())
                {
                    minheap[i + days[i]] = apples[i];
                }
                else
                {
                    minheap[i + days[i]] += apples[i];
                }
            }
            
            while(!minheap.empty())
            {
                while(!minheap.empty() && (minheap.begin()->first <= i ||
                                         minheap.begin()->second == 0))
                {
                    minheap.erase(minheap.begin());
                }
                
                if(!minheap.empty())
                {
                    --minheap.begin()->second;
                    ++ret;
                    break;
                }
            }
        }
        
        while(!minheap.empty())
        {
            while(!minheap.empty() && (minheap.begin()->first <= i ||
                                     minheap.begin()->second == 0))
            {
                minheap.erase(minheap.begin());
            }
            
            if(!minheap.empty())
            {
                --minheap.begin()->second;
                ++ret;
            }
            
            ++i;
        }
        
        return ret;
    }
};