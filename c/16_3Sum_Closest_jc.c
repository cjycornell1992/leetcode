int compar(int *a, int *b);
#define CLOSEST(a,b) ((abs(a) > abs(b)) ? (b) : (a))
int threeSumClosest(int* nums, int numsSize, int target) {
    if (nums == NULL || numsSize < 3)    return 0;
    int dif,min_dif;
    int i,j,k;
    qsort(nums, numsSize, sizeof(int), compar);

    min_dif = nums[0] + nums[1] + nums[2] - target;
    for (i = 0; i < numsSize - 2; i++) {
        j = i + 1;
        k = numsSize - 1;
        while (j < k) {
            dif = nums[i] + nums[j] + nums[k] - target;
            if (dif == 0)   return target;
            
            if(dif < 0)     j++;
            else            k--;
            min_dif = CLOSEST(dif,min_dif);
        }
    }
    return target + min_dif;
}

int compar(int *a, int *b) {
    return (*a) - (*b);    
}