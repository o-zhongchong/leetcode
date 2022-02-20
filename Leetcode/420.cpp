class Solution {
public:
    string removeKdigits(string num, int k) {
        string ret = "";
        int len = num.size();
        if(k >= len) return "0";
        for(int i=0, j=k; i<len; ++i) {
            char c = num[i];
            while(j && ret.size() && ret.back() > c) {
                ret.pop_back();
                --j;
            }
            ret.push_back(c);
        }
        ret.resize(len - k);
        while(ret.size() && ret[0] == '0')
            ret.erase(ret.begin());
        return ret.size() ? ret : "0";
    }
};