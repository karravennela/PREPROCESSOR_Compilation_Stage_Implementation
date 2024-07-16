//Prgm to create string with "filename.i"

#include"header.h"

void dot_i(char *g, char *v, int l)
{
	
	char i;
	for(i=0; i<l+1; i++)
		g[i] = v[i]; //abc.c
	g[l-1] = 'i';
}
