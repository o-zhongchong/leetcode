class Solution {
public:
    string originalDigits(string s) {
        vector<int> char_cnt(26, 0);
        vector<int> num_cnt(10, 0);
        string ret;
        
        for(auto c : s)
        {
            ++char_cnt[c - 'a'];
        }
        
        num_cnt[0] = char_cnt['z' - 'a'];
        num_cnt[2] = char_cnt['w' - 'a'];
        num_cnt[4] = char_cnt['u' - 'a'];
        num_cnt[6] = char_cnt['x' - 'a'];
        num_cnt[8] = char_cnt['g' - 'a'];
        
        num_cnt[1] = char_cnt['o' - 'a'] - num_cnt[0] - num_cnt[2] - num_cnt[4];
        num_cnt[3] = char_cnt['t' - 'a'] - num_cnt[2] - num_cnt[8];
        num_cnt[5] = char_cnt['f' - 'a'] - num_cnt[4];
        num_cnt[7] = char_cnt['s' - 'a'] - num_cnt[6];
        
        num_cnt[9] = char_cnt['i' - 'a'] - num_cnt[5] - num_cnt[6] - num_cnt[8];
        
        for(int i=0; i<10; ++i)
        {
            ret += string(num_cnt[i], '0' + i);
        }
        
        return ret;
    }
};