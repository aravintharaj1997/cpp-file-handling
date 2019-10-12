#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
int putl(long int l,FILE *in)
{
	if(fwrite(&l,sizeof(long int),1,in)>0)
		return 1;
	return 0;
}
long int getl(FILE *in)
{
	long int l;
	if(fread(&l,sizeof(long int),1,in)>0)
		return l;
	return 0;
}
struct Node 
{ 
	int key; 
	struct Node *left;
	char *str; 
	struct Node *right; 
	int height; 
}; 
int max(int a, int b); 
int height(struct Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 
int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 
struct Node* newNode(int key,char data[]) 
{ 
	struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL;
	node->str=malloc(sizeof(char [strlen(data)+1]));
	strcpy(node->str,data);
	node->height = 1; 
	return(node); 
} 
struct Node *rightRotate(struct Node *y) 
{ 
	struct Node *x = y->left; 
	struct Node *T2 = x->right; 
	x->right = y; 
	y->left = T2; 
	y->height = max(height(y->left), height(y->right))+1; 
	x->height = max(height(x->left), height(x->right))+1; 
	return x; 
} 
struct Node *leftRotate(struct Node *x) 
{ 
	struct Node *y = x->right; 
	struct Node *T2 = y->left; 
	y->left = x; 
	x->right = T2; 
	x->height = max(height(x->left), height(x->right))+1; 
	y->height = max(height(y->left), height(y->right))+1; 
	return y; 
} 
int getBalance(struct Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 
struct Node* insert(struct Node* node, int key,char data[]) 
{ 
	if (node == NULL) 
		return(newNode(key,data)); 
	if (key < node->key) 
		node->left = insert(node->left, key,data); 
	else if (key > node->key) 
		node->right = insert(node->right, key,data); 
	else
		return node; 
	node->height = 1 + max(height(node->left), height(node->right)); 
	int balance = getBalance(node); 
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 
	return node; 
} 
struct Node* search(struct Node* root, long int key) 
{ 
    if (root == NULL || root->key == key) 
       return root; 
    if (root->key < key) 
       return search(root->right, key); 
    return search(root->left, key); 
}
void inOrder(struct Node *root,FILE *o) 
{ 
	if(root != NULL) 
	{ 
		inOrder(root->left,o); 
		fputs(root->str,o);
		//printf("%s",root->str);
		inOrder(root->right,o); 
	} 
}
main()
{
	struct Node *s=NULL;
	static char str[]={};
	char temp[10];
	FILE *output,*sort,*index;
	output=fopen("output.txt","wb");
	sort=fopen("sort.txt","rb");
	index=fopen("index.txt","rb");
	int i=0,j=0;
	char c,nc;
	long int k,pos,t;
	fseek(sort,0,SEEK_END);
	t=ftell(sort);
	fseek(sort,0,SEEK_SET);
	while(c!=EOF)
	{
		c=fgetc(sort);
		
		if ((c==' ')||(c==',')||(c == '.')||(c =='\n')||(c=='\t'))
		{
			str[i++]=c;
			str[i]='\0';
			nc=fgetc(index);
			while(nc!=' ')
			{
				temp[j++]=nc;
				nc=fgetc(index);
			}
			temp[j]='\0';
			k=atol(temp);
			s=insert(s,k,str);
			pos=ftell(sort);
			printf("%ld %ld\n",pos,t);
			i=0;
			j=0;
		}
		else
		{
			str[i++]=c;
		}
	}
	inOrder(s,output);
	fseek(output,-1,SEEK_END);
	ftruncate(fileno(output), ftello(output));
	fclose(output);
	fclose(index);
	fclose(sort);
}
