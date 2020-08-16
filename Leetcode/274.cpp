class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int ret = 0;
        qsort(citations, 0, len-1);
        
        for(int i = 0; i < len; ++i)
        {
            if(citations[i] >= i + 1)
            {
                ret = i + 1;
            }
            else
            {
                break;
            }
        }
        
        return ret;
    }
    
    int qsort(vector<int>& array, int start, int end)
    {
        int len = array.size();
        
        if(start < 0 || start >= len || end < 0 || end >= len)
            return -1;
        
        int base = array[start];
        int i = start;
        int j = end;
        
        while(i < j)
        {
            while(i < j && array[j] <= base)
            {
                --j;
            }
            
            if(i < j && array[j] > base)
            {
                array[i] = array[j];
                ++i;
            }
            
            while(i < j && array[i] >= base)
            {
                ++i;
            }
            
            if(i < j && array[i] < base)
            {
                array[j] = array[i];
                --j;
            }
        }
        
        if(i == j)
        {
            array[i] = base;
            qsort(array, start, i - 1);
            qsort(array, i + 1, end);
        }
        
        return 0;
    }
};