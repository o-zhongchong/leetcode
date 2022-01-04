class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n) return 1;
        uint32_t mask = UINT_MAX;
        while(mask & n) {
            mask <<= 1;
        }
        return ~mask ^ n;
    }
};