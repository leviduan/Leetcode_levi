#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int indexValue = 0;

void dfs(const char *s ,char** letter_matrix, int count, int n, char **returnArray, char *newArray);

char** letterCombinations(char* digits, int* returnSize) {
	if (!strlen(digits)) {
		*returnSize = 0;
		return 0;
	}
	indexValue = 0;
	char *letter_matrix[10];
	letter_matrix[0] = " ";
	letter_matrix[1] = " ";
	letter_matrix[2] = "abc";
	letter_matrix[3] = "def";
    letter_matrix[4] = "ghi";
    letter_matrix[5] = "jkl";
    letter_matrix[6] = "mno";
    letter_matrix[7] = "pqrs";
    letter_matrix[8] = "tuv";
    letter_matrix[9] = "wxyz";
    char *s = malloc(sizeof(char) * strlen(digits));
    memset(s, '\0', strlen(digits));
    int j =0;
    for (int i=0;digits[i]!='\0';++i) {
    	if (digits[i]== '0' || digits[i] == '1') continue;
    	s[j++] = digits[i];
    }
    s[j] = '\0';
    int n = strlen(s);
    if (!n) {
		*returnSize = 0;
		return 0;
	}
	int sum = 1;
	for (int i=0;i<n;++i) {
		if (s[i] == '7' || s[i] == '9') {
			sum *=4;
			continue;
		}
		sum *=3;
	}
	*returnSize = sum;
	char **returnArray = malloc(sizeof(char *) * sum);
	memset(returnArray, '\0', sizeof(char *) * sum);
	char* newArray = malloc(sizeof(char) *n);
	dfs(s, letter_matrix, 0, n, returnArray, newArray);
	return returnArray;
}

void dfs(const char *s ,char** letter_matrix, int count, int n, char **returnArray, char *newArray) {
	if (count == n) {
		newArray[count] = '\0';
		char* array = malloc(sizeof(char) * n );
		memcpy(array, newArray, n);
		array[count] = '\0';
		returnArray[indexValue++] = array;
		return;
	}
	int len = strlen(letter_matrix[s[count]-'0']);
	for(int i=0;i<len;++i) {
		newArray[count] = letter_matrix[s[count]-'0'][i];
		dfs(s, letter_matrix, count+1, n, returnArray, newArray);
	}
}
