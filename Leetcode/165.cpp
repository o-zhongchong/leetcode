class Solution {
public:
    vector<int> getVer(const string &version) {
        int len = version.size();
        vector<int> ret;
        for(int i=0,j=0; i<len; ++i) {
            if(version[i] == '.') {
                string t = version.substr(j,i-j);
                if(!t.empty()) {
                    ret.push_back(stoi(t));
                }
                j = i + 1;
                continue;
            }
            if(i == len-1) {
                string t = version.substr(j,len-j);
                if(!t.empty()) {
                    ret.push_back(stoi(t));
                }
                j = i + 1;
                continue;
            }
        }
        return ret;
    }
    int compareVersion(string version1, string version2) {
        vector<int> ver1, ver2;
        ver1 = getVer(version1);
        ver2 = getVer(version2);
        int len = max(ver1.size(), ver2.size());
        for(int i=0; i<len; ++i) {
            int v1, v2;
            v1 = v2 = 0;
            if(i < ver1.size()) v1 = ver1[i];
            if(i < ver2.size()) v2 = ver2[i];
            if(v1 > v2) return 1;
            if(v1 < v2) return -1;
        }
        return 0;
    }
};