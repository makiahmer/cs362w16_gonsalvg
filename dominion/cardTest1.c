#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdlib.h>

int main () {
  struct gameState testState;
  //setup game
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  printf ("Starting game.\n");
  
  int r = initializeGame(2, k, 1, &testState);
		
  assert (r == 0);
  //put a card into the first players hand
  testState.hand[0][0] = gardens;
  //get the result from the play
  int returnTest = playCard(0, 0, 0, 0, &testState);

  if (returnTest == -1) printf("card works as intended.\n");
  else printf("exiting cardTest2.\n");
  
  return 0;
}