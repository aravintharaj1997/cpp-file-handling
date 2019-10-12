#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <iomanip>
using namespace std;
struct obfr
{
	string str;
	long int count;
};
void crle(ifstream &in,ofstream &outo,ofstream &outf)
{
	char buf[11];
	long int c,max=0;
	static int i,j,z,id;
	bool flag;
	string str,pstr;
	long n=0;
	obfr of[10];
//	in.clear();
	while(!in.eof())
	{
		for(i=1;i<=10;i++)
		{
			//n=0;
			in.read(buf,i);
			buf[i]='\0';
			pstr=buf;
			for(j=0;j<i;j++)
			buf[j]='\0';
			n+=pstr.length();
			in.read(buf,i);
			buf[i]='\0';
			str=buf;
			for(j=0;j<i;j++)
			buf[j]='\0';
			n+=str.length();
			c=1;
			while(pstr==str)
			{
				if(in.eof())
				{
					flag=1;
					break;
				}
				else
				{
					flag=0;
				}
				c++;
				in.read(buf,i);
				buf[i]='\0';
				str=buf;
				for(j=0;j<i;j++)
				buf[j]='\0';
				n+=str.length();
			}
			if(!in)
			{
				//cout<<" errot "<<in.gcount()<<endl;
				n=n+in.gcount();
			}
			if(in.eof())
			{
				flag=1;
			}
			if(in.bad())
			{
				n--;
			}
			of[i-1].str=pstr;
			of[i-1].count=c;
			in.clear();
			if(flag)
			{
				if(in)
					n=n-str.length();				
			}
		//	cout<<of[i-1].str<<" "<<of[i-1].count<<" "<<n<<endl;
		//	system("PAUSE");
			in.seekg(-n,ios::cur);
			n=0;
			str.clear();
			pstr.clear();
			for(j=0;j<i;j++)
			buf[j]='\0';
		}
		for(i=0;i<10;i++)
		{
			if(max<of[i].count)
			{
				id=i;
				max=of[i].count;
			}
		}
		//n=n+of[id].count;
		//n=n;
		//cout<<of[id].str<<" "<<of[id].count<<endl;
		outo<<of[id].str<<" ";
		outf<<of[id].count<<" ";
		in.seekg(of[id].count*of[id].str.length(),ios::cur);
		in.get();
		if(in.eof())
			break;
		in.seekg(-1,ios::cur);
		max=0;
		//break;
	}
}
main(int argc, char *argv[])
{
	ifstream in;
	ofstream outo,outf;
	in.open("bwt.txt");
	outo.open("crleo.txt");
	outf.open("crlef.txt");
	crle(in,outo,outf);
}
