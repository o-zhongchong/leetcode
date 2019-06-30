#/usr/bin/python
#coding=utf8
#ZigZag Conversion

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        str_list = [""] * numRows
        group_len= 2 * numRows - 2
        
        for i in range(len(s)):
            group_id=0
            if(group_len):
                group_id = i%group_len
            if(group_id >= numRows):
                group_id = group_len - group_id
            str_list[group_id] += s[i]
        
        r_str="".join(str_list)
        return r_str