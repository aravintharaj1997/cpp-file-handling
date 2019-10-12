#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
main()
{
	ifstream ins,ini;
	ofstream out;
	int *lis,*r,count=0,i=0,min,temp;
	string str;
	ins.open("index8ss.txt");
	ini.open("index8si.txt");
	out.open("or.txt");
	getline(ins,str,' ');
	while(!ins.eof())
	{
		count++;
		getline(ins,str,' ');
	}
	lis=new int[count];
	r=new int[count];
	ins.clear();
	ins.seekg(0,ios::beg);
	getline(ins,str,' ');
	while(!ins.eof())
	{
		lis[i]=atoi(str.c_str());
		getline(ini,str,' ');
		r[i]=atoi(str.c_str());
		i++;
		getline(ins,str,' ');
	}
	for(i=0;i<count;i++)
		r[i]+=i;
	for(i=count-1;i>=0;i--)
	{
		min=r[i];
		temp=lis[i];
		lis[i]=lis[min];
		lis[min]=temp;
	}
	for(i=0;i<count;i++)
	{
		out<<lis[i]<<" ";
	}
}
