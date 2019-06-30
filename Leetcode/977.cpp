class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> B;
        int i = 0;
        int len = A.size();
        while( i < len && A.at(i) < 0)
            ++i;
        int j = i - 1;
        
        while( j >= 0 && i < len )
        {
            int num1 = A.at(j)*A.at(j);
            int num2 = A.at(i)*A.at(i);
            if( num1 <= num2)
            {
                B.push_back( num1 );
                --j;
            }
            else
            {
                B.push_back( num2 );
                ++i;
            }
        }
        
        while( j >= 0 )
        {
            B.push_back( A.at(j) * A.at(j) );
            --j;
        }
        
        while( i< A.size() )
        {
            B.push_back( A.at(i)*A.at(i) );
            ++i;  
        }
        
        return B;
    }
};