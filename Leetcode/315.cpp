class BIT
{
public:
    BIT(int n):data(n+1, 0){}
    ~BIT(){}
    
    void update(int i, int diff)
    {
        int len = data.size();
        
        while(i < len)
        {
            data[i] += diff;
            i += lowbit(i);
        }
    }
    
    int query(int i)
    {
        int sum = 0;
        
        while(i > 0)
        {
            sum += data[i];
            i -= lowbit(i);
        }
        
        return sum;
    }
    
    static inline int lowbit(int x)
    {
        return x & (-x); 
    }
    
protected:
    vector<int> data;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> sorted(nums.begin(), nums.end());
        unordered_map<int, int> ranks;
        int rank = 0;
        int len = nums.size();
        vector<int> ret(len, 0);
        BIT bit(sorted.size());
        
        for(auto i : sorted)
        {
            ranks[i] = ++rank;
        }
        
        for(int i=len-1; i>=0; --i)
        {
            bit.update(ranks[nums[i]], 1);
            ret[i] = bit.query(ranks[nums[i]] - 1);
        }
        
        return ret;
    }
};