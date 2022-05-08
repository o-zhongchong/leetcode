/**
 * class NestedInteger {
 *   public:
 *     bool isInteger() const;
 *     int getInteger() const;
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        int len = nestedList.size();
        for(int i=len-1; i>=0; --i) {
            st.push(nestedList[i]);
        }
        helper();
    }
    int next() {
        if(st.empty()) return -1;
        NestedInteger t = st.top(); st.pop();
        helper();
        return t.getInteger();
    }
    bool hasNext() {
        return !st.empty();
    }
private:
    void helper() {
        if (st.empty()) return;
        NestedInteger t = st.top();
        while(!t.isInteger()) {
            st.pop();
            const vector<NestedInteger>& list = t.getList();
            int len = list.size();
            for(int i=len-1; i>=0; --i) {
                st.push(list[i]);
            }
            if(!st.empty()) {
                t = st.top();
            } else {
                break;
            }
        }
    }
private:
    stack<NestedInteger> st;
};
