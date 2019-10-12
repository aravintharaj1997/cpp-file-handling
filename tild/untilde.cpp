#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<string>
using namespace std;
string unstrcle(string str1,string str2)
{
	string str,strn;
	int num,i;
	for (i = 0; i < str2.size(); ++i) 
	{ 
         if (!(str2[i] < '0' || str2[i] > '9') )
        {   
            strn+=str2[i];
            //cout<<str2[i];
            //i--; 
        }
        else
        {
        	break;
		}
    }
    if(i!=0)
    {
    cout<<endl<<i<<endl;
    	str=str1.substr(0,atoi(strn.c_str()))+str2.substr(i);
    //cout<<strn<<"\t" << str; 
	}
	else
	{
		str=str2;
	}
	cout<<str<<" ";
	return str;
}
untilde(ifstream &in,ofstream &out)
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
		sc=unstrcle(ps,s);
		out<<ps<<" ";
		ps=sc;
	}
}
main()
{
	ifstream in;
	ofstream out;
	string ps;
	in.open("otest.txt");
	out.open("out.txt");
	//in.get();
	//getline(in,ps,' ');
	untilde(in,out);
}
