#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Array standard length
#define A_LEN 1024
//Color Codes for UNIX
#define COL(x) "\033[" #x ";1m" 
#define COL_RED COL(31)
#define COL_GREEN COL(32)
#define COL_YELLOW COL(33)
#define COL_BLUE COL(34)
#define COL_WHITE COL(37)
#define COL_GRAY "\033[0m"
#define COL_STD COL_WHITE

int GCD(int a, int b);
//GCD(a,b,c)=GCD(GCD(a,b),c)
int mul_GCD(int* elements, int n_of_elements);
void print_divisors(int m);
void clean_buffer(void);
int binomial(int k,int n);
int fact(int n, int result);
int frequencies(char c, char* string);