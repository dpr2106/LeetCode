int minimumDeletions(int* nums, int numsSize) {
    if (numsSize <+ 2){
        return numsSize;
    }

    int min_idx = 0;
    int max_idx = 0;

    for(int i = 0 ; i < numsSize ; i++){
        if(nums[i] < nums[min_idx]){
            min_idx = i;
        }
        if(nums[i] > nums[max_idx]){
            max_idx = i;
        }
    }

    int first , second;
    if (min_idx < max_idx){
        first = min_idx;
        second = max_idx;
    }
    else{
        first = max_idx;
        second = min_idx;
    }

    int both_front = second + 1;
    int both_back = numsSize - first;
    int both_sides = (first + 1) + (numsSize - second);

    int result = both_front;

    if(both_back <  result){
        result = both_back;
    }

    if(both_sides < result){
        result = both_sides;
    }

    return result;
}