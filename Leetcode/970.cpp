class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int i = 0;
        int j = 0;
        int sum = 0;
        set<int> myset;
        vector<int> ret;
        
        for(int i=1; i<bound; i*=x)
        {
            for(int j=1; i + j <= bound; j*=y)
            {
                myset.insert(i + j);
                
                if(1 == y)
                {
                    break;
                }
            }
            
            if(1 == x)
            {
                break;
            }
        }
        
        for(auto n : myset)
        {
            ret.push_back(n);
        }
        
        return ret;
    }
};