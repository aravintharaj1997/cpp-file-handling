#include<stdio.h>
#include<conio.h>
intoas(FILE *in, FILE *out)
{
	int value;
	char str[50];
	fseek(in,0,SEEK_SET);
	value=getw(in);
	while(!feof(in))
	{
		itoa(value,str,10);
		fputs(str,out);
		value=getw(in);
		if(!feof(in))
		fputc(' ',out);
	}
}
unpmeand(FILE *q,FILE *r, FILE *out)
{
	int pmean, nmean,num,quo,rem;
	fseek(q,0,SEEK_SET);
	fseek(r,0,SEEK_SET);
	pmean=getw(q);
	nmean=getw(q);
	quo=getw(q);
	rem=getw(r);
	while(feof(q)==0)
	{
		if(quo>=0&&rem>=0)
		{
			num=(pmean*quo)+rem;
			putw(num,out);
		}
		else
		{
			num=(nmean*quo)+rem;
			putw(num,out);
		}
		quo=getw(q);
		rem=getw(r);
	}
}
unfo(FILE *o, FILE *f,FILE *out)
{
	int oj,count;
	fseek(o,0,SEEK_SET);
	fseek(f,0,SEEK_SET);
	fseek(out,0,SEEK_SET);
	oj=getw(o);
	count=getw(f);
	while(feof(o)==0)
	{
		while(count>0)
		{
			putw(oj,out);
			count--;
		}
		oj=getw(o);
		count=getw(f);
	}
}
pf(FILE *p)
{
	int d;
	printf("\n");
	fseek(p,0,SEEK_SET);
	while(1)
	{
		d=getw(p);
		if(feof(p))
		break;
		printf("%d ",d);
	}
}
void main()
{
	FILE *out,*cout, *ur1,*ur2,*ur3,*ur4,*ur5,*ur6,*ur7,*ur8,*uq1,*uq2,*uq3,*uq4,*uq5,*uq6,*uq7,*uq8,*f1,*f2,*f3,*f4,*f5,*f6,*f7,*o1,*o2,*o3,*o4,*o5,*o6,*o7;
	int flag=0,i=0;
	out=fopen("out.txt","wb+");
	cout=fopen("cout.txt","wb+");
	f1=fopen("f1.txt","rb");
	f2=fopen("f2.txt","rb");
	f3=fopen("f3.txt","rb");
	f4=fopen("f4.txt","rb");
	f5=fopen("f5.txt","rb");
	f6=fopen("f6.txt","rb");
	f7=fopen("f7.txt","rb");
	o1=fopen("o1.txt","rb");
	o2=fopen("o2.txt","rb");
	o3=fopen("o3.txt","rb");
	o4=fopen("o4.txt","rb");
	o5=fopen("o5.txt","rb");
	o6=fopen("o6.txt","rb");
	o7=fopen("o7.txt","rb");
	void *f[]={f1,f2,f3,f4,f5,f6,f7};
	for(i=0;i<8;i++)
		if(f[i]==NULL)
			break;
	switch(i)
	{
		case 8:
		case 7: 
			ur8=fopen("r8.txt","rb");
			uq8=fopen("q8.txt","rb");
			ur7=fopen("ur7.txt","wb+");
			uq7=fopen("uq7.txt","wb+");
			unpmeand(uq8,ur8, ur7);
			unfo(o7, f7,uq7);
		case 6: 
			if(i==6)
			{
				ur7=fopen("r7.txt","rb");
				uq7=fopen("q7.txt","rb");
			}
			ur6=fopen("ur6.txt","wb+");
			uq6=fopen("uq6.txt","wb+");
			unpmeand(uq7,ur7, ur6);
			unfo(o6, f6,uq6);
		case 5: 
			if(i==5)
			{
				ur6=fopen("r6.txt","rb");
				uq6=fopen("q6.txt","rb");
			}
			ur5=fopen("ur5.txt","wb+");
			uq5=fopen("uq5.txt","wb+");
			unpmeand(uq6,ur6, ur5);
			unfo(o5, f5,uq5);
		case 4: 
			if(i==4)
			{
				ur5=fopen("r5.txt","rb");
				uq5=fopen("q5.txt","rb");
			}
			ur4=fopen("ur4.txt","wb+");
			uq4=fopen("uq4.txt","wb+");
			unpmeand(uq5,ur5, ur4);
			unfo(o4, f4,uq4);
		case 3: 
			if(i==3)
			{
				ur4=fopen("r4.txt","rb");
				uq4=fopen("q4.txt","rb");
			}
			ur3=fopen("ur3.txt","wb+");
			uq3=fopen("uq3.txt","wb+");
			unpmeand(uq4,ur4, ur3);
			unfo(o3,f3,uq3);
		case 2: 
			if(i==2)
			{
				ur3=fopen("r3.txt","rb");
				uq3=fopen("q3.txt","rb");
			}
			ur2=fopen("ur2.txt","wb+");
			uq2=fopen("uq2.txt","wb+");
			unpmeand(uq3,ur3, ur2);
			unfo(o2, f2,uq2);
		case 1: 
			if(i==1)
			{
				ur2=fopen("r2.txt","rb");
				uq2=fopen("q2.txt","rb");
			}
			ur1=fopen("ur1.txt","wb+");
			uq1=fopen("uq1.txt","wb+");
			unpmeand(uq2,ur2, ur1);
			unfo(o1, f1,uq1);
	}
	unpmeand(uq1,ur1,cout);
	intoas(cout, out);
}
