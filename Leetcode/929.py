class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        e_set=set([])
        for e in emails:
            a_index=e.find("@")
            e_front=e[:a_index]
            e_back=e[a_index:]
            
            plus_index=e_front.find("+")
            e_front=e_front[:plus_index].replace(".","")
            e_set.add(e_front+e_back)
        return len(e_set)
            