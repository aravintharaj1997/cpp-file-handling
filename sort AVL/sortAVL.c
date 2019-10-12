#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#include<errno.h>
struct Node 
{ 
	long int key; 
	struct Node *left;
	char *str; 
	struct Node *right; 
	int height; 
};
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
struct Node *search(struct Node* root, char key[]) 
{ 
    if(root==NULL||strcmp(key,root->str)==0)
       return root; 
    if(strcmp(key,root->str)>0)
      return search(root->right, key); 
     return search(root->left, key); 
}
struct Node* insert(struct Node* node, int key,char data[]) 
{ 
	if (node == NULL) 
		return(newNode(key,data)); 
	if(strcmp(data,node->str)<0)
		node->left = insert(node->left, key,data); 
	else// if(strcmp(data,node->str)>0)
		node->right = insert(node->right, key,data); 
	//else 
	//	node->right = insert(node->right, key,data); 
	node->height = 1 + max(height(node->left), height(node->right)); 
	int balance = getBalance(node); 
	if(balance > 1 && strcmp(data,node->left->str)<0)
		return rightRotate(node); 
	if(balance < -1 && strcmp(data,node->right->str)>=0)
		return leftRotate(node); 
	if(balance > 1 && strcmp(data,node->left->str)>=0)
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 
	if(balance < -1 && strcmp(data,node->right->str)<0)
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 
	return node; 
}
void inOrder(struct Node *root,FILE *s,FILE *i) 
{ 
	if(root != NULL) 
	{ 
		//printf("%d ", root->key); 
		
		char temp[20];
		inOrder(root->left,s,i); 
		//printf("%s",root->str);
		fputs(root->str,s);
		ltoa(root->key,temp,10);
		fputs(temp,i);
		fputc(' ',i);
		inOrder(root->right,s,i); 
	} 
}
void main()
{
	FILE *input,*sort,*index;
	struct Node *s=NULL;
	static char str[]={};
	input=fopen("bwts.txt","rb");
	sort=fopen("sort8.txt","wb");
	index=fopen("index8.txt","wb");
	int i=0;
	char c;
	long int k=0,pos,t;
	fseek(input,0,SEEK_END);
	t=ftell(input);
	fseek(input,0,SEEK_SET);
	while(c!=EOF)
	{
		c=fgetc(input);
		
		if ((c==-1)||(c==' ')||(c=='\n')||(c=='\t')||(c==';')||(c==':')||(c=='#')||(c=='='))
		{
			if(c==-1)
			str[i++]=' ';
			else
			str[i++]=c;
			str[i]='\0';
			//printf("%ld ",k);
			//printf("%s\n",str);
			s=insert(s,k++,str);
			//pos=ftell(input);
			//inOrder(s,sort,index);
			//printf("\n");
			//system("PAUSE");
			//printf("%ld %ld\n",pos,t);
			i=0;
		}
		else
		{
			str[i++]=c;
		}
	}
	inOrder(s,sort,index);
	fclose(input);
	fclose(index);
	fclose(sort);
}
