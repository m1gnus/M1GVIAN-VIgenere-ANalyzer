#include "iof.h"

int iox(char *string){
    double fs=0;
    int f;
    char start='A';
    if(strlen(string)==1)
        return 1;
    for(int i=0; i<26; i++){
        f=frequencies(start+i,string);
        fs+=(f*(f-1));
    }
    printf("iox=%s%.3f%s\n",COL_GREEN,(fs/(strlen(string)*(strlen(string)-1))),COL_STD);
    return(fs/(strlen(string)*(strlen(string)-1)));
}

int indexOfCoincidence(char* ciphertext){
    int m=1, cont=0, remin, rowl, max;
    char **tmp=malloc(A_LEN);
    _Bool found=0;

    for(int i=0; i<A_LEN; i++)
        *(tmp+i)=malloc(A_LEN);
    
    printf("choose max -> ");
    scanf("%d",&max);
    while(m<=max){
        cont=0;
        rowl=strlen(ciphertext)/m;
	remin=strlen(ciphertext)%m;
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
        for(int i=0; i<m; i++)
            printf("%s\n",*(tmp+i));

        for(int i=0; i<m; i++)
            iox(*(tmp+i));

        printf("m=%s%d%s\n\n\n",COL_BLUE,m,COL_STD);
        m++;
    }
}
