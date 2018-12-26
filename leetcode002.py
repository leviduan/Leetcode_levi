# Definition for singly-linked list.
#!/usr/bin/python3
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):

    def initData(self, str):
        t = len(str)
        flag = 0
        ret = ListNode(int(str[0]))
        dd = ret
        for i in xrange(1,t+1):
            if flag == 0:
                flag = 1
            else:
                ret.next = ListNode(int(str[i-1]))
                ret = ret.next
        return dd 

    def printNode(self, l):
        while l:
            print l.val,
            l = l.next
        print ' '


    def addTwoNumbers(self, l1, l2):
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        ret = ListNode(0)
        dd = ret
        flag = 0
        while l1 or l2 or flag:
            mark = 0
            if l1:
                a = l1.val
                l1 = l1.next
            else :
                a = 0
            if l2:
                b = l2.val 
                l2 = l2.next
            else :
                b = 0
            ddsum = a + b + flag
            flag = ddsum / 10
            ret.val = ddsum%10
            if l1 :
                mark = 1
            if l2 :
                mark = 1
            if flag:
                mark = 1
            if mark:
                ret.next = ListNode(0)
                ret = ret.next
        return dd


if __name__ == '__main__':
    a = Solution()
    b = a.initData('5')
    c = a.initData('5')
    a.printNode(b)
    a.printNode(c)
    d = a.addTwoNumbers(b,c)
    a.printNode(d)