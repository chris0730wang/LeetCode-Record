int compress(char* chars, int charsSize) {
    if(charsSize == 1) return charsSize;
    int write = 0, read = 0;
    while(read < charsSize){
        char curr = chars[read];
        int count = 0;
        while(read < charsSize && chars[read] == curr){
            read++;
            count++;
        }
        chars[write++] = curr;
        if(count > 1){
            char buffer[10];
            int index = 0;
            while(count > 0){
                buffer[index++] = (count % 10) + '0';
                count /= 10;
            }
            while(index > 0){
                chars[write++] = buffer[--index];
            }
        }
    }
    return write;
}