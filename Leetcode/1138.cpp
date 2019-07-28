struct Position_t
{
    int x, y;
    Position_t(int a, int b) :x(a), y(b){}
};

class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<string> board = { "abcde", "fghij", "klmno", "pqrst", "uvwxy", "z" };
        unordered_map<char, Position_t> board_map;

        for (unsigned int i = 0; i < board.size(); ++i)
        {
            for (unsigned int j = 0; j < board[i].size(); ++j)
            {
                Position_t pos(i, j);
                board_map.insert( make_pair(board[i][j], pos) );
            }
        }

        Position_t curr_pos(0, 0);
        int col, row;
        string ret;

        for (auto &ch : target)
        {
            auto search = board_map.find(ch);
            if (search == board_map.end())
                return string("");
            Position_t target_pos = search->second;

            cout << curr_pos.x << " " << curr_pos.y << endl;
            cout << target_pos.x << " " << target_pos.y << endl;

            row = target_pos.x - curr_pos.x;
            col =  target_pos.y - curr_pos.y;

            string s1, s2;
            if (row > 0)
                s1.insert(0, abs(row), 'D');
            else if (row < 0)
                s1.insert(0, abs(row), 'U');

            if (col > 0)
                s2.insert(0, abs(col), 'R');
            else if (col < 0)
                s2.insert(0, abs(col), 'L');

            if (target_pos.x == 5 && target_pos.y == 0)
            {
                ret = ret + s2 + s1;
            }
            else
                ret = ret + s1 + s2;

            ret += string("!");
            curr_pos= target_pos ;
        }
        return ret;
    }
};