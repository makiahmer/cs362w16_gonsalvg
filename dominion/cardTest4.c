#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

int main () {
  struct gameState testState;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  printf ("Starting game.\n");
  
  int r = initializeGame(2, k, 1, &testState);

  assert (r == 0);
  
  int effectReturn = cardEffect(great_hall , 0, 0, 0, &testState, 1, 0);
  
  if (testState.numActions != 2) printf("effect most likely did not work as intended.\n");
  else printf("exiting cardTest4.\n");
	
  return 0;
}