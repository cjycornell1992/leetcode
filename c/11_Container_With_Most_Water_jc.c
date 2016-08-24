#define MIN(a,b) ((a > b) ? (b) : (a))
#define MAX(a,b) ((a > b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    
    if(height == NULL || heightSize < 0) {
        return 0;
    }
    
    int i = 0, j = heightSize - 1;
    int cur_height;
    int cur_max_area = 0;
    while(i < j) {
        cur_height = MIN(height[i],height[j]);
        cur_max_area = MAX(cur_max_area, (j - i) * cur_height);
        while(height[i] <= cur_height && i < j)  i++;
        while(height[j] <= cur_height && i < j)  j--;
    }

    return cur_max_area;
}