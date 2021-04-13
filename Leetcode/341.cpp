/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int len = nestedList.size();
        
        for(int i=len-1; i>=0; --i)
        {
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        NestedInteger p = st.top();
        st.pop();
        return p.getInteger();
    }
    
    bool hasNext() {
        while(!st.empty())
        {
            NestedInteger p = st.top();
            
            if(p.isInteger())
            {
                return true;
            }
            
            st.pop();
            vector<NestedInteger> list = p.getList();
            int len = list.size();
            
            for(int i=len-1; i>=0; --i)
            {
                st.push(list[i]);
            }
        }
        
        return false;
    }
    
protected:
    stack<NestedInteger> st;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */