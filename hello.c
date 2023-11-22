#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* my_strdup(const char* s) {
    char* p = malloc(strlen(s) + 1);  // Allocate memory
    if (p != NULL) {
        strcpy(p, s);  // Copy the string
    }
    return p;
}

int main(){
	FILE *file;
	char buffer[100];
	int count = 0;
	srand(time(NULL));

	

	file = fopen("words.txt", "r");
	if(file == NULL) {
		perror("Error opening file");
		return 1;
	}

	while (fgets(buffer, sizeof(buffer), file)) {
		count++;
	}
	fclose(file);

	printf("%d",count);

	char **wordsArray = malloc(count * sizeof(char*));
	
	if(wordsArray == NULL){
		perror ("memory allocation failed");
		return 1;
	}

	file = fopen ("words.txt", "r");
	
	if (file == NULL) {
		perror("Error opening file");
		return 1;
	}
	int i = 0;
	while (fgets(buffer, sizeof(buffer), file)){
		wordsArray[i] = my_strdup(buffer);
		i++;
	}
	fclose(file);


	int random_number = rand() % count;
	printf("%s", wordsArray[random_number]);
	char wordToGuess[10];
	strcpy(wordToGuess,wordsArray[random_number]);
	printf("%s", wordToGuess);
	for (i = 0; i < count; i++) {
		free(wordsArray[i]);
	}
	free(wordsArray);
	return 0;
}