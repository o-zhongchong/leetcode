class Solution {
public:
    enum State {
        Normal = 0,
        StrLen,
        StrBody,
        SubStrLen,
        SubStrBody
    };
public:
    string decodeString(string s) {
        int len = s.size();
        string ret;
        mState = Normal;
        int idx = 0, pos = 0;
        while(idx < len) {
            switch(mState) {
            case Normal:
                if(s[idx] >= '0' && s[idx] <= '9') {
                    mState = StrLen;
                    break;
                }
                ret.append(1, s[idx++]);
                break;
            case StrLen:
                pos = s.find("[", idx);
                mStrLen = stoi(s.substr(idx, pos-idx));
                mStrBody = "";
                idx = pos+1;
                mState = StrBody;
                break;
            case StrBody:
                if(s[idx] >= '0' && s[idx] <= '9') {
                    mState = SubStrLen;
                    break;
                }
                if(s[idx] == ']') {
                    ret += generate(mStrBody, mStrLen);
                    ++idx;
                    mState = Normal;
                    break;
                }
                mStrBody.append(1, s[idx++]);
                break;
            case SubStrLen:
                st.push(make_pair(mStrLen, mStrBody));
                pos = s.find("[", idx);
                mStrLen = stoi(s.substr(idx, pos-idx));
                mStrBody = "";
                idx = pos+1;
                mState = SubStrBody;
                break;
            case SubStrBody:
                if(s[idx] >= '0' && s[idx] <= '9') {
                    mState = SubStrLen;
                    break;
                }
                if(s[idx] == ']') {
                    string t = generate(mStrBody, mStrLen);
                    ++idx;
                    auto ctx = st.top();st.pop();
                    mStrLen = ctx.first;
                    mStrBody = ctx.second + t;
                    st.empty() ? mState=StrBody : mState=SubStrBody;
                    break;
                }
                mStrBody.append(1, s[idx++]);
                break;
            }
        }
        return ret;
    }
private:
    string generate(string &str, int cnt) {
        string ret = "";
        while(cnt--) {
            ret += str;
        }
        return ret;
    }
private:
    State mState;
    int mStrLen;
    string mStrBody;
    stack<pair<int,string>> st;
};