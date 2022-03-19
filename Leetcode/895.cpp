/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
class FreqStack {
public:
    FreqStack() {
        maxFreq = 0;
    }
    void push(int val) {
        m[++freq[val]].push_back(val);
        maxFreq = max(maxFreq, freq[val]);
    }
    int pop() {
        
        int ans = m[maxFreq].back();
        m[maxFreq].pop_back(); --freq[ans];
        if(m[maxFreq].empty()) --maxFreq;
        return ans;
    }
private:
    int maxFreq;
    unordered_map<int,int> freq;
    unordered_map<int,vector<int>> m;
};