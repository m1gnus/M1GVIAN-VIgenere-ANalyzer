#include "kasiski.h"

int kasiski(char* ciphertext, int ignore, int n_least){
	int *dists=malloc(A_LEN*sizeof(int)), cip_length=strlen(ciphertext), index=0, n_elements=0;
	char *n_gr_cmp=malloc(A_LEN*sizeof(char)), *n_gr_cmp2=malloc(A_LEN*sizeof(char));
	_Bool ignored=0, found=0;

	for(int i=0; i<cip_length-n_least; i++){
		index=i;
		for(int j=0; j<n_least; j++)
			*(n_gr_cmp+j)=*(ciphertext+j+i);
		*(n_gr_cmp+n_least)='\0';
		
		for(int j=1; j<cip_length-n_least-i+1; j++){
			if(ignored){
				ignored=0;
				continue;
			}
			for(int k=0; k<n_least; k++)
				*(n_gr_cmp2+k)=*(ciphertext+i+j+k);
			*(n_gr_cmp2+n_least)='\0';
			if(!strcmp(n_gr_cmp,n_gr_cmp2)){
				if(ignore!=0){
					ignore--;
					ignored=1;
					continue;
				}
				found=1;
				printf("[%s*%s] %s%s%s | distance : %d \n",COL_BLUE,COL_STD,COL_YELLOW,COL_STD,n_gr_cmp,i+j-index);
				*(dists+n_elements)=i+j-index;
				index=i+j;
				n_elements++;
			}
		}
		if(found){
			int m=mul_GCD(dists,n_elements);
			printf("\nprobably m=");
			print_divisors(m);
			break;
		}
	}	
		if(!found)
			printf("[%s-%s] Nothing found... try with Index of coincidence (i)...\n",COL_RED,COL_STD);
		//freeing memory
		free(dists);
		free(n_gr_cmp);
		free(n_gr_cmp2);
		return 0;
}
