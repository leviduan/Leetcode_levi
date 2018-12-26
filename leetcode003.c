#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int letter[130];

int lengthOfLongestSubstring(char* s) {
    int left, count, index, max, preIndex;
    left = count = index = max = preIndex = 0;
    memset(letter, -1, sizeof(letter));
    for (int i=0;s[i]!='\0';++i) {
        index = s[i]-'A' + 65;
        if (letter[index] == -1) {
            letter[index] = i;
            ++count;
        }
        else {
            if (count > max) max = count;
            int tmp = letter[index];
            while(left <= tmp) {
                int preIndex = s[left]-'A' + 65;
                letter[preIndex] = -1;
                ++left;
            }
            count = i - left + 1;
            letter[index] = i;
        }
    }
    return count>max?count:max;
}

int main(int argc, char const *argv[])
{
	char *ch = "abcabcbb\0";
	int t = 0;
	t = lengthOfLongestSubstring(ch);
	printf("%d\n", t);
	return 0;
}
