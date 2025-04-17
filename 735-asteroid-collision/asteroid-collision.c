/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * asteroidsSize);
    *returnSize = 0;

    for(int i = 0; i < asteroidsSize; i++){
        int speed = asteroids[i];
        int index = (*returnSize) - 1;
        res[(*returnSize)++] = speed;
        if(speed < 0){
            while(index >= 0 && speed < 0){
                if(res[index] < 0){
                    res[(*returnSize) - 1] = speed;
                    break;
                }
                int sum = res[index] + speed;
                if(sum > 0) {
                    (*returnSize)--;
                    break;
                }
                else if(sum == 0) {
                    (*returnSize) = index;
                    break;
                }
                else{
                    res[index--] = speed;
                    (*returnSize)--;
                }
            }
        }
    }
    return res;
}