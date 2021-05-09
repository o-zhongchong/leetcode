class Comparator
{
public:
    bool operator()(const int &a, const int &b)
    {
        return a < b;
    }
};

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long sum = 0;
        priority_queue<int, vector<int>, Comparator> pq;
        
        for(int &i : target)
        {
            sum += i;
            pq.push(i);
        }
        
        while(!pq.empty() && pq.top() != 1 && sum - pq.top() != 1)
        {
            int t = pq.top();
            pq.pop();
            sum -= t;
            
            if(t < sum || sum == 0 || t % sum == 0)
            {
                return false;
            }
            
            t = t % sum;
            sum += t;
            pq.push(t);
        }
        
        return true;
    }
};