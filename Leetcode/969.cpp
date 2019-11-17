class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ret;
        int len = A.size();
        
        for(int i=len; i>1; --i)
        {
            int index = getMax(0,i-1,A);
            if(index == i-1)
                continue;
            
            if(index != 0)
            {
                pancakeFlip(A,index+1);
                ret.push_back(index+1);
            }
            pancakeFlip(A,i);
            ret.push_back(i);
        }
        
        return ret;
    }
    
    int getMax(int i, int j, vector<int> &A)
    {
        int maxN = A[i];
        int ret = i;
        
        for(int p=i+1; p<=j; ++p)
            if(A[p] > maxN)
            {
                ret = p;
                maxN = A[p];
            }
        
        return ret;
    }
    
    int pancakeFlip(vector<int> &A, int k)
    {
        int mid = k/2;
        for(int i=0; i<mid; ++i)
        {
            swap(A[i],A[k-i-1]);
        }
        return 0;
    }
};