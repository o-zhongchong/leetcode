class SE_String
{
public:
    SE_String(string x, string y):even(x),odd(y){}
    bool operator< (const SE_String& e) const
    {
        if( even < e.even  )
            return true;
        else if( even == e.even)
        {
            if( odd < e.odd)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    string even;
    string odd;
};

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<SE_String> se_string_set;
        
        for( auto &str:A )
        {
            string even, odd;
            strParse(str,even,odd);
            SE_String se_str(even,odd);
            
            auto search = se_string_set.find(se_str);
            if( search == se_string_set.end() )
                se_string_set.insert(se_str);
        }
        
        return se_string_set.size();
    }
protected:
    int strParse(string &origin,string &even, string &odd)
    {
        int i = 1;
        even = odd = "";
        
        for( auto &c:origin )
        {
            if( i & 1 )
                even.push_back(c);
            else
                odd.push_back(c);
            ++i;
        }
        
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        
        return 0;
    }
};