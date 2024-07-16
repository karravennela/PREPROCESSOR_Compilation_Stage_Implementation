#include"header.h"


void replace(char *q, char *v3, int i, int k, int diff)
{
	int j; 
	if(diff<0)  //if diff=-1, then dec strlen by 1
	{
		for(j=k+diff; q[j]; j++)
			q[j] = q[j-diff];
	}
	else //diff=1, then inc strlen by 1
	{	
		for(j=k; q[j]; j++);
		q[j+diff] = 0;
		for(j; j>k; j--)
			q[j] = q[j-diff];		
	}
	for(j=0; i<k+diff; i++,j++)
		q[i] = v3[j];
}
void rp_macro(char *g)
{
	FILE *fp;
	fp = fopen(g, "r");

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

	char v2[ll],v3[ll];
	while(fgets(p,ll+1,fp) != 0)
	{
		if(r = strstr(p,"#define"))
			continue;
		else
		{
			for(i=0; p[i]; i++)
				q[k++] = p[i];
		}
	}
	q[k] = 0;
	rewind(fp);

	while(fgets(p,ll+1,fp) != 0)
	{
		if(r = strstr(p,"#define"))
		{
			r = r + 8;
			//pf w1-replace
			j=0;
			while(*r != 32)
				v2[j++] = *r++;
			v2[j] = 0;

			//printf w2-replace with
			j=0;
			while(*++r != 10)
				v3[j++] = *r;
			v3[j] = 0;

			//v2-w1 pf  v3-w2 printf

			int x = strlen(v2), y = strlen(v3), diff;

			for(i=0; q[i]; i++)
				if(q[i] == v2[0])
				{
					for(j=1,k=i+1; v2[j]; j++,k++)
						if(q[k] != v2[j])
							break;
					if(v2[j] == 0)
					{
						diff = y-x;
						replace(q,v3,i,k,diff);
					}
				}
		}
	}
	fclose(fp);
	fp = fopen(g,"w");
	fputs(q,fp);
	fclose(fp);
	
	free(p);
	free(q);
}

