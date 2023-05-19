#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "champion.h"

int main(int argc, char* argv[]){
	srand(time(NULL)); //random seed
	if(argc != 2){  //stops program if no command arguments
		printf("ERROR: NO NUMBER INPUTTED\n");
		return -1;
	}
	int numOfChamps = atoi(argv[1]);  //converts the command argument to an integer
	if(numOfChamps <= 0){  //stops program if number is not greater than 0
		printf("ERROR: NUMBER NOT GREATER THAN 0\n");
		return -1;
	}
	
	printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n\n");
	Champion* p1List = buildChampionList(numOfChamps);  //builds champion lists for both player
	Champion* p2List = buildChampionList(numOfChamps);
	int rounds = 1;
	Champion* created = NULL; //creates the node for if a champion is created
	while(p1List != NULL && p2List != NULL){ //runs program until one or both lists are empty
		printf("----- ROUND %d -----\n", rounds); //prints round info
		printf("Player 1: ");
		printChampionList(p1List);
		printf("\n");
		printf("Player 2: ");
		printChampionList(p2List);
		printf("\n");
		
		//ALL 16 VARIATIONS
		if(p1List->role == MAGE && p2List->role == MAGE){
			printf("Player 1 is a MAGE and Player 2 is a MAGE\n");
			if(p1List->level > p2List->level){
				printf("Player 1 (MAGE) wins and gains a new champion.\n");
				printf("Player 2 (MAGE) loses one champion.\n");
				p1List = removeChampion(p1List);
				p2List = removeChampion(p2List);
				p2List = removeChampion(p2List);
				created = createChampion();
				p1List = addChampion(p1List, created);
			}
			else if(p1List->level < p2List->level){
				printf("Player 1 (MAGE) loses one champion.\n");
				printf("Player 2 (MAGE) wins and gains a new champion.\n");
				p1List = removeChampion(p1List);
				p1List = removeChampion(p1List);
				p2List = removeChampion(p2List);
				created = createChampion();
				p2List = addChampion(p2List, created);
			}else{
				printf("Nothing happens - no penalty or reward.\n");
				p1List = removeChampion(p1List);
				p2List = removeChampion(p2List);
			}
		}
		else if(p1List->role == MAGE && p2List->role == FIGHTER){
                       	printf("Player 1 is a MAGE and Player 2 is a FIGHTER\n");
                        if(p1List->level > p2List->level){
                                printf("Player 1 (MAGE) wins and gains a new champion.\n");
                                printf("Player 2 (FIGHTER) loses but with no penalty.\n");
                                p1List = removeChampion(p1List);
                                p2List = removeChampion(p2List);
                                created = createChampion();
                                p1List = addChampion(p1List, created);
                        }
                        else if(p1List->level < p2List->level){
                                printf("Player 1 (MAGE) loses one champion.\n");
                                printf("Player 2 (FIGHTER) wins but with no reward.\n");
                                p1List = removeChampion(p1List);
                                p1List = removeChampion(p1List);
                                p2List = removeChampion(p2List);
                        }else{
                                printf("Nothing happens - no penalty or reward.\n");
                                p1List = removeChampion(p1List);
                                p2List = removeChampion(p2List);
                        }
                }
		else if(p1List->role == MAGE && p2List->role == SUPPORT){
                        printf("Player 1 is a MAGE and Player 2 is a SUPPORT\n");
                        if(p1List->level > p2List->level){
                                printf("Player 1 (MAGE) wins and gains a new champion.\n");
                                printf("Player 2 (SUPPORT) loses two champions.\n");
                                p1List = removeChampion(p1List);
                                p2List = removeChampion(p2List);
				p2List = removeChampion(p2List);
                                p2List = removeChampion(p2List);
                                created = createChampion();
                                p1List = addChampion(p1List, created);
                        }
                        else if(p1List->level < p2List->level){
                                printf("Player 1 (MAGE) loses one champion.\n");
                                printf("Player 2 (SUPPORT) wins and gains two new champions.\n");
                                p1List = removeChampion(p1List);
                                p1List = removeChampion(p1List);
                                p2List = removeChampion(p2List);
                                created = createChampion();
                                p2List = addChampion(p2List, created);
				created = createChampion();
				p2List = addChampion(p2List, created);
                        }else{
                                printf("Nothing happens - no penalty or reward.\n");
                                p1List = removeChampion(p1List);
                                p2List = removeChampion(p2List);
                        }
                }
		else if(p1List->role == MAGE && p2List->role == TANK){
                        printf("Player 1 is a MAGE and Player 2 is a TANK\n");
                        printf("Player 1 (MAGE) wins and gains a new champion.\n");
			printf("Player 2 (TANK) loses one champion.\n");
			p1List = removeChampion(p1List);
			p2List = removeChampion(p2List);
			p2List = removeChampion(p2List);
			created = createChampion();
			p1List = addChampion(p1List, created);
                }
		else if(p1List->role == FIGHTER && p2List->role == MAGE){
                        printf("Player 1 is a FIGHTER and Player 2 is a MAGE\n");
                        if(p1List->level < p2List->level){
                                printf("Player 1 (FIGHTER) loses but with no penalty.\n");
                                printf("Player 2 (MAGE) wins and gains a new champion.\n");
                                p1List = removeChampion(p1List);
                                p2List = removeChampion(p2List);
                                created = createChampion();
                                p2List = addChampion(p2List, created);
                        }
                        else if(p1List->level > p2List->level){
                                printf("Player 1 (FIGHTER) wins but with no reward.\n");
                                printf("Player 2 (MAGE) loses one champion.\n");
                                p1List = removeChampion(p1List);
                                p2List = removeChampion(p2List);
                                p2List = removeChampion(p2List);
                        }else{
                                printf("Nothing happens - no penalty or reward.\n");
                                p1List = removeChampion(p1List);
                                p2List = removeChampion(p2List);
                        }
                }	
		else if(p1List->role == FIGHTER && p2List->role == FIGHTER){
                        printf("Player 1 is a FIGHTER and Player 2 is a FIGHTER\n");
                        printf("Player 1 (FIGHTER) gains a new champion.\n");
                        printf("Player 2 (FIGHTER) gains a new champion.\n");
                        p1List = removeChampion(p1List);
                        p2List = removeChampion(p2List);
                        created = createChampion();
                        p1List = addChampion(p1List, created);
			Champion* created2 = createChampion();
			p2List = addChampion(p2List, created2);
                }
		else if(p1List->role == FIGHTER && p2List->role == SUPPORT){
                        printf("Player 1 is a FIGHTER and Player 2 is a SUPPORT\n");
                        if(p1List->level < p2List->level){
                                printf("Player 1 (FIGHTER) loses but with no penalty.\n");
                                printf("Player 2 (SUPPORT) wins and gains a new champion.\n");
                                p1List = removeChampion(p1List);
                                p2List = removeChampion(p2List);
                                created = createChampion();
                                p2List = addChampion(p2List, created);
                        }
                        else if(p1List->level > p2List->level){
                                printf("Player 1 (FIGHTER) wins but with no reward.\n");
                                printf("Player 2 (SUPPORT) loses one champion.\n");
                                p1List = removeChampion(p1List);
                                p2List = removeChampion(p2List);
                                p2List = removeChampion(p2List);
                        }else{
                                printf("Nothing happens - no penalty or reward.\n");
                                p1List = removeChampion(p1List);
                                p2List = removeChampion(p2List);
                        }
                }
		else if(p1List->role == FIGHTER && p2List->role == TANK){
                        printf("Player 1 is a FIGHTER and Player 2 is a TANK\n");
                        printf("Player 1 (FIGHTER) wins and gains a new champion.\n");
                        printf("Player 2 (TANK) loses but with no penalty.\n");
			p1List = removeChampion(p1List);
			p2List = removeChampion(p2List);
			created = createChampion();
			p1List = addChampion(p1List, created);
                }
		else  if(p1List->role == SUPPORT && p2List->role == MAGE){
                        printf("Player 1 is a SUPPORT and Player 2 is a MAGE\n");
                        if(p1List->level < p2List->level){
                                printf("Player 1 (SUPPORT) loses two champions.\n");
                                printf("Player 2 (MAGE) wins and gains a new champion.\n");
                                p2List = removeChampion(p2List);
                                p1List = removeChampion(p1List);
                                p1List = removeChampion(p1List);
                                p1List = removeChampion(p1List);
                                created = createChampion();
                                p2List = addChampion(p2List, created);
                        }
                        else if(p1List->level > p2List->level){
                                printf("Player 1 (SUPPORT) wins and gains two new champions.\n");
                                printf("Player 2 (MAGE) loses one champion.\n");
                                p2List = removeChampion(p2List);
                                p2List = removeChampion(p2List);
                                p1List = removeChampion(p1List);
                                created = createChampion();
                                p1List = addChampion(p1List, created);
                                created = createChampion();
                                p1List = addChampion(p1List, created);
                        }else{
                                printf("Nothing happens - no penalty or reward.\n");
                                p1List = removeChampion(p1List);
                                p2List = removeChampion(p2List);
                        }
                }
		else if(p1List->role == SUPPORT && p2List->role == FIGHTER){
                        printf("Player 1 is a SUPPORT and Player 2 is a FIGHTER\n");
                        if(p1List->level > p2List->level){
                                printf("Player 1 (SUPPORT) wins and gains a new champion.\n");
                                printf("Player 2 (FIGHTER) loses but with no penalty.\n");
                                p1List = removeChampion(p1List);
                                p2List = removeChampion(p2List);
                                created = createChampion();
                                p1List = addChampion(p1List, created);
                        }
                        else if(p1List->level < p2List->level){
                                printf("Player 1 (SUPPORT) loses one champion .\n");
                                printf("Player 2 (FIGHTER) wins but with no reward.\n");
                                p1List = removeChampion(p1List);
                                p1List = removeChampion(p1List);
                                p2List = removeChampion(p2List);
                        }else{
                                printf("Nothing happens - no penalty or reward.\n");
                                p1List = removeChampion(p1List);
                                p2List = removeChampion(p2List);
                        }
                }
		else if(p1List->role == SUPPORT && p2List->role == SUPPORT){
			printf("Player 1 is a SUPPORT and Player 2 is a SUPPORT\n");
			printf("Both players lose the next champion.\n");
			p1List = removeChampion(p1List);
			p1List = removeChampion(p1List);
			p2List = removeChampion(p2List);
			p2List = removeChampion(p2List);
		}
		else if(p1List->role == SUPPORT && p2List->role == TANK){
                        printf("Player 1 is a SUPPORT and Player 2 is a TANK\n");
                        printf("Player 1 (SUPPORT) loses but with no penalty.\n");
			printf("Player 2 (TANK) wins and gains a new champion.\n");
                        p1List = removeChampion(p1List);
                        p2List = removeChampion(p2List);
                        created = createChampion();
			p2List = addChampion(p2List, created);
                }
		else if(p1List->role == TANK && p2List->role == MAGE){
                        printf("Player 1 is a TANK and Player 2 is a MAGE\n");
                        printf("Player 1 (TANK) loses one champion.\n");
                        printf("Player 2 (MAGE) wins and gains a new champion.\n");
                        p1List = removeChampion(p1List);
                        p1List = removeChampion(p1List);
                        p2List = removeChampion(p2List);
                        created = createChampion();
                        p2List = addChampion(p2List, created);
                }
		else if(p1List->role == TANK && p2List->role == FIGHTER){
                        printf("Player 1 is a TANK and Player 2 is a FIGHTER\n");
                        printf("Player 1 (TANK) loses but with no penalty.\n");
                        printf("Player 2 (FIGHTER) wins and gains a new champion.\n");
                        p1List = removeChampion(p1List);
                        p2List = removeChampion(p2List);
                        created = createChampion();
                        p2List = addChampion(p2List, created);
                }
		else if(p1List->role == TANK && p2List->role == SUPPORT){
                        printf("Player 1 is a TANK and Player 2 is a SUPPORT\n");
                        printf("Player 1 (TANK) wins and gains a new champion.\n");
                        printf("Player 2 (SUPPORT) loses but with no penalty.\n");
                        p1List = removeChampion(p1List);
                        p2List = removeChampion(p2List);
                        created = createChampion();
                        p1List = addChampion(p1List, created);
                }
		else if(p1List->role == TANK && p2List->role == TANK){
                        printf("Player 1 is a TANK and Player 2 is a TANK\n");
                        printf("Nothing happens - no penalty or reward.\n");
                        p1List = removeChampion(p1List);
                        p2List = removeChampion(p2List);
                }
		printf("\n");
		rounds++;
	}
	printf("============ GAME OVER  =============\n\n");  //prints game results
	printf("Player 1 ending champion list: ");
	printChampionList(p1List);
	printf("\nPlayer 2 ending champion list: ");
	printChampionList(p2List);
	printf("\n\n");
	if(p1List != NULL && p2List == NULL){  //if player 1 wins
		printf("Player 2 ran out of champions. Player 1 wins.\n");
	}
	else if(p1List == NULL && p2List != NULL){  //if player 2 wins
		printf("Player 1 ran out of champions. Player 2 wins.\n");
	}
	else{
		printf("TIE -- both players ran out of champions.\n"); //if the players tie
	}
	p1List = destroyChampionList(p1List);  //deletes and frees both player's lists
	p2List = destroyChampionList(p2List);
return 0;
}
