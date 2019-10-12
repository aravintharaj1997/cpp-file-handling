#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<list>
#include<iterator>
#include<algorithm>
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
		long int get(long int i)
		{
			list <long int> :: iterator it; 
			it=ls.begin();
			advance(it,i);
			return *it;
		}
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
    	//cout<<"constured";
	}
    ~Node()
    {
    	
    	//cout<<"destroyed ";
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
	    Node *x = y->left; 
	    Node *T2 = x->right; 
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
	inOrder(struct Node *root) 
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
	deall(struct Node *root)
	{
		if(root!=NULL)
		{
			//cout<<"true";
			deall(root->left);
			deall(root->right);
			//free(root);
			//cout<<"free";
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
selectionsort(int *a,int *ji,long int start, long int end)
{
	Node<longintarray> *d=NULL,*se=NULL;
	long int i=0,j,id,val,t;
	longintarray lia,temp;
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
		id=temp.get(1);
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
	d->deall(d);
	delete d;
	delete se;
}
main() 
{ 
	
	long int i=0,j,id,val,t,k,rn,p,start,end,loop=1;
	int *a,*ji;
	long int count=0;
	string str;
	char buf[10];
	
	ifstream in;
	ofstream out,outi;
	in.open("index8.txt");
	out.open("index8ss.txt");
	outi.open("index8si.txt");
	rn=1000000;
	s:
	cout<<endl<<"loop="<<loop<<endl;
	count=0;
	if(!in.is_open())
	{
		cout<<"Not open";
		exit(0);
	}
	getline(in,str,' ');
	while(!in.eof())
	{
		count++;
		getline(in,str,' ');
	}
	cout<<"count = "<<count<<endl;
	if(loop==1)
	{
	a=new int[count];
	ji=new int[count];
	}
	in.clear();
	in.seekg(0,ios::beg);
	i=0;
	getline(in,str,' ');
	while(!in.eof())
	{
		a[i++]=atoi(str.c_str());
		getline(in,str,' ');
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
	
	
	p=count/rn;
	if(count%rn!=0)
		p++;
	/*rn=100/p;
	if(100%p!=0)
		rn++;*/
	printf("\nSorted Array : \n");
	for(k=0;k<p;k++)
	{
		cout<<endl<<k<<endl;
		start=rn*k;
		end=rn+(rn*k);
		if(end>count)
			end=end-((rn+(rn*k))-count);
		selectionsort(a,ji,start,end);
	}
	//selectionsort(a,ji,0,7200);
	//selectionsort(a,ji,7200,count);
	cout<<"code write";
	for(i=0;i<count;i++)
	{
		out<<a[i]<<" ";
		outi<<ji[i]<<" ";
	}
	out.close();
	outi.close();
	in.clear();
	in.seekg(0,ios::beg);
	//delete a;
//	delete ji;
	switch(loop)
	{
		case 1: out.open("index8ss1.txt");
				outi.open("index8si1.txt");
				rn=500000;
				loop++;
				goto s;
		case 2: out.open("index8ss2.txt");
				outi.open("index8si2.txt");
				rn=100000;
				loop++;
				goto s;
	}
	in.close();
} 
