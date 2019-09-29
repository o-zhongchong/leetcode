class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[5];
        for(int i=0; i<5; ++i)
            cnt[i]=0;
        
        for( auto &c: text)
        {
            switch(c)
            {
                case 'b':
                    ++cnt[0];break;
                case 'a':
                    ++cnt[1];break;
                case 'l':
                    ++cnt[2];break;
                case 'o':
                    ++cnt[3];break;
                case 'n':
                    ++cnt[4];break;
            }
        }
        cnt[2] /= 2;
        cnt[3] /= 2;
        
        int min = cnt[0];
        for( int i=1; i<5; ++i)
            if(cnt[i] < min)
                min = cnt[i];
        return min;
    }
};