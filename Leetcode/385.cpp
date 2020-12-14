/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s.empty())
        {
            return {};
        }
        
        NestedInteger ret;
        int len = s.size();
        
        if(s[0] == '[' && len >= 2 && s[len-1] == ']')
        {
            if(len > 2)
            {
                vector<string> strs = split(s.substr(1, len - 2));
                
                for(auto str : strs)
                {
                    NestedInteger nt = deserialize(str);
                    ret.add(nt);
                }
            }
        }
        else
        {
            int val = stoi(s);
            ret = NestedInteger(val);
        }
        
        return ret;
    }
    
    vector<string> split(string s)
    {
        int len = s.size();
        int start = 0;
        vector<string> ret;
        
        for(int i=0; i<len; ++i)
        {
            if(s[i] == '[')
            {
                int cnt = 1;
                i = i + 1;
                
                while(i < len && cnt != 0)
                {
                    if(s[i] == '[')
                    {
                        ++cnt;
                    }
                    else if(s[i] == ']')
                    {
                        --cnt;
                    }
                    
                    ++i;
                }
            }
            
            if(s[i] == ',')
            {
                string tmp = s.substr(start, i-start);
                ret.push_back(tmp);
                start = i + 1;
            }
        }
        
        if(start != len)
        {
            string tmp = s.substr(start, len-start);
            ret.push_back(tmp);
        }

        return ret;
    }
};