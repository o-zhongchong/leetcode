class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()) return 0;
        int len = s.size();
        int start = 0, end = len-1;
        int sign = 1;
        while(start < len && s[start] == ' ') ++start;
        while(end >= 0 && (s[end]<'0' || s[end]>'9')) --end;
        if(s[start] == '+') {
            ++start;
        } else if(s[start] == '-') {
            sign = -1;
            ++start;
        }
        if(start > end) return 0;
        int64_t ret = 0;
        for(int i=start; i<=end; ++i) {
            if(s[i] == '.' || s[i] < '0' || s[i] > '9') break;
            ret = ret * 10 + (int64_t)(s[i]-'0');
            if(ret*sign > INT_MAX) return INT_MAX;
            if(ret*sign < INT_MIN) return INT_MIN;
        }
        ret *= sign;
        return ret;
    }
};