class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int sum = 0;
        int lines = 0, last = 0;
        vector<int> ret;
        
        if( widths.size() != 26 )
            return ret;
        
        for( auto &c:S )
        {
            int index =  c - 'a';
            int tmp = sum + widths[index];
            if( tmp == 100 )
            {
                ++lines;
                last = 100;
                sum = 0;
            }
            else if( tmp > 100 )
            {
                ++lines;
                last = widths[index];
                sum = widths[index];
            }
            else
            {
                last = tmp;
                sum = tmp;
            }
        }

        if( last > 0)
            ret.push_back(lines+1);
        else if( last == 100 )
            ret.push_back(lines);
        ret.push_back(last);
        
        return ret;
    }
};