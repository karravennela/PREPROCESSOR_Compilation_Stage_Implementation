#include"header.h"


void cpy_file(char *dest, char *src)
{
	FILE *sp, *dp;
	sp = fopen(src, "r");
	dp = fopen(dest, "r+");

	char ch; 
	int ll=0,c=0;
	while( (ch = fgetc(sp)) != EOF)
	{
		c++;
		if(ch == 10)
		{
			if(c > ll)
				ll = c;
			c = 0;
		}
	}
	rewind(sp);

	char *p;
	p = malloc(ll+1);

	while( fgets(p, ll+1, sp) != 0)
		fputs(p, dp);
	fclose(sp);
	fclose(dp);
}

void cpy_file_app(char *dest, char *src)
{
	FILE *sp, *dp;
	sp = fopen(src, "r");
	dp = fopen(dest, "a");

	char ch; 
	int ll=0,c=0;
	while( (ch = fgetc(sp)) != EOF)
	{
		c++;
		if(ch == 10)
		{
			if(c > ll)
				ll = c;
			c = 0;
		}
	}
	rewind(sp);

	char *p;
	p = malloc(ll+1);

	while( fgets(p, ll+1, sp) != 0)
		fputs(p, dp);
	fclose(sp);
	fclose(dp);
}
