#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<limits.h>
#include<fstream>
using namespace std;
char b64[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|'};
string base64(int n)
{
	string b64n,btemp,temp;
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
		if(i!=-1)
		{
			temp+=btemp.at(i);
			i--;
		}
		//cout<<temp<<endl;
		reverse(temp.begin(),temp.end());
		//cout<<strtol(temp.c_str(),NULL,2)<<endl;
		b64n+=b64[strtol(temp.c_str(),NULL,2)];
	}
	reverse(b64n.begin(),b64n.end());
	//cout<<b64n;
	return b64n;	
}
main()
{
	ifstream in;
	ofstream out,out1;
	string str,gstr;
	int num;
	in.open("8ssi.txt");
	out.open("b648ssi.txt");
	out1.open("b648ssisl.txt");
	while(!in.eof())
	{
		getline(in,str,' ');
		if(in.eof())
		break;
		num=atoi(str.c_str());
		gstr=base64(num);
		out<<gstr;//<<" ";
		out1<<gstr.length();
	}
}
