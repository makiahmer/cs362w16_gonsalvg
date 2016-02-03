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
int main (int argc, char** argv) {
	struct gameState testState;
	//testState->player = 1;
	int supplyPos = 0;
	int toFlag= 2;
	int player = 1;
	
	gainCard(supplyPos, testState, toFlag, player);
	assert(testState->handCount < 5); //assert if the hand we are testing has less than 5 cards in their hand.
	return 0;
}