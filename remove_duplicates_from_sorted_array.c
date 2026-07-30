int removeDuplicates(int* nums, int numsSize) {
    int insertpos = 1;
    for(int i = 1 ; i < numsSize ; i++){
        if (nums[i] != nums[i-1]){
            nums[insertpos] = nums[i];
            insertpos++;
        }
    }
    return insertpos;
}