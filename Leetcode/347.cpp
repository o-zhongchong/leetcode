class Solution {
public:
    typedef pair<int,int> node;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ret;
        for(auto n: nums) ++m[n];
        auto comp = [](const node &a, const node &b) {
            return a.second > b.second;
        };
        priority_queue<node, vector<node>, decltype(comp)> pq(comp);
        for(auto n: m) {
            pq.push(make_pair(n.first,n.second));
            while(pq.size() > k) pq.pop();
        }
        for(int i=0; i<k; ++i) {
            auto t = pq.top(); pq.pop();
            ret.push_back(t.first);
        }
        return ret;
    }
};