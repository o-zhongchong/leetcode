class Comprator
{
public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        return a[0] > b[0];
    }
};

class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[1] > b[1];
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> engineers(n, vector<int>(2,0));
        priority_queue<vector<int>, vector<vector<int>>, Comprator> pq;
        
        for(int i=0; i<n; ++i)
        {
            engineers[i][0] = speed[i];
            engineers[i][1] = efficiency[i]; 
        }
        
        sort(engineers.begin(), engineers.end(), cmp);
        long long sum = 0;
        long long ret = 0;
        long long M = 1e9+7;
        
        for(int i=0; i<n; ++i)
        {
            while(pq.size() >= k)
            {
                sum -= pq.top()[0];
                pq.pop();
            }
            
            pq.push(engineers[i]);
            sum += engineers[i][0];
            long long perf = sum * engineers[i][1];
            ret = max(ret, perf);
        }
        
        return ret % M;
    }
};