class NumArray {
public:
    NumArray(vector<int>& nums) {
        int len = nums.size();
        data.resize(len);
        bit.resize(len+1);
        
        for(int i=0; i<len; ++i)
        {
            update(i, nums[i]);
        }
    }
    
    inline int lowbit(int x)
    {
        return x&(x^(x-1));
    }
    
    void update(int index, int val) {
        int len = bit.size();
        int diff = val - data[index];
        data[index] = val;
        
        for(int i=index+1; i<len; i+=lowbit(i))
        {
            bit[i] += diff;
        }
    }
    
    int sumRange(int left, int right) {
        return getSum(right+1) - getSum(left);
    }
    
    int getSum(int index)
    {
        int ret=0;
        
        for(int i=index; i>0; i-=lowbit(i))
        {
            ret += bit[i];
        }
        
        return ret;
    }
    
protected:
    vector<int> data;
    vector<int> bit;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */