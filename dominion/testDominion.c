#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define NUM_TESTS 10
int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;
  
  int money = 0;
  int cutpursePos = -1;
  int adventurerPos = -1;
  int i=0, x = 0;
  int numSmithies = 0;
  int numAdventurers = 0;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};


  
for (x = 0; x < NUM_TESTS; x++){
  srand(time(NULL));
  int seed = (rand() % 1000 + 1);
  initializeGame(2, k, seed, p);
   printf ("Starting game %d .\n", x);
   
  
  while (!isGameOver(p)) {
    money = 0;
    cutpursePos = -1;
    adventurerPos = -1;
    for (i = 0; i < numHandCards(p); i++) {
      if (handCard(i, p) == copper)
    money++;
      else if (handCard(i, p) == silver)
    money += 2;
      else if (handCard(i, p) == gold)
    money += 3;
      else if (handCard(i, p) == cutpurse)
    cutpursePos = i;
      else if (handCard(i, p) == adventurer)
    adventurerPos = i;
    }

    if (whoseTurn(p) == 0) {
      if (cutpursePos != -1) {
        printf("0: cutpurse played from position %d\n", cutpursePos); 
	playCard(cutpursePos, -1, -1, -1, p); 
	printf("cutpurse played.\n");
	money = 0;
	i=0;
	while(i<numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      }

      if (money >= 8) {
        printf("0: bought province\n"); 
        buyCard(province, p);
      }
      else if (money >= 6) {
        printf("0: bought gold\n"); 
        buyCard(gold, p);
      }
      else if ((money >= 4) && (numSmithies < 2)) {
        printf("0: bought cutpurse\n"); 
        buyCard(cutpurse, p);
        numSmithies++;
      }
      else if (money >= 3) {
        printf("0: bought silver\n"); 
        buyCard(silver, p);
      }

      printf("0: end turn\n");
      endTurn(p);
    }
    else {
      if (adventurerPos != -1) {
        printf("1: adventurer played from position %d\n", adventurerPos);
	playCard(adventurerPos, -1, -1, -1, p); 
	money = 0;
	i=0;
	while(i<numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      }

      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
      else if ((money >= 6) && (numAdventurers < 2)) {
        printf("1: bought adventurer\n");
	buyCard(adventurer, p);
	numAdventurers++;
      }else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("1: endTurn\n");
      
      endTurn(p);      
    }

      printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));
	    
  } // end of While

  printf ("Finished game %d .\n", x);
  printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));
}
  return 0;
}
