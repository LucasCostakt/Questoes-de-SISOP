#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

void strolower(char * str) 
{
  	// Convert string to upper case
  	while (*str) {
    		*str = tolower((unsigned char) *str);
    		str++;
  	}

}
int main () 
{
	char texto[1024];

	gets(texto);
	strolower(texto);
	puts(texto);
}

