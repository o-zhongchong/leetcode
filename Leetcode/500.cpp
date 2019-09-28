class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char,int> alphabet = { {'Q',1}, {'W',1}, {'E',1},
            {'R',1}, {'T',1}, {'Y',1}, {'U',1}, {'I',1},
            {'O',1}, {'P',1}, {'A',2}, {'S',2}, {'D',2}, {'F',2},
            {'G',2}, {'H',2}, {'J',2}, {'K',2}, {'L',2},
            {'Z',3}, {'X',3}, {'C',3}, {'V',3}, {'B',3}, {'N',3}, {'M',3} };
        
        vector<string> res;
        
        for( auto &word: words)
        {
            bool is_one_row = true;
            int line = -1;
            for( auto c: word )
            {
                if( c>= 'a' && c <= 'z')
                    c = 'A' + (c - 'a');
                if( c>= 'A' && c<='Z')
                {
                    if( line == -1)
                        line = alphabet[c];
                    else
                    {
                        if( alphabet[c] != line )
                        {
                            is_one_row = false;
                            break;
                        }
                    }
                }
                else
                {
                    is_one_row = false;
                    break;
                }
            }
            if( is_one_row )
                res.push_back(word);
        }
        return res;
    }
};