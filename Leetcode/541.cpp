class Solution {
public:
    void reverse(string &s, int left, int right) {
        int len = s.size();
        left = max(0, left);
        right = min(len-1, right);
        while(left < right) {
            swap(s[left++], s[right--]);
        }
    }
    string reverseStr(string s, int k) {
        int len = s.size();
        for(int i=0; i<len; i+=2*k) {
            reverse(s, i, i+k-1);
        }
        return s;
    }
};