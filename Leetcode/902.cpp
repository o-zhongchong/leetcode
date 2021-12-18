class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int cnt = digits.size();
        string num = to_string(n);
        int len = num.size();
        int ret = 0;
        for(int i=1; i<len; ++i) {
            ret += pow(cnt, i);
        }
        for(int i=0; i<len; ++i) {
            bool hasSameNum = false;
            for(auto &d : digits) {
                if(d[0] < num[i]) {
                    ret += pow(cnt, len-1-i);
                } else if(d[0] == num[i]) {
                    hasSameNum = true;
                }
            }
            if(!hasSameNum) return ret;
        }
        return ret+1;
    }
};