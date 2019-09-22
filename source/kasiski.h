#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

/*
 * Kasiski's test:
 * if we have two n-grams of length at least three, then there
 * are high probability that they represent the same plaintext
 * */
int kasiski(char* ciphertext, int ignore, int n_least, _Bool verbose);