#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<list>
using namespace std;
class longintarray
{
	private:
	//public:
		list<long int> ls;
	public:
		longintarray()
		{
			
		}
		longintarray(long int a)
		{
			ls.clear();
			ls.push_back(a);
		}
		void operator = (long int li)
		{
			//longintarray(li);
			ls.clear();
			ls.push_back(li);
		}
		/*void operator =(const longintarray &li)
		{
			ls=li.ls;
		}*/
		longintarray operator +(longintarray &c)
		{
			longintarray n;
			n.ls.merge(ls);
			n.ls.merge(c.ls);
			return n;
		}
		bool operator <(longintarray &c)
		{
			return ls<c.ls;
		}
		bool operator <=(longintarray &c)
		{
			return ls<=c.ls;
		}
		bool operator >(longintarray &c)
		{
			return ls>c.ls;
		}
		bool operator >=(longintarray &c)
		{
			return ls>=c.ls;
		}
		bool operator ==(longintarray &c)
		{
			return ls==c.ls;
		}
		bool operator !=(longintarray &c)
		{
			return ls!=c.ls;
		}
		friend longintarray operator +(long int a, longintarray &c)
		{
			longintarray n;
			n=a;
			n.ls.merge(c.ls);
			return n;
		}
		friend longintarray operator +(longintarray &c,long int a)
		{
			longintarray n;
			n.ls.merge(c.ls);
			n.ls.push_back(a);
			return n;
		}
		friend ostream &operator << (ostream &out, longintarray &g)
		{
			list <long int> :: iterator it; 
    		for(it = g.ls.begin(); it != g.ls.end(); ++it)
        		cout << *it<<' '; 
		}
};
template <typename T>
struct Node 
{ 
	Node<T> *left; 
    long int key;
    T str;
    Node<T> *right; 
    int height; 
	int heigh(Node *N) 
	{ 
    	if (N == NULL) 
        	return 0; 
    	return N->height; 
	} 
	int max(int a, int b) 
	{ 
	    return (a > b)? a : b; 
	}
	Node* newNode(long int key,T str) 
	{	
    	struct Node* node=new struct Node;
    	node->key   = key; 
    	node->str = str;
    	node->left   = NULL; 
    	node->right  = NULL; 
    	node->height = 1;
    	return(node);    
	}
	struct Node *rightRotate(struct Node *y) 
	{ 
	    struct Node *x = y->left; 
	    struct Node *T2 = x->right; 
    	x->right = y; 
    	y->left = T2; 
    	y->height = max(heigh(y->left), heigh(y->right))+1; 
    	x->height = max(heigh(x->left), heigh(x->right))+1; 
	    return x; 
	} 
	struct Node *leftRotate(struct Node *x) 
	{ 
	    struct Node *y = x->right; 
	    struct Node *T2 = y->left; 
  
		y->left = x; 
		x->right = T2; 
    	x->height = max(heigh(x->left), heigh(x->right))+1; 
    	y->height = max(heigh(y->left), heigh(y->right))+1; 
	    return y; 
	} 
	int getBalance(Node *N) 
	{ 
    	if (N == NULL) 
        	return 0; 
    	return heigh(N->left) - heigh(N->right); 
	}
	Node* search(struct Node* root, T str)
	{
		if(root==NULL)
			return NULL;
		if(root->str==str)
			return root;
		if(str>root->str)
			return search(root->right,str);
		return search(root->left,str);
	}
	Node* insert(struct Node* node, long int key, T str) 
	{ 
    	if (node == NULL) 
	        return(newNode(key,str)); 
    	if (str < node->str) 
        	node->left  = insert(node->left, key,str); 
    	else if (str >= node->str) 
        	node->right = insert(node->right, key,str); 
    	else
        	return node; 
  
		node->height = 1 + max(heigh(node->left), heigh(node->right)); 

	    int balance = getBalance(node); 
	    if (balance > 1 && str < node->left->str) 
    	    return rightRotate(node); 
    	if (balance < -1 && str > node->right->str) 
        	return leftRotate(node); 
	    if (balance > 1 && str > node->left->str) 
    	{ 
        	node->left =  leftRotate(node->left); 
        	return rightRotate(node); 
    	}	
	    if (balance < -1 && str < node->right->str) 
    	{ 
        	node->right = rightRotate(node->right); 
        	return leftRotate(node); 
    	} 
	    return node; 
	} 
	void inOrder(struct Node *root) 
	{ 
    	if(root != NULL) 
    	{ 
        	//printf("%d ", root->key); 
        	inOrder(root->left); 
			cout<<root->key;
			cout<<" ";
			cout<<root->str;
			cout<<endl;		
        	inOrder(root->right); 
    	} 
	} 
	void deall(struct Node *root)
	{
		if(root!=NULL)
		{
			deall(root->left);
			deall(root->right);
			free(root);
		}
	}
};
main() 
{ 
	Node<string> *d=NULL,*se=NULL;
	Node<longintarray> *lia=NULL,*sei=NULL;
	longintarray li,tempi,pi;
	ifstream in;
	fstream out;
	ofstream outi;
	in.open("b64index.txt",ios::binary);
	out.open("cb64.txt",ios::binary|ios::out|ios::in);
	outi.open("pcb64.txt");
	char c;
	string ch;
	string p;
	string temp;
	int i=0;
	long int s;
	long int ci;
	long int k=0;
	long int max=0;
	in.seekg(0,ios::end);
	long t=in.tellg(),pos;
	in.seekg(0,ios::beg);
	if(!(in.is_open()))
	{
		cout<<"File not open";
		exit(0);
	}
	cout<<"check";
	for(i=0;i<256;i++)
	{
		ch=(char)i;
		d=d->insert(d,k++,ch);
	}
	k++;
	//d->inOrder(d);
	c=in.get();
	p=c;
	//cout<<"p="<<p<<endl;
	while(!(in.eof()))
	{
		//cout<<"true";
		c=in.get();
		if(in.eof())
			break;
		temp=p;
		temp=temp+c;
		//cout<<"temp = "<<temp<<endl;
		se=se->search(d,temp);
		if(se!=NULL)
			p=temp;
		else
		{
			//cout<<"se"<<endl;
			//se->inOrder(se);
			se=se->search(d,p);
			
			if(se!=NULL)
			{
				s=se->key;
				if(max<s)
				{
					max=s;
				}
				//out<<s;
				out.write((char *)&s,sizeof(long int));
				//pos=in.tellg();
				//cout<<pos<<" "<<t<<endl;
			}
			d=d->insert(d,k++,temp);
			temp=c;
			p=temp;
		}
		
	}
	se=se->search(d,p);
	if(se!=NULL)
	{
		//cout<<"se "<<endl;
		//cout<<se->key;
		s=se->key;
		//out<<s;
		out.write((char *)&s,sizeof(long int));
	}
	if(max<s)
		max=s;
	s=256;
	out<<s;
	if(max<256)
	{
		max=256;
	}
	cout<<"k="<<k<<endl;
	cout<<"max="<<max<<endl;
	d->deall(d);
	//free(d);
	d=NULL;
	//system("PAUSE");
	k=0;
	for(i=0;i<=max;i++)
	{
		li=i;
		//cout<<li;
		//cout<<endl;
		lia=lia->insert(lia,k++,li);
	}
	//lia->inOrder(lia);
	t=out.tellg();
	out.seekg(0,ios::beg);
	out.read((char *)&ci,sizeof(long int));
	pi=ci;
	while(!(out.eof()))
	{
		out.read((char *)&ci,sizeof(long int));
		//cout<<ci<<endl;
		
		if(out.eof())
			break;
		tempi=pi;
		tempi=tempi+ci;
		sei=sei->search(lia,tempi);
		if(sei!=NULL)
		{
			pi=tempi;
		}
		else
		{
			sei=sei->search(lia,pi);
			if(se!=NULL)
			{
				s=sei->key;
				if(max<s)
				{
					max=s;
				}
				outi.write((char *)&s,sizeof(long int));
				//pos=out.tellg();
				//cout<<pos<<" "<<t<<endl;
			}
			lia=lia->insert(lia,k++,tempi);
			tempi=ci;
			pi=tempi;
		}
	}
	sei=sei->search(lia,pi);
	if(se!=NULL)
	{
		s=sei->key;
		outi.write((char *)&s,sizeof(long int));
	}
	cout<<"max="<<max;
	in.close();
	out.close();
	outi.close();
} 
