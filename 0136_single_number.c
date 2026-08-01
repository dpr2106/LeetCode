int singleNumber(int* nums, int numsSize) {
    int lone_number = 0;
    for (int i = 0 ; i < numsSize ; i++){
        lone_number = lone_number ^ nums[i];
    }
    return lone_number;
}