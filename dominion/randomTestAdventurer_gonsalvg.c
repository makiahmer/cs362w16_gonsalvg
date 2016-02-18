/*
   Name: Griffin Gonsalves
   Date: 2/12/2016
   Description: Adventurer Random Test for Assignment 3 for CS 362
*/
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_TESTS 1

void randomHands(int deckArr, int deckCount, int handCount);

/*tests the effect of the adventured with randomized gamestates */
int main(){
   int deckArr[10] = {adventurer, gardens, embargo, village, minion, mine,
       cutpurse, sea_hag, tribute, smithy};
   
	int seed, players, player, beforeCount, card1, card2;
   
	struct gameState state;
   
	printf("Running randomized adventurer card test.\n");
	
   for (int i = 0; i < NUM_TESTS; i++){
      seed = rand();
      players = rand() % 4;
		player = rand() % players; //choose a random player out of the ones we created.
		//player = 1;
		initializeGame(players, deckArr, seed, &state);
      
		state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		state.discardCount[player] = rand() % MAX_DECK;
		state.handCount[player] = rand() % MAX_HAND;
		
		if (seed % 3 == 0) state.deckCount[player] = 0;
		
		beforeCount = state.handCount[player]; //get the count of the player's hand before adventurer card played
		
		//1 in 3 chance of making an empty deck.
		
		
		cardEffect(adventurer, 1, 1, 1, &state); //run the card
		
		beforeCount += 2; // current count should equal before +2.
		
		card1 = state.hand[player][state.handCount[player] - 1];
		card2 = state.hand[player][state.handCount[player] - 2];
		
		if (state.handCount[player] != beforeCount) printf("Error: player did not draw two cards.\n");
		
		if (card1 != copper || card1 != silver || card1 != gold) printf("Error: player didn't recieve 1st treasure.\n");
		if (card2 != copper || card2 != silver || card2 != gold) printf("Error: player didn't recieve 2nd treasure.\n"); 
   }
   

   return 0;
}