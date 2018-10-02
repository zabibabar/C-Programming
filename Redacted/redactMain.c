/*Zabeeh Ullah Babar. This program manipulates text from an input file 
using the string library.*/
#include <stdio.h>
#include <string.h>
#include "fileUtils.h"
#include "strManip.h"

int main(int argc, char *argv[]) 
{
	char str[3000], chars[3000], words[3000];
	//Reads the input file onto str file
	readFromFile(str, argv[1]);
	
	//Gets the character count and writes it to the output file
	int charCount = characterCount (str);
	sprintf(chars, "CHARACTER COUNT : %d\n", charCount);
	writeToFile(chars, argv[2], 0);

	//Gets the word count and appends it to the output file
	int wCount = wordCount (str);
	sprintf(words, "WORD COUNT : %d\n\n", wCount);	
	writeToFile(words, argv[2], 1);

	//Reads every arguments and redacts it in the string
	for (int i = 3; i < argc; i++)
	{
		redact (str, argv[i]);
	}
	
	//Appends the redacted string in the output file
	writeToFile(str, argv[2], 1);
	return 0;
}