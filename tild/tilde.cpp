#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<string>
using namespace std;
string strcle(string str1,string str2)
{
	string strc;
	char buf[10];
	int i;
	for(i=0;str1[i]==str2[i];i++)
	{
		if(i>str1.length()-1)
		{
			break;
		}
	}
	//cout<<endl<<i<<endl;
	itoa(i,buf,10);
	if(i!=0)
	{
		strc=buf;
	}//strc=str1.substr(--i);
	//strc="~"+str1;
	strc+=str1.substr(i);
	cout<<i<<"\t\""<<str1<<"\"\t\""<<str2<<"\"\t"<<strc<<endl;
	return strc;
}
tilde(ifstream &in,ofstream &out)
{
	string ps, s,sc;
	getline(in,ps,' ');
	while(!in.eof())
	{
		getline(in,s,' ');
		if(in.eof())
		{
			out<<ps<<' ';
			break;
		}
		sc=strcle(ps,s);
		ps=s;
		out<<sc<<" ";
	}
}
/*tilder(ifstream &in,ofstream &out,string ps)
{
	string s;
	if(!in.eof())
	{
		getline(in,s,' ');
		//cout<<s<<" ";
		if(in.eof())
		{
			//cout<<strcle(ps,s)<<endl;
			//cout<<ps<<endl;
			out<<ps<<" ";
			return 0;
		}
		//cout<<s;
		tilder(in,out,s);
		//cout<<strcle(ps,s)<<endl;
		out<<strcle(ps,s)<<" ";
	}
}*/
main()
{
	ifstream in;
	ofstream out;
	string ps;
	in.open("test.txt");
	out.open("otest.txt");
	in.get();
	//getline(in,ps,' ');
	tilde(in,out);
	//tilder(in,out,ps);
}
