#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
	int length = strlen(s);
	if (length <= 1) return s;
	if (numRows == 1) return s;
	char *a = malloc(sizeof(char)*(length+1));
	int lenarray[numRows];
	int leng = length-1;
	int yushu = leng%(2*numRows-2);
	lenarray[0] = (leng - leng%(2*numRows-2))/(2*numRows-2)+1;
	int total = lenarray[0];
	for (int i=1;i<numRows-1;++i) {
		int flag = 0;
		if (yushu >= i) flag = 1;
		if (yushu >= 2*numRows-2-i) flag = 2;
		lenarray[i] = (lenarray[0]-1)*2 + flag;
		total += lenarray[i];
		lenarray[i] = total;
	}
	for (int i=0,j=0;s[i]!='\0';++i) {
		if (i % (2*numRows-2) == 0) {
			a[i/(2*numRows-2)] = s[i];
		}
		else if (i % (2*numRows-2) == numRows-1) {
			a[total+(i-(numRows-1))/(2*numRows-2)] = s[i];
		}
		else {
			int yushu = i%(2*numRows-2);
			int cengci = (i - i%(2*numRows-2))/(2*numRows-2);
			int row = 0;
			if (yushu < numRows-1) {
				row = yushu;
				a[lenarray[row-1]-1+cengci*2+1] = s[i];
			}
			else {
				row = 2*numRows-2-yushu;
				a[lenarray[row-1]-1+cengci*2+2] = s[i];
			}
		}
	}
	a[length] = '\0';
	return a;
}

int main(int argc, char const *argv[])
{
	// char *s = "PAYPALISHIRING\0";
	char *s = "AB\0";
	char *p = convert(s, 1);
	printf("%s\n", p);
	return 0;
}

