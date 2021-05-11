class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        vector<int> prefix_sum(len+1, 0);
        int ret = 0;
        
        for(int i=1; i<=len; ++i)
        {
            prefix_sum[i] = prefix_sum[i-1] + cardPoints[i-1];
        }
        
        for(int i=0; i<=k; ++i)
        {
            int score = prefix_sum[i] + prefix_sum[len] - 
                        prefix_sum[len - (k - i)];
            ret = max(ret, score);
        }
        
        return ret;
    }
};