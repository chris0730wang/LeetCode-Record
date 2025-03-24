int cmp(const void *a, const void *b){
    return (*(char*)a - *(char*)b); 
}

bool isAnagram(char* s, char* t) {
    qsort(s, strlen(s), sizeof(char), cmp);
    qsort(t, strlen(t), sizeof(char), cmp);
    if(strcmp(s, t) == 0) return true;
    return false;
}