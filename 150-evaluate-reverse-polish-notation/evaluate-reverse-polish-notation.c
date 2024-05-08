int evalRPN(char** tokens, int tokensSize) {
	int* vals = (int*)malloc(sizeof(int) * tokensSize);
	int index = 0;
    for(int i = 0; i < tokensSize; i++){
		vals[index] = 0;
		int val = 0;
		if(tokens[i][0] == '+'){
			vals[index - 2] = vals[index - 2] + vals[index - 1];
			index --;
		}
		else if(tokens[i][0] == '-' && strlen(tokens[i]) == 1){
			vals[index - 2] = vals[index - 2] - vals[index - 1];
			index --;
		}
		else if(tokens[i][0] == '*'){
			vals[index - 2] = vals[index - 2] * vals[index - 1];
			index --;
		}
		else if(tokens[i][0] == '/'){
			vals[index - 2] = vals[index - 2] / vals[index - 1];
			index --;
		}
		else{
			int len = strlen(tokens[i]);
			if(tokens[i][0] == '-'){
				for(int j = 1; j < len; j++){
					int tmp = tokens[i][j] - '0';
					val = val * 10 + tmp;
				}
				vals[index++] = 0 - val;
			}
			else{
				for(int j = 0; j < len; j++){
					int tmp = tokens[i][j] - '0';
					val = val * 10 + tmp;
				}
				vals[index++] = val;
			}
		}
	}
	return vals[0];
}
