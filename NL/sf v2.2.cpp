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
    std::ifstream file( path_to_file, std::ios::binary ) ; // open in binary mode

    char c ;
    while( file.get(c) ) // read byte by byte
        bitstring += std::bitset<BITS_PER_BYTE>( byte(c) ).to_string() ; // append as string of '0' '1'

    return bitstring ;
}
void write_bits( std::string bitstring, const char* path_to_file )
{
    // pad with zeroes to make it represent an integral multiple of bytes
    while( bitstring.size()% BITS_PER_BYTE ) bitstring += '0' ;

    std::ofstream file( path_to_file, std::ios::binary ) ; // open in binary mode

    for( std::size_t i = 0 ; i < bitstring.size() ; i += BITS_PER_BYTE )
    {
        // convert each sequence of '0' or '1' to a byte
        byte b = std::bitset<BITS_PER_BYTE>( bitstring.substr( i, BITS_PER_BYTE ) ).to_ulong() ;
        file << b ; // and write it
    }
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
	if(!str.empty())
	file<<str;
	file.close();
}
main()
{
	char bitname[32];
	char buffer[sizeof(long int)*8+1];
	char c;
	bool flag=0;
	ifstream in;
	ofstream out;
	string str,temp;
	int i,fmax,d;
	long int li,max=0;
	for(i=0;i<32;i++)
	{
		if(i<26)
			bitname[i]='A'+i;
		else
			bitname[i]='A'+i+6;
	}
	bitname[i]='\0';
	in.open("asdel2.txt",ios::binary);
	out.open("sinput.txt",ios::binary);
	//i=3;
	//itoa(i,buffer,2);
	//str=buffer;
	//cout<<str;
	start:
	while(!(in.eof()))
	{
		c=in.get();
		if(c==' ')
		{
			//cout<<str<<endl;
			li=atol(str.c_str());
			if(li<0)
			{
				//cout<<li<<" ";
				li=li*-1;
			}
			if(li>max)
				max=li;
			//cout<<li<<endl;
			str.clear();
		}
		else
		{
			str+=c;
		}
	}
	in.clear();
	in.seekg(0,ios::beg);
	c='a';
	cout<<max<<endl;
	itoa(max,buffer,2);
	str=buffer;
	//cout<<str.length();
	string bitstring[str.length()]="";
	fmax=str.length();
	fmax++;
	out.put((char)fmax);
	fmax--;
	str.clear();
	while(!(in.eof()))
	{
		c=in.get();
		if(c==' ')
		{
			//cout<<str<<endl;
			li=atol(str.c_str());
			if(li<0)
			{
				//cout<<li;
				li=li*-1;
				out.put('-');
			}
			ltoa(li,buffer,2);
			//str=buffer;
			temp=buffer;
			d=pow(2,temp.length()-1);
			//d+=1;
			if(d!=1)
			li=li-d;
			ltoa(li,buffer,10);
			str=buffer;
			str+=c;
			
			
			bitstring[temp.length()-1]+=str;
			//cout<<str<<endl<<bitstring[temp.length()-1]<<endl;
			out.put(bitname[temp.length()-1]);
			//cout<<li<<endl;
			str.clear();
		}
		else
		{
			str+=c;
		}
	}
	cout<<endl;
	for(i=0;i<fmax;i++)
	{
		ltoa(i,buffer,10);
		str=buffer;
		str+=".txt";
		cout<<str<<endl;
		temp=bitstring[i];
		write_str(temp,str.c_str(),flag);
		str.clear();
	}
	if(fmax!=1)
	{
		in.close();
		out.close();
		fmax--;
		ltoa(fmax,buffer,10);
		str=buffer;
		str+=".txt";
		in.open(str.c_str(),ios::binary|ios::in);
		str="s"+str;
		flag=1;
		out.open(str.c_str(),ios::binary);
		max=0;
		goto start;
	}
}
