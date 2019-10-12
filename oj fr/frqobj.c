#include<stdio.h>
#include<conio.h>
#include<string.h>
frqobj(FILE *in, FILE *o,FILE *f)
{
	char c,temp[10];
	int count=0,i=0;
	char pstr[32000],str[32000];
	pstr[0]='\0';
	while(feof(in)==0)
	{
		c=fgetc(in);
		if ((c==-1)||(c==' ')||(c=='\n')||(c=='\t')||(c==';')||(c==':')||(c=='#')||(c=='='))
		{
			if(c!=-1)
			str[i++]=c;
			str[i]='\0';
			if(pstr[0]=='\0')
			{
				strcpy(pstr,str);
				count++;
			}
			else
			{
				if(strcmp(pstr,str)==0)
				{
					count++;
				}
				else
				{
					itoa(count,temp,10);
					fputs(temp,f);
					fputc(' ',f);
					fputs(pstr,o);
					//fputc(' ',o);
					strcpy(pstr,str);
					count=1;
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
	FILE *in,*f,*o;
	in=fopen("8bwtfbwt.txt","rb");
	o=fopen("8bwtfbwto.txt","wb");
	f=fopen("8bwtfbwtf.txt","wb");
	frqobj(in, o,f);
	printf("successfully run");
}
