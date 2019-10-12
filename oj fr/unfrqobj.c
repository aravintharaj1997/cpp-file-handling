#include<stdio.h>
#include<conio.h>
#include<string.h>
unfrqobj(FILE *o,FILE *f,FILE *out)
{
	char c;
	char nc;
	int i=0,j=0,k;
	char str[32000],count[32000];
	while((c=fgetc(o))!=EOF)
	{
		
		if ((c==-1)||(c==' ')||(c==',')||(c == '.')||(c =='\n')||(c=='\t'))
		{
			if(c!=-1)
			str[i++]=c;
			str[i]='\0';
			while(1)
			{
				nc=fgetc(f);
				if(nc==' ')
				{
					count[j]='\0';
					for(k=0;k<atoi(count);k++)
					{
						fputs(str,out);
						//printf("%s",str);
					}
					j=0;
					break;
				}
				else
				{
					count[j++]=nc;
				}
			}
			i=0;
		}
		else
		{
			str[i++]=c;
		}
	}
}
main()
{
	FILE *o,*f,*out;
	o=fopen("osort.txt","rb");
	f=fopen("fsort.txt","rb");
	out=fopen("outsort.txt","wb");
	unfrqobj(o,f,out);
	printf("successfully run");
}
