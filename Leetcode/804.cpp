class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        char* morseCode[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> strSet;
        for(size_t i = 0; i < words.size(); ++i)
        {
            string str = words.at(i);
            string str_c;
            for(size_t j = 0; j < str.length(); ++j)
            {
                char c = str.at(j);
                int pos = c - 'a';
                str_c += string(morseCode[pos]);
            }
            auto search = strSet.find(str_c);
            if( search == strSet.end() )
                strSet.insert(str_c);
        }
        return strSet.size();
    }
};