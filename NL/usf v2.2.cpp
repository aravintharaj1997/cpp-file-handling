#include <limits>
#include <bitset>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#define BITS_PER_BYTE std::numeric_limits<byte>::digits

typedef unsigned char byte;
using namespace std;
std::string read_bits( const char* path_to_file )
{
    std::string bitstring ;
    std::ifstream file( path_to_file, std::ios::binary ) ; 

    char c ;
    while( file.get(c) ) 
        bitstring += std::bitset<BITS_PER_BYTE>( byte(c) ).to_string() ; 

    return bitstring ;
}
void write_bits( std::string bitstring, const char* path_to_file )
{
    
    while( bitstring.size()% BITS_PER_BYTE ) bitstring += '0' ;

    std::ofstream file( path_to_file, std::ios::binary ) ; 

    for( std::size_t i = 0 ; i < bitstring.size() ; i += BITS_PER_BYTE )
    {
        
        byte b = std::bitset<BITS_PER_BYTE>( bitstring.substr( i, BITS_PER_BYTE ) ).to_ulong() ;
        file << b ; 
    }
}
string read_str(const char* path_to_file)
{
	string str;
	ifstream file(path_to_file,ios::binary);
	char c;
	while(file.get(c))
		str+=c;
	return str;
}
void reverseStr(string& str) 
{ 
    int n = str.length();
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 
long int binaryToDecimal(string n) 
{ 
    string num = n; 
    long int dec_value = 0; 
    int base = 1; 
      
    int len = num.length(); 
    for (int i=len-1;i>=0;i--) 
    { 
        if (num[i] == '1')         
            dec_value += base; 
        base = base * 2; 
    } 
      
    return dec_value; 
} 
void write_str(string str,const char* path_to_file,bool flag)
{
	ofstream file;
	if(flag){
		file.open(path_to_file, ios::binary|ios::app);
		file<<" -1 ";
	}
	else
		file.open(path_to_file, ios::binary);
	file<<str;
	file.close();
}
main()
{
	char bitname[32];
	char buffer[sizeof(long int)*8+1];
	char c;
	bool flag;
	ifstream in;
	ofstream out;
	string str,temp;
	int i,fmax,max,d;
	long int li,t,pos;
	for(i=0;i<32;i++)
	{
		if(i<26)
			bitname[i]='A'+i;
		else
			bitname[i]='A'+i+6;
	}
	bitname[i]='\0';
	//cout<<bitname;
	in.open("s1.txt",ios::binary);
	out.open("out.txt",ios::binary);
	
	//in.seekg(0,ios::end);
	//t=in.tellg();
	//in.clear();
	//in.seekg(0,ios::beg);
	c=in.get();
	fmax=c;
	fmax--;
	cout<<fmax;
	//fmax++;
	string bitstring[fmax]="";
	//cout<<endl;
	for(i=0;i<fmax;i++)
	{
		//cout<<i<<" i"<<endl;
		ltoa(i,buffer,10);
		str=buffer;
		str+=".txt";
		bitstring[i]=read_str(str.c_str());
		reverseStr(bitstring[i]);
		temp=bitstring[i];
		bitstring[i]=bitstring[i].substr(bitstring[i].find(" 1- "));
		bitstring[i]=bitstring[i].substr(4);
		reverseStr(bitstring[i]);
		write_str(bitstring[i],str.c_str(),0);
		bitstring[i]=temp;
		bitstring[i].resize(bitstring[i].find(" 1- "));
	//	cout<<bitstring[i]<<endl;
	}
	c=in.get();
	str.clear();
	cout<<"While start";
	while(!(in.eof()))
	{
		//cout<<c;
		//c='b';
		if(c=='-')
		{
			//str="-";
			//out<<'-';
			flag=1;
			c=in.get();
			continue;
		}
		else if(c<'a')
			max=c-'A';
		else
			max=c-6-'A';
		for(i=0;;i++)
		{
			if(bitstring[max].at(bitstring[max].length()-1)!=' ')
			{
				str+=bitstring[max].at(bitstring[max].length()-1);
				bitstring[max].erase(bitstring[max].size()-1, 1);
			}
			else
			{
					bitstring[max].erase(bitstring[max].size()-1, 1);
					break;
			}		
			//bitstring[max].erase(0,1);
			//bitstring[max]=bitstring[max].substr(1,bitstring[max].length()-1);
		}
		//cout<<str<<" ";
		//pos=in.tellg();
		//cout<<pos<<" "<<t<<endl;
		//li=binaryToDecimal(str);
		//cout<<li<<" ";
		li=atol(str.c_str());
		d=pow(2,max);
		li=li+d;
		li--;
		if(flag)
		{
			li=li*-1;
			flag=0;
		}
		ltoa(li,buffer,10);
		str=buffer;
		//cout<<str<<" ";
		out<<str;
		out<<' ';
		str.clear();
		c=in.get();
	}
}
