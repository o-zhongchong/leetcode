class Solution {
public:
    vector<int> partitionLabels(string s) {
        int pos[26][2];
        int len = s.size();
        for(int i=0; i<26; ++i) {
            pos[i][0] = pos[i][1] = -1;
        }
        for(int i=0; i<len; ++i) {
            int c = s[i] - 'a';
            if(pos[c][0] == -1) {
                pos[c][0] = i;
            } else {
                pos[c][1] = i;
            }
        }
        int start = 0, end = 0;
        vector<int> ans;
        for(int i=0; i<len; ++i) {
            int c = s[i] - 'a';
            end = max(end, pos[c][1]);
            if(i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
                end = start;
            }
        }
        return ans;
    }
};