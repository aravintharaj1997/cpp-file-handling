#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;
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
		/*void operator =(const longintarray &li)
		{
			ls=li.ls;
		}*/
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
		friend ostream &operator << (ostream &out, stringarray &g)
		{
			list <string> :: iterator it; 
    		for(it = g.ls.begin(); it != g.ls.end(); ++it)
        		cout << *it<<' '; 
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
	Node* insert(Node* node, long int key, T str) 
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
			//free(root);
			delete root;
		}
	}
};
reverseArray(int *arr, int start, int end) 
{ 
	end--;
    while (start < end) 
    { 
        int temp = arr[start];  
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    }  
} 
selectionsort(string *a,int *ji,long int start, long int end)
{
	Node<stringarray> *d=NULL,*se=NULL;
	long int i=0,j,id;
	string val,t;
	stringarray lia,temp;
	for(i=start;i<end;i++)
	{
		lia=a[i];
		lia=lia+i;
		d=d->insert(d,i,lia);
	}
	cout<<"Tree Builded successfully "<<endl;
	for(i=start;i<end;i++)
	{
		//cout<<i<<" ";
		se=d->minValueNode(d);
		temp=se->str;
		val=temp.get(0);
		id=atol(temp.get(1).c_str());
		temp=a[i];
		temp=temp+i;
		if(id==i)
		{
			d=d->deleteNode(d,temp);
		}
		else
		{
			d=d->deleteNode(d,temp);
			temp=a[id];
			temp=temp+id;
			d=d->deleteNode(d,temp);
			t=a[i];
			a[i]=a[id];
			a[id]=t;
			temp=a[id];
			temp=temp+id;
			d=d->insert(d,i,temp);
		}
		ji[i]=id-i;
		//ji[i]=id;
	}
}
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
	long int i=0,j,id,val,t;
	string *a;
	int *ji;
	long int count=0;
	string str;
	char buf[10];
	
	ifstream in;
	ofstream out,outi;
	in.open("8.txt",ios::binary);
	out.open("8ss.txt",ios::binary);
	outi.open("8in.txt",ios::binary);
	if(!in.is_open())
	{
		cout<<"Not open";
		exit(0);
	}
	//getline(in,str,' ');
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
	a=new string[count];
	ji=new int[count];
	in.clear();
	in.seekg(0,ios::beg);
	
	//getline(in,str,' ');
	str=getlinenew(in);
	while(i<count)
	{
		//a[i++]=atoi(str.c_str());
		a[i++]=str;
		//getline(in,str,' ');
		str=getlinenew(in);
	}
	cout<<"Assign successfully a"<<endl;
	//reverseArray(a, 0, count);
	//reverseArray(a, 0, 7200);
	//reverseArray(a, 7200, count);
	//cout<<"Reversed"<<endl;
	//d->inOrder(d);
	/*for(i=0;i<count;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(i=0;i<count;i++)
	{
		cout<<ji[i]<<" ";
	}*/
	selectionsort(a,ji,0,count);
	//selectionsort(a,ji,0,7200);
	//selectionsort(a,ji,7200,count);
	cout<<"code write";
	for(i=0;i<count;i++)
	{
		out<<a[i];//<<" ";
		outi<<ji[i]<<" ";
	}
	in.close();
} 
