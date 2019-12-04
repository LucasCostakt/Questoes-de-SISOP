#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

void stroupper(char * str) 
{
  	// Convert string to upper case
  	while (*str) {
    		*str = toupper((unsigned char) *str);
    		str++;
  	}

}
int main () 
{
	char texto[1024];

	gets(texto);
	stroupper(texto);
	puts(texto);
}

