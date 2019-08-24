class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int dict[26];
        int len = keyboard.size();
        int ret = 0;
        
        for( int i=0; i<len; ++i)
        {
            int index = keyboard[i] - 'a';
            dict[index] = i;
        }
        
        int curr = 0;
        for( char &c : word)
        {
            int dest = dict[c-'a'];
            ret = ret + abs(dest-curr);
            curr = dest;
        }
        return ret;
    }
};