/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i,j;
    for(i = 0; i < numsSize; i++){
        for(j = i + 1; j < numsSize; j++){
            if(nums[i] + nums[j] == target){
                int* a;
                a = malloc(sizeof(int) * 2);
                a[0] = i;
                a[1] = j;
                return a;  
            }
        }
    }
    return NULL;
}