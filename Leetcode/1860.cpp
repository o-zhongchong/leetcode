class Solution {
public:
    int allocate(int &m1, int &m2, int t)
    {
        if( (m1 > m2 && m1 >= t) || (m1 == m2 && m1 >= t) )
        {
            m1 -= t;
            return 0;
        }
        else if(m1 < m2 && m2 >= t)
        {
            m2 -= t;
            return 0;
        }
        
        return -1;
    }
    
    vector<int> memLeak(int memory1, int memory2) {
        int t = 1;
        
        while(allocate(memory1, memory2, t) == 0)
        {
            ++t;
            continue;
        }
        
        return {t, memory1, memory2};
    }
};