// 9. Palindrome Number

bool isPalindrome(int x) {
    if (x<0) return false;
    if (x == 0) return true;
    int sum = 0;
    int tmp = 0;
    int oldValue = x;
    while (x) {
        sum *= 10;
        int t = x%10;
        sum += t;
        x /= 10;
    }
    if (oldValue == sum) return true;
    else return false;
    return false;
}
