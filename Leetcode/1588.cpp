class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int step = 1;
        int len = arr.size();
        int ret = 0;
        
        while(step <= len)
        {
            for(int i=0; i<len; ++i)
            {
                for(int j=i; j<i+step && i+step<=len; ++j)
                {
                    ret += arr[j];
                }
            }
            
            step += 2;
        }
        
        return ret;
    }
};