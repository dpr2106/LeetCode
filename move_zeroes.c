void moveZeroes(int* nums, int numsSize) {
    int insertpos = 0;
    for (int i = 0; i < numsSize;i++){
        if(nums[i] != 0){
            nums[insertpos] = nums[i];
            insertpos++;
        }
    }
    while (insertpos < numsSize) {
        nums[insertpos] = 0;
        insertpos++;
    }
}