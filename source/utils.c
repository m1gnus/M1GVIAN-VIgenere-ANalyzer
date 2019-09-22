#include "utils.h"

int frequencies(char c, char* string){
	int cont=0;
	for(int i=0; i<strlen(string); i++){
		if(*(string+i)==c)
			cont++;
	}
	return cont;
}

int fact(int n, int result){
	if(n==1)
		return result;
	else
		fact(n-1, n*result);
}

int binomial(int k, int n){
	int num=1, den;
	for(int i=0; i<n; i++)
		num*=(k-i);
	den=fact(n,1);
	return num/den;
}

int GCD(int a, int b){
	if(b==0)
		return a;
	else
		return GCD(b,a%b);
}

int mul_GCD(int* elements, int n_of_elements){
	int result=*elements;
	for(int i=1; i<n_of_elements; i++)
		result=GCD(*(elements+i),result);
	return result;
}

void print_divisors(int m){
	int *div=malloc(A_LEN), mid=m/2, cont=1;
	
	*(div)=m;
	for(int i=mid; i>0; i--){
		if(m%i==0){
			*(div+cont)=i;
			cont++;
		}
	}
	*(div+cont)=-1; //end of the divs
	cont=0;
	//formatting output
	printf("[%s ",COL_GREEN);
	while(*(div+cont)!=(-1)){
		printf("%d ",*(div+cont));
		cont++;
	}
	printf("%s]\n",COL_STD);
	//freeing memory
	free(div);
	div=NULL;
}

void clean_buffer(){
	while(getchar()!='\n');
}