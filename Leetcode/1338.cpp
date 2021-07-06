class Solution {
public:
    static bool cmp(const pair<int,int> &a, const pair<int,int> &b)
    {
        return a.first > b.first;
    }
    
    int minSetSize(vector<int>& arr) {
        int len = arr.size();
        unordered_map<int,int> cnt;
        vector<pair<int,int>> freq;
        
        for(int i=0; i<len; ++i){
            ++cnt[arr[i]];
        }
        
        for(auto i : cnt){
            freq.push_back(make_pair(i.second, i.first));
        }
        
        sort(freq.begin(), freq.end(), cmp);
        int ret = 0;
        int len2 = freq.size();
        
        for(int i=0, j=0; i<len2; ++i)
        {
            j += freq[i].first;
            ++ret;
            
            if(j >= len/2) break;
        }
        
        return ret;
    }
};