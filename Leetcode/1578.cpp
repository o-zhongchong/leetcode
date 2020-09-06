class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int len = s.size();
        int pre = 0;
        int sum = 0;
        
        for(int i=1; i<len; ++i)
        {
            if(s[i] == s[pre] && cost[i] <= cost[pre])
            {
                sum += cost[i];
            }
            else if(s[i] == s[pre] && cost[i] > cost[pre])
            {
                sum += cost[pre];
                pre = i;
            }
            else
            {
                pre = i;
            }
        }
        
        return sum;
    }
};