class Comparator
{
public:
    bool operator()(vector<int> &t1, vector<int> &t2)
    {
        if(t1[1] < t2[1] || (t1[1] == t2[1] && t1[2] < t2[2]))
        {
            return false;
        }
        
        return true;
    }
};

class Solution {
public:
    static bool comp(vector<int> &t1, vector<int> &t2)
    {
        return t1[0] < t2[0];
    }
    
    vector<int> getOrder(vector<vector<int>>& tasks)
    {
        int len = tasks.size();
        priority_queue<vector<int>, vector<vector<int>>, Comparator> q;
        vector<int> ret;
        
        for(int i=0; i<len; ++i)
        {
            tasks[i].push_back(i);
        }
        
        sort(tasks.begin(), tasks.end(), comp);
        int timestamp = 0;
        
        for(int i=0; i<len; )
        {
            if(tasks[i][0] <= timestamp)
            {
                q.push(tasks[i]);
                ++i;
            }
            else if(tasks[i][0] > timestamp)
            {
                if(q.empty())
                {
                    timestamp = tasks[i][0];
                }
                else
                {
                    vector<int> t = q.top();
                    q.pop();
                    ret.push_back(t[2]);
                    timestamp += t[1];
                }
            }
        }
        
        while(!q.empty())
        {
            vector<int> t = q.top();
            q.pop();
            ret.push_back(t[2]);
        }
        
        return ret;
    }
};