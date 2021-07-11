class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int left = 0;
        int right = data.size();
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(data[mid] < num) {
                left = mid + 1;
            }
            else
                right = mid;
        }
        
        if(left < data.size()) {
            data.insert(data.begin() + left, num);
        }
        else
            data.push_back(num);
    }
    
    double findMedian() {
        int len = data.size();
        if(len & 1) return data[(len-1)/2];
        return ((double)data[len/2] + (double)data[len/2-1])/2.0;
    }
    
protected:
    vector<int> data;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */