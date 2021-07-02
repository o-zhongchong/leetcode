class Solution {
public:
    int find(vector<int> &arr, int target)
    {
        int left = 0;
        int right = arr.size();
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(arr[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        
        return left;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int len = arr.size();
        vector<int> ret;
        int pos1 = find(arr, x);
        int pos2 = pos1 - 1;
        
        for(int i=0; i<k; ++i)
        {
            int d1, d2;
            d1 = d2 = INT_MAX;
            
            if(pos2 >= 0)
            {
                d2 = abs(arr[pos2] - x);
            }
            
            if(pos1 < len)
            {
                d1 = abs(arr[pos1] - x);
            }
            
            if(d1 < d2)
            {
                ret.push_back(arr[pos1]);
                ++pos1;
            }
            else
            {
                ret.push_back(arr[pos2]);
                --pos2;
            }
        }

        sort(ret.begin(), ret.end());
        return ret;
    }
};