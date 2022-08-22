

int mostWordsFound(char ** sentences, int sentencesSize){
    int max = 0, times = 0, gap = 1;
    for(int i=0; i<sentencesSize; i++){
        char *locate = sentences[i];
        while(*locate){
            printf("%c", *locate);
            if(*locate == ' ') times++;
            *locate = *(sentences[i] + gap++);
        }
        if(times+1 > max) max = times+1;
        times = 0;
        gap = 1;
    }
    return max;
}