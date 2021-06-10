class MyCalendar {
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        pair<int,int> it(start,end);
        int pos = find(it);
        int len = intervals.size();
        
        if(pos >= 0 && pos < len && isCross(intervals[pos], it))
        {
            return false;
        }
        
        if(pos+1 >= 0 && pos+1 < len && isCross(intervals[pos+1], it))
        {
            return false;
        }
        
        if(pos + 1 >=0 && pos + 1 < len)
        {
            intervals.insert(intervals.begin()+pos+1, it);
        }
        else
        {
            intervals.push_back(it);
        }
        
        return true;
    }
    
    bool isCross(pair<int,int> a, pair<int,int> b)
    {
        int x = max(a.first, b.first);
        int y = min(a.second, b.second);
        return x < y;
    }
    
    int find(pair<int,int> target)
    {
        int left = 0;
        int right = intervals.size();
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(intervals[mid].first <= target.first)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        
        return left - 1;
    }
    
protected:
    vector<pair<int,int>> intervals;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */