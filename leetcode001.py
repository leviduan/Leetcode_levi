#!/usr/bin/python3

class Solution(object):
    def twoSum(self, nums, target):
    	myDict = {}
    	for i in xrange(0,len(nums)):
    		if target-nums[i] in myDict:
    			return [myDict[target-nums[i]], i]
    		myDict[nums[i]] = i

if __name__ == '__main__':
    a = Solution()
    dd = [5,5]

    c = a.twoSum(dd,10)
    print c