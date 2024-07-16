//Prgm to open .c file

#include"header.h"

void main(int gc, char **gv)
{
	if(gc != 2)
	{
		printf("Usage: ./preprocessor file_name...\n");
		return;
	
	}
	FILE *sp, *dp, *temp;

	sp = fopen(gv[1], "r");
	
	if(sp == 0)
	{
		printf("FILE NOT FOUND\n");
		return;
	}
	fclose(sp);

	//length of gv[1]
	int l = strlen(gv[1]);

	//string with .i name 
	char g[l+1];
	dot_i(g ,gv[1], l);
   	
	//printf("%s\n",g);
	
	//create new .i file	
	dp = fopen(g,"w");
	fclose(dp);
	
	//cpy .c content to .i
	cpy_file(g,gv[1]);

	//remove comments
	rm_comments(g);
	
	//replace macros
	rp_macro(g);
	
	//cpy .i content to temp file
	temp = fopen("temp.i", "w");
	cpy_file("temp.i",g);
	fclose(temp);	
	
	//include header file content
	dp = fopen(g,"w");
	fclose(dp);
	inc_header("temp.i",g); 
	
	//cpy temp.i to abc.i
	cpy_file_app(g,"temp.i");
	remove("temp.i");
}
