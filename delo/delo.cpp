#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
main(int argc, char *argv[])
{
	ifstream in;
	ofstream out;
	string str, pstr;
	in.open(argv[1]);
	out.open(argv[2]);
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
		out<<t2-t1<<" ";
		t1=t2;
	}
}
