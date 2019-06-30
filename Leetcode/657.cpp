class Solution {
public:
    bool judgeCircle(string moves) {
        int vert, horz;
        vert = horz = 0;
        for( auto ch:moves )
        {
            switch(ch)
            {
                case 'U':
                    ++vert;break;
                case 'D':
                    --vert;break;
                case 'L':
                    ++horz;break;
                case 'R':
                    --horz;break;
            }
        }
        if( vert == 0 && horz == 0 )
            return true;
        else
            return false;
    }
};