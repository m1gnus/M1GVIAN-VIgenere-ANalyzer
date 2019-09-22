#include "utils.h"
#include "kasiski.h"

//prototypes
char* read_ciphertext(char* path);
void menu(char* ciphertext);
void bye(void);
void help(void);
void credits(void);

char* read_ciphertext(char* path){
	char c, *ciphertext=malloc(A_LEN*4);
	FILE* cip_file=fopen(path,"r");
	int cont=0;
	if((cip_file=fopen(path,"r"))==NULL){
		printf("%sERROR WHILE OPENING THE FILE... EXITING WITH EXIT CODE 1%s\n",COL_RED,COL_STD);
		exit(1);
	}
	while((c=getc(cip_file))!=EOF){
		*(ciphertext+cont)=c;
		cont++;
	}
	*(ciphertext+cont)='\0';
	return ciphertext;
}

void menu(char* ciphertext){
	char choice='h';
	int ignore,least=0,m;
	credits();
	while(1){
		printf("\n%s\n\n",ciphertext);
		printf("[%s+%s] Command -> %s",COL_GREEN,COL_STD,COL_BLUE);
		scanf("%s", &choice);
		clean_buffer();
		printf("%s",COL_STD);
		switch(choice){
			case 'k':
				printf("how many ignores? -> ");
				scanf("%d",&ignore);
				clean_buffer();
				least=0;
				while(least<3){
					printf("minumum length? (>=3) -> ");
					scanf("%d",&least);
					clean_buffer();
				}
				printf("\n");
				kasiski(ciphertext,ignore,least,0);
				break;
			case 'h':
				help();
				break;
			case 'c':
				credits();
				break;
			case 'i':
				indexOfCoincidence(ciphertext);
				break;
			case 'g':
				printf("insert m -> ");
				scanf("%d",&m);
				guess_key(ciphertext, m)
				break;
			case 'q':
				return;
			default:
				printf("\n%sINVALID COMMAND%s\n",COL_RED,COL_STD);
		}
	}
}

void credits(){
	printf("\n%s",COL_YELLOW);
	printf("**************************************************\n");
	printf("***VIAN v1.0 -- VIgenere ANalyzer*****************\n");
	printf("***BY M1GNUS -- -- PGIATASTI**********************\n");
	printf("**************************************************\n");
	printf("***PLS REPORT ANY BUGS AT m1gnus@protonmail.com***\n");
	printf("**************************************************\n");
	printf("\n%s",COL_STD);
}

void bye(){
	printf("\n\n%sBYE -- VIAN v1.0 -- VIgenere ANalyzer -- by M1GNUS -- -- PGIATASTI%s\n",COL_BLUE,COL_STD);
	exit(0);
}

void help(){
	printf("\nAvailable commands:\nh (help)\nk (kasiski's test)\nc (print credits)\nq (quit)\n");
}

int main(int argc, char** argv){
	char* ciphertext;

	if(argc<2)
		ciphertext=read_ciphertext("./cipher/b.txt");
	else{
		ciphertext=malloc(A_LEN);
		for(int i=0; i<strlen(*(argv+1)); i++)
			*(ciphertext+i)=*(*(argv+1)+i);
		*(ciphertext+strlen(*(argv+1)))='\0';
		ciphertext=read_ciphertext(ciphertext);
	}
	
	printf("%s",COL_STD); //set the standard color for the output
	menu(ciphertext);

	//freeing memory
	free(ciphertext);
	ciphertext=NULL;

	bye();
}