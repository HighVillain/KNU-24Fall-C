#include <conio.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <io.h> 
#include <Windows.h>
#include <time.h>

int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;
int snake_length;
int snake_x[400], snake_y[400];
clock_t start_time;
double decreasing_time = 180.0,timer;
int healthx, healthy, bombx, bomby, sfruitx, sfruity;
const double PlusTime=30.0, MinusTime=30.0;
const int life = 16, bomb=26,special=40;


void setup() //초기 설정을 해주는 함수
{
	gameover = 0;

	x = height / 2;
	y = width / 2;
	srand(time(NULL));

	fruitx = 0;
	while (fruitx == 0) {
		fruitx = rand() % (width - 2) + 1;
	} 
	fruity = 0; 
	while (fruity == 0) {
		fruity = rand() % (height - 2) + 1;
	} 
	healthx = 0; 
	while (healthx == 0) { 
		healthx = rand() % (width - 2) + 1;
	} 
	healthy = 0;
	while (healthy == 0) {
		healthy = rand() % (height - 2) + 1;
	} 
	bombx = 0;
	while (bombx == 0) {
		bombx = rand() % (width - 2) + 1;
	} 
	bomby = 0;
	while (bomby == 0) {
		bomby = rand() % (height - 2) + 1;
	} 
	sfruitx = 0; 
	while (sfruitx == 0) {
		sfruitx = rand() % (width - 2) + 1;
	} 
	sfruity = 0;
	while (sfruity == 0) 	{
		sfruity = rand() % (height - 2) + 1;
	}


	score = 0; //게임 점수의 초기값 설정
	start_time = clock (); //타이머 시작
	snake_length = 1; //뱀의 초기 길이 설정
	snake_x[0] = x; 
	snake_y[0] = y;
}

void draw() 
{
	system("cls");
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (i == 0 || i == width - 1 || j == 0|| j == height - 1) {
				printf("#"); //게임판 그리기
			} else {
				int printed = 0; 
				for (int k = 0; k < snake_length; k++) {//뱀을 그리는 반복문
					if (i == snake_x[k] && j == snake_y[k]) {
						printf("0");
						printed = 1;
						break;
					}
				}
				if (!printed) {//뱀이 없는 위치라면 아래와 같은 조건에 부합했을 때 아래 열매들과 빈칸을 생성
					if (i == fruitx && j == fruity)
						printf("*");
					else if (score >= life && i == healthx && j == healthy)
						printf("♥");
					else if (score >= bomb && i == bombx && j == bomby)
						printf("⊙");
					else if (score >= special && i == sfruitx && j == bomby)
						printf("S");
					else
						printf(" ");
				}
			}
		}
		printf("\n");
	}
	
	printf("score = %d", score);
	printf("\n");
	printf("x를 눌러 게임을 종료합니다.\n");
	
	timer = (double)(clock() - start_time) / CLOCKS_PER_SEC;
	double remain_time = decreasing_time - timer;
	if (remain_time >=0) {
		printf("남은 시간:  %d 분 %d 초\n", (int)remain_time / 60, (int)remain_time % 60);
	}
	else {
		printf("▶TIME OVER !◀\n");
	}
}

void input()
{
	if (_kbhit()) {
		switch (getch()) {
		case 'a':
		case 'A':
			flag = 1;
			break;
		case 's':
		case 'S':
			flag = 2;
			break;
		case 'd':
		case 'D':
			flag = 3;
			break;
		case 'w':
		case 'W':
			flag = 4;
			break;
		case 'x':
		case 'X':
				gameover = 1;
			break;
		}
	}
}

void remove_items() {
	int min_x = x - 1, max_x = x + 1;
	int min_y = y - 1, max_y = y + 1;
	if (fruitx >= min_x && fruitx <= max_x && fruity >= min_y && fruity <= max_y) {
		fruitx = rand() % (width - 2) + 1;
		fruity = rand() % (height - 2) + 1;
	}
	if (healthx >= min_x && healthx <= max_x && healthy >= min_y && healthy <= max_y) {
		healthx = rand() % (width - 2) + 1;
		healthy = rand() % (height - 2) + 1;
	}
	if (sfruitx >= min_x && sfruitx <= max_x && sfruity >= min_y && sfruity <= max_y) {
		sfruitx = rand() % (width - 2) + 1;
		sfruity = rand() % (height - 2) + 1;
	}
}

void logic()
{
	Sleep(200);

	for (int k = snake_length - 1; k > 0; k--) {
		snake_x[k] = snake_x[k - 1];
		snake_y[k] = snake_y[k - 1];
	}

	switch (flag) {
	case 1:
		snake_y[0]--;
		break;
	case 2:
		snake_x[0]++;
		break;
	case 3:
		snake_y[0]++;
		break;
	case 4:
		snake_x[0]--;
		break;
	default:
		break;
	}

	x = snake_x[0];
	y = snake_y[0];

	if (x < 0 || x > height|| y < 0 || y > width)
		gameover = 1;


	if (x == fruitx && y == fruity) {
		fruitx = 0; 
		while (fruitx == 0) {
			fruitx = rand() % (width - 2) + 1;
		} 
		fruity = 0; 
		while (fruity == 0) {
			fruity = rand() % (height - 2) + 1;
		}
		score += 10;
		snake_length++;
	}

	if (score>=life&&x == healthx && y == healthy) {
		healthx = 0;
		while (healthx == 0) {
			healthx = rand() % (width - 2) + 1;
		} 
		healthy = 0;
		while (healthy == 0) { 
			healthy = rand() % (height - 2) + 1;
		}
		decreasing_time += PlusTime;
		snake_length++;
	}

	if (score>=bomb && x == bombx && y == bomby) {
		bombx = 0;
		while (bombx == 0) {
			bombx = rand() % (width - 2) + 1;
		} 
		bomby = 0; 
		while (bomby == 0) {
			bomby = rand() % (height - 2) + 1;
		}
		remove_items();
		decreasing_time -= MinusTime;
	}

	if (score>=special&&x == sfruitx && y == sfruity) {
		sfruitx = 0; 
		while (sfruitx == 0) {
			sfruitx = rand() % (width - 2) + 1;
		}
		sfruity = 0; 
		while (sfruity == 0) { 
			sfruity = rand() % (height - 2) + 1;
		}
		score += 3;
		snake_length++;
	}

	timer = (double)(clock() - start_time) / CLOCKS_PER_SEC;
	if (timer >= decreasing_time) {
		gameover = 1;
	}
}

void main()
{
	setup();

	while (!gameover) {
		draw();
		input();
		logic();
	}
	printf("--------------------------\n");
	printf("\t▶게임결과◀\t\n");
	printf("점수: %d\n", score);
	printf("총 플레이 시간: %d 분 %d 초\n", (int)timer/60,(int)timer%60);
	printf("--------------------------\n");
	return 0;
}
