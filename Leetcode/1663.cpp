class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        while(n) {
            if((n-1)*26 >= k-1) {
                ans.push_back('a');
                --n; --k;
            } else {
                int c = k - (n-1)*26;
                ans.push_back(c - 1 + 'a');
                if(n - 1 > 0) ans += string(n-1, 'z');
                break;
            }
        }
        return ans;
    }
};
