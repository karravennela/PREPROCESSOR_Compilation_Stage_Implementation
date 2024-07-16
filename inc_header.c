#include"header.h"

int size_fname(char *p)
{
	int i=0;
	if(*p == '<') //<stdio.h>
		while(p[i++] != '>');
	else if(*p == '"')
		while(p[++i] != '"');
	else
	{
		printf("\033[31;1mFATAL ERROR: \033[0mNo such file or directory\n");
		return 0;	
	}
	return i; 
}
void get_path(char *f, char *lib, int flag)
{
	int i=0, j=0; 
	if(flag == 1) 
		lib[i++] = '.';
	char *p= "/usr/include/";
	while(*p)
		lib[i++] = *p++;
	while(*f)
		lib[i++] = *f++; 		
	lib[i] = 0;			
}
void get_fname(char *p, char *f) //stdio.h>
{
	int i=0;
	if(*p == '<') //<stdio.h>
		while(p[++i] != '>')
			f[i-1] = p[i];
	else if(*p == '"')
		while(p[++i] != '"')
			f[i-1] = p[i];
	f[i-1] = 0;
}
void fetch(char *lib, char *g) //g->abc.i
{			
	FILE *fp;
	fp = fopen(g, "a");
	cpy_file_app(g,lib); //abc.i "/usr/include/stdio.h/"
	fclose(fp);
}
void inc_header(char *g, char *doti)
{
	FILE *fp;
	fp = fopen(g, "r"); //g- temp.i
	
	int c=0,s=0,ll=0,i,j,k=0;
	char ch,*p,*q,*r;

	while((ch=fgetc(fp)) != EOF)
	{
		c++;
		s++;
		if(ch == 10)
		{
			if(c>ll)
				ll = c;
			c=0;
		}
	}
	rewind(fp);
	
	p = malloc(ll+1);
	q = malloc(s+1);

	int l, flag=0;
	
	while( (fgets(p, ll+1, fp) ) != 0)
	{
		if(r = strstr(p,"#include"))
		{		
			r = r + 8;
			while(*r)
			{	                                                      
				if(*r == ' ')				
				{
					r++;
					continue;
				}
				else if(*r == '<')
				{	
					l = size_fname(r);
					char f[l+2],  lib[16+l];					
					get_fname(r,f);	
					get_path(f,lib,flag);
					fetch(lib,doti);
					break; 
				}
				else if(*r == '"')
				{
					l = size_fname(r);
					char f[l+2],lib[16+l];				
					get_fname(r,f);
					flag = 1;
					get_path(f,lib,flag);
					fetch(lib,doti);
					break; 
				}
				else
				{
					printf("\033[31;1mERROR: \033[0m#include expects ""FILENAME"" or <FILENAME>\n");
					return;
				}
				r++;			
			}
		}
	}
	rewind(fp);
	
	while(fgets(p,ll+1,fp) != 0)
	{
		if(r = strstr(p,"#include"))
			continue;
		else
		{
			for(i=0; p[i]; i++)
				q[k++] = p[i];
		}
	}
	q[k] = 0;
	fclose(fp);
	
	fp = fopen(g, "w");
	fputs(q,fp);
	fclose(fp);
	free(p);
	free(q);	
}
