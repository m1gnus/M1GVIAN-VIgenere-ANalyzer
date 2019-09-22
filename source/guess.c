#include "guess.h"

void print_table(char* s){
	int f, len=strlen(s);
	double freqs[26]={0.082, 0.015, 0.028, 0.043, 0.127, 0.022, 0.020, 0.061, 0.070, 0.002, 0.008, 0.040, 0.024, 0.067, 0.075, 0.019, 0.001, 0.060, 0.063, 0.091, 0.028, 0.010, 0.023, 0.001, 0.020, 0.001}, Mg, Mgs[26];

	printf("|%s ",COL_YELLOW);
	for(int g=0; g<26; g++){
		Mg=0;
		for(int i=0; i<26; i++){
			Mg+=(freqs[i]*(frequencies((char)((i+g)%26+65),s)/(double)len));
		}
		printf("%d:%.3f%s|%s",g,Mg,COL_STD,COL_YELLOW);
		Mgs[g]=Mg;
	}
	printf(" %s--> %sMAX%s: %s%c%s\n",COL_STD,COL_BLUE,COL_STD,COL_GREEN,(char)(max_d(Mgs,26)+65),COL_STD);
}

void guess_key(char* ciphertext, int m){
	int cont=0, rowl=strlen(ciphertext)/m, remin=strlen(ciphertext)%m;
	char **tmp=malloc(A_LEN);
	
	for(int i=0; i<A_LEN; i++)
        	*(tmp+i)=malloc(A_LEN);

        for(int i=0; i<rowl; i++){
            for(int j=0; j<m; j++){
                *(*(tmp+j)+i)=*(ciphertext+cont);
                cont++;
            }
        }
        for(int i=0; i<m; i++)
            *(*(tmp+i)+rowl)='\0';
        for(int i=0; i<remin; i++){
            *(*(tmp+i)+rowl)=*(ciphertext+cont);
            cont++;
            *(*(tmp+i)+rowl+1)='\0';
        }
	
	for(int i=0; i<m; i++){
		printf("%d: ",i);
		print_table(*(tmp+i));	
	}
	//freeing memory	
	free(tmp);
	tmp=NULL;
}
