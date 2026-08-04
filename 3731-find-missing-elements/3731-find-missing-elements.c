/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    int min = nums[0];
    int max = nums[0];

    for (int i = 0 ; i < numsSize ; i++){
        if (nums[i] < min){
            min = nums[i];
        } 
        if (nums[i] > max){
            max = nums[i];
        }}
        int* checklist = (int*)calloc(max + 1, sizeof(int));
        for (int i = 0; i < numsSize ; i++){
            int number = nums[i];
            checklist[number] = 1;
     }
        int* result = (int*)malloc((max - min + 1) * sizeof(int));
        int missing_count = 0;
        for (int i = min ; i <= max ; i++){
            if (checklist[i] == 0) {
                result[missing_count] = i;
                missing_count++;
            }
        }
        free(checklist);
        *returnSize = missing_count;

        return result;
    }
