/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compar(const void *a, const void *b);
int** threeSum(int* nums, int numsSize, int* returnSize) {
    (*returnSize) = 0;
    if(nums == NULL || numsSize <= 2)   return NULL;
    int** ans;
    int i = 0,j = 1,k = 2;
    int prevSize = 0;
    ans = malloc(sizeof(int*));
    ans[0] = malloc(sizeof(int) * 3);
    memset(ans[0],0,sizeof(int) * 3);
    qsort(nums, numsSize, sizeof(int), compar);
    
    for(i = 0; i < numsSize; i++) {
        if((*returnSize) != 0 && nums[i] <= ans[prevSize][0]) continue;
        for(j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] > 0) break;
            for(k = j + 1; k < numsSize; k++) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    if((*returnSize) != 0 && nums[j] == ans[prevSize][1] && nums[k] == ans[prevSize][2]) {
                        break;
                    }
                    
                    if((*returnSize) != 0){
                        ans = realloc(ans, sizeof(int*) * ((*returnSize) + 1));
                        ans[(*returnSize)] = malloc(sizeof(int) * 3);
                    }
                    ans[(*returnSize)][0] = nums[i];
                    ans[(*returnSize)][1] = nums[j];
                    ans[(*returnSize)][2] = nums[k];
                    prevSize = (*returnSize)++;
                }
            }
        }
    }
    if(*(returnSize) == 0)  return NULL;
    return ans;
}

int compar(const void *a, const void *b) {
    return *((int*) a) - *((int*) b);
}