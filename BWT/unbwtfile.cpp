#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;
int co;
class stringarray
{
	private:
	//public:
		list<string> ls;
	public:
		longintarray(string a)
		{
			ls.clear();
			ls.push_back(a);
		}
		void operator = (string li)
		{
			//longintarray(li);
			ls.clear();
			ls.push_back(li);
		}
		string get(long int i)
		{
			list <string> :: iterator it; 
			it=ls.begin();
			advance(it,i);
			return *it;
		}
		stringarray operator +(stringarray &c)
		{
			stringarray n;
			n.ls.merge(ls);
			n.ls.merge(c.ls);
			return n;
		}
		bool operator <(stringarray &c)
		{
			return ls<c.ls;
		}
		bool operator <=(stringarray &c)
		{
			return ls<=c.ls;
		}
		bool operator >(stringarray &c)
		{
			return ls>c.ls;
		}
		bool operator >=(stringarray &c)
		{
			return ls>=c.ls;
		}
		bool operator ==(stringarray &c)
		{
			return ls==c.ls;
		}
		bool operator !=(stringarray &c)
		{
			return ls!=c.ls;
		}
		friend stringarray operator +(long int a, stringarray &c)
		{
			stringarray n;
			char buf[10];
			string str;
			ltoa(a,buf,10);
			str=buf;
			//n=a;
			n=buf;
			n.ls.merge(c.ls);
			return n;
		}
		friend stringarray operator +(string a, stringarray &c)
		{
			stringarray n;
			n=a;
			n.ls.merge(c.ls);
			return n;
		}
		friend stringarray operator +(stringarray &c,long int a)
		{
			stringarray n;
			char buf[10];
			string str;
			ltoa(a,buf,10);
			str=buf;
			n.ls.merge(c.ls);
			//n.ls.push_back(a);
			n.ls.push_back(str);
			return n;
		}
		friend stringarray operator +(stringarray &c,string a)
		{
			stringarray n;
			
			n.ls.merge(c.ls);
			n.ls.push_back(a);			
			return n;
		}
		friend ostream &operator << (ostream &out, stringarray &g)
		{
			list <string> :: iterator it; 
    		for(it = g.ls.begin(); it != g.ls.end(); ++it)
        		cout << *it<<' '; 
		}
		string pop_back()
		{
			string temp= ls.back();
			ls.pop_back();
			return temp;
		}
		push_front(string a)
		{
			ls.push_front(a);			
		}
		string back()
		{
			return ls.back();
		}
		int size()
		{
			return ls.size();
		}
};
template <typename T>
class Node 
{ 
public:
	Node *left; 
    long int key;
    T str;
    Node *right; 
    int height; 

	Node()
	{
		
	}
	~Node()
	{
		//cout<<"d";
	}
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
	Node* newNode(T str) 
	{	
    	struct Node* node=new struct Node;
    	node->key   = 0; 
    	node->str = str;
    	node->left   = NULL; 
    	node->right  = NULL; 
    	node->height = 1;
    	co=0;
    	return(node);    
	}
	Node *rightRotate(Node *y) 
	{ 
	    struct Node *x = y->left; 
	    struct Node *T2 = x->right; 
    	x->right = y; 
    	y->left = T2; 
    	y->height = max(heigh(y->left), heigh(y->right))+1; 
    	x->height = max(heigh(x->left), heigh(x->right))+1; 
	    return x; 
	} 
	Node *leftRotate(Node *x) 
	{ 
	    Node *y = x->right; 
	    Node *T2 = y->left; 
  
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
	Node* search(Node* root, T str)
	{
		if(root==NULL)
			return NULL;
		if(root->str==str)
			return root;
		if(str>root->str)
			return search(root->right,str);
		return search(root->left,str);
	}
	Node* insert(Node* node, T str) 
	{ 
    	if (node == NULL) 
	        return(newNode(str)); 
    	if (str < node->str) 
        	node->left  = insert(node->left, str); 
    	else if (str > node->str) 
        	node->right = insert(node->right,str); 
    	else
    	{
    		node->key=node->key+1;
    		co=node->key;
        	return node; 
    	}
  
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
	Node *minValueNode(Node* node) 
	{ 
	    Node* current = node; 
	    while (current->left != NULL) 
	        current = current->left; 
	  
	    return current; 
	} 
	Node* deleteNode(Node* root, T key) 
	{ 
	    if (root == NULL) 
	        return root; 
	    if ( key < root->str ) 
	        root->left = deleteNode(root->left, key); 
	    else if( key > root->str ) 
	        root->right = deleteNode(root->right, key); 
	    else
	    { 
	        if( (root->left == NULL) || (root->right == NULL) ) 
	        { 
	            Node *temp = root->left ? root->left : 
	                                             root->right; 
	            if (temp == NULL) 
	            { 
	                temp = root; 
	                root = NULL; 
	            } 
	            else
	             *root = *temp;
	            //free(temp); 
	            delete temp;
	        } 
	        else
	        { 
	            Node* temp = minValueNode(root->right);  
	            root->str = temp->str; 
	  			root->right = deleteNode(root->right, temp->str); 
	        } 
    } 
    if (root == NULL) 
      return root;
    root->height = 1 + max(heigh(root->left), heigh(root->right));
    int balance = getBalance(root); 
    if (balance > 1 && getBalance(root->left) >= 0) 
        return rightRotate(root); 
    if (balance > 1 && getBalance(root->left) < 0) 
    { 
        root->left =  leftRotate(root->left); 
        return rightRotate(root); 
    }
    if (balance < -1 && getBalance(root->right) <= 0) 
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
    return root; 
	}  
	void inOrder(Node *root) 
	{ 
    	if(root != NULL) 
    	{ 
        	inOrder(root->left); 
			cout<<root->key;
			cout<<" ";
			cout<<root->str;
			cout<<endl;		
        	inOrder(root->right); 
    	} 
	} 
	void deall(Node *root)
	{
		if(root!=NULL)
		{
			deall(root->left);
			deall(root->right);
			delete root;
			//return root;
		}	
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
	int i=0,j=0;
	long int count=0;
	string str;
	ifstream in,ini;
	ofstream out;
	Node<string> *d=NULL;
	stringarray *bwt,*t,*ori;
	in.open("8bwt.txt",ios::binary);
	ini.open("8bwti.txt",ios::binary);
	out.open("or.txt",ios::binary);
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
	//count++;
	cout<<"count = "<<count<<endl;
	in.clear();
	in.seekg(0,ios::beg);
	str=getlinenew(in);
	cout<<"check";
	i=0;
	bwt=new stringarray[count];
	t=new stringarray[count];
	ori=new stringarray[count];
	while(i<count)
	{
		bwt[i]=str;
		t[i]=str;
		//cout<<t[i];
		str=getlinenew(in);
		i++;
	}
	sort(t,t+count);
	cout<<"count = "<<count<<endl;
	int c;
	for(i=0;i<count;i++)
	{
		c=0;
		t[i]=t[i]+c;
		///cout<<t[i];
		//cout<<"\n";
		while(i<count-1&&t[i].get(0)==t[i+1].get(0))
		{
			c++;
			t[i+1]=t[i+1]+c;
			//cout<<t[i+1];
		//	cout<<"\n";
			i++;
		}
	}
	cout<<"count = "<<count<<endl;
	/*for(i=0;i<count;i++)
	{
		c=0;
		if(bwt[i].size()==1)
		{
			bwt[i]=bwt[i]+c;
			for(j=i+1;j<count;j++)
			{
				if(bwt[i].get(0)==bwt[j].get(0))
				{
					c++;
					bwt[j]=bwt[j]+c;
				}
			}
		}
	}*/
	for(i=0;i<count;i++)
	{
		d=d->insert(d,bwt[i].get(0));
		//cout<<co<<" ";
		bwt[i]=bwt[i]+co;
		//cout<<bwt[i];
		//cout<<"\n";
	}
	system("PAUSE");
	d->deall(d);
	//d=NULL;
	//delete d;
	system("PAUSE");
	cout<<"count = "<<count<<endl;
	getline(ini,str,' ');
	int l=atoi(str.c_str());
	cout<<"l="<<l<<" ";
	int l1,i1,j1, flag = 0;
	int num=count;
	/*for(i=0;i<count;i++)
	{
		ori[i]=t[l];
		for(j=0;j<count;j++)
		{
			if(bwt[l]==t[j])
				break;
		}
		l=j;
	}*/
	for(i=0;i<count;i++)
	{
		ori[i]=t[l];
		
		flag=0;
	   l1 = 0;
	   i1 = num-1;
	   while(l1 <= i1)
	   {
	      j1 = (l1+i1)/2;
	      if( t[j1] == bwt[l])
	      {
	    //printf("\nThe element %d is present at position %d in list\n",ele,j);
	     //    flag =1;
	     //cout<<"found ";
	         break;
	      }
	      else
	      	if(t[j1].get(0)==bwt[l].get(0))
	      	{
	      		 if(atoi(t[j1].get(1).c_str())<atoi(bwt[l].get(1).c_str()))
			   		l1 = j1+1;
			   	else
			   		i1 = j1-1;
			}
	        else if(t[j1].get(0) < bwt[l].get(0))
			{
			   	l1 = j1+1;
	       	}
	        else
	        {
	           i1 = j1-1;
	    	}
	   }
		//ori[i]=bwt[j];
		l=j1;
	}
	cout<<"file write "<<count;
	string temp=ori[1].get(0);
	temp.erase(temp.begin()+temp.length()-1,temp.end());
	ori[1]=temp;
	out<<ori[0].get(0);
	for(i=count-1;i!=0;i--){
		out<<ori[i].get(0);
		//cout<<" ";
	}
}
