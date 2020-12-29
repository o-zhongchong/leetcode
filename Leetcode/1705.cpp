class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int len = apples.size();
        map<int,int> mymap;
        int ret = 0, i = 0;
        
        for(i=0; i<len; ++i)
        {
            if(apples[i] != 0 )
            {
                if(mymap.find(i + days[i]) == mymap.end())
                {
                    mymap[i + days[i]] = apples[i];
                }
                else
                {
                    mymap[i + days[i]] += apples[i];
                }
            }
            
            while(!mymap.empty())
            {
                while(!mymap.empty() && (mymap.begin()->first <= i ||
                                         mymap.begin()->second == 0))
                {
                    mymap.erase(mymap.begin());
                }
                
                if(!mymap.empty())
                {
                    --mymap.begin()->second;
                    ++ret;
                    break;
                }
            }
        }
        
        while(!mymap.empty())
        {
            while(!mymap.empty() && (mymap.begin()->first <= i ||
                                     mymap.begin()->second == 0))
            {
                mymap.erase(mymap.begin());
            }
            
            if(!mymap.empty())
            {
                --mymap.begin()->second;
                ++ret;
            }
            
            ++i;
        }
        
        return ret;
    }
};