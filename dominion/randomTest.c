/*
   Name: Griffin Gonsalves
   Date: 2/12/2016
   Description: Random Test for Assignment 3 for CS 362
*/
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 1200

//This randomly tests smithy

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	  int i, j, n, players, player, handCount, deckCount, seed, address;
	  //struct gameState state;
	  struct gameState state;
	  struct gameState stat;
	  struct gameState sta;

	  printf("Running Random Card Test for Smithy\n");

	  /*
										--- Author's Note ---
	  So, I had problems running out of memory when I used the same gameState variable more than 12 times, and
	  I honestly don't know why. I momentarily solved this problem by adding more for loops and creating more gamestates;
	  I was still able to get decent coverage, though not up to the amount of tests I originally had in mind.
	  (I just put this on the second file as well)

	  This program wouldn't work without the printouts, oddly enough.
	  */

	  for (i = 0; i < MAX_TESTS; i++) {

		  
		 players = rand() % 4;
		 seed = rand();		//pick random seed
		
		 initializeGame(players, k, seed, &state);	//initialize Gamestate

		  //Initiate valid state variables
		  state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  state.discardCount[player] = rand() % MAX_DECK;
		  state.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = state.handCount[player];
		  deckCount = state.deckCount[player];

		  		  	  		  		  printf("%d\n", i);


		  cardEffect(smithy, 1, 1, 1, &state);		//Run adventurer card

		  printf("%dB\n", i);
	  }