#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "champion.h"

Champion* createChampion(){  //creates a random champion
	Champion* new = (Champion*)malloc(sizeof(Champion));  //allocates the memory
	int randChampType;
	int levelT;
	randChampType = (rand() % 4) + 1; //randomizes the role with a 25% chance for each
	switch(randChampType){ //switch case to assign a level to the created champion
		case 1:
		new->role = MAGE;
		levelT = (rand() % 4) + 5;
		new->level = levelT;
		break;
		case 2:
		new->role = FIGHTER;
		levelT = (rand() % 4) + 1;
		new->level = levelT;
		break;
		case 3:
		new->role = SUPPORT;
		levelT = (rand() % 4) + 3;
		new->level = levelT;
		break;
		case 4:
		new->role = TANK;
		levelT = (rand() % 8) + 1;
		new->level = levelT;
		break;
	}
	new->next = NULL;  //makes next node in list NULL to avoid segmentation faults
	return new; //returns champion created 
}

Champion* addChampion(Champion *head, Champion *c){ //adds champion to list
	if(head == NULL){ //if list is empty adds c which is the champion
		return c;
	}
	if(c == NULL){  //if chammpion is NULL just returns original list
		return head;
	}
	if(c->level > head->level){  //inserts character into correct place in list
		c->next = head;
		return c;
	}
	Champion* prev = NULL;
	Champion* temp = head;
 	while (temp != NULL && temp->level >= c->level) {
		prev = temp;
		temp = temp->next;
	}
	c->next = temp;
	prev->next = c;
	return head;
}

Champion* buildChampionList(int n){  //builds the champion list based on the command argument
	int i;
	Champion* head = NULL; //creates empty list
	Champion* c; //filler for champion
	for(i=0; i<n; i++){  //runs loop til it reaches n value
	c = createChampion();
	head = addChampion(head, c);
	}
	return head;
}

void printChampionList(Champion *head){  //prints the champion list
	if(head != NULL){  //continues to print until it reaches end of list
	switch(head->role){ //switch case for the roles
		case MAGE:
		printf("M%d ", head->level);
		break;
		case FIGHTER:
		printf("F%d ", head->level);
		break;
		case SUPPORT:
		printf("S%d ", head->level);
		break;
		case TANK:
		printf("T%d ", head->level);
		break;
	}
	printChampionList(head->next); //calls the function recursively
	}
}

Champion* removeChampion(Champion *head){  //removes the champion from the top of the list
	if(head == NULL){ //if list is empty returns
		return head;
	}
	Champion* newHead = head->next; //creates new head for list
	free(head); //frees and removes previous head
	return newHead;
}

Champion* destroyChampionList(Champion *head){  //continues to call removeChampion function till list is empty
	do{
		head = removeChampion(head);
	}while(head != NULL);
		return NULL;
}
