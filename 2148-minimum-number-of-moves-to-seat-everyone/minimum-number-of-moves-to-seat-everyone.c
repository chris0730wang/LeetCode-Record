int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    int ret = 0;
    for(int i = 1; i < seatsSize; i++){
        int tmp = seats[i];
        int j = i - 1;
        while(j >= 0 && tmp < seats[j]){
            seats[j + 1] = seats[j];
            j--;
        }
        seats[j + 1] = tmp;
        tmp = students[i];
        j = i - 1;
        while(j >= 0 && tmp < students[j]){
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = tmp;
    }
    for(int i = 0; i < seatsSize; i++){
        ret += students[i] - seats[i] > 0 ? students[i] - seats[i] : seats[i] - students[i];
    }
    return ret;
}