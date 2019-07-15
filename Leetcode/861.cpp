class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int score;
        vector<vector<int>> B=A;
        score = 0;
        
        if( !(B.size()>=1 && B[0].size() >= 1) )
            return -1;
        
        for(int i=0; i<B.size(); ++i)
        {
            if( B[i][0] == 0 )
                if( flipMatrix(B, i, -1) )
                    return -1;
        }
        score = getScore(B);
        
        for(int j=1; j<B[0].size(); ++j)
        {
            int s1 = getScore(B);
            if( flipMatrix(B, -1, j) )
                return -1;
            int s2 = getScore(B);
            if( s1 > s2 )
            {
                score = s1;
                if( flipMatrix(B,-1,j) )
                    return -1;
            }
            else
                score = s2;
        }
       
        return score;
    }

private:
    int flipMatrix(vector<vector<int>>& A, int row, int col)
    {
        int h, w;
        h = A.size();
        
        if( h <= 0 )
            return -1;
        else
            w = A[0].size();
        
        if( row >=0 && row < h )
        {
            for( auto &i: A[row] )
                i = i ^ 1;
        }
        
        if( col >=0 && col < w )
        {
            for( int i=0; i<h; ++i)
                A[i][col] = A[i][col] ^ 1;
        }
        return 0;
    }
    
    int getScore(vector<vector<int>>& A)
    {
        int ret = 0;
        for( auto i: A)
        {
            int weight = 1;
            for(int j=i.size()-1; j>=0; --j)
            {
                ret += i[j] * weight;
                weight = weight * 2;
            }
        }
        return ret;
    }
};