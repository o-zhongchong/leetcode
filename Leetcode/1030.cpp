struct Distance
{
    int x;
    int y;
    int dis;
    Distance(int p1,int p2,int p3):x(p1),y(p2),dis(p3){}
};

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<struct Distance> all_dis;
        for(int i=0; i<R; ++i)
        {
            for(int j=0; j<C; ++j)
            {
                int dis = getDis(i,j,r0,c0);
                struct Distance node(i,j,dis);
                all_dis.push_back(node);
            }
        }
        sort(all_dis.begin(), all_dis.end(), Solution::comp);
        vector<vector<int>> ret;
        for( auto &i: all_dis)
        {
            ret.push_back({i.x,i.y});
        }
        return ret;
    }
protected:
    int getDis(int a,int b,int c,int d)
    {
        return abs(a-c) + abs(b-d);
    }
    static bool comp(const struct Distance &a, const struct Distance &b)
    {
        return a.dis < b.dis;
    }
};