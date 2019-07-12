class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        if ( !(left >= 1 && right <= 10000) )
            return ret;

        for (int num = left; num <= right; ++num)
        {
            if (isSelfDividingNum(num))
            {
                ret.push_back(num);
                cout << num << endl;
            }
        }

        return ret;
    }
private:
    int isSelfDividingNum(const int N)
    {
        int check = N;

        while ( check )
        {
            int div = check % 10;
            check /= 10;

            if (div == 0)
                return 0;
            else if (div != 0 && N % div != 0)
                return 0;
            else
                continue;
        }
        return 1;
    }
};