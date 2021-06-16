class Solution {
public:
    static bool cmp(const pair<int,int> &a, const pair<int,int> &b)
    {
        return a.first > b.first;    
    }
    
    int maxJumps(vector<int>& arr, int d) {
        int len = arr.size();
        vector<pair<int,int>> arr1;
        vector<int> dp(len, 1);
        int ret = 1;
        
        for(int i=0; i<len; ++i)
        {
            arr1.push_back(make_pair(arr[i],i));
        }
        
        sort(arr1.begin(), arr1.end(), cmp);
        
        for(int i=0; i<len; ++i)
        {
            int pos = arr1[i].second;
            
            for(int j=1; j<=d; ++j)
            {
                if(pos+j<len && arr[pos+j]<arr[pos])
                {
                    dp[pos+j] = max(dp[pos+j], dp[pos]+1);
                    ret = max(ret, dp[pos+j]);
                }
                else
                {
                    break;
                }
            }
            
            for(int j=1; j<=d; ++j)
            {
                if(pos-j>=0 && arr[pos-j]<arr[pos])
                {
                    dp[pos-j] = max(dp[pos-j], dp[pos]+1);
                    ret = max(ret, dp[pos-j]);
                }
                else
                {
                    break;
                }
            }
        }
        
        return ret;
    }
};