class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int i, int target)
    {
        int p = 0;
        int q = matrix[i].size();
        
        while(p < q)
        {
            int mid = p + (q - p) / 2;

            if(matrix[i][mid] > target)
            {
                q = mid;
            }
            else if(matrix[i][mid] < target)
            {
                p = mid + 1;
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        
        if(matrix.empty() || matrix[0].empty())
        {
            return false;
        }
        
        int i = 0, j = m;
        
        while(i < j)
        {
            int mid = i + (j - i) / 2;
            
            if(target == matrix[mid][0])
            {
                return true;
            }
            else if(target < matrix[mid][0])
            {
                j = mid;
            }
            else if(target > matrix[mid][0])
            {
                i = mid + 1;
            }
        }
        
        if(i > 0)
        {
            --i;
        }
        
        if(searchMatrix(matrix, i, target))
        {
            return true;
        }
        
        return false;
    }
};