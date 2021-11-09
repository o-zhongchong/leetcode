class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> ret;
        unordered_map<int,int> maskMap;
        for(auto &word : words) {
            int m = 0;
            for(auto c : word) {
                m |= 1 << (c - 'a');
            }
            ++maskMap[m];
        }
        for(auto &str : puzzles) {
            int m = 0;
            for(auto c : str) {
                m |= 1 << (c - 'a');
            }
            int sub = m, cnt = 0, first = (1 << (str[0] - 'a'));
            while(sub) {
                if((sub & first) && maskMap.count(sub)) {
                    cnt += maskMap[sub];
                }
                sub = (sub - 1) & m;
            }
            ret.push_back(cnt);
        }
        return ret;
    }
};