#include<stdio.h>
astoin(FILE *in, FILE *out)
{
	int value,i=0;
	char c, str[50];
	fseek(in,0,SEEK_SET);
	while(!feof(in))
	{
		c=fgetc(in);
		if((c==' ')||(c=='\n')||(c=='\t')||(c==EOF))
		{
			str[i]='\0';
			value=atoi(str);
			putw(value,out);
			i=0;
			str[i]='\0';
		}
		else
		{
			str[i++]=c;
		}
	}
}
int pmeand(FILE *in, FILE *q, FILE *r)
{
	int pmean=0,nmean=0,temp,quo,rem, num, pc=0,nc=0,v;
	fseek(in,0,SEEK_SET);
	while(!feof(in))
	{
		v=getw(in);
		if(feof(in))
		break;
		if(v>=0)
		{
			pmean+=v;
			if(v!=0)
			pc++;
		}
		else
		{	
			v*=-1;
			nmean+=v;
			nc++;
		}
	}
	if(pc==0)
	goto pe;
	pmean=pmean/pc;
	pe:
	if(nc==0)
	goto ne;
	nmean=nmean/nc;
	ne:
	if(pmean==1)
	return 1;
	putw(pmean,q);
	putw(nmean,q);
	fseek(in,0,SEEK_SET);
	num=getw(in);
	while(1)
	{
		if(feof(in))
		break;
		if(num>=0)
		{
			quo=num/pmean;
			rem=num%pmean;
		}
		else
		{
			quo=num/nmean;
			rem=num%nmean;
		}
		putw(quo,q);
		putw(rem,r);
		num=getw(in);
	}	
	return 0;
}
fo(FILE *in, FILE *o, FILE *f)
{
	int pi,ni,count=0;
	fseek(in,0,SEEK_SET);
	fseek(o,0,SEEK_SET);
	fseek(f,0,SEEK_SET);
	pi=getw(in);
	count++;
	while(feof(in)==0)
	{
		ni=getw(in);
		if(pi!=ni)
		{
			putw(pi,o);
			putw(count,f);
			pi=ni;
			count=1;
		}
		else
		{
			count++;
		}
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
main()
{
	FILE *in,*cin, *r1,*r2,*r3,*r4,*r5,*r6,*r7,*r8,*q1,*q2,*q3,*q4,*q5,*q6,*q7,*q8,*f1,*f2,*f3,*f4,*f5,*f6,*f7,*o1,*o2,*o3,*o4,*o5,*o6,*o7;
	int flag=0,i=0;
	in=fopen("test.txt","rb");
	cin=fopen("cin.txt","wb+");
	r1=fopen("r1.txt","wb+");
	r2=fopen("r2.txt","wb+");
	r3=fopen("r3.txt","wb+");
	r4=fopen("r4.txt","wb+");
	r5=fopen("r5.txt","wb+");
	r6=fopen("r6.txt","wb+");
	r7=fopen("r7.txt","wb+");
	r8=fopen("r8.txt","wb+");
	q1=fopen("q1.txt","wb+");
	q2=fopen("q2.txt","wb+");
	q3=fopen("q3.txt","wb+");
	q4=fopen("q4.txt","wb+");
	q5=fopen("q5.txt","wb+");
	q6=fopen("q6.txt","wb+");
	q7=fopen("q7.txt","wb+");
	q8=fopen("q8.txt","wb+");
	f1=fopen("f1.txt","wb+");
	f2=fopen("f2.txt","wb+");
	f3=fopen("f3.txt","wb+");
	f4=fopen("f4.txt","wb+");
	f5=fopen("f5.txt","wb+");
	f6=fopen("f6.txt","wb+");
	f7=fopen("f7.txt","wb+");
	o1=fopen("o1.txt","wb+");
	o2=fopen("o2.txt","wb+");
	o3=fopen("o3.txt","wb+");
	o4=fopen("o4.txt","wb+");
	o5=fopen("o5.txt","wb+");
	o6=fopen("o6.txt","wb+");
	o7=fopen("o7.txt","wb+");
	astoin(in, cin);
	flag=pmeand(cin, q1, r1);
	if(flag)
	goto end;
	i++;
	fo(q1, o1, f1);
	flag=pmeand(r1, q2, r2);
	if(flag)
	goto end;
	i++;
	fo(q2, o2, f2);
	flag=pmeand(r2, q3, r3);	
	if(flag)
	goto end;
	i++;
	fo(q3, o3, f3);
	flag=pmeand(r3, q4, r4);
	if(flag)
	goto end;
	i++;
	fo(q4, o4, f4);
	flag=pmeand(r4, q5, r5);
	if(flag)
	goto end;
	i++;
	fo(q5, o5, f5);
	flag=pmeand(r5, q6, r6);
	if(flag)
	goto end;
	i++;
	fo(q6, o6, f6);
	flag=pmeand(r6, q7, r7);
	if(flag)
	goto end;
	i++;
	fo(q7, o7, f7);
	if(flag)
	goto end;
	i++;
	flag=pmeand(r7, q8, r8);
	if(flag)
	goto end;
	i++;
	end:
	//	printf("%d",i);
		switch(i)
		{
			case 1: 
				fclose(q2);
				fclose(r2);
				fclose(f1);
				fclose(o1);
				remove("q2.txt");
				remove("r2.txt");
				remove("f1.txt");
				remove("o1.txt");
			case 2:
				fclose(q3);
				fclose(r3);
				fclose(f2);
				fclose(o2);
				remove("q3.txt");
				remove("r3.txt");
				remove("f2.txt");
				remove("o2.txt");
			case 3:
				fclose(q4);
				fclose(r4);
				fclose(f3);
				fclose(o3);
				remove("q4.txt");
				remove("r4.txt");
				remove("f3.txt");
				remove("o3.txt");
			case 4:
				fclose(q5);
				fclose(r5);
				fclose(f4);
				fclose(o4);
				remove("q5.txt");
				remove("r5.txt");
				remove("f4.txt");
				remove("o4.txt");
			case 5:
				fclose(q6);
				fclose(r6);
				fclose(f5);
				fclose(o5);
				remove("q6.txt");
				remove("r6.txt");
				remove("f5.txt");
				remove("o5.txt");
			case 6:
				fclose(q7);
				fclose(r7);
				fclose(f6);
				fclose(o6);
				remove("q7.txt");
				remove("r7.txt");
				remove("f6.txt");
				remove("o6.txt");
			case 7:
				fclose(q8);
				fclose(r8);
				fclose(f7);
				fclose(o7);
				remove("q8.txt");
				remove("r8.txt");
				remove("f7.txt");
				remove("o7.txt");
		}
}
