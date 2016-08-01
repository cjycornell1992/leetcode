#define INT_MAX ((long) (2147483647))
#define INT_MIN ((long) (-2147483648)) 
#define IS_NUMBER(c) (c >= '0' && c <= '9')
#define DIGIT_CHAR_TO_DECIMAL(c) (c - 48)

int myAtoi(char* str) {
    long ret = 0;
    int i = 0;
    bool positive = true;
    bool exceed = false;
    /* Stripe white space */
    while(str[i] == ' ') {
        i++;
    }
    /* First character */
    if(str[i] == '-' || str[i] == '+') {
        if(str[i] == '-') {
            positive = false;
        }
    } else if(IS_NUMBER(str[i])) {
        ret = (long) DIGIT_CHAR_TO_DECIMAL(str[i]);
    } else {
        return 0;
    }
    i++;
    /* Remaining characters */
    while(IS_NUMBER(str[i])) {
        if (ret >= INT_MAX / 10) {
            if(ret > INT_MAX / 10 || (DIGIT_CHAR_TO_DECIMAL(str[i]) > 7)) {
                exceed = true;
                break;
            }
        }
        int digit_dec;
        digit_dec = DIGIT_CHAR_TO_DECIMAL(str[i]);
        ret = 10 * ret + (long) digit_dec;
        i++;
    }
    /* Overflow routine */
    if (exceed) {
        if(positive) {
            return INT_MAX;            
        } else {
            return INT_MIN;
        }
    }
    
    ret = positive ? ret : -ret;
    return ((int) ret);
}