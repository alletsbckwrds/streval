//not the same as ch's streval(), this cannot remember variables. Also, you need to do this printf("%s",streval(...)) if you want to see any output at all

char* streval(char* in) {
	FILE* file = popen(in, "r");
	if(file == NULL){return (char*) NULL;}
	
	size_t bufferSize=128;
	char *buffer = (char*) malloc(bufferSize);
	if(buffer == NULL){
		pclose(file);
		return (char*) NULL;
	}

	size_t totalCharsRead = 0;
	size_t charsRead = 0;

	while((charsRead = fread(buffer + totalCharsRead, 1, bufferSize - totalCharsRead - 1, file)) > 0){
		totalCharsRead += charsRead;
		if (totalCharsRead >= bufferSize -1){
			bufferSize *= 2; //doubles the buffer if there is not enough space
			char *temp = (char*) realloc(buffer, bufferSize); //new pointer for buffer
			if(temp == NULL){
				free(buffer); pclose(file); return (char*) NULL;
			}
			buffer=temp;
		}
	}

	pclose(file);
	buffer[totalCharsRead] = '\0';	

	
	return buffer;
	
}
