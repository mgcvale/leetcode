/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* r = (int*) malloc(2*sizeof(int*));
    for(int i=0; i<numsSize; i++){
        for(int j=0; j<numsSize; j++){
            if(j<=i)
                continue;
            if(nums[i]+nums[j]==target){
                r[0]=i; r[1]=j;
                *returnSize = 2;
                return r;
            }
        }
    }
    return NULL;
}
