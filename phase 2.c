#include <stdio.h>
#include <conio.h>
	struct Location
	{
		int x;
		int y;
	};
	void up (char [5][10], struct Location *);
	void down (char [5][10], struct Location *);
	void left(char [5][10], struct Location *);
	void right (char [5][10], struct Location *);
	void print_maze (char [][10]);
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
				
			printf("if you want to play pacman type in: 'Y'\n");
			char start;
			scanf("%c", &start);
			if (start=='Y' || start=='y')
			{
					print_maze(maze);			
					int ch1, ch2;
					printf("if you want to end the game at any point type in -1 \n");
					while((ch1 = getch())!=-1)
					{
						ch2 = 0;
						if (ch1 == 0xE0) 
						{ // a scroll key was pressed
							ch2 = getch();
							// determine what it was
							switch(ch2)
							{
								case 72:
									system("cls");
									up(maze, ptr);
								 	continue;
								case 80:
							 	system("cls");
							 	down(maze, ptr); 
							 	continue;
								case 75: 
									system("cls");
									left(maze, ptr); 
								continue;
								case 77: 
									system("cls");
									right(maze, ptr); 
									continue;
							};
	
						}
					}
	
			}
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
	void right (char maze [][10], struct Location *ptr)
	{
		int x, y;
		x=ptr->x;
		y=ptr->y;
		char temp;
			if (maze[x][y+1]=='*') maze[x][y+1]='-';
			temp=maze[x][y+1];
			maze[x][y+1]=maze[x][y];
			maze[x][y]=temp;
			ptr->y++;
			print_maze(maze);
	}
	void left (char maze [][10], struct Location *ptr)
	{
		int x, y;
		x=ptr->x;
		y=ptr->y;
		char temp;
		if (maze[x][y-1]=='*') maze[x][y-1]='-';
		temp=maze[x][y-1];
		maze[x][y-1]=maze[x][y];
		maze[x][y]=temp;
		ptr->y--;
		print_maze(maze);
	}
	void up (char maze [][10], struct Location *ptr)
	{
		int x, y;
		x=ptr->x;
		y=ptr->y;
		char temp;
		if (maze[x-1][y]=='*') maze[x-1][y]='-';
		temp=maze[x-1][y];
		maze[x-1][y]=maze[x][y];
		maze[x][y]=temp;
		ptr->x--;
		print_maze(maze);
	}
	void down (char maze [][10], struct Location *ptr)
	{
		int x, y;
		x=ptr->x;
		y=ptr->y;
		char temp;
		if (maze[x+1][y]=='*') maze[x+1][y]='-';
		temp=maze[x+1][y];
		maze[x+1][y]=maze[x][y];
		maze[x][y]=temp;
		ptr->x++;
		print_maze(maze);
	}

