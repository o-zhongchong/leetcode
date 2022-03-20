class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;
        helper(tops, bottoms, true, true, 0, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }
private:
    void helper(vector<int>& t, vector<int>& b, bool flag1, bool flag2,
                int idx, int cnt, int &ret) 
    {
        if(t.empty() || b.empty() || t.size() != b.size()) return;
        int len = t.size();
        if(idx >= len) {
            ret = min(ret, cnt);
            return;
        }
        if(!flag1 && !flag2) return;
        bool f1, f2;
        if(idx == 0) {
            f1 = flag1;
            f2 = flag2;
        } else {
            f1 = flag1 && t[idx-1]==t[idx];
            f2 = flag2 && b[idx-1]==b[idx];
        }
        if(f1 || f2) {
            helper(t, b, f1, f2, idx+1, cnt, ret);
        }
        if(t[idx] == b[idx]) return;
        swap(t[idx], b[idx]);
        if(idx == 0) {
            f1 = flag1;
            f2 = flag2;
        } else {
            f1 = flag1 && t[idx-1]==t[idx];
            f2 = flag2 && b[idx-1]==b[idx];
        }
        if(f1 || f2) {
            helper(t, b, f1, f2, idx+1, cnt+1, ret);
        }
        swap(t[idx], b[idx]);
    }
};