#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
//enum b32{A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,AA,AB,AC,AD,AE,AF,AG,AH,AI,AJ,AK,AL,AM,AN,AO,AP,AQ,AR,AS,AT,AU,AV};
char b32[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V'};
int unbase32(string str)
{
	int n,i,j;
	char b[64];
	string btemp,temp;
	for(i=0;i<str.length();i++)
	{
		//b32n=temp.c_str();
		for(j=0;j<32;j++)
		{
			if(b32[j]==str.at(i))
			{
				break;
			}
		}
		itoa(j,b,2);
		//cout<<b<<endl;
		temp.clear();
		temp=b;
		//cout<<temp<<endl;
		for(j=temp.length();j<5;j++)
		{
			//cout<<"1";
			temp="0"+temp;
		}
		//cout<<temp;
		//cout<<b<<" ";
		// cout<<b32n;
		btemp+=temp;
	}
	n=strtol(btemp.c_str(),NULL,2);
	//cout<<n;
	return n;
}
main()
{
	ifstream in;
	ofstream out;
	string str;
	char numstr[20];
	int num;
	in.open("b32index.txt");
	out.open("out.txt");
	while(!in.eof())
	{
		getline(in,str,' ');
		if(in.eof())
		break;
		num=unbase32(str);
		itoa(num,numstr,10);
		out<<numstr;
		out<<" ";
	}
}
