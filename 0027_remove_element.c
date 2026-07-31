int removeElement(int* nums, int numsSize, int val) {
    int insertpos = 0;
    for (int i = 0; i < numsSize ; i++){
        if(nums[i] != val){
            nums[insertpos] = nums[i];
            insertpos++;
        }
    }
    return insertpos;
}
