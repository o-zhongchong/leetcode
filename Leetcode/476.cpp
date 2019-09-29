class Solution {
public:
    int findComplement(int num) {
        int res = num;
        int weight = 0;

        while( num )
        {
            res ^= (1<<weight);
            num = num >>1;
            ++weight;
        }
        return res;
    }
};