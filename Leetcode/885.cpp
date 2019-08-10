class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int step[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, {-1,0} };
        vector<vector<int>> ret;
        ret.push_back({r0,c0});
        int direction = 0, end_cnt = 1;

        for (int i = 0; end_cnt < R*C; ++i)
        {
            int cnt = i / 2 + 1;
            while (cnt--)
            {
                r0 += step[direction][0];
                c0 += step[direction][1];
                if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C)
                {
                    ret.push_back({ r0, c0 });
                    ++end_cnt;
                }
            }
            direction = (direction + 1) % 4;
        }

        return ret;
    }
};