#include "utils.h"

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
}

void clean_buffer(){
	while(getchar()!='\n');
}
