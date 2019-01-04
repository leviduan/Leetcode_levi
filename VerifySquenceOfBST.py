# -*- coding:utf-8 -*-
class Solution:
    def VerifySquenceOfBST(self, sequence):
        length = len(sequence)
        if length == 0:
            return False
        if length == 1:
            return True
        str = sequence[-1]
        i = 0
        while sequence[i] < str:
            i+=1
        for x in xrange(i, length-1):
            if sequence[x] < str:
                return False 
        a = True
        b = True
        if len(sequence[:i])>0:
            a = self.VerifySquenceOfBST(sequence[:i])
        if len(sequence[i:length-1])>0:
            b = self.VerifySquenceOfBST(sequence[i:length-1])
        return a and b

if __name__ == '__main__':
    a = Solution()
    dd = [5,7,6,9,11,10,8]
    b = a.VerifySquenceOfBST(dd)
    print b