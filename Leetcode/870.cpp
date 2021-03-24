class Solution {
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        
        while(left < right)
        {
            int mid = (right - left) / 2 + left;
            
            if(nums[mid] > target)
            {
                right = mid;
            }
            else if(nums[mid] <= target)
            {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int len = A.size();
        sort(A.begin(), A.end());
        vector<int> ret;
        
        for(int i=0; i<len; ++i)
        {
            int idx = search(A, B[i]);
            
            if(idx >= A.size())
            {
                idx = 0;
            }
            
            ret.push_back(A[idx]);
            A.erase(A.begin() + idx);
        }
        
        return ret;
    }
};