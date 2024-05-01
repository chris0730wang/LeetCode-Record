int cmp(const void *a, const void *b){
    return *(char*)a - *(char*)b;
}

bool canConstruct(char* ransomNote, char* magazine) {
    int rlen = strlen(ransomNote);
    int mlen = strlen(magazine);
    qsort(ransomNote, rlen, sizeof(char), cmp);
    qsort(magazine, mlen, sizeof(char), cmp);
    int tmp = 0;
    for(int i = 0; i < rlen; i++){
        if(tmp == mlen) return false;
        for(int j = tmp; j < mlen; j++){
            if(ransomNote[i] == magazine[j]) {
                tmp = j + 1;
                break;
            }
            if(j == mlen - 1) return false;
        }
    }
    return true;
}