class RecentCounter {
public:
    int ping(int t) {
        req.push(t);
        int start = req.front();
        while (start < t - 3000)
        {
            req.pop();
            start = req.front();
        }
        return req.size();
    }
private:
    queue<int> req;
};