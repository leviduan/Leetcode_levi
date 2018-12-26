# dic 方法
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        left = 0
        maxlen = 0
        dict = {}
        for i in range(len(s)):
            dict[s[i]] = -1
        for i in range(len(s)):
            if dict[s[i]] != -1
                while left <= dict[s[i]]:
                    dict[s[left]] = -1
                    left += 1
            if i + 1 - left > maxlen:
                maxlen = i + 1 - left
            dict[s[i]] = i
        return maxlen

# set 方法
class Solution:
    def lengthOfLongestSubstring(self, s):
        left, right = 0, 0
        chars = set()
        res = 0
        while left < len(s) and right < len(s):
            if s[right] in chars:
                if s[left] in chars:
                    chars.remove(s[left])
                left += 1
            else:
                chars.add(s[right])
                right += 1
                res = max(res, len(chars))
        return res
