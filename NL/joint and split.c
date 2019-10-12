#include<stdio.h>
#include<string.h>
void jointfun(FILE *joint,FILE *f[])
{
	char c,temp[5];
	int i;
	int max;
	max=24;
	//printf("%d",max);
	for(i=0;i<max;i++)
	{
		c=fgetc(f[i]);
		while(c!=EOF)
		{
			fputc(c,joint);
			c=fgetc(f[i]);
			//count++;
		}
		if(i!=max-1)
		fputs("-1",joint);
	}
}
void split(FILE *joint)
{
	char filename[20]="us",temp[10];
	char c,pc;
	FILE *s=NULL;
	int i=1;
	fseek(joint,0,SEEK_SET);
	c='1';
	itoa(i,temp,10);
	strcat(temp,".txt");
	strcat(filename,temp);
	//printf("%s\n",filename);
	printf("%s\n",filename);
	s=fopen(filename,"wb");
	i++;
	strcpy(filename,"us");
	while(c!=EOF)
	{
		//printf("ture");
		c=fgetc(joint);
		if(c==EOF)
				break;
		if(c=='-')
		{
			pc=c;
			c=fgetc(joint);
			
			if(c=='1')
			{
				fclose(s);
				itoa(i,temp,10);
				strcat(temp,".txt");
				strcat(filename,temp);
				printf("%s\n",filename);
				s=fopen(filename,"wb+");
				i++;
				strcpy(filename,"us");
				//continue;
			}
			else
			{
				fputc(pc,s);
				fputc(c,s);
			}
		}
		else{
		fputc(c,s);
	}
	}
}
main()
{
	FILE *joint,*f[23];
	int i;
	f[0]=fopen("s1.txt","rb");
	f[1]=fopen("s2.txt","rb");
	f[2]=fopen("s3.txt","rb");
	f[3]=fopen("s4.txt","rb");
	f[4]=fopen("s5.txt","rb");
	f[5]=fopen("s6.txt","rb");
	f[6]=fopen("s7.txt","rb");
	f[7]=fopen("s8.txt","rb");
	f[8]=fopen("s9.txt","rb");
	f[9]=fopen("s10.txt","rb");
	f[10]=fopen("s11.txt","rb");
	f[11]=fopen("s12.txt","rb");
	f[12]=fopen("s13.txt","rb");
	f[13]=fopen("s14.txt","rb");
	f[14]=fopen("s15.txt","rb");
	f[15]=fopen("s16.txt","rb");
	f[16]=fopen("s17.txt","rb");
	f[17]=fopen("s18.txt","rb");
	f[18]=fopen("s19.txt","rb");
	f[19]=fopen("s20.txt","rb");
	f[20]=fopen("s21.txt","rb");	
	f[21]=fopen("s22.txt","rb");
	f[22]=fopen("s23.txt","rb");
	f[23]=fopen("s24.txt","rb");
	joint=fopen("joint.txt","wb+");
	jointfun(joint,f);
	for(i=0;i<24;i++)
		fclose(f[i]);
	split(joint);
}
