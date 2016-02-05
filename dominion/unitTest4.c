#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main () {
	//initialize variables to test operation of the compare function.
	int a = 1 , b = 3, c = 1, j, k;


	j = compare(&a, &b);
	assert(j != 0);

	k = compare(&a, &c);
	assert(k == 0);
	
	//end of unit test 4
  
  return 0;
}