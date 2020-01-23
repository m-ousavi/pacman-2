#include <stdio.h>
#include <conio.h>
	struct Location
	{
		int x;
		int y;
	};
	void up (char [5][10], struct Location *, struct Location *, int);
	void down (char [5][10], struct Location *, struct Location *, int);
	void left(char [5][10], struct Location *, struct Location *, int);
	void right (char [5][10], struct Location *, struct Location *, int);
	void print_maze (char [][10]);
	int checkfood (struct Location *, int);
	int whereisfood (struct Location *, int, int, int);
	int main()
	{
		struct Location pacman;
		struct Location *ptr;
		ptr=&pacman;
		struct Location foodlist[50];
		char maze[5][10];
		char c;
		FILE *p;
		if (p==NULL)
		{
			printf("file could not be opened");
		}
		else
		{
			p=fopen("C:\\Users\\ACER\\Desktop\\map2.txt","r+");
			int i, j;
			int cnt=0;
			for (i=0; i<5; i++)
				for (j=0; j<10; j++)
				{
					while(feof(p)==0)
					{
						fscanf(p,"%c",&c);
						if (c=='1' || c=='0' || c=='#' || c=='*')
						{
							if (c=='0'){
								pacman.x=i;
								pacman.y=j;
							}
							if (c=='*'){
								foodlist[cnt].x=i;
								foodlist[cnt].y=j;
								cnt++;
							}	
							break;
						}
						else{
							continue;
						}
					}
				maze[i][j]=c;	
				}
				
			printf("press enter to start the game.\n");
			char start;
			scanf("%c", &start);
			if (start=='\n')
			{
					system("cls");				
					printf("if you want to end the game at any point type in -1 \n");
					sleep(1);
					system("cls");				
					print_maze(maze);			
					int ch1, ch2;
					int flag=0;
					while(flag==0)
					{
						ch1 = getch();
						ch2 = 0;
						if (ch1 == 0xE0 || ch1=='-') 
						{ 
							ch2 = getch();
							if (ch1=='-' && ch2=='1')
								break;
							switch(ch2)
							{
								case 72:
									system("cls");
									up(maze, ptr, foodlist, cnt);
									if (cnt==checkfood(foodlist, cnt))
									{
										system("cls");
										printf("You ate all the food!");
										flag++;
										break;
									} 
								 	continue;
								case 80:
							 		system("cls");
							 		down(maze, ptr, foodlist, cnt);
									if (cnt==checkfood(foodlist, cnt))
									{
										system("cls");
										printf("You ate all the food!");
										flag++;
										break;
									} 
							 		continue;
								case 75: 
									system("cls");
									left(maze, ptr, foodlist, cnt);
									if (cnt==checkfood(foodlist, cnt))
									{
										system("cls");
										printf("You ate all the food!");
										flag++;
										break;
									} 
									continue;
								case 77: 
									system("cls");
									right(maze, ptr, foodlist, cnt);
									if (cnt==checkfood(foodlist, cnt))
									{
										system("cls");
										printf("You ate all the food!");
										flag++;
										break;
									} 
									continue;
							};
	
						}
						/*if (cnt==checkfood(foodlist, cnt))
						{
							system("cls");
							printf("congrats you beat the game");
							break;
						}*/
					}
	
			}
		}
	}
	int checkfood(struct Location foodlist[], int num)
	{
		int counter=0, i;
		for (i=0; i<num; i++)
		{
			if (foodlist[i].x==0 && foodlist[i].y==0)
				counter++;
		}
		return counter;
		
	}
	int whereisfood (struct Location foodlist[], int x, int y, int num)
	{
		int i;
		for (i=0; i<num; i++)
		{
			if (foodlist[i].x==x && foodlist[i].y==y)
				return i;
		}
	}
	void print_maze(char maze [][10])
	{
		int i, j;
			for (i=0; i<5; i++)
			{
				for (j=0; j<10; j++)
				{
					if (maze[i][j]=='1') {
						printf("-  ");
					}
					else
					{
						printf("%c  ", maze[i][j]);
					}
			}
			printf("\n\n");				
		}
		sleep(1);
		//system("cls");
	}
	void right (char maze [][10], struct Location *ptr, struct Location foodlist[], int cnt)
	{
		int x, y;
		x=ptr->x;
		y=ptr->y;
		char temp;
		int foodishere;
		if (maze[x][y+1]=='#')
		{
			print_maze(maze);
			printf("cant move there!");
		}
		else
		{	
			if (maze[x][y+1]=='*')
			{
			 	maze[x][y+1]='-';
			 	foodishere=whereisfood(foodlist, x, y+1, cnt);
			 	foodlist[foodishere].x=0;
			 	foodlist[foodishere].y=0;
			} 	
			temp=maze[x][y+1];
			maze[x][y+1]=maze[x][y];
			maze[x][y]=temp;
			ptr->y++;
			print_maze(maze);
		}
	}
	void left (char maze [][10], struct Location *ptr, struct Location foodlist[], int cnt)
	{
		int x, y;
		x=ptr->x;
		y=ptr->y;
		char temp;
		int foodishere;
		if (maze[x][y-1]=='#')
		{
			print_maze(maze);
			printf("cant move there!");
		}
		else
		{
			if (maze[x][y-1]=='*') 
			{
				maze[x][y-1]='-';
			 	foodishere=whereisfood(foodlist, x, y-1, cnt);
			 	foodlist[foodishere].x=0;
			 	foodlist[foodishere].y=0;
			}
			temp=maze[x][y-1];
			maze[x][y-1]=maze[x][y];
			maze[x][y]=temp;
			ptr->y--;
			print_maze(maze);
		}
	}
	void up (char maze [][10], struct Location *ptr, struct Location foodlist[], int cnt)
	{
		int x, y;
		x=ptr->x;
		y=ptr->y;
		char temp;
		int foodishere;
		if (maze[x-1][y]=='#')
		{
			print_maze(maze);
			printf("cant move there!");
		}
		else
		{
			if (maze[x-1][y]=='*') 
			{
				maze[x-1][y]='-';
			 	foodishere=whereisfood(foodlist, x-1, y, cnt);
			 	foodlist[foodishere].x=0;
			 	foodlist[foodishere].y=0;
			}
			temp=maze[x-1][y];
			maze[x-1][y]=maze[x][y];
			maze[x][y]=temp;
			ptr->x--;
			print_maze(maze);
		}
	}
	void down (char maze [][10], struct Location *ptr, struct Location foodlist[], int cnt)
	{
		int x, y;
		x=ptr->x;
		y=ptr->y;
		char temp;
		int foodishere;
		if (maze[x+1][y]=='#')
		{
			print_maze(maze);
			printf("cant move there!");
		}
		else
		{	
			if (maze[x+1][y]=='*') 
			{
				maze[x+1][y]='-';
			 	foodishere=whereisfood(foodlist, x+1, y, cnt);
			 	foodlist[foodishere].x=0;
			 	foodlist[foodishere].y=0;
			}
			temp=maze[x+1][y];
			maze[x+1][y]=maze[x][y];
			maze[x][y]=temp;
			ptr->x++;
			print_maze(maze);
		}
	}

