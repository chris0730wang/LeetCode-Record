int peakIndexInMountainArray(int* arr, int arrSize) {
    int pre = arr[0];
    int idx = 1;
    for(idx = 1; idx < arrSize; idx++){
        if(arr[idx] < pre) break;
        else pre = arr[idx];
    }
    return idx - 1;
}