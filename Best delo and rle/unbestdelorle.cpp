#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int count,r;
int *a, *del,*ro,*rf;
undelo(int deln,int reln)
{
	int i,j,rc=0;
	deln+=1;
	reln+=1;
	for(i=0;i<r;i++)
	{
		count+=rf[i];
	}
	a=new int[count];
	del=new int[count];
	for(i=0;i<reln;i++)
	{
		for(j=i;j<count;j=j+reln)
		{
			//cout<<j<<" ";
			if(rf[rc]==0)
			{
				rc++;
			}
			a[j]=ro[rc];
			rf[rc]--;
		}
	}
	for(i=0;i<deln;i++)
	{
		//cout<<a[i]<<" ";
		del[i]=a[i];
	}
	for(i=deln;i<count;i=i+deln)
	{
		for(j=0;j<deln;j++)
		{
			if((j+i)<count)
			{
				del[j+i]=a[j+i]+del[i+j-deln];
				//cout<<j+i<<" = "<<j+i<<" - "<<i+j-deln<<endl;
			}
		}
	}
	/*for(i=0;i<count;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(i=0;i<count;i++)
		cout<<del[i]<<" ";*/
}
main()
{
	ifstream ino,inf;
	ofstream out;
	string str;
	int i=0,mi,mj;
	ino.open("ob.txt");
	inf.open("of.txt");
	out.open("or.txt");
	count=0;
	r=0;
	getline(ino,str,' ');
	while(!ino.eof())
	{
		r++;
		getline(ino,str,' ');
	}
	cout<<"r = "<<r<<endl;
	//a=new int[count];
	//del=new int[count];
	ino.clear();
	ino.seekg(0,ios::beg);
	getline(ino,str,' ');
	mi=atoi(str.c_str());
	getline(ino,str,' ');
	mj=atoi(str.c_str());
	r=r-2;
	ro=new int[r];
	rf=new int[r];
	//r=r-2;
	getline(ino,str,' ');
	while(!ino.eof())
	{
		ro[i]=atoi(str.c_str());
		getline(inf,str,' ');
		rf[i]=atoi(str.c_str());
		i++;
		getline(ino,str,' ');
	}
/*	for(i=0;i<r;i++){
		cout<<ro[i]<<" ";
	}
	cout<<endl;
	for(i=0;i<r;i++){
		cout<<rf[i]<<" ";
	}*/
	undelo(mi,mj);
	/*getline(in,str,' ');
	while(!in.eof())
	{
		a[i]=atoi(str.c_str());
		i++;
		getline(in,str,' ');
	}*/
	/*for(i=0;i<count;i++)
		cout<<a[i]<<" ";*/
	//undelo(2);
	for(i=0;i<count;i++)
		out<<del[i]<<" ";
}
