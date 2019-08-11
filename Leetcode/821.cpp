class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> pos;
        vector<int> ret;
        
        for(int i=0; i < S.size(); ++i)
            if(S[i] == C)
                pos.push_back(i);
        
        if( pos.size() == 0)
            return ret;
        
        for(int i=0; i < S.size(); ++i)
        {
            int min = abs(i-pos[0]);
            for(int j=1; j<pos.size(); ++j)
            {
                int dis = abs(i-pos[j]);
                if(dis < min)
                    min = dis;
            }
            ret.push_back(min);
        }
        return ret;
    }
};
