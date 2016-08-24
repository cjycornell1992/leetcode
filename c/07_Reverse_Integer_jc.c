#define IntegerMAX_VALUE 2147483647
#define IntegerMIN_VALUE -2147483648

int reverse(int x) {
    int negative = 0;
    if (x == IntegerMIN_VALUE) return 0;
    if (x < 0){
        negative = 1;
        x = -x;
    }
    x = reverseHelper(x);
    if(negative) return -x;
    else return x;
}

int reverseHelper(int x){
    long a = 0;
    while(x >= 10){
        a = 10*(a + (x % 10));
        if(a >= IntegerMAX_VALUE)   return 0;
        x = x/10;
    }
    a += x;
    return (int) a;
} 