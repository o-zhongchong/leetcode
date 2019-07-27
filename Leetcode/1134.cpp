class Solution {
public:
    bool isArmstrong(int N) {
        int sum = 0, n = N;
        vector<int> digit;

        while ( n )
        {
            int i = n % 10;
            digit.push_back(i);
            n = n / 10;
        }

        int len = digit.size();
        for (auto &i : digit)
        {
            sum = sum + (int)(pow(i, len));
        }

        if (sum == N)
            return true;

        return false;
    }
};