#include <stdio.h>
#include "strManip.h"
#include <string.h>
#include "fileUtils.h"

//function for character count
int characterCount (char *str)
{
	int len = strlen (str);

return len;
} 
//function for character count
int wordCount (char *str)
{
	int i = 0; //variable for words
	char * pch, tokens[3000];
	strcpy(tokens, str);
  	pch = strtok (tokens," .,!?;:\n\t");
  	while (pch != NULL)
  	{
  		i++; //increments after hitting a delimiter
    	pch = strtok (NULL, " .,!?;:\n\t");
  	}

return i;
}

void redact (char *str, char argv[])
{
	//declaring variables
	char temp[3000];
	strcpy(temp, ""); //clears it for the next call
	char cen[] = "REDACTED"; 
	char * pch;	
	char *p = str;

	//checks if the blacklisted is word is in the string
	while ((pch = strstr(p, argv)) != 0) 
	{
		strncat (temp,p,pch-p); //stores the string before the blacklisted word
		strcat(temp, cen); //adds redacted to it
		p = pch + strlen(argv); //moves the pointer next to the blacklisted word
	}
	strcat(temp, p); //adds the rest of the string
	strcpy(str, temp); //copies it to the original array
}