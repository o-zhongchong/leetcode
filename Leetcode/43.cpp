class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int len3 = len1 + len2;
        int upper = 0;
        string ret(len3, '0');
        for(int i=0; i<len2; ++i) {
            for(int j=0; j<len1; ++j) {
                int t = (int)(num2[len2-1-i] - '0') * (int)(num1[len1-1-j] - '0');
                t += (int)(ret[len3-1-i-j] - '0') + upper;
                ret[len3-1-i-j] = t % 10 + '0';
                upper = t / 10;
            }
            if(upper > 0) {
                ret[len3-1-i-len1] = upper + '0';
                upper = 0;
            }
        }
        while(ret.size() > 1 && ret[0] == '0') {
            ret.erase(ret.begin());
        }
        return ret;
    }
};