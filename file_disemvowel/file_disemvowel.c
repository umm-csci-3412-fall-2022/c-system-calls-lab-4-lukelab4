#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#define BUF_SIZE 1024

//A method that checks if a character is a vowel
bool is_vowel(char c) {
	char lower = tolower(c);
	if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'){
		return true;
	}
	return false;
}

//A method that copys all the non-vowels and returns the number of non-vowels
int copy_non_vowels(int num, char* in_buf, char* out_buf){
	int num_chars = 0;
	for(int x = 0; x < num; x++){
		if(!is_vowel(in_buf[x])){
			out_buf[num_chars] = in_buf[x];
			num_chars++;
		}
	}
	return num_chars;
}

//A method that copys non-vowels from an input to an output
void disemvowel(FILE* inputFile, FILE* outputFile){
	char in[BUF_SIZE];
	char out[BUF_SIZE];
	while(!feof(inputFile)){
		int num_chars = fread(in, sizeof(char), BUF_SIZE, inputFile);
		int non_vowel = copy_non_vowels(num_chars, in, out);
		fwrite(out, sizeof(char), non_vowel, outputFile);
	}
}

//Driver method
int main(int argc, char *argv[]){
	FILE *inputFile = stdin;
	FILE *outputFile = stdout;
	if(argc == 2) {
		inputFile = fopen(argv[1], "r");
	} else if(argc == 3){
		inputFile = fopen(argv[1], "r");
		outputFile = fopen(argv[2], "w");
	} else if(argc > 3){
		fprintf(stderr, "An error has occurred.");
		exit(1);
	}
	if(inputFile == NULL || outputFile == NULL){
		fprintf(stderr, "An error has occurred.");
		exit(1);
	}
	disemvowel(inputFile, outputFile);
	if(inputFile != stdin){
		fclose(inputFile);
	}
	if(outputFile != stdout){
		fclose(outputFile);
	}
	return 0;
}
