class Solution {
public:
    string maximumBinaryString(string binary) {
        int len = binary.size();
        int pre = -1;
        
        for(int i=0; i<len; ++i)
        {
            if(binary[i] == '0' && pre == -1)
            {
                pre = i;
            }
            else if(binary[i] == '0' && pre != -1)
            {
                if(i == pre + 1)
                {
                    binary[pre] = '1';
                    pre = i;
                }
                else
                {
                    binary[pre] = binary[i] = '1';
                    binary[pre + 1] = '0';
                    pre = pre + 1;
                }
            }
        }
        
        return binary;
    }
};