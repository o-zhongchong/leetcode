/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

class FreqStack {
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int x) {
        ++freq[x];
        data[freq[x]].push_back(x);
        maxFreq = max(maxFreq, freq[x]);
    }
    
    int pop() {
        int ret = data[maxFreq].back();
        data[maxFreq].pop_back();
        --freq[ret];
        
        if(data[maxFreq].empty())
        {
            --maxFreq;
        }
        
        return ret;
    }
    
protected:
    unordered_map<int,int> freq;
    unordered_map<int,vector<int>> data;
    int maxFreq;
};
