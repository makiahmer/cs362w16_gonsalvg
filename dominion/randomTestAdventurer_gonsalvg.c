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

/*test will generate many different hands, then use the card and test some of
the results*/
int main(){
   int deckArr[10] = {adventurer, gardens, embargo, village, minion, mine,
       cutpurse, sea_hag, tribute, smithy};
   int seed, players, handCount, deckCount, address;

   for (int i = 0; i < NUM_TESTS; i++){
      seed = rand();
      players = rand() % 4;


   }

   return 0;
}

void randomHands(int deckArr, int deckCount, int handCount){


}
