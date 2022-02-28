class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};
        int len = nums.size();
        vector<string> ret;
        int start, end;
        start = end = nums[0];
        char str[100];
        for(int i=0; i<len; ++i) {
            if(i > 0) {
                if(nums[i] != nums[i-1] + 1) {
                    format(str, sizeof(str), start, end);
                    ret.push_back(string(str));
                    start = end = nums[i];
                } else {
                    end = nums[i];
                }
            }
            if(i == len - 1) {
                format(str, sizeof(str), start, end);
                ret.push_back(string(str));
            }
        }
        return ret;
    }
private:
    void format(char *str, int len, int start, int end) {
        if(start == end) {
            snprintf(str, len, "%d", start);
        } else {
            snprintf(str, len, "%d->%d", start, end);
        }
    }
};