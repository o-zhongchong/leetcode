class Solution {
public:
    int disjoint_set_init(int N)
    {
        disjoint_set = new int[N + 1];
        for (int i = 1; i <= N; ++i)
            disjoint_set[i] = i;
        return 0;
    }

    int disjoint_set_destroy()
    {
        if ( disjoint_set != nullptr)
            delete []disjoint_set;
        disjoint_set = nullptr;
        return 0;
    }

    int find_set(int x)
    {
        if (x != disjoint_set[x])
            return find_set(disjoint_set[x]);
        return x;
    }

    int merge_set(int a, int b)
    {
        int p1 = find_set(a);
        int p2 = find_set(b);
        disjoint_set[p1] = p2;
        return 0;
    }

    int minimumCost(int N, vector<vector<int>>& conections) {
        int ret = 0, count = 1;

        if (N <= 0)
            return -1;
        else if (N == 1)
            return 0;

        sort(conections.begin(), conections.end(), Solution::comp);
        disjoint_set_init(N);
        for (auto &i : conections)
        {
            int p1 = find_set( i[0] );
            int p2 = find_set( i[1]);
            if (p1 != p2)
            {
                merge_set(i[0], i[1]);
                ++count;
                ret += i[2];
                if (count == N)
                {
                    disjoint_set_destroy();
                    return ret;
                }
            }
        }
        disjoint_set_destroy();
        return -1;
    }
private:
    int *disjoint_set;
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }
};