#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	int hp = 100, maxHP = 100, encounter = 1, enemyType, enemyHP, enemyMaxHP, choice = 0;
	char enemy[10];
	
	srand(time(0));
	
	printf("Welcome to Otter Adventure. You are an otter recently escaped from an otter sactuary and are trying to get through as much of the forest as you can. Good luck!\n");
	printf("Press [enter] to advance dialogue.\n");
	scanf("%c");
	
	//Main game loop
	while(hp > 0)
	{
		//Randomly picks which encounter you will encounter.
		encounter = rand() % 4 + 1;
		
		if(encounter == 1)
		{
			//The Enemy Encounter. First it picks what enemy you will fight and sets the stats to correspond.
			enemyType = rand() % 100 + 1;
			if(enemyType < 20)
			{
				enemyHP = 10;
				enemyMaxHP = 10;
				strcpy(enemy, "squirrel");
			}
			else if(enemyType < 50)
			{
				enemyHP = 20;
				enemyMaxHP = 20;
				strcpy(enemy, "eagle");
			}
			else if(enemyType < 90)
			{
				enemyHP = 30;
				enemyMaxHP = 30;
				strcpy(enemy, "coyote");
			}
			else
			{
				enemyHP = 35;
				enemyMaxHP = 35;
				strcpy(enemy, "bear");
			}

			if(strcmp(enemy, "eagle") == 0)
				printf("Oh no! You encounter an %s!\n", enemy);
			else
				printf("Oh no! You encounter a %s!\n", enemy);
			scanf("%c");
			
			//This the the main enemy encounter loop.
			while(enemyHP > 0 || hp > 0)
			{
				if(strcmp(enemy, "eagle") == 0)
						printf("You are in combat with an %s!\n", enemy);
				else
					printf("You are in combat with a %s!\n", enemy);
				printf("You have %d health.\nThe %s has %d health.\n", hp, enemy, enemyHP);
				
				do
				{
					printf("What would you like to do?\n1) Attack\n2) Defend\n3) Food\n4) Observe\n5) Flee\n");
					scanf("%d", &choice);
					if(choice < 1 || choice > 5)
					{
						printf("\n\033[31mPlease select an option between 1-5.\033[0m\n\n");
					}
					
				} while(choice < 1 || choice > 5);
				
				if(choice == 1)
				{
					attack()
				}
				else if(choice == 2)
				{
					defend()
				}
				else if(choice == 3)
				{
					food()
				}
				else if(choice == 4)
				{
					//Observe
				}
				else
				{
					//Flee
				}
			}
		}
	}
	
	return 0;
}
