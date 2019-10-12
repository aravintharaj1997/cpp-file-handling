#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
main()
{
	ifstream in;
	ofstream out;
	string str, pstr;
	in.open("delo.txt");
	out.open("or.txt");
	int t1,t2;
	getline(in,pstr,' ');
	t1=atoi(pstr.c_str());
	out<<t1<<" ";
	while(!in.eof())
	{
		getline(in,str,' ');
		if(in.eof())
			break;
		t2=atoi(str.c_str());
		out<<t2+t1<<" ";
		t1=t2+t1;
	}
}
