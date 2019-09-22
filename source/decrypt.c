#include "decrypt.h"

char* decrypt(char* ciphertext, char* key){
	char* decrypted_text=malloc(strlen(ciphertext)+1);
	int mod=strlen(key), tmp;

	for(int i=0; i<strlen(ciphertext)-1; i++){
		tmp=((*(ciphertext+i)-65-(*(key+(i%mod))-65))%26);
		if(tmp<0)
			tmp+=26;
		*(decrypted_text+i)=(char)(tmp+65);
	}
	*(decrypted_text+strlen(ciphertext))='\0';
	return decrypted_text;
}
