

int maxArea(int* height, int heightSize){
    int *head = height, *tail = height + heightSize - 1;
    int max = 0, water = 0;
    while(head != tail){
        int len = tail - head;
        water = *head < *tail ? (*head * len) : (*tail * len);
        if(water > max) max = water;
        if(*head < *tail){
            head = head + 1;
        }else{
            tail = tail - 1;
        }
    }
    return max;
}