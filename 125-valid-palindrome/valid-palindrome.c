bool isAlphaNumber(char c) {
    if (c >= 'a' && c <= 'z') return true;
    if (c >= 'A' && c <= 'Z') return true;
    if (c >= '0' && c <= '9') return true;
    return false;
}
bool isPalindrome(char* s) {
    int left = 0, right = strlen(s) - 1;
    while (left < right) {
        while (left < right && !isAlphaNumber(s[left])) {
            left++;
        }
        while (left < right && !isAlphaNumber(s[right])) {
            right--;
        }
        if (tolower(s[left++]) != tolower(s[right--])) {
            return false;
        }
    }
    return true;
}