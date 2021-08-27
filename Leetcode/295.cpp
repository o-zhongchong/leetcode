/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class MedianFinder {
public:
    MedianFinder() {}
    void addNum(int num) {
        if(left.size() == right.size()) {
            right.push(num);
            int t = right.top();
            right.pop();
            left.push(t);
            return;
        }
        left.push(num);
        int t = left.top();
        left.pop();
        right.push(t);
    }
    double findMedian() {
        if(left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }
        return left.top();
    }
private:
    priority_queue<int,vector<int>,less<int>> left;
    priority_queue<int,vector<int>,greater<int>> right;
};