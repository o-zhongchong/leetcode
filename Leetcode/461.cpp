class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0;
        while( x | y)
        {
            if( (x&1) ^ (y&1) )
                ++dist;
            x = x >> 1;
            y = y >> 1;
        }
        return dist;
    }
};