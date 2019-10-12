#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
string getlinenew(ifstream &input)
{
	int i=0;
	char str[100000];
	string buf;
	char c;
	int e=1;
	if(input.eof())
	{
		return " ";
	}
	while(e!=0)
	{
		c=input.get();
		if ((c==-1)||(c==' ')||(c =='\n')||(c=='\t'))
		{
			if(c==-1){
				cout<<"EOF TRUE "<<endl;
				str[i++]=' ';
			}
			else
			{
				str[i++]=c;
			}
			str[i]='\0';
			e=0;
			
		}
		else
		{
			str[i++]=c;
		}
	}
	buf=str;
	return buf;
}
main()
{
	ifstream ins,ini;
	ofstream out;
	int *r,count=0,i=0,min;
	string *lis,temp;
	string str;
	ins.open("8ss.txt",ios::binary);
	ini.open("8ssi.txt",ios::binary);
	out.open("or.txt",ios::binary);
	getline(ini,str,' ');
	//str=getlinenew(ins);
	while(!ini.eof())
	{
		count++;
		getline(ini,str,' ');
		//str=getlinenew(ins);
	}
	//count++;
	lis=new string[count];
	r=new int[count];
	ini.clear();
	ini.seekg(0,ios::beg);
	//getline(ins,str,' ');
	str=getlinenew(ins);
	while(i<count)
	{
		//lis[i]=atoi(str.c_str());
		lis[i]=str;
		getline(ini,str,' ');
		r[i]=atoi(str.c_str());
		i++;
		//getline(ins,str,' ');
		str=getlinenew(ins);
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
	temp=lis[count-1];
	temp.erase(temp.begin()+temp.length()-1,temp.end());
	lis[count-1]=temp;
	for(i=0;i<count;i++)
	{
		out<<lis[i];
	}
}
