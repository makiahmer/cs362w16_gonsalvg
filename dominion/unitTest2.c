 /*int isGameOver(struct gameState *state) {
  int i;
  int j;

  //if stack of Province cards is empty, the game ends
  if (state->supplyCount[province] == 0)
    {
      return 1;
    }

  //if three supply pile are at 0, the game ends
  j = 0;
  for (i = 0; i < 25; i++)
    {
      if (state->supplyCount[i] == 0)
	{
	  j++;
	}
    }
  if ( j >= 3)
    {
      return 1;
    }

  return 0;
}*/

//this unit test will test the GameOver function
#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main () {
  struct gameState testState;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  printf ("Starting game.\n");
  
  int r = initializeGame(2, k, 1, &testState);

  assert (r == 0);
  //change all supply to 1
  for (int i=0; i < 25; i++){
	    testState.supplyCount[i]= 1;	  
  }
  //can be a random test here if you change a random set of 3 different cards to 0.
  int result1= isGameOver(&testState);

  if (result1 == 0) printf("Game does not end, and test 2 exits successfully.\n");
  else printf("Game ends, bug has been found!\n");
  
  return 0;
}