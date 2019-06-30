class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        set_J=set(J)
        count=0
        for i in S:
            if i in set_J:
                count=count+1
        return count