#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a[1002];

char* longestPalindrome(char* s) {
	if (s[0] == '\0') return s;
	int i, left, right, max, length, maxleft, maxright, mark;
	i = left = right = max = length = maxleft = maxright = mark = 0;
	while (s[i] != '\0') {
		if (mark == 0) left = i-1;
		else left = i;
		right = i+1;
		while (s[left] == s[right] && left>=0) {
			left--;
			right++;
		}
		if (mark) {
			++i;
			mark = 0;
			length = right-left+1-2;
		}
		else {
			mark = 1;
			length = (i-(left+1))*2+1;
		}
		if (max < length) {
			maxleft = ++left;
			maxright = --right;
			max = length;
		}
	}
	int j=0;
	while (maxright>=maxleft) a[j++] = s[maxleft++];
	a[j] = '\0';
	return a;
}

int main(int argc, char const *argv[])
{
	char *s = "babad\0";
	char *d = longestPalindrome(s);
	printf("%s\n", d);
	return 0;
}

// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: "cbbd"
// Output: "bb"