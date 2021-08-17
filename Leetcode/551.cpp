class Solution {
public:
    bool checkRecord(string s) {
        int len = s.size();
        int cntA, cntL;
        for(int i=0, cntA=0, cntL=0; i<len; ++i) {
            if(s[i] == 'A')    ++cntA;
            if(s[i] == 'L')    ++cntL;
            if(cntA >= 2 || cntL >=3) return false;
            if(s[i] != 'L') cntL=0;
        }
        return true;
    }
};