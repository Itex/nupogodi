//============================================================================
// Name        : nuPogodi.cpp
// Author      : xolvo & David
// Version     :
// Copyright   :
// Description :
//============================================================================

/* TODO list for this project
	1. Переделать фон
	2. Вставить музыку
	3. Сделать лучший результат
	4. Изменить сканирование движения
	5. Исправить Devid на David
	6. Подумать о реализации игры
/*----------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

int bestscore=-1;
int sou=100;

enum {UP_ARROW=72, LEFT_ARROW=75, DOWN_ARROW=80, RIGHT_ARROW=77, ESC=27, ENTER=13};
void action();

void back_pic() {
	settextstyle(4, 0, 3); // font family, derection, size
	outtextxy(260, 60, "Nu, pogodi!");
	/* The Grass =) */
	setcolor(2);
	for(int i=0;i<639;i+=2)
		line(i, 330, i, 325);
	/* Developers */
	setcolor(15);
	settextstyle(0, 0, 1);
	outtextxy(200, 100, "Developed by David & Sanchez Inc.");
	sound(sou);
	delay(150);
	nosound();
	sou=sou+100;
}

void woolf(int x,int y) {
	setcolor(7);
	setfillstyle(1, 7);
	rectangle(20+x,20+y,70+x,30+y);
	floodfill(69+x,29+y,7);
	circle(20+x,20+y,5);

	circle(60+x,20+y,10);

	line(65+x,10+y,70+x,5+y);
	line(68+x,20+y,70+x,5+y);
	ellipse(60+x,60+y,0,360,20,30);
	line(67+x,90+y,90+x,130+y);
	line(53+x,90+y,30+x,130+y);
	/* arms */
	line(40+x,60+y,x,60+y);
	line(40+x,60+y,x,80+y);
	/* fill woolf */
	floodfill(19+x,20+y,7);
	floodfill(59+x,19+y,7);
	floodfill(60+x,60+y,7);
	setcolor(15);
}

void two_chickens(int x, int y) {
	setfillstyle(9, 14);

	/* first chicken */
	ellipse(x, y, 0, 360, 20, 8);
	circle(x - 15, y - 12, 7);
	/* fill chicken's body and head*/
	floodfill(x, y + 1, 15);
	floodfill(x - 15, y - 13, 15);

	/* second chicken */
	ellipse(x - 20, y + 20, 0, 360, 20, 8);
	circle(x - 35, y + 7, 7);
	/* fill chicken's body and head*/
	floodfill(x - 20, y + 21, 15);
	floodfill(x - 35, y + 8, 15);
}

int isstart(int y) {
	int value=0;

	if(y==61)
		value=1;

	return value;
}

int arrow(char KeyStroke) {

  KeyStroke=getch();
  if(KeyStroke==0)
		KeyStroke=getch();

	return KeyStroke;
}

void active_item(int y) {
  setfillstyle(9, 12);
  floodfill(31, y, 15);
}

void text(int y) {
  if(y==61) {
		outtextxy(240, 70, "Will start in 2 seconds...");
	}
  if(y==121) {
		outtextxy(370, 70, "Hight score");
		char hs[100];
		FILE *st;
		st=fopen("file.txt","r");
		fgets(hs,100,st);
		outtextxy(240, 90, hs);
		fclose(st);
	}
  if(y==181 || y==1) {
		/* TODO think about rules improvements */

		outtextxy(240, 70, "To win in this game you should catch all");
		outtextxy(240, 80, "eggs with the basket.");
		outtextxy(240, 90, "If you didn't catch one egg you would have");
		outtextxy(240, 100, "another attempt to catch another egg.");
		outtextxy(240, 110, "But you have only 3 attempts.");

		outtextxy(240, 130, "To catch left top egg you should");
		outtextxy(240, 140, "press 'A' key. To catch left bottom egg");
		outtextxy(240, 150, "press 'Z' key. To catch right top egg press");
		outtextxy(240, 160, "'\"' key. To catch right bottom egg press");
		outtextxy(240, 170, "'/' key.");
		outtextxy(240, 190, "Good luck =) ");
	}
}

void menutext() {
	/*нарисовать прямоугольник*/
  rectangle(30, 60, 200, 100);
  /*нарисовать второй прямоугольник*/
  rectangle(30, 120, 200, 160);
  /*нарисовать третий прямоугольник*/
  rectangle(30, 180, 200, 220);
  /*нарисовать главную область*/
  rectangle(230, 60, getmaxx()-50, getmaxy()-50);

  outtextxy(30, 10, "UP and DOWN arrow - for navigate");
  outtextxy(30, 20, "ENTER - for choice");
  outtextxy(30, 30, "ESC - for exit");

  outtextxy(35, 65, "Start the game");
  outtextxy(35, 125, "Hight score");
  outtextxy(35, 185, "Rules");
}

void menu() {
	char arrow_key;
	int y=61;

	cleardevice();
	menutext();
  active_item(y);

	do {
	arrow_key=arrow(arrow_key);

    switch(arrow_key) {
		case DOWN_ARROW:
		/* !!! ОЧЕНЬ НУЖНАЯ ДВОЙНАЯ ПРОВЕРКА !!! */
		/* ======================================= */
		/* двойная проверка нужна, что бы вдруг при нажатии на */
		/* стрелку вверх не произшло прибавление 60 на последующем этапе */
		/* и экран не закрасился */
		  if(y>=181)
		    y=1;
		  cleardevice();
		  menutext();
		  active_item(y+=60);
		  if(y>=181) /* т.к. пунктов меню всего три делаем так */
		    y=1;     /* для последующего сложения с 60 и получения правильных результатов */
		break;

		case UP_ARROW:
		  switch(y) {
			case 1:
			  y=121; /* что бы исправить переход вниз */
			  cleardevice();
	      menutext();
	      active_item(y);
			break;

			case 121:
			  y=61;
			  cleardevice();
	      menutext();
	      active_item(y);
			break;

			case 61:
			  y=181;
			  cleardevice();
			  menutext();
			  active_item(y);
			break;

			case 181:
			  y=121;
			  cleardevice();
	      menutext();
	      active_item(y);
			break;
		  }
		break;

		case ENTER:
		  text(y);
			if(isstart(y)==1) {
				delay(200);
				action();
			}
		break;
    }
  } while(arrow_key!=ESC);
}

void vlvv(int x, int y) {
  setcolor(7);
	setfillstyle(1,7);
	rectangle(20+x,20+y,70+x,30+y);
	floodfill(69+x,29+y,7);
	circle(20+x,20+y,5);

	circle(60+x,20+y,10);

	line(65+x,10+y,70+x,5+y);
	line(68+x,20+y,70+x,5+y);
	ellipse(60+x,60+y,0,360,20,30);
	line(67+x,90+y,90+x,130+y);
	line(53+x,90+y,30+x,130+y);
	line(40+x,60+y,10+x,60+y);
	ellipse(10+x,50+y,180,360,10,10);
	floodfill(19+x,20+y,7);
	floodfill(59+x,19+y,7);
	floodfill(60+x,60+y,7);
	setcolor(15);
}
void vlvn(int x,int y)
{
setcolor(7);
setfillstyle(1,7);
rectangle(20+x,20+y,70+x,30+y);
floodfill(69+x,29+y,7);
circle(20+x,20+y,5);
circle(60+x,20+y,10);
line(65+x,10+y,70+x,5+y);
line(68+x,20+y,70+x,5+y);
ellipse(60+x,60+y,0,360,20,30);
line(67+x,90+y,90+x,130+y);
line(53+x,90+y,30+x,130+y);
line(40+x,60+y,10+x,80+y);
ellipse(10+x,70+y,180,360,10,10);
floodfill(19+x,20+y,7);
floodfill(59+x,19+y,7);
floodfill(60+x,60+y,7);
setcolor(15);
}
void vpvv(int x,int y)
{
setcolor(7);
setfillstyle(1,7);
rectangle(50+x,20+y,100+x,30+y);
floodfill(98+x,22+y,7);
circle(100+x,20+y,5);
circle(60+x,20+y,10);
line(60+x,15+y,50+x,5+y);
line(50+x,5+y,55+x,18+y);
ellipse(60+x,60+y,0,360,20,30);
line(67+x,90+y,90+x,130+y);
line(53+x,90+y,30+x,130+y);
line(80+x,60+y,120+x,60+y);
ellipse(120+x,50+y,180,360,10,10);
floodfill(101+x,21+y,7);
floodfill(61+x,19+y,7);
floodfill(60+x,60+y,7);
setcolor(15);
}

void vpvn(int x,int y)
{
setcolor(7);
setfillstyle(1,7);
rectangle(50+x,20+y,100+x,30+y);
floodfill(98+x,22+y,7);
circle(100+x,20+y,5);
circle(60+x,20+y,10);
line(60+x,15+y,50+x,5+y);
line(50+x,5+y,55+x,18+y);
ellipse(60+x,60+y,0,360,20,30);
line(67+x,90+y,90+x,130+y);
line(53+x,90+y,30+x,130+y);
line(80+x,60+y,120+x,80+y);
ellipse(120+x,70+y,180,360,10,10);
floodfill(101+x,21+y,7);
floodfill(61+x,19+y,7);
floodfill(60+x,60+y,7);
setcolor(15);
}

void chickens() {
	line(getmaxx()/2 - 190, getmaxy()/2 - 40, (getmaxx()/2 - 190) + 50, getmaxy()/2 - 40);
	/* start of left up chicken */
	ellipse(getmaxx()/2 - 165, getmaxy()/2 - 48, 0, 360, 20, 8);
	circle(getmaxx()/2 - 150, getmaxy()/2 - 60, 7);
	/* end of chicken */
	line(getmaxx()/2 - 187, getmaxy()/2 - 40, getmaxx()/2 - 60, getmaxy()/2);

	line(getmaxx()/2 - 190, getmaxy()/2 + 20, (getmaxx()/2 - 190) + 50, getmaxy()/2 + 20);
	/* start of left down chicken */
	ellipse(getmaxx()/2 - 165, getmaxy()/2 + 12, 0, 360, 20, 8);
	circle(getmaxx()/2 - 150, getmaxy()/2, 7);
	/* end of chicken */
	line(getmaxx()/2 - 187, getmaxy()/2 + 20, getmaxx()/2 - 60, getmaxy()/2 + 60);

	line(getmaxx()/2 + 190, getmaxy()/2 - 40, (getmaxx()/2 + 190) - 50, getmaxy()/2 - 40);
	/* start of right up chicken */
	ellipse(getmaxx()/2 + 165, getmaxy()/2 - 48, 0, 360, 20, 8);
	circle(getmaxx()/2 + 150, getmaxy()/2 - 60, 7);
	/* end of chicken */
	line(getmaxx()/2 + 187, getmaxy()/2 - 40, getmaxx()/2 + 60, getmaxy()/2);

	line(getmaxx()/2 + 190, getmaxy()/2 + 20, (getmaxx()/2 + 190) - 50, getmaxy()/2 + 20);
	/* start of right down chicken */
	ellipse(getmaxx()/2 + 165, getmaxy()/2 + 12, 0, 360, 20, 8);
	circle(getmaxx()/2 + 150, getmaxy()/2, 7);
	/* end of chicken */
	line(getmaxx()/2 + 187, getmaxy()/2 + 20, getmaxx()/2 + 60, getmaxy()/2 + 60);
}
void best(int bestscore)
{
char name[20];
FILE *fPtr;
int oldbest=0;

if((fPtr=fopen("file.txt","r"))==NULL)//schitivaem proshliy luchsiy rezultat
printf("First game?\n");
else
{
   fscanf(fPtr,"%d",&oldbest);
   printf("%d ",oldbest+1);

fclose(fPtr);

}


if(oldbest>bestscore)
{
puts("Try Again");
getch();
}
else
{

if((fPtr=fopen("file.txt","w+"))==NULL)//esli uslovie vipoln
printf("File could not to be opened\n");
else
{


puts("Enter your name");
scanf("%s",name);
fprintf(fPtr,"%d ",bestscore);
fprintf(fPtr,"%s ",name);
}
fclose(fPtr);

}

}

void action() {
	int y=61;

		cleardevice();
		chickens();
		vlvv(255, 200);
	       //	int bestscore=-1;
		int dvig=-1; // for fixing bug
		while(dvig!=ESC) {
			dvig=getch();
			bestscore++;
			if(dvig==97) {
				cleardevice();
				chickens();
				vlvv(255, 200);
			}
			if (dvig==122) {
				cleardevice();
				chickens();
				vlvn(255,200);
			}
			if(dvig==39) {
				cleardevice();
				chickens();
				vpvv(255,200);
			}
			if (dvig==47) {
				cleardevice();
				chickens();
				vpvn(255,200);
			}
		}
		best(bestscore);
		cleardevice();
    menutext();
    active_item(y);
}

void main() {
  int gd, gm, error;
  char arrow_key;
  int y=61, i;

  detectgraph (&gd, &gm);
  initgraph (&gd, &gm, "C:\\borlandc\\bgi");
  error = graphresult ();

  if(error != grOk) {
    puts (grapherrormsg (error));
    exit (-1);
  }

/* Splash befor the game */
  for(i=0;i<260;i+=20) {
		cleardevice();
		back_pic();
		woolf(290-i, 200);
		two_chickens(250-i, 300);
		delay(150);


	}
/*-----------------------*/

	menu();

  closegraph();
}
