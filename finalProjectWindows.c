#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	int hp = 100, maxHP = 100, encounter = 1, enemyType, enemyHP, enemyMaxHP, choice = 0, attackStrength = 5, damage, critChance = 10, defense = 0, maxDefense = 10, clearBuffer, fishingChance = 50, enemyMove = 0, denarii = 0, denariiFound = 0, damagePrior = 0, enemyFlight = 0, enemyDamageBuff = 0, enemyLazy = 0, levels = 0, heal = 0, bearBuff = 0, enemyBaseDamageBuff = 0, enemyBaseHPBuff = 0, randomCheck = 0, spicyBoost = 0, difficulty = 1, showLog = 0;
	char enemy[20];
	char chara;
	int inventory[10] = {0}, log[10][5] = {{0}};
	
	srand(time(0));
	
	//Though it is not ideal, functions are added inside main() so the variables could be used.
	void enemyAttack()
	{
		//This increases the attack by the damage buff.
		damage += enemyDamageBuff;
		//This is to tell how much defense to lose.
		damagePrior = damage;
		
		//Calculate how much damage gets done.
		if (damage - defense < 0)
			damage = 0;
		else
			damage -= defense;
		
		//Calculate and modify how much defense is left
		if(defense - damagePrior < 0)
			defense = 0;
		else
			defense -= damagePrior;
		
		//Actually modify health
		if(hp - damage < 0)
			hp = 0;
		else
			hp -= damage;
	}
		
	void printHealthLeft()
	{
		if(hp < 21)
				printf("You now only have \033[5;31m%d health\033[0m!\n", hp);
			else
				printf("You now have %d health.\n", hp);
		return;
	}
	void attackResultPrint()
	{
		if(damage < 1)
			printf("You successfully blocked all the \033[31mdamage\033[0m!\n");
		else if(damagePrior != damage)
		{
			printf("You blocked some of the damage, but the %s still deals \033[31m%d damage\033[0m to you.\n", enemy, damage);
			printHealthLeft();
		}
		else
		{
			printf("The %s attacks you and does \033[31m%d damage\033[0m to you!\n", enemy, damage);
			printHealthLeft();
		}
	}
	
	void critResultPrint()
	{
		if(damage < 1)
			printf("You successfully blocked all the \033[31mdamage\033[0m!\n");
		else if(damagePrior != damage)
		{
			printf("The %s fells a mighty blow! You block some of it, but you still took \033[31m%d damage\033[0m.\n", enemy, damage);
			printHealthLeft();
		}
		else
		{
			printf("The %s fells a mighty blow and does \033[31m%d damage\033[0m to you!\n", enemy, damage);
			printHealthLeft();
		}
	}
	
	void goFishing() //Used as a function due to it being used in two different encounters.
	{
		printf("You begin to fish, how far would you like to cast?\n1) Close\n2) Halfway\n3) Far\n");
		do
		{
			if (scanf("%d", &choice) == 1) {}
			else
				while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { } //This checks to make sure an integer was inputed. Google was used to find out how to do this.
			if(choice < 1 || choice > 3)
			{
				printf("\n\033[31mPlease select an option between 1-3.\033[0m\n\n");
			}
					
		} while(choice < 1 || choice > 3);
				
		//The following line clears the input buffer. This removes the enter after a %d or %i. Google was used to find out how to do this.
		while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
		
		//Now actual fishing starts
		if(rand() % 100 + 1 < fishingChance + 1)
		{
			randomCheck = rand() % 100 + 1;
			if(choice == 1)
			{
				if(randomCheck < 11) //Plain Fish
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 1;
							printf("You caught a Plain Fish!\n");
							break;
						}
					}
				}
				else if(randomCheck < 31) //Small Fish
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 2;
							printf("You caught a Small Fish!\n");
							break;
						}
					}
				}
				else if(randomCheck < 51) //Substatial Fish
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 3;
							printf("You caught an Enormous Fish!\n");
							break;
						}
					}
				}
				else if(randomCheck< 61) //Angry Eel
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 4;
							printf("You caught an Angry Eel!\n");
							break;
						}
					}
				}
				else if(randomCheck < 71) //Spicy Fish
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 5;
							printf("You caught a Spicy Fish!\n");
							break;
						}
					}
				}
				else if(randomCheck < 91) //Clam
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 6;
							printf("You caught a Clam!\n");
							break;
						}
					}
				}
				else if(randomCheck < 100) //Angler
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 7;
							printf("You caught an Angler Fish!\n");
							break;
						}
					}
				}
				else //MEGA Fish. Always a very very low chance of getting this one.
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 8;
							printf("You caught a \e[0;33mMEGA GLORIOUS FISH\033[0m!\n");
							break;
						}
					}
				}
			}
			else if (choice == 2)
			{
				if(randomCheck < 21) //Plain Fish
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 1;
							printf("You caught a Plain Fish!\n");
							break;
						}
					}
				}
				else if(randomCheck < 30) //Small Fish
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 2;
							printf("You caught a Small Fish!\n");
							break;
						}
					}
				}
				else if(randomCheck < 40) //Substatial Fish
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 3;
							printf("You caught an Enormous Fish!\n");
							break;
						}
					}
				}
				else if(randomCheck< 60) //Angry Eel
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 4;
							printf("You caught an Angry Eel!\n");
							break;
						}
					}
				}
				else if(randomCheck < 80) //Spicy Fish
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 5;
							printf("You caught a Spicy Fish!\n");
							break;
						}
					}
				}
				else if(randomCheck < 90) //Clam
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 6;
							printf("You caught a Clam!\n");
							break;
						}
					}
				}
				else if(randomCheck < 99) //Angler
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 7;
							printf("You caught an Angler Fish!\n");
							break;
						}
					}
				}
				else //MEGA Fish. Always a very very low chance of getting this one.
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 8;
							printf("You caught a \e[0;33mMEGA GLORIOUS FISH\033[0m!\n");
							break;
						}
					}
				}
			}
			else
			{
				if(randomCheck < 21) //Plain Fish
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 1;
							printf("You caught a Plain Fish!\n");
							break;
						}
					}
				}
				else if(randomCheck < 31) //Small Fish
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 2;
							printf("You caught a Small Fish!\n");
							break;
						}
					}
				}
				else if(randomCheck < 51) //Substatial Fish
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 3;
							printf("You caught an Enormous Fish!\n");
							break;
						}
					}
				}
				else if(randomCheck< 61) //Angry Eel
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 4;
							printf("You caught an Angry Eel!\n");
							break;
						}
					}
				}
				else if(randomCheck < 71) //Spicy Fish
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 5;
							printf("You caught a Spicy Fish!\n");
							break;
						}
					}
				}
				else if(randomCheck < 81) //Clam
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 6;
							printf("You caught a Clam!\n");
							break;
						}
					}
				}
				else if(randomCheck < 100) //Angler
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 7;
							printf("You caught an Angler Fish!\n");
							break;
						}
					}
				}
				else //MEGA Fish. Always a very very low chance of getting this one.
				{
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
						{
							inventory[loop] = 8;
							printf("You caught a \e[0;33mMEGA GLORIOUS FISH\033[0m!\n");
							break;
						}
					}
				}
			}
		}
		else
			printf("You were unable to catching anything.\n");
		return;
	}
	
	int isInventoryFull()
	{
		int fullness = 0;
		
		for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] != 0)
						{
							fullness ++;
						}
					}
		if (fullness >= 10)
			return 0;
		else
			return 1;
	}
	
	int addToLog(int level, int encounter, int object, int maxhp, int hp)
	{
		for(int loop = 0; loop < 10; loop ++)
		{
			if (log[loop][1] == 0)
			{
				log[loop][1] = level;
				log[loop][2] = encounter;
				log[loop][3] = object;
				log[loop][4] = maxhp;
				log[loop][5]= hp;
				break;
			}
		}
		for(int loop = 0; loop < 9; loop ++)
		{
			log[loop][1] = log[loop+1][1];
			log[loop][2] = log[loop+1][2];
			log[loop][3] = log[loop+1][3];
			log[loop][4] = log[loop+1][4];
			log[loop][5] = log[loop+1][5];
		}
		
		log[9][1] = level;
		log[9][2] = encounter;
		log[9][3] = object;
		log[9][4] = maxhp;
		log[9][5]= hp;
	}


	printf("Welcome to Otter Adventure. You are an otter recently escaped from an otter sactuary and are trying to get through as much of the forest as you can. Good luck!\n");
	printf("Press [enter] to advance dialogue.\n");
	scanf("%c", &chara);
	
	printf("What difficulty/mode do you want to play?\n1) Normal\n2) Low Health\n3) Medium Health\n4) Master\n");
	do
	{
		if (scanf("%d", &choice) == 1) {} //This checks to make sure an integer was inputed. Google was used to find out how to do this.
		else
			while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
		if(choice < 1 || choice > 4)
		{
			printf("\n\033[31mPlease select an option between 1-4.\033[0m\n\n");
		}
		
	} while(choice < 1 || choice > 4);
	
	//The following line clears the input buffer. Google was used to find out how to do this.
	while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
	
	difficulty = choice;
	
	if(difficulty == 1) //Normal
	{
		maxHP = 100;
		hp = 100;
	}
	else if (difficulty == 2) //Low Health
	{
		maxHP = 50;
		hp = 50;
	}
	else if (difficulty == 3) //Medium Health
	{
		maxHP = 75;
		hp = 75;
	}
	else //Master
	{
		maxHP = 50;
		hp = 50;
		enemyBaseHPBuff = 10;
		enemyBaseDamageBuff = 1;
	}
	
	//Main game loop
	while(hp > 0)
	{
		//The very first encounter will always be an enemy.	
		if(encounter == 1)
		{
			//The Enemy Encounter. First it picks what enemy you will fight and sets the stats to correspond.
			enemyType = rand() % 100 + 1;
			if(enemyType < 20)
			{
				enemyHP = 10 + enemyBaseHPBuff;
				enemyMaxHP = 10 + enemyBaseHPBuff;
				strcpy(enemy, "squirrel");
				enemyType = 1;
			}
			else if(enemyType < 50)
			{
				enemyHP = 20 + enemyBaseHPBuff;
				enemyMaxHP = 20 + enemyBaseHPBuff;
				strcpy(enemy, "eagle");
				enemyType = 2;
			}
			else if(enemyType < 90)
			{
				enemyHP = 30 + enemyBaseHPBuff;
				enemyMaxHP = 30 + enemyBaseHPBuff;
				strcpy(enemy, "coyote");
				enemyType = 3;
			}
			else
			{
				enemyHP = 35 + enemyBaseHPBuff;
				enemyMaxHP = 40 + enemyBaseHPBuff;
				strcpy(enemy, "bear");
				enemyType = 4;
			}

			if(strcmp(enemy, "eagle") == 0)
				printf("Oh no! You encounter an %s!\n", enemy);
			else
				printf("Oh no! You encounter a %s!\n", enemy);
				
			scanf("%c", &chara);
			
			//This the the main enemy encounter loop.
			while(enemyHP > 0 && hp > 0)
			{
				if(strcmp(enemy, "eagle") == 0)
						printf("You are in combat with an %s!\n", enemy);
				else
					printf("You are in combat with a %s!\n", enemy);
				printf("You have %d health.\nThe %s has %d health.\n", hp, enemy, enemyHP);
				
				do
				{
					printf("What would you like to do?\n1) Attack (%d - %d damage)\n2) Defend (%d defense)\n3) Food\n4) Observe\n5) Flee (%d%% chance)\n6) Pass\n", attackStrength, attackStrength + 3, maxDefense, maxHP - hp > 50 ? 50 : maxHP - hp);
					if (scanf("%d", &choice) == 1) {} //This checks to make sure an integer was inputed. Google was used to find out how to do this.
					else
						while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
					if(choice < 1 || choice > 6)
					{
						printf("\n\033[31mPlease select an option between 1-6.\033[0m\n\n");
					}
					
				} while(choice < 1 || choice > 6);
				
				//The following line clears the input buffer. Google was used to find out how to do this.
				while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
				
				if(choice == 1)
				{
					//Does damage to the enemy
					printf("\n");
					if(enemyFlight > 0)
					{
						printf("The %s is too high in the sky to hit from here!\n", enemy);
					}
					else
					{
						if(rand() % 100 + 1 <= critChance)
						{
							damage = ((rand() % 4 + 1) * 2 + (attackStrength - 1)) + spicyBoost;
							printf("You attack with extra vigor and deal more damage!\n");
							if(spicyBoost > 0)
							printf("Your attack was extra spicy!\n");
						}
						else
							damage = rand() % 4 + attackStrength + spicyBoost;
					
						if(enemyHP - damage < 0)
							enemyHP = 0;
						else
							enemyHP -= damage;
					
						printf("You attack for \033[31m%d damage!\033[0m\nThe %s now has %d health.\n", damage, enemy, enemyHP);
						if(spicyBoost > 0)
							printf("Your attack was extra spicy!\n");
							
						spicyBoost = 0;
					}
					scanf("%c", &chara);
				}
				else if(choice == 2)
				{
					//Sets defense
					defense = maxDefense;
					printf("You move to defend.\n");
				}
				else if(choice == 3)
				{
					//Shows you the inventory and lets you eat something
					printf("What would you like to eat?\n");
					
					//This prints what is in your inventory.
					for(int loop = 0; loop < 10; loop ++)
					{
						if(inventory[loop] == 0)
							printf("%2d) Nothing\n", loop + 1);
						else if(inventory[loop] == 1)
							printf("%2d) Plain Fish (Heals some health)\n", loop + 1);
						else if(inventory[loop] == 2)
							printf("%2d) Small Fish (Heals a small amount of health)\n", loop + 1);
						else if(inventory[loop] == 3)
							printf("%2d) Enormous Fish (Heals a large amount of health)\n", loop + 1);
						else if(inventory[loop] == 4)
							printf("%2d) Angry Eel (Lose some health, but deals the same damage to the enemy)\n", loop + 1);
						else if(inventory[loop] == 5)
							printf("%2d) Spicy Fish (Gain a little health and your next attack does more damage)\n", loop + 1);
						else if(inventory[loop] == 6)
							printf("%2d) Clam (Gain some health and increase your maximum health\n", loop + 1);
						else if(inventory[loop] == 7)
							printf("%2d) Angler (Lose some denarri but heals an equal amount)\n", loop + 1);
						else if(inventory[loop] == 8)
							printf("%2d) \e[0;33mMEGA GLORIOUS FISH (Completely refills your health)\033[0m\n", loop + 1);
						else
							printf("%2d) \e[0;33mHoney (Heals some health)\033[0m\n", loop +1);
					}
					printf("11) Back\n");
					
					do
					{
						if (scanf("%d", &choice) == 1) {}
						else
							while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
							
						if(choice < 1 || choice > 11)
							printf("\n\033[31mPlease select an option between 1-11.\033[0m\n\n");
						else if(choice == 11)
							printf("I geuss you are not hungry...\n");
						else if(inventory[choice - 1] == 0)
							printf("It would be hard to eat nothingness.\n");
							
					} while((choice < 1 || choice > 11));
						
					while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
					
					//This is where the food actually takes affect
					if(choice == 11)
					{
						//This is to detect if the user just wants to go back.
					}
					else
					{
						if (inventory[choice - 1] == 1) //Plain Fish
						{
							heal = rand() % 5 + 10;
							if (hp + heal > maxHP)
							{
								hp = maxHP;
								heal = maxHP - hp;
							}
							else
								hp += heal;
								
							printf("You eat the Plain Fish and heal \033[32m%d health\033[0m! You now have \033[32m%d health\033[0m.\n", heal, hp);
						}
						else if(inventory[choice - 1] == 2) //Small Fish
						{
							heal = rand() % 5 + 8;
							if (hp + heal > maxHP)
							{
								hp = maxHP;
								heal = maxHP - hp;
							}
							else
								hp += heal;
								
							printf("You eat the Small Fish and heal \033[32m%d health\033[0m! You now have \033[32m%d health\033[0m.\n", heal, hp);
						}
						else if(inventory[choice - 1] == 3) //Substantial Fish
						{
							heal = rand() % 5 + 12;
							if (hp + heal > maxHP)
							{
								hp = maxHP;
								heal = maxHP - hp;
							}
							else
								hp += heal;
								
							printf("You eat the Enormous Fish and heal \033[32m%d health\033[0m! You now have \033[32m%d health\033[0m.\n", heal, hp);
						}
						else if(inventory[choice - 1] == 4) //Angry Eel
						{
							damage = rand() % 5 + 6;
						
							if(enemyHP - damage < 0)
								enemyHP = 0;
							else
								enemyHP -= damage;
								
							if(hp - damage < 0)
								hp = 0;
							else
								hp -= damage;
								
							printf("You try to eat the Angry Eel and lose \033[31m%d health\033[0m! The Angry Eel also deals \033[31m%d damage\033[0m the the %s.\n You now have \033[31m%d health\033[0m. The %s now has \033[31m%d health\033[0m.\n", damage, damage, enemy, hp, enemy, enemyHP);
						}
						else if(inventory[choice - 1] == 5) //Spicy Fish
						{
							spicyBoost = rand() % 3 + 3;
							
							heal = rand() % 5 + 8;
							if (hp + heal > maxHP)
							{
								hp = maxHP;
								heal = maxHP - hp;
							}
							else
								hp += heal;
							
							printf("You eat the Spicy Fish and heal \033[32m%d health\033[0m! You now have \033[32m%d health\033[0m. Your next attack will deal %d more damage!\n", heal, hp, spicyBoost);
						}
						else if(inventory[choice - 1] == 6) //Clam
						{
							heal = rand() % 5 + 4;
							
							maxHP += heal;
							
							if (hp + heal > maxHP)
							{
								hp = maxHP;
								heal = maxHP - hp;
							}
							else
								hp += heal;
								
							printf("You eat the Clam! You maximum health has increased to \033[32m%d\033[0m! You heal \033[32m%d health\033[0m and now have \033[32m%d health\033[0m.\n", maxHP, heal, hp);
						}
						else if(inventory[choice - 1] == 7) //Angler
						{
							heal = rand() % 7 + 12;
							
							if (denarii - heal < 0)
							{
								heal = denarii;
								denarii = 0;
							}
							else
							{
								denarii -= heal;
							}
							
							if (hp + heal > maxHP)
							{
								hp = maxHP;
								heal = maxHP - hp;
							}
							else
								hp += heal;
								
							printf("You eat the Angler and heal \033[32m%d health\033[0m! You now have \033[32m%d health\033[0m, but you lost \e[0;33m%d denarii\033[0m...\n", heal, hp,denarii);
						}
						else if(inventory[choice - 1] == 8) //MEGA
						{
							heal = rand() % 5 + 12;
							if (hp + heal > maxHP)
							{
								hp = maxHP;
								heal = maxHP - hp;
							}
							else
								hp += heal;
								
							printf("You ate the \e[0;33mMEGA GLORIOUS FISH\033[0m! Your health has been restored to the \033[32maximum\033[0m!\n");
						}
						else if(inventory[choice - 1] == 9) //Honey
						{
							heal = rand() % 5 + 10;
							if (hp + heal > maxHP)
							{
								hp = maxHP;
								heal = maxHP - hp;
							}
							else
								hp += heal;
								
							printf("You eat the \e[0;33mHoney\033[0m and heal \033[32m%d health\033[0m! You now have \033[32m%d health\033[0m.\n", heal, hp);
						}
						inventory[choice - 1] = 0;
					}
					choice = 3;
					scanf("%c", &chara);
				}
				else if(choice == 4)
				{
					//Prints stats
					if (hp < 21)
						printf("\nYou currently have \033[5;31m%d health\033[0m. ", hp);
					else
						printf("\nYou currently have \033[32m%d health\033[0m. ", hp);
						
					printf("Your max health is \033[32m%d\033[0m.\nThe %s has \033[31m%d health\033[0m and its max health is \033[31m%d\033[0m.\nYou have %d defense currently.\nYou have a %d%% chance of catching fish.\nYou have a \033[31m%d%%\033[0m chance to land a \033[31mvigorous attack\033[0m.\nYou have \e[0;33m%d denarii\033[0m.\n", maxHP, enemy, enemyHP, enemyMaxHP, defense, fishingChance, critChance, denarii);
					scanf("%c", &chara);
				}
				else if (choice == 5)
				{
					//Possibly lets you flee the battle
					printf("\n");
					if(rand() % 100 + 1 <= (maxHP - hp > 50 ? 50 : maxHP - hp))
					{
						printf("You successfully flee from the battle!\n");
						choice = 6;
					}
					else
					{
						printf("\033[31mOh no! You were not able to escape the fight!\033[0m\n");
					}
					scanf("%c", &chara);
				}
				else
				{
					choice = 5; //Because choice 6 was already taken as a successful flee, this changes the value of choice to 5 which will do "nothing" or act as a failed flee.
				}
				
				//Enemy Turn:
				if(enemyHP > 0 && choice != 4 && choice != 3 && choice != 6)
				{
					if(enemyType == 1)
					{
						enemyMove = rand() % 2 + 1;
						if(enemyMove == 1)
						{
							damage = rand() % 4 + 4;
							enemyAttack();
							attackResultPrint();
						}
						else
						{
							damage = rand() % 20+1;
							enemyAttack();
							if(damage < 1)
								printf("You successfully blocked all the \033[31mdamage\033[0m!\n");
							else if(damagePrior != damage)
								printf("The %s thows a bunch of nuts at you! You blocked some of the damage, but the nuts still deal \033[31m%d damage\033[0m to you.\n", enemy, damage);
							else
								printf("The %s throws a bunch of nuts and does \033[31m%d damage\033[0m to you!\n", enemy, damage);
							printHealthLeft();
						}
					}
					else if(enemyType == 2)
					{
						enemyMove = rand() % 3 + 1;
						if(enemyMove == 1)
						{
							damage = rand() % 4 + 5;
							enemyAttack();
							attackResultPrint();
						}
						else if(enemyMove == 2)
						{
							damage = rand() % 6 + 6;
							enemyAttack();
							critResultPrint();
						}
						else
						{
							if(enemyFlight == 0)
							{
								enemyFlight = 3;
								printf("The %s flys high into the sky! Your melee attack can't hit it from here.\n", enemy);
							}
							else if (enemyFlight > 0)
							{
								enemyFlight = 3;
								printf("The %s flys into an updraft! It will be in the sky longer. Your melee attack can't hit it from here.\n", enemy);
							}
						}
					}
					else if(enemyType == 3)
					{
						enemyMove = rand() % 3 + 1;
						if(enemyMove == 1)
						{
							damage = rand() % 4 + 6;
							enemyAttack();
							attackResultPrint();
						}
						else if(enemyMove == 2)
						{
							damage = rand() % 6 + 7;
							enemyAttack();
							critResultPrint();
						}
						else
						{
							enemyDamageBuff += 1;
							printf("The %s howls loudly and gets stronger.\n", enemy);
						}
					}
					else if(enemyType == 4)
					{
						if(enemyLazy > 2)
						{
							enemyLazy = 0;
							printf("The %s is resting.\n", enemy);
						}
						else
						{
							enemyMove = rand() % 4 + 1;
							if(enemyMove == 1)
							{
								damage = rand() % 4 + 6;
								enemyAttack();
								attackResultPrint();
								enemyDamageBuff -= bearBuff;
								bearBuff = 0;
							}
							else if(enemyMove == 2)
							{
								damage = rand() % 6 + 7;
								enemyAttack();
								critResultPrint();
								enemyDamageBuff -= bearBuff;
								bearBuff = 0;
							}
							else if(enemyMove == 3)
							{
								bearBuff = rand() % 4 + 3;
								enemyDamageBuff += bearBuff;
								printf("The %s is gearing up for a more powerful attack!\n", enemy);
							}
							else
							{
								heal = rand() % 6 + 5;
								if(heal + enemyHP > enemyMaxHP)
									enemyHP = enemyMaxHP;
								else
									enemyHP += heal;
								printf("The %s eats some \033[33mhoney\033[0m and regains \033[32m%d health\033[0m. The %s now has %d health.\n", enemy, heal, enemy, enemyHP);
							}
							enemyLazy ++;
						}
					}
					scanf("%c", &chara);
					//This lowers the enemy's flight.
					if(enemyFlight > 0)
					{
						enemyFlight --;
						if(enemyFlight == 0)
						{
							printf("The %s has landed.\n", enemy);
							scanf("%c", &chara);
						}
					}
				}
				else
				{
					if(choice == 6)
					{
						enemyHP = 0;
					}
					else if(enemyHP <= 0)
					{
						printf("You defeated the %s!\n", enemy);
						
						denariiFound = rand() % 10 + 1;
						
						if(enemyType == 4) //If you defeat the bear you either get more denarii or you get honey.
						{
							if (rand() % 2 + 1 == 1 && isInventoryFull() == 1)
							{
								for(int loop = 0; loop < 10; loop ++)
								{
									if(inventory[loop] == 0)
									{
										inventory[loop] = 9;
										break;
									}
								}
								printf("The %s left behind some of its \e[0;33mhoney\033[0m!\n",enemy);
							}
							else
							{
								denariiFound += 5;
								denarii += denariiFound;
								printf("You collected \e[0;33m%d denarii\033[0m! You now have \e[0;33m%d denarii\033[0m.\n", denariiFound, denarii);
							}
						}
						else
						{
							denarii += denariiFound;
							
							printf("You collected \e[0;33m%d denarii\033[0m! You now have \e[0;33m%d denarii\033[0m.\n", denariiFound, denarii);
						}
						scanf("%c", &chara);
					}
				}
			}
			//This resets the stats from the battle.
			enemyFlight = 0;
			enemyDamageBuff = enemyBaseDamageBuff;
			bearBuff = 0;
			addToLog(levels, encounter, enemyType, maxHP, hp);
		}
		else if (encounter == 2)
		{
			//Resting Spot Encounter
			randomCheck = rand() % 100 + 1;
			if (hp < 21)
						printf("\nYou currently have \033[5;31m%d health\033[0m.\n", hp);
					else
						printf("\nYou currently have \033[32m%d health\033[0m.\n", hp);
						
			if (randomCheck < 61)
				printf("You come into a clearing. There is a peaceful river flowing nearby. It looks like a nice spot to rest.\nWhat would you like to do?\n1) Rest (heal 8-13 health)\n2) Look Around (next encounter is a chest)\n3) Fish (%d%% chance of catching a fish)\n", fishingChance);
			else
				printf("You come into a clearing. There is a cosy looking log in the center. It looks like a nice spot to rest.\nWhat would you like to do?\n1) Rest (heal 10-15 health)\n2) Look Around (next encounter is a chest)\n3) Hunt (40%% of healing 20-25 health)\n");
				
			do
			{
				if (scanf("%d", &choice) == 1) {}
				else
					while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
					
				if(choice < 1 || choice > 3)
				{
					printf("\n\033[31mPlease select an option between 1-3.\033[0m\n\n");
				}
					
			} while(choice < 1 || choice > 3);
				
			while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
				
			if(choice == 1)
			{
				if (randomCheck < 61)
					heal = rand() % 6 + 8;
				else
					heal = rand() % 6 + 10;
					
				if (hp + heal > maxHP)
				{
					hp = maxHP;
					printf("You wake fully rested and are healed to the max. You have %d health.\n", hp);
				}
				else
				{
					hp += heal;
					printf("You take a quick nap and heal \033[32m%d health\033[0m! You now have %d health.\n", heal, hp);
				}
			}
			else if(choice == 2)
			{
				printf("You look around the clearing and spot a chest!\n");
			}
			else
			{
				if (randomCheck < 61)
				{
					if(isInventoryFull() == 1)
					{
						printf("You go over to the river to fish.\n");
						goFishing();
					}
					else
						printf("Your inventory is full!\n");
				}
				else
				{
					choice =rand() % 100 + 1;
					if (choice <= 40)
					{
						heal = rand() % 6 + 20;
						if (heal + hp > maxHP)
						{
							hp = maxHP;
							printf("You hunt some food and heal. You heal to \033[32mmaximum health\033[0m! You now have %d health.\n", hp);
						}
						else
						{
							hp += heal;
							printf("You hunt some food and heal. You heal by \033[32m%d\033[0m! You now have %d health.\n", heal, hp);
						}
					}
					else
					{
						if (rand() % 2 + 1 == 1)
							printf("You couldn't find anything to hunt.\n");
						else
							printf("You went hunting, but you weren't able to catch anything.\n");
					}
				}
				choice = 3; //This resets the choice to three for the encounter check later that determines if the next enocunter is a chest.
			}
			scanf("%c", &chara);
			addToLog(levels, encounter, choice, maxHP, hp);
		}
		else if(encounter == 3)
		{
			printf("You find a chest! What do you want to do?\n1) Open It\n2) Leave It\n");
			do
			{
				if (scanf("%d", &choice) == 1) {}
				else
					while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
					
				if(choice < 1 || choice > 2)
				{
					printf("\n\033[31mPlease select an option between 1-2.\033[0m\n\n");
				}
					
			} while(choice < 1 || choice > 2);
				
			while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
			
			if(choice == 1)
			{
				randomCheck = rand() % 4 + 1;
				if (randomCheck == 1) //Old Hook
				{
					if (fishingChance + 5 > 80) //This makes the maximum fishing chance a player can have to be 80.
					{
						printf("You found an Old Hook! However your fishing chance cannot be increased further.\n");
					}
					else
					{
						fishingChance += 5;
						printf("You found an Old Hook! Your fishing chance has increased to %d.\n", fishingChance);
					}
				}
				else if (randomCheck == 2) //Heart Necklace
				{
					maxHP += 5;
					hp += 5;
					printf("You found a Heart Necklace! Your maximum health has increased to \033[32m%d\033[0m\n", maxHP);
				}
				else if (randomCheck == 3) //Warm Soup
				{
					heal = 15;
					if (hp + heal > maxHP)
					{
						hp = maxHP;
						printf("You found some Warm Soup! You eat it and are \033[32mfully healed!\033[0m!\n");
					}
					else
					{
						hp += heal;
						printf("You found some Warm Soup! You eat it and heal by \033[32m%d health\033[0m. You now have %d health.\n", heal, hp);
					}
				}
				else //Thorn
				{
					attackStrength += 1;
					printf("You found a Thorn! Your attack strength has been increased to %d!\n", attackStrength);
				}
			}
			else
			{
				printf("It's probably safer to leave it alone...\n");
				randomCheck = 0; //This is for the log so it knows if you didn't open the chest.
			}
			scanf("%c", &chara);
			addToLog(levels, encounter, randomCheck, maxHP, hp);
		}
		else if(encounter == 4)
		{
		}
		else if(encounter == 5)
		{
		}
		
		if(hp > 0) //This is so it doesn't count the level you lost on.
			levels ++;
		
		//This will increase the damage of all enemies by 1 every ten levels.
		if(levels % 10 == 0)
			enemyBaseDamageBuff ++;
			
		//This will increase the health of all enemies by 5 every twenty levels.
		if(levels % 20 == 0)
			enemyBaseHPBuff += 5;
			
		if (encounter == 2 && choice == 2)
			encounter = 3;
		else
		{
			if (difficulty == 4) //Makes enemies slightly more common for Master difficulty.
			{
				encounter = rand() % 100 + 1;
				/*
				if (encounter < 41)
					encounter = 1; //Enemy
				else if (encounter < 56)
					encounter = 2; //Rest Spot
				else if (encounter < 76)
					encounter = 3; //Chest
				else if (encounter < 91)
					encounter = 4; //Shop
				else
					encounter = 5; //Pond
					*/
					if (encounter < 61) //This is used because encounters 4 and 5 are not complete.
						encounter = 1;
					else if (encounter < 81)
						encounter = 2;
					else
						encounter = 3;
			}
			else
			{
				encounter = rand() % 100 + 1;
				/*
				if (encounter < 41)
					encounter = 1; //Enemy
				else if (encounter < 61)
					encounter = 2; //Rest Spot
				else if (encounter < 81)
					encounter = 3; //Chest
				else if (encounter < 91)
					encounter = 4; //Shop
				else
					encounter = 5; //Pond
					*/
					if (encounter < 51) //This is used because encounters 4 and 5 are not complete.
						encounter = 1;
					else if (encounter < 76)
						encounter = 2;
					else
						encounter = 3;
			}
		}
		
		if (showLog == 0)
		{
			printf("Do you want to view the log?\n1) Yes\n2) No\n3) Hide Log this Game\n");
			do
			{
				if (scanf("%d", &choice) == 1) {}
				else
					while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
					
				if(choice < 1 || choice > 3)
				{
					printf("\n\033[31mPlease select an option between 1-3.\033[0m\n\n");
				}
					
			} while(choice < 1 || choice > 3);
				
			while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
			
			if(choice == 1)
			{
				for (int loop = 0; loop < 10; loop ++)
				{
					if(log[loop][2] == 0)
						printf("Undiscovered.\n");
					else
					{
						printf("Level: %d. ", log[loop][1] + 1); //Adds one because the level counter doesn't increase until after the log is recorded.
						if (log[loop][2] == 1)
						{
							if(log[loop][3] == 1)
								printf("Fought: Squirrel. ");
							else if(log[loop][3] == 2)
								printf("Fought: Eagle. ");
							else if(log[loop][3] == 3)
								printf("Fought: Coyote. ");
							else if(log[loop][3] == 4)
								printf("Fought: Bear. ");
						}
						else if (log[loop][2] == 2)
						{
							if(log[loop][3] == 1)
								printf("Action: Rested. ");
							else if(log[loop][3] == 2)
								printf("Action: Looked Around. ");
							else if(log[loop][3] == 3)
								printf("Action: Hunted or Fished. ");
						}
						else if (log[loop][2] == 3)
						{
							if(log[loop][3] == 0)
								printf("Found: Not Opened. ");
							else if(log[loop][3] == 1)
								printf("Found: Old Hook. ");
							else if(log[loop][3] == 2)
								printf("Found: Heart Necklace. ");
							else if(log[loop][3] == 3)
								printf("Found: Warm Soup. ");
							else if(log[loop][3] == 4)
								printf("Found: Thorn. ");
						}
						else if (log[loop][2] == 4)
						{
						}
						else
						{
						}
						printf("Max Health: %d. ", log[loop][4]);
						printf("Health: %d.\n", log[loop][5]);
					}
				}
			}
			else if (choice == 2) {}
			else
				showLog = 1;
			printf("\n");
		}
	}
	if(levels == 1)
		printf("Oh no! I'm afraid you were defeated. You completed 1 level! You had \e[0;33m%d denarii\033[0m and ", denarii);
	else
		printf("Oh no! I'm afraid you were defeated. You completed %d levels! You had \e[0;33m%d denarii\033[0m and ", levels, denarii);
	
	if(difficulty == 1)
		printf("you were playing the normal difficulty. Thanks for playing!\n");
	else if(difficulty == 2)
		printf("you were playing the Low Health mode. Thanks for playing!\n");
	else if(difficulty == 3)
		printf("you were playing the Medium Health mode. Thanks for playing!\n");
	else
		printf("you were playing the master difficulty. Thanks for playing!\n");
	
	system("sl"); //Just for fun if you have it installed (at least on Linux) this will play a train animation.
	return 0;
}
