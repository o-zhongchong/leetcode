class Solution {
public:
    bool divisorGame(int N) {
        initRet();
        return ret[N];
    }
protected:
    vector<bool> ret;
    int initRet()
    {
        if( !ret.empty() )
            return -1;
        
        int N = 1000;
        ret.push_back(false);
        ret.push_back(false);
        
        for(int n=2; n<=N; ++n)
        {
            bool n_ret = false;
            for(int i=1;i<n;++i)
            {
                if( n%i == 0 && ret[n-i] == false)
                    n_ret = true;
            }
            ret.push_back(n_ret);
        }
        return 0;
    }
};