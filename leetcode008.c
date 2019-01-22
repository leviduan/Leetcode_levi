#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int myAtoi(char* str) {
	int mark = 0;
	int i = 0;
	while (str[i] == ' ') {
		++i;
	}
	if (str[i] == '\0' || str[i] < 48 || str[i] > 57) {
		if (str[i] == '-') {
			mark = 1;
			++i;
		}
		else if (str[i] == '+') {
			mark = 0;
			++i;
		}
		else return 0;
	}
	int j = 0;
	long long sum = 0;
	int tmp = 0;
	int t = 0;
	int max = 0;
	while (str[i] == '0') {
		++i;
	}
	while(str[i] >= 48 && str[i] <= 57) {
		++j;
		if (j >= 11) {
			max = 1;
			break;
		}
		sum *= 10;
		t = str[i]-'0';
		sum+=t;
		++i;
		tmp = sum;
		if (sum > INT_MAX) {
			max = 1;
			break;
		}
	}
	if (max == 1 && mark==0) return INT_MAX;
	if (max == 1 && mark==1) return INT_MIN;
	return mark? sum*-1 : sum;
}

int main(int argc, char const *argv[])
{
	char *s = "2147483648";
	int result = myAtoi(s);
	printf("%d\n", result);
	return 0;
}