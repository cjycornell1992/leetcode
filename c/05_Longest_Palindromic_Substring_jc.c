void extendPalindrome(char* s, int left, int right, int* ret, int s_len);

char* longestPalindrome(char* s) {
    
    if(s == NULL) {
        return NULL;
    }
    
    int len;
    char *ans;
    len = strlen(s);

    if(len <= 2) {
        ans = malloc(len + 1);
        memset(ans, 0, len + 1);
        memcpy(ans, s, len);
        return ans;
    }
    
    int i;
    int ret[2] = {0,0}; // start, length
    for(i = 0; i < len; i++) {
        extendPalindrome(s, i, i, ret, len); // assume odd number chars in string
        extendPalindrome(s, i, i+1, ret, len);// assume even number chars in string
    }
    int ans_len = ret[1];
    ans = malloc(ans_len + 1);
    memset(ans, 0, ans_len + 1);
    memcpy(ans, &s[ret[0]], ans_len);
    return ans;
}

void extendPalindrome(char* s, int left, int right, int* ret, int s_len) {
    while(left >= 0 && right < s_len && s[left] == s[right]) {
        left--;
        right++;
    }
    left++;
    right--;
    
    int palindrome_len = right - left + 1;
    if(palindrome_len > ret[1]) {
        ret[0] = left;
        ret[1] = palindrome_len;
    }
}