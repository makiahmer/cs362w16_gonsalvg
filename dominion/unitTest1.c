#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

/* function to be tested: gainCard
Test purpose: to verify that supply is added to the players.

int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)
{
  //Note: supplyPos is enum of chosen card

  //check if supply pile is empty (0) or card is not used in game (-1)
  if ( supplyCount(supplyPos, state) < 1 )
    {
      return -1;
    }

  //added card for [whoseTurn] current player:
  // toFlag = 0 : add to discard
  // toFlag = 1 : add to deck
  // toFlag = 2 : add to hand

  if (toFlag == 1)
    {
      state->deck[ player ][ state->deckCount[player] ] = supplyPos;
      state->deckCount[player]++;
    }
  else if (toFlag == 2)
    {
      state->hand[ player ][ state->handCount[player] ] = supplyPos;
      state->handCount[player]++;
    }
  else
    {
      state->discard[player][ state->discardCount[player] ] = supplyPos;
      state->discardCount[player]++;
    }

  //decrease number in supply pile
  state->supplyCount[supplyPos]--;

  return 0;
}
*/

int main () {
	struct gameState testState;
	//testState->player = 1;
	int supplyPos = 0;
	int toFlag= 2;
	int player = 1;
	
	int preCardGainCount = 0;
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
	int r = initializeGame(2, k, 1, &testState);
	
	preCardGainCount = testState.handCount[player];
	gainCard(supplyPos, &testState, toFlag, player);
	int postCardGainCount = testState.handCount[player];
	//bug: treasuremap is counted as a supply deck that is counted toward ending the game. 
	if (postCardGainCount > preCardGainCount) printf("Test player 1's hand being greater than 5.\n");	
	
	printf("pre-cardGain call hand size: %d, post: %d.\n", preCardGainCount, postCardGainCount);
	printf("Test completed successfully\n");
	
	return 0;
}
