#/usr/bin/python
#coding=utf8

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums_dict = {}
        res_id = [0,0]
        for i in range(len(nums)):
            if( nums_dict.has_key(nums[i]) ):
                nums_dict[nums[i]].append(i)
            else:
                nums_dict[nums[i]] = [i]

        for i in range(len(nums)):
            first_node = nums[i]
            second_node = target - first_node
            if(first_node == second_node and len(nums_dict[first_node]) > 1):
                res_id[0]=nums_dict[first_node][0]
                res_id[1]=nums_dict[first_node][1]
                break
            elif(first_node != second_node and nums_dict.has_key(second_node) ):
                res_id[0]=i
                res_id[1]=nums_dict[second_node][0]
                break
        return res_id