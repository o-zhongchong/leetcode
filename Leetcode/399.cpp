class Solution {
public:
    typedef pair<string, double> Node;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries) 
    {
        int len = equations.size();
        unordered_map<string, Node> m;
        for(int i=0; i<len; ++i) {
            string s1 = equations[i][0];
            string s2 = equations[i][1];
            if(!m.count(s1)) m[s1] = make_pair(s1, 1.0);
            if(!m.count(s2)) m[s2] = make_pair(s2, 1.0);
            Node n1 = find(m, s1);
            Node n2 = find(m, s2);
            if(n1.first != n2.first) {
                m[n1.first] = make_pair(n2.first, values[i] * n2.second / n1.second);
            }
        }
        vector<double> ans;
        for(auto query : queries) {
            Node n1 = find(m, query[0]);
            Node n2 = find(m, query[1]);
            if(n1.second < 0 || n2.second < 0 || n1.first != n2.first) {
                ans.push_back(-1.0);
            } else {
                ans.push_back(n1.second / n2.second);
            }
        }
        return ans;
    }
private:
    Node find(unordered_map<string, Node> &m, string &s) 
    {
        if(!m.count(s)) return make_pair(s, -1.0);
        if(s != m[s].first) {
            Node n = find(m, m[s].first);
            return make_pair(n.first, m[s].second * n.second);
        }
        return m[s];
    }
};