/*  I       V       X       L       C       D       M       */
/*  1       5       10      50      100     500     1000    */

//  Same letter in a row results in the sum of these letters, e.g：III = 3;
//  Small Letter on the right side results in sum, e.g：VIII = 8, XII = 12;
//  Small Letter on the left side, Greater Letter on the right(I,X,C only), results in the difference of two letters, e.g：IV=4;
//  Same letter is not allowed to appear more than 3 times consecutively;

static const char*  Thousand[]  =   {"","M","MM","MMM"}; 
static const char*  Hundred[]   =   {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
static const char*  Tens[]      =   {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
static const char*  Digits[]    =   {"","I","II","III","IV","V","VI","VII","VIII","IX"};

char* intToRoman(int num) {
    char* buf;
    buf = malloc(24);
    memset(buf,0,24);
    if(num > 3999 || num < 1)   return NULL;

    strcat(buf, Thousand[num / 1000]);
    strcat(buf, Hundred[(num / 100) % 10]);
    strcat(buf, Tens[(num % 100) / 10]);
    strcat(buf, Digits[num % 10]);

    return buf;
}