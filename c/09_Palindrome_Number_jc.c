bool isPalindrome(int x) {
    int a = 0;
    if((x < 0) || ((x % 10) == 0) && (x != 0))   return false;
    while(x > a) {
        a = (10 * a) + (x % 10);
        x = x / 10;
    }
    return ((x == a) || (x == a / 10));
}