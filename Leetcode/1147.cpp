class Solution {
public:
    int longestDecomposition(string text) {
        int len = text.size();
        int start = 0, mid = len / 2;
        int ret = 0;

        for (int i = 0; i < mid; ++i)
        {
            int sub_len = i - start + 1;
            string s1 = text.substr(start, sub_len);
            string s2 = text.substr(len - 1 - i, sub_len);

            if (s1 == s2)
            {
                ret += 2;
                start = i + 1;
            }
        }

        if (len & 1 || start != mid )
            ++ret;

        return ret;
    }
};