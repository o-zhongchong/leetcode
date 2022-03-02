class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int len = data.size();
        for(int i=0; i<len; ++i) {
            int t = getType(data[i]);
            if(t == -1) return false;
            for(int j=1; j<=t; ++j) {
                if(i+j >= len || !isValid(data[i+j])) {
                    return false;
                }
            }
            i += t;
        }
        return true;
    }
private:
    int getType(int &n) {
        if((n & 0x80) == 0x00) return 0;
        if((n & 0xE0) == 0xC0) return 1;
        if((n & 0xF0) == 0xE0) return 2;
        if((n & 0xF8) == 0xF0) return 3;
        return -1;
    }
    bool isValid(int &n) {
        return (n & 0xC0) == 0x80;
    }
};