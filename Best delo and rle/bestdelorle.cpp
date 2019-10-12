#include<iostream>
#include<fstream>
#include<cstdlib>
#include<limits.h>
#define loop 50
using namespace std;
int count,r;
int *a, *del,*ro,*rf;
delo(int deln)
{
	int i,j,pi,ni;
	
	char buf[10];
	string str;
	
	deln+=1;
	//reln+=1;
	/*if(reln>=count)
		return -1;*/
	for(i=0;i<deln;i++)
	{
		del[i]=a[i];
	}
	for(i=deln;i<count;i=i+deln)
	{
		for(j=0;j<deln;j++)
		{
			if((j+i)<count)
			{
				del[j+i]=a[j+i]-a[i+j-deln];
				//cout<<j+i<<" = "<<j+i<<" - "<<i+j-deln<<endl;
			}
		}
	}
}
long rle(int reln)
{
	int pi,rc=0,i,j,ni;
	long size=0;
	char buf[10];
	string str;
	reln+=1;
	pi=del[0];
	rc=1;
	r=0;
	if(reln>=count)
		return -1;
	for(i=0;i<reln;i++)
	{
		for(j=i;j<count;j=j+reln)
		{
			//cout<<j<<" ";
			if(j!=0)
			{
				ni=del[j];
				if(pi!=ni)
				{
					ro[r]=pi;
					rf[r]=rc;
					r++;
					pi=ni;
					rc=1;
				}
				else
				{
					rc++;
				}
			}
		}
	}
	ro[r]=pi;
	rf[r]=rc;
	r++;
	/*for(i=0;i<r;i++)
	{
		cout<<ro[i]<<" ";
	}
	cout<<endl;
	for(i=0;i<r;i++)
	{
		cout<<rf[i]<<" ";
	}
	cout<<endl;*/
	for(i=0;i<r;i++)
	{
		itoa(ro[i],buf,10);
		str=buf;
		size+=str.length();
		size++;
	}
	return size;
}
main()
{
	ifstream in;
	ofstream outo,outf;
	string str;
	int i=0,j,mi,mj;
	long int min=LONG_MAX;
	long int tsize[50][50];
	in.open("nindex0.txt");
	outo.open("ob.txt");
	outf.open("of.txt");
	getline(in,str,' ');
	count=0;
	while(!in.eof())
	{
		count++;
		getline(in,str,' ');
	}
	cout<<"count = "<<count<<endl;
	a=new int[count];
	del=new int[count];
	ro=new int[count];
	rf=new int[count];
	in.clear();
	in.seekg(0,ios::beg);
	getline(in,str,' ');
	while(!in.eof())
	{
		a[i]=atoi(str.c_str());
		i++;
		getline(in,str,' ');
	}
	/*for(i=0;i<count;i++)
		cout<<a[i]<<" ";*/
	//cout<<delo(0,0);
	/*for(i=0;i<count;i++)
		out<<del[i]<<" ";*/
	for(i=0;i<loop;i++)
	{
		delo(i);
		for(j=0;j<loop;j++)
		{
			cout<<i<<"\t"<<j<<" ";
			
			tsize[i][j]=rle(j);
			cout<<tsize[i][j]<<endl;
		}
	}
	for(i=0;i<loop;i++)
	{
		for(j=0;j<loop;j++)
		{
			//cout<<tsize[i][j]<<endl;
			
			if(tsize[i][j]<min&&tsize[i][j]!=-1)
			{
				min=tsize[i][j];
				mi=i;
				mj=j;
			}
		}
	}
	cout<<"mi = "<<mi<<" mj = "<<mj<<"min = "<<min<<endl;
	delo(mi);
	rle(mj);
	outo<<mi<<" "<<mj<<" ";
	for(i=0;i<r;i++)
	{
		outo<<ro[i]<<" ";
		outf<<rf[i]<<" ";
	}
}
