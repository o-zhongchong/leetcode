class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ret, str_vec;
        str_split(text, " ", str_vec);

        for (unsigned int i = 0; i < str_vec.size() - 2; ++i)
        {
            if (str_vec[i] == first && str_vec[i + 1] == second)
                ret.push_back(str_vec[i + 2]);
        }

        return ret;
    }
private:
    int str_split(string str, string split_str, vector<string> &str_vec)
    {
        int start = 0, position = 0;
        int split_str_len = split_str.size();

        position = str.find(split_str, start);
        while ( position != string::npos)
        {
            string sub_str = str.substr(start, position - start);
            str_vec.push_back(sub_str);
            start = position + split_str_len;
            position = str.find(split_str, start);
        }
        if (start < str.size())
        {
            string sub_str = str.substr(start);
            str_vec.push_back(sub_str);
        }
        return 0;
    }
};