class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, 
        vector<vector<int>>& secondList) {
        int len1 = firstList.size();
        int len2 = secondList.size();
        vector<vector<int>> ret;
        int i=0, j=0;
        while(i<len1 && j<len2) {
            vector<int> t = getIntersection(firstList[i],secondList[j]);
            if(!t.empty()) {
                ret.push_back(t);
            }
            if(firstList[i][1] < secondList[j][1]) {
                ++i;
            } else if(firstList[i][1] > secondList[j][1]) {
                ++j;
            } else {
                ++i;
                ++j;
            }
        }
        return ret;
    }
private:
    vector<int> getIntersection(vector<int> &L1, vector<int> &L2) {
        vector<int> ret;
        int x1=L1[0], y1=L1[1];
        int x2=L2[0], y2=L2[1];
        int x3 = max(x1, x2);
        int y3 = min(y1, y2);
        if(x3 <= y3) {
            ret.push_back(x3);
            ret.push_back(y3);
        }
        return ret;
    }
};