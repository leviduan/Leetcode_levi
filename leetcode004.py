#!/usr/bin/python2

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        i = 0
        j = 0
        length = len(nums1)+len(nums2)
        if length%2!=0:
            res = (length-1)/2
            respre = 0
        else:
            res = length/2
            respre = length/2-1
        for x in range(length):
            if i < len(nums1) and j < len(nums2):
                if nums1[i] < nums2[j]:
                    dd = nums1[i]
                    i = i+1
                else:
                    dd = nums2[j]
                    j = j+1
            elif i < len(nums1):
                dd = nums1[i]
                i = i+1
            elif j < len(nums2):
                dd = nums2[j]
                j = j+1
            if x == res:
                resA = dd
                break
            if x == respre:
                resB = dd
        if length%2!=0: 
            return resA   
        else: 
            return (resA + resB)/2.0
        
if __name__ == '__main__':
    a = Solution()
    d1 = [1,2]
    d2 = [3]
    c = a.findMedianSortedArrays(d1,d2)
    print c

    