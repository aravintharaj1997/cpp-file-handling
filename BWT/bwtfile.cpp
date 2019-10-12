#include<iostream>
#include<string>
#include<cstdlib>
#include<list>
#include<iterator>
#include<fstream>
#include<algorithm>
using namespace std;
template <typename T>
struct node
{
	T data;
	node *next;	
};
template <typename T>
class clist
{
	public:
		node<T> *head;
		node<T> *tail;
	
		clist()
		{
			head=NULL;
			tail=NULL;
		}
		insert(T data)
		{
			node<T> *newnode=new node<T>;
			newnode->data=data;
			newnode->next=NULL;
			if(head==NULL)
			{
				head=newnode;
				head->next=head;
				tail=newnode;
			}
			else
			{
				tail->next=newnode;
				tail=tail->next;
				tail->next=head;
			}
		}
		clist<T>* nexthead()
		{
			clist<T> *temp=new clist<T>;
			temp->head=head->next;
			temp->tail=tail->next;
			return temp;
		}
		print()
		{
			node<T> *temp=head;
			if(head!=NULL)
			{
				do
				{
					cout<<temp->data<<" ";
					temp=temp->next;
				}while(temp!=head);
				cout<<"\n";
			}
		}
		list<T> listc()
		{
			list<T> ls;
			node<T> *temp=head;
			
			if(head!=NULL)
			{
				do
				{
					ls.push_back(temp->data);
					temp=temp->next;
				}while(temp!=head);
			}
			return ls;
			/*list<int>::iterator it; 
    		for(it = ls.begin(); it != ls.end(); ++it)
        		cout << *it<<' ';*/
		}
		T last()
		{
			return tail->data;
		}
		static bool compare(clist<T> *c1, clist<T> *c2)
		{
			/*list<T> l1,l2;
			l1=c1->listc();
			l2=c2->listc();
			return l1<l2;*/
			node<T> *str1=c1->head,*str2=c2->head;
			do
			{
				if(str1->data==str2->data)
				{
					//cout<<str1->data<<" "<<str2->data<<endl;
					str1=str1->next;
					str2=str2->next;
					continue;
				}
				if(str1->data<str2->data)
					return true;
				else
					return false;
				//cout<<str1->data<<" "<<str2->data<<"\t";
				str1=str1->next;
				str2=str2->next;
			}while(str1!=c1->head);
			return false;
		
		}
};

string getlinenew(ifstream &input)
{
	int i=0;
	char str[100000];
	string buf;
	char c;
	int e=1;
	if(input.eof())
	{
		return " ";
	}
	while(e!=0)
	{
		c=input.get();
		if ((c==-1)||(c==' ')||(c=='\n')||(c=='\t')||(c==';')||(c==':')||(c=='#')||(c=='='))
		{
			if(c==-1)
				str[i++]=' ';
			else
				str[i++]=c;
			str[i]='\0';
			e=0;
			
		}
		else
		{
			str[i++]=c;
		}
	}
	buf=str;
	return buf;
}

main()
{
	clist<string> *cl=new clist<string>,*temp;
	int i=0;
	long int count=0;
	/*cl->insert("aravintharaj");
	cl->insert("ajith");
	cl->insert("devisri");
	cl->insert("aravintharaj");
	cl->insert("ajith");*/
	string str;
	ifstream in;
	ofstream out,outi;
	in.open("8bwtfbwto.txt",ios::binary);
	out.open("8bwtfbwtobwt.txt",ios::binary);
	outi.open("8bwtfbwtobwti.txt",ios::binary);
	if(!in.is_open())
	{
		cout<<"Not open";
		exit(0);
	}
	str=getlinenew(in);
	//cout<<str<<endl;
	while(!in.eof())
	{
		count++;
		//getline(in,str,' ');
		str=getlinenew(in);
	//	cout<<str<<endl;
	}
	count++;
	cout<<"count = "<<count<<endl;
	in.clear();
	in.seekg(0,ios::beg);
	str=getlinenew(in);
	clist<string>** cy=new clist<string>*[count];
	cout<<"check";
	i=0;
	while(i<count)
	{
		//a[i++]=atoi(str.c_str());
		//a[i++]=str;
		
		//getline(in,str,' ');
		//cout<<str;
		cl->insert(str);
		str=getlinenew(in);
		i++;
	}
	cy[0]=cl;
	//cy[0]->print();
	cout<<"er";
	for(i=1;i<count;i++)
	{
		cy[i]=cy[i-1]->nexthead();
		//cy[i]->print();
	}
	cout<<"begin sort ";
	sort(cy,cy+count,clist<string>::compare);
	cout<<"After sort";
	cout<<"taril : ";
	for(i=0;i<count;i++)
	{
		//cy[i]=cy[i-1]->nexthead();
		out<<cy[i]->last();
	}
	for(i=0;i<count;i++)
	{
		if(cl==cy[i])
			break;
	}
	//cout<<"i="<<i;
	outi<<i;
}
