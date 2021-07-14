class Solution {
public:
    string customSortString(string order, string str) {
        unordered_map<char,int> m;
        int len1 = order.size();
        int len2 = str.size();
        
        for(int i=0; i<len1; ++i) 
            m[order[i]] = i;
        
        for(int i=0; i<len2; ++i) {
            for(int j=0; j<len2-i-1; ++j) {
                int w1, w2;
                w1 = w2 = INT_MAX;
                if(m.count(str[j])) w1 = m[str[j]];
                if(m.count(str[j+1])) w2 = m[str[j+1]];
                if(w1 > w2) swap(str[j], str[j+1]);
            }
        }
        
        return str;
    }
};
