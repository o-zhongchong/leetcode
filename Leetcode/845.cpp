class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int len = seats.size();
        int start=0, end=len-1;
        int dist=0;
        while(seats[0]==0 && seats[start]==0) ++start;
        if(start != 0 && start > dist) {
            dist = start;
        }
        while(seats[len-1]==0 && seats[end]==0) --end;
        if(end != len-1 && len-1-end > dist) {
            dist = len-1-end;
        }
        for(int i=start+1,j=start; i<=end; ++i) {
            if(seats[i]==1) {
                if(i-j>1 && (i-j)/2 > dist) {
                    dist = (i-j)/2;
                }
                j = i;
            }
        }
        return dist;
    }
};