class Node
{
public:
    string str;
    double val;
    Node(string s="", double v=1.0):str(s),val(v){};
};

class Solution {
public:
    unordered_map<string, Node> ds;
    
    void init(string s)
    {
        if(!ds.count(s))
        {
            ds[s] = Node(s);
        }
    }
    
    Node find(string x)
    {
        if(x == ds[x].str)
        {
            return ds[x];
        }
        
        Node n(x, 1.0);
        Node m = find(ds[x].str);
        n.str = m.str;
        n.val = m.val * ds[x].val;
        
        return ds[x] = n;
    }
    
    int merge(string x, string y, double v)
    {
        Node fx = find(x);
        Node fy = find(y);
        
        if(fx.str != fy.str)
        {
            ds[fx.str].str = fy.str;
            ds[fx.str].val = fy.val * v / fx.val;
            
            return 1;
        }
        
        return 0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int len = equations.size();
        
        for(int i=0; i<len; ++i)
        {
            string x = equations[i][0];
            string y = equations[i][1];
            double val = values[i];
            
            init(x);
            init(y);
            merge(x, y, val);
        }
        
        vector<double> ret;
        
        for(auto q : queries)
        {
            if(!ds.count(q[0]) || !ds.count(q[1]))
            {
                ret.push_back(-1.0);
                continue;
            }
            
            Node fx = find(q[0]);
            Node fy = find(q[1]);
            
            if(fx.str == fy.str)
            {
                ret.push_back(fx.val/fy.val);
            }
            else
            {
                ret.push_back(-1.0);
            }
        }
        
        return ret;
    }
};