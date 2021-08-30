/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
class Solution {
public:
    Solution(vector<int>& w) {
        int pre = 0;
        for(auto i : w) {
            data.push_back(i + pre);
            pre += i;
        }
    }
    int pickIndex() {
        if(data.empty()) return -1;
        int r = rand()%data.back();
        return find(r);
    }
    int find(int target) {
        int left = 0, right = data.size()-1;
        while(left < right) {
            int mid = left + (right - left)/2;
            if(data[mid] <= target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
private:
    vector<int> data;
};