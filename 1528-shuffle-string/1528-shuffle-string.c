char * restoreString(char * s, int* indices, int indicesSize){
    char *res = (char*)malloc(sizeof(char) * 101);
    int i;
    for(i=0; i<indicesSize; i++){
        *(res+indices[i]) = *s++;
    }
    res[i] = '\0';
    return res;
}