#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isMatchLen(char* s, char* p, int sIndex, int pIndex, int slen, int plen) {
    char s1 = s[sIndex];
    char s2 = p[pIndex];
    if (plen == 0) return !slen;
    int result1 = slen && (s1 == s2 || s2 == '.');
    if (plen >= 2 && p[pIndex+1] == '*') 
        return isMatchLen(s, p, sIndex, pIndex+2, slen, plen-2) | (result1 && isMatchLen(s, p, sIndex+1, pIndex, slen-1, plen));
    else return (result1 && isMatchLen(s, p, sIndex+1, pIndex+1, slen-1, plen-1));
}

bool isMatch(char* s, char* p) {
    int slen = strlen(s);
    int plen = strlen(p);
    return isMatchLen(s, p, 0, 0, slen, plen);
}

int main(int argc, char const *argv[])
{
    char *s = "aab";
    char *p = "c*a*ba*b";
    printf("%s\n", s);
    printf("%s\n", p);
    printf("%d\n", isMatch(s, p));
    return 0;
}
