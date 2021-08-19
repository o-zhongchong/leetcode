class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        set<char> vow = {'a','e','i','o','u','A','E','I','O','U'};
        while(left < right) {
            while(left < right && !vow.count(s[left])) ++left;
            while(left < right && !vow.count(s[right])) --right;
            if(left < right) swap(s[left++], s[right--]);
        }
        return s;
    }
};