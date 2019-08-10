class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        res[0] = 0;
        
        if( num >= 1 )
            res[1] = 1;
        
        for(int i=1 ; i<=num/2; ++i)
        {
            res[2*i] = res.at(i);
            if( i*2+1 <= num)
                res[i*2+1] = res[i] + 1;
        }
        return res;
    }
};
