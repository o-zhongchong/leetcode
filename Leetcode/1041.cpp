class Point {
public:
    Point():x(0),y(0),d(1){}
    ~Point(){}
    int x;
    int y;
    int d;
};

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int step[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        Point pos;
        for(auto c : instructions) {
            switch(c) {
            case 'G':
                pos.x += step[pos.d][0];
                pos.y += step[pos.d][1];
                break;
            case 'L':
                pos.d = (pos.d + 1) % 4;
                break;
            case 'R':
                pos.d = (pos.d + 3) % 4;
                break;
            }
        }
        if((pos.x == 0 && pos.y == 0) || pos.d != 1) {
            return true;
        }
        return false;
    }
};