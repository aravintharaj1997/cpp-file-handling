#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

/*
OpenMP implementation example
Details of implementation/tutorial can be found here: http://madhugnadig.com/articles/parallel-processing/2017/02/25/parallel-computing-in-c-using-openMP.html
*/

clock_t t, end;
double cpu_time_used;

// Structure for enabling reduction on the index of elements
struct Compare { int val; int index; };
// Custom reduction for finding hte index of the max element.
#pragma omp declare reduction(maximum : struct Compare : omp_out = omp_in.val > omp_out.val ? omp_in : omp_out)

int count=0;
int *swaparray;
void swap(int* a, int* b);
void selectionSort(int* A, int n);
void verify(int* A, int n);
int* f_read(FILE *in)
{
	
	int i=0,j=0;
	int *a;
	char buf[10];
	char c;
	while((c=fgetc(in))!=EOF)
	{
		if(c==' ')
		{
			count++;
		}
	}
	//count++;
	printf("count = %d",count);
	a=(int *)malloc(count * sizeof(int));
	swaparray=(int *)malloc(count * sizeof(int));
	fseek(in,0,SEEK_SET);
	
	while((c=fgetc(in))!=EOF)
	{
		if(c==' ')
		{
			buf[j]='\0';
			a[i++]=atoi(buf);
			j=0;
		}
		else
		{
			buf[j++]=c;
		}
	}
	/*buf[j]='\0';
	a[i]=atoi(buf);*/
	/*for(i=0;i<count;i++)
	{
		printf("%d ",a[i]);
	}*/
	return a;
}
int main(){

	int number, iter =0;
	int* Arr;
	char buf[10];
	FILE *in=fopen("index8.txt","rb");
	FILE *out=fopen("insorted8.txt","wb");
	FILE *out1=fopen("inindex8.txt","wb");
	//scanf("%d", &number);
	//Arr = (int *)malloc( number * sizeof(int));
	/*for(; iter<number; iter++){
		//scanf("%d", &Arr[iter]);
		Arr[iter]=iter;
	}*/
    Arr=f_read(in);
    number = count;
    t = clock();
	selectionSort(Arr, number);
    t = clock()-t;
	
	for(iter=0; iter<number;iter++){
		//printf("%d ", Arr[iter]);
		itoa(Arr[iter],buf,10);
		fputs(buf,out);
		fputc(' ',out);
		itoa(swaparray[iter],buf,10);
		fputs(buf,out1);
		fputc(' ',out1);
	}

	cpu_time_used = ((double)t)/CLOCKS_PER_SEC;
	
	// Verify if the algorithm works as advised
	verify(Arr, number);

	printf("\nTime taken for sort: %lf\n", cpu_time_used);
	return 0;
}

void selectionSort(int* A, int n){
	int startpos,i;
	for(startpos =0; startpos < n; startpos++){
		// Declare the structure required for reduction
		struct Compare max;
        // Initialize the variables
        max.val = A[startpos];
        max.index = startpos;
		printf("%d ",startpos);
        // Parallel for loop with custom reduction, at the end of the loop, max will have the max element and its index.
        #pragma omp parallel for reduction(maximum:max)
		for(i=startpos +1; i< n; ++i){
			if(A[i] > max.val){
				max.val = A[i];
				max.index = i;
			}
			if(A[i] == startpos){
				max.val = A[i];
				max.index = i;
				break;
			}
		}
		
		swap(&A[startpos], &A[max.index]);
		swaparray[startpos]=max.index-startpos;
	}
}

// Verification function
void verify(int* A, int n){
	int failcount = 0;
	int iter;
	for(iter = 0; iter < n-1; iter++){
		if(A[iter] < A[iter+1]){
			failcount++;
		}
	}
	printf("\nFail count: %d\n", failcount);
}

//Swap function
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
