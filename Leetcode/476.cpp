class Solution {
public:
    int findComplement(int num) {
        uint32_t mask = INT_MAX;
        while(mask & num) mask <<= 1;
        return ~mask & ~num;
    }
};