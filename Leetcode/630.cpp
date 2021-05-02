class Comparator
{
public:
    bool operator()(int &a, int &b)
    {
        return a < b;
    }
};

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        int len = courses.size();
        priority_queue<int, vector<int>, Comparator> pq;
        sort(courses.begin(), courses.end(), cmp);
        int total = 0;
        
        for(int i=0; i<len; ++i)
        {
            total += courses[i][0];
            pq.push(courses[i][0]);
            
            if(total > courses[i][1])
            {
                total -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};