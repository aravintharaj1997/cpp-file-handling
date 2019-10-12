#include<iostream>
#include<fstream>
#include<string>
using namespace std;
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
	Node* search(struct Node* root, long int key)
	{
		if(root==NULL)
			return NULL;
		if(root->key==key)
			return root;
		if(key>root->key)
			return search(root->right,key);
		return search(root->left,key);
	}
	Node* insert(struct Node* node, long int key, T str) 
	{ 
    	if (node == NULL) 
	        return(newNode(key,str)); 
    	if (key < node->key) 
        	node->left  = insert(node->left, key,str); 
    	else if (key >= node->key) 
        	node->right = insert(node->right, key,str); 
    	else
        	return node; 
  
		node->height = 1 + max(heigh(node->left), heigh(node->right)); 

	    int balance = getBalance(node); 
	    if (balance > 1 && key < node->left->key) 
    	    return rightRotate(node); 
    	if (balance < -1 && key > node->right->key) 
        	return leftRotate(node); 
	    if (balance > 1 && key > node->left->key) 
    	{ 
        	node->left =  leftRotate(node->left); 
        	return rightRotate(node); 
    	}	
	    if (balance < -1 && key < node->right->key) 
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
			cout<<root->key<< " "<<root->str<<endl;		
        	inOrder(root->right); 
    	} 
	} 
};
main()
{
	struct Node<string> *d=NULL,*se=NULL;
	ifstream in;
	ofstream out;
	in.open("jcompress.txt",ios::binary);
	out.open("output.txt",ios::binary);
	int i=0;
	long int o,n,k=0,pos,t;
	string s,ch;
	char c;
	for(i=0;i<256;i++)
	{
		ch=(char)i;
		d=d->insert(d,k++,ch);
	}
	k++;
	in.seekg(0,ios::end);
	t=in.tellg();
	in.seekg(0,ios::beg);
	in.read((char *)&o,sizeof(long int));
	cout<<o;
	se=se->search(d,o);
	out<<se->str;
	while(!(in.eof()))
	{
		in.read((char *)&n,sizeof(long int));
		if(in.eof())
			break;
		se=se->search(d,n);
		if(se==NULL)
		{
			se=se->search(d,o);
			s=se->str;
			s=s+ch;
		}
		else
		{
			s=se->str;
		}
		out<<s;
		pos=in.tellg();
		cout<<pos<<" "<<t<<endl;
		c=s.at(0);
		se=se->search(d,o);
		s=se->str;
		ch=c;
		s=s+ch;
		d=d->insert(d,k++,s);
		o=n;
	}
	out.close();
	in.close();
}
