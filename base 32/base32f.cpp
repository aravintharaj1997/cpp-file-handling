#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<limits.h>
#include<fstream>
using namespace std;
char b32[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V'};
string base32(int n)
{
	string b32n,btemp,temp;
	int i;
	char b[64];
	itoa(n,b,2);
	btemp=b;
	//cout<<b<<endl;
	for(i=btemp.length()-1;i!=-1;)
	{
		temp.clear();
		if(i!=-1)
		{
			temp+=btemp.at(i);
			i--;
		}
		if(i!=-1)
		{
			temp+=btemp.at(i);
			i--;
		}
		if(i!=-1)
		{
			temp+=btemp.at(i);
			i--;
		}
		if(i!=-1)
		{
			temp+=btemp.at(i);
			i--;
		}
		if(i!=-1)
		{
			temp+=btemp.at(i);
			i--;
		}
		//cout<<temp<<endl;
		reverse(temp.begin(),temp.end());
		//cout<<strtol(temp.c_str(),NULL,2)<<endl;
		b32n+=b32[strtol(temp.c_str(),NULL,2)];
	}
	reverse(b32n.begin(),b32n.end());
	//cout<<b32n;
	return b32n;	
}
main()
{
	ifstream in;
	ofstream out;
	string str;
	int num;
	in.open("index8.txt");
	out.open("b32index8.txt");
	while(!in.eof())
	{
		getline(in,str,' ');
		if(in.eof())
		break;
		num=atoi(str.c_str());
		out<<base32(num);
		out<<" ";
	}
}
