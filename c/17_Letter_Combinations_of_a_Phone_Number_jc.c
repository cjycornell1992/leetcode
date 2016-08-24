/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define DIGIT_TO_INDEX(a) ((a) - 48)
const int digit_size_table[] = {0,0,3,3,3,3,3,4,3,4};
const char* digit_char_table[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

char** letterCombinations(char* digits, int* returnSize) {
    if (digits == NULL || digits[0] == '\0') return NULL;
    int digitsLen = strlen(digits);
    int i,j;
    (*returnSize) = 1;
    for (i = 0; i < digitsLen; i++) {
        (*returnSize) *= digit_size_table[DIGIT_TO_INDEX(digits[i])];
    }
    if ((*returnSize) == 0) return NULL;
    
    char** ans;
    ans = malloc((*returnSize) * sizeof(char*));
    for (i = 0; i < (*returnSize); i++) {
        ans[i] = malloc(digitsLen + 1);
        memset(ans[i], 0, digitsLen + 1);
    }
    
    int loopPeriod = 1;
    for (i = digitsLen - 1; i >= 0; i--) {
        int index = DIGIT_TO_INDEX(digits[i]);
        int digit_size = digit_size_table[index];
        for (j = 0; j < (*returnSize); j++) {
            ans[j][i] = digit_char_table[index][(j / loopPeriod) % digit_size];           
        }
        loopPeriod *= digit_size;
    }
    return ans;
}