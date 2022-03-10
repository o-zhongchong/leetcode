class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int dict[26], j = -1;
        int repeat = 0, c = -1;
        memset(dict, 0, sizeof(dict));
        for(auto ch : s) ++dict[ch-'a'];
        string ans = "";
        do {
            c = -1;
            for(int i=25; i>=0; --i) {
                if(dict[i] <= 0) continue;
                if(!ans.empty() && ans.back()-'a' == i) {
                    if(repeat + 1 > repeatLimit) {
                        continue;
                    }
                    repeat += 1;
                } else {
                    repeat = 1;
                }
                c = i; 
                --dict[i];
                break;
            }
            if(c != -1) ans.push_back('a' + c);
        } while(c != -1);
        return ans;
    }
};