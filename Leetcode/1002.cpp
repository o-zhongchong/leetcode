class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        unsigned int N = A.size();
        vector<string> ret;
        int (*count)[26] = new int[N][26];
        
        for( unsigned int i=0; i<N; ++i )
            for(unsigned int j=0; j<26; ++j)
            {
                count[i][j]=0;
            }
        
        for( unsigned int i=0; i<N; ++i )
            for( auto &ch: A[i] )
            {
                ++count[i][ch-'a'];
            }
        
        for( unsigned int i=0; i<26; ++i)
        {
            int min = -1;
            for( unsigned int j=0; j<N; ++j)
            {
                if( min == -1 )
                    min = count[j][i];
                else
                {
                    if( count[j][i] == 0)
                    {
                        min = 0;
                        break;
                    }
                    
                    if( count[j][i] < min )
                        min = count[j][i];
                }
            }
            
            if( min == 0 || min == -1 )
                continue;
            else
                for( unsigned int k=0; k<min; ++k)
                {
                    string s = "1";
                    s[0]='a'+i;
                    ret.push_back(s);
                }
        }
        
        delete []count;
        return ret;
    }
};