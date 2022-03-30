class Solution {
public:
    int countCollisions(string directions) {
        int len = directions.size();
        int L=0, R=len-1, S=0;
        while(L <= R && directions[L] == 'L') ++L;
        while(L <= R && directions[R] == 'R') --R;
        for(int i=0; i<len; ++i) if(directions[i]=='S') ++S;
        return R>L? R-L+1-S : 0;
    }
};