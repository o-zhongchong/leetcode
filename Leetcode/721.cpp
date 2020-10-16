class Solution {
public:
    string find(unordered_map<string, string>& ds, string x)
    {
        return x == ds[x] ? x : ds[x] = find(ds, ds[x]);
    }
    
    int merge(unordered_map<string, string>& ds, string x, string y)
    {
        string fx = find(ds, x);
        string fy = find(ds, y);
        
        if(fx != fy)
        {
            ds[fx] = fy;
            return 1;
        }
        
        return 0;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> mymap1;
        unordered_map<string, string> mymap2;
        unordered_map<string, vector<string>> mymap3;
        
        unordered_set<string> myset;
        
        vector<vector<string>> ret;
        int len = accounts.size();
        
        for(int i=0; i<len; ++i)
        {
            int len2 = accounts[i].size();
            string name = accounts[i][0];
            
            if(len2 == 1)
            {
                myset.insert(name);
                continue;
            }
            
            if(len2 > 1)
            {
                mymap1[accounts[i][1]] = name;
                
                if(!mymap2.count(accounts[i][1]))
                {
                    mymap2[accounts[i][1]] = accounts[i][1];
                }
            }
            
            for(int j=2; j<len2; ++j)
            {
                mymap1[accounts[i][j]] = name;
                
                if(!mymap2.count(accounts[i][j]))
                {
                    mymap2[accounts[i][j]] = accounts[i][j];
                }
                
                merge(mymap2, accounts[i][1], accounts[i][j]);
            }
        }
        
        for(auto a : mymap2)
        {
            string f = find(mymap2, a.first);
            
            if(!mymap3.count(f))
            {
                mymap3[f] = vector<string>(1, a.first);
            }
            else
            {
                mymap3[f].push_back(a.first);
            }
        }
        
        for(auto a : mymap3)
        {
            sort(a.second.begin(), a.second.end());
            a.second.insert(a.second.begin(), mymap1[a.first]);
            ret.push_back(a.second);
        }
        
        for(auto a : myset)
        {
            ret.push_back(vector<string>(1, a));
        }
        
        return ret;
    }
};