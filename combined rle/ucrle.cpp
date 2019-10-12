#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<sstream>
#include<string>
using namespace std;
uncrle(ifstream &ino,ifstream &inf,ofstream &out)
{
	char buf[11];
	string str,c;
	int co;
	while(!ino.eof())
	{
		getline(ino,str,' ');
		getline(inf,c,' ');
		co=atoi(c.c_str());
		cout<<str<<" "<<c<<endl;
		while(co>0)
		{
			out<<str;
			co--;
		}
	}
}
main()
{
	ofstream out;
	ifstream ino,inf;
	out.open("testout.txt");
	ino.open("otest.txt");
	inf.open("ftest.txt");
	uncrle(ino,inf,out);
}
