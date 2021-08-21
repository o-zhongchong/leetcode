class Solution {
public:
    void fill(vector<char> &chars, int &start, const string &str) {
        int len = str.size();
        for(int i=0; i<len; ++i) {
            chars[start+i] = str[i];
        }
        start += str.size();
    }
    int compress(vector<char>& chars) {
        int len = chars.size();
        int ret = 0;
        char c = '\0';
        for(int i=0,j=0,cnt=0; i<len; ++i) {
            if(cnt == 0 || chars[i] == c) {
                ++cnt;
                c = chars[i];
            }
            if(cnt != 0 && chars[i] != c) {
                chars[j++]=c;
                if(cnt > 1) {
                    string n = to_string(cnt);
                    fill(chars, j, n);
                }
                cnt = 1;
                c = chars[i];
            }
            if(cnt != 0 && i == len-1) {
                chars[j++]=c;
                if(cnt > 1) {
                    string n = to_string(cnt);
                    fill(chars, j, n);
                }
                cnt = 0;
                ret = j;
            }
        }
        return ret;
    }
};