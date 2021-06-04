class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadlock;
        unordered_set<string> visited;
        queue<string> task;
        int ret = 0;
        task.push("0000");
        
        for(auto &s : deadends)
        {
            deadlock.insert(s);
        }
        
        if(deadlock.count("0000"))
        {
            return -1;
        }
        else if(target == "0000")
        {
            return 0;
        }
        
        while(!task.empty())
        {
            ++ret;
            
            for(int i=task.size(); i>0; --i)
            {
                string t = task.front();
                task.pop();
                
                for(int j=0; j<4; ++j)
                {
                    char c = t[j];
                    string s1 = t.substr(0,j) + to_string(c == '9' ? 0 : c - '0' + 1) + t.substr(j+1);
                    string s2 = t.substr(0,j) + to_string(c == '0' ? 9 : c - '0' - 1) + t.substr(j+1);
                    
                    if(s1 == target || s2 == target)
                    {
                        return ret;    
                    }
                    
                    if(!visited.count(s1) && !deadlock.count(s1))
                    {
                        task.push(s1);
                    }
                    
                    if(!visited.count(s2) && !deadlock.count(s2))
                    {
                        task.push(s2);
                    }
                    
                    visited.insert(s1);
                    visited.insert(s2);
                }
            }
        }
        
        return -1;
    }
};