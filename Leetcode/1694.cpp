class Solution {
public:
    string filter(string number)
    {
        string r;
        
        for(auto c : number)
        {
            if(c >= '0' && c <= '9')
            {
                r.push_back(c);
            }
        }
        
        return r;
    }
        
    string reformatNumber(string number) {
        string r;
        number = filter(number);
        int len = number.size();
        
        for(int i=0; i<len;)
        {
            string s = "";
            
            if(i != 0)
            {
                r += "-";
            }
            
            if(len - i < 3)
            {
                s = number.substr(i, len-i);
                i += (len - i);
            }
            else if(len - i == 4)
            {
                s = number.substr(i, 2) + "-" + number.substr(i+2, 2);
                i += 4;
            }
            if(len - i == 5)
            {
                s = number.substr(i, 3) + "-" + number.substr(i+3, 2);
                i += 5;
            }
            else
            {
                s += number.substr(i, 3);
                i += 3;
            }
            
            r += s;
        }
        
        return r;
    }
};