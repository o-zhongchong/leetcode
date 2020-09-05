class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int len = arr.size();
        int left = 0, right = len - 1;
        
        while(left < len - 1 && arr[left+1] >= arr[left])
        {
            ++left;
        }
        
        while(right > 0 && arr[right] >= arr[right-1])
        {
            --right;
        }
        
        if(left >= right)
        {
            return 0;
        }
         
        int leftcheck = 0, rightcheck = 0;
        int i = left;
        
        while( i >=0 && arr[i] > arr[right])
        {
            --i;
        }
        
        leftcheck = right - i - 1;
        i = right;
        
        while( i < len && arr[i] < arr[left])
        {
            ++i;
        }
        
        rightcheck = i - left - 1;
        
        return min(leftcheck, rightcheck);
    }
};