#include"header.h"

void rm_single_commment(char *p)
{
	char *q, *r; int i=0;
	if(q = strstr(p,"//"))
	{
		while(q[i])
			q[i++] = 32;	
		q[i++] = 10;
		q[i] = 0;
	}
}

void rm_multi_comment(char *p)
{
	
	int i=0;
	char *q = strstr(p,"/*");
	while(q[i] != '*')
		q[i++] = 32;	
	q[i++] = 10;
	q[i] = 0;
}
void rm_comments(char *g)
{
	FILE *fp;
	fp = fopen(g, "r+");

	char ch; 
	int ll=0, c=0, s=0;
	while( (ch = fgetc(fp)) != EOF)
	{
		c++;
		s++;
		if(ch == 10)
		{
			if(c > ll)
				ll = c;
			c = 0;
		}
	}
	rewind(fp);

	char *p, *q; int l,i,j=0;
	p = malloc(ll+1);
	q = malloc(s+1);

	while( fgets(p, ll+1, fp) != 0)
	{
		l = strlen(p);

		rm_single_commment(p);
		
		fseek(fp, -l, SEEK_CUR);
		
		for(i=0; p[i]; i++)
			q[j++] = p[i];

		fputs(p,fp);
	}
	fclose(fp);	
	rm_multi_comment(q);
	fp = fopen(g, "w");
	fputs(q,fp);
	fclose(fp);
}
