char* longestCommonPrefix(char** strs, int strsSize) {
    char* ret;
    if(strs == NULL || strs[0] == NULL) {
        ret = malloc(1);
        ret[0] = '\0';
        return ret;
    }
    int len = strlen(strs[0]);
    ret = malloc(len + 1);
    memset(ret, 0, len + 1);
    int i,j;
    char c;
    for(i = 0; i < len; i++) {
        if(strs[0][i])   c = strs[0][i];
        else            return ret;
        for(j = 0; j < strsSize; j++) {
            if(strs[j][i] == c)  continue;
            else    return ret;
        }
        ret[i] = c;
    }
    return ret;
}
