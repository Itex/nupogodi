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

#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <bios.h>

int bestscore=0;
int sou=100;//Переменная частоты звука

enum {UP_ARROW=72, LEFT_ARROW=75, DOWN_ARROW=80, RIGHT_ARROW=77, ESC=27, ENTER=13};
enum bios_keis {bios_up = 18432, bios_right = 19712, bios_down = 20480, bios_left = 19200, bios_esc = 283, bios_enter = 7181,
		up_left = 7777, down_left = 11386, up_right = 10279, down_right = 13615};

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
	delay(50);
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

int egg(int buf)
{
switch (buf){
case 1:
	{
	setcolor(BLACK);
	circle(250,236,6);
	circle(237,259,6);
	circle(390,232,6);
	circle(390,260,6);
	setcolor(15);
	circle(182,191,6);
	}
break;	
case 2:
	{
	setcolor(BLACK);
	circle(250,236,6);
	circle(237,259,6);
	circle(390,232,6);
	circle(390,260,6);
	setcolor(15);
	circle(456,190,6);
	}
break;	
case 3:
	{
	setcolor(BLACK);
	circle(250,236,6);
	circle(237,259,6);
	circle(390,232,6);
	circle(390,260,6);
	setcolor(15);
	circle(185,252,6);
	}
break;
case 4:
	{
	setcolor(BLACK);
	circle(250,236,6);
	circle(237,259,6);
	circle(390,232,6);
	circle(390,260,6);
	setcolor(15);
	circle(456,246,6);
	}
break;
case 11:
	{
	setcolor(BLACK);
	circle(182,191,6);
	setcolor(15);
	circle(222,212,6);
	}
break;	
case 12:
	{
	setcolor(BLACK);
	circle(456,190,6);
	setcolor(15);
	circle(423,209,6);
	}
break;	
case 13:
	{
	setcolor(BLACK);
	circle(185,252,6);
	setcolor(15);
	circle(210,255,6);
	}
break;	
case 14:
	{
	setcolor(BLACK);
	circle(456,246,6);
	setcolor(15);
	circle(423,252,6);
	}
break;	
case 21:
	{
	setcolor(BLACK);
	circle(222,212,6);
	setcolor(15);
	circle(250,236,6);
	}
break;	
case 22:
	{
	setcolor(BLACK);
	circle(423,209,6);
	setcolor(15);
	circle(390,232,6);
	}
break;	
case 23:
	{
	setcolor(BLACK);
	circle(210,255,6);
	setcolor(15);
	circle(237,259,6);
	}
break;	
case 24:
	{
	setcolor(BLACK);
	circle(423,252,6);
	setcolor(15);
	circle(390,260,6);
	}
break;
default: 

	{
	setcolor(BLACK);
	circle(250,236,6);
	circle(237,259,6);
	circle(390,232,6);
	circle(390,260,6);
	}
}
if (buf>19)
buf=-25;
delay(800);
return buf+10;
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
		if((st=fopen("file.txt","r"))==NULL)
		outtextxy(240, 90, "No Best score");
		else
		{
		//st=fopen("file.txt","r");
		fgets(hs,100,st);
		outtextxy(240, 90, hs);
		fclose(st);
		}
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
	cleardevice();
				bestscore=0;
				action();
			}
		break;
    }
  } while(arrow_key!=ESC);
}

int vlvv(int x, int y,int wolfcol) {
  setcolor(wolfcol);
	setfillstyle(1,wolfcol);
	rectangle(20+x,20+y,70+x,30+y);
	floodfill(69+x,29+y,wolfcol);
	circle(20+x,20+y,5);
	circle(60+x,20+y,10);
	line(65+x,10+y,70+x,5+y);
	line(68+x,20+y,70+x,5+y);
	ellipse(60+x,60+y,0,360,20,30);
	line(67+x,90+y,90+x,130+y);
	line(53+x,90+y,30+x,130+y);
	line(40+x,60+y,10+x,60+y);
	ellipse(10+x,50+y,180,360,10,10);
	floodfill(19+x,20+y,wolfcol);
	floodfill(59+x,19+y,wolfcol);
	floodfill(60+x,60+y,wolfcol);
	setcolor(15);
	return 1;
}
int vlvn(int x,int y,int wolfcol)
{
setcolor(wolfcol);
setfillstyle(1,wolfcol);
rectangle(20+x,20+y,70+x,30+y);
floodfill(69+x,29+y,wolfcol);
circle(20+x,20+y,5);
circle(60+x,20+y,10);
line(65+x,10+y,70+x,5+y);
line(68+x,20+y,70+x,5+y);
ellipse(60+x,60+y,0,360,20,30);
line(67+x,90+y,90+x,130+y);
line(53+x,90+y,30+x,130+y);
line(40+x,60+y,10+x,80+y);
ellipse(10+x,70+y,180,360,10,10);
floodfill(19+x,20+y,wolfcol);
floodfill(59+x,19+y,wolfcol);
floodfill(60+x,60+y,wolfcol);
setcolor(15);
return 3;
}
int vpvv(int x,int y,int wolfcol)
{
setcolor(wolfcol);
setfillstyle(1,wolfcol);
rectangle(50+x,20+y,100+x,30+y);
floodfill(98+x,22+y,wolfcol);
circle(100+x,20+y,5);
circle(60+x,20+y,10);
line(60+x,15+y,50+x,5+y);
line(50+x,5+y,55+x,18+y);
ellipse(60+x,60+y,0,360,20,30);
line(67+x,90+y,90+x,130+y);
line(53+x,90+y,30+x,130+y);
line(80+x,60+y,120+x,60+y);
ellipse(120+x,50+y,180,360,10,10);
floodfill(101+x,21+y,wolfcol);
floodfill(61+x,19+y,wolfcol);
floodfill(60+x,60+y,wolfcol);
setcolor(15);
return 2;
}

int vpvn(int x,int y,int wolfcol)
{
setcolor(wolfcol);
setfillstyle(1,wolfcol);
rectangle(50+x,20+y,100+x,30+y);
floodfill(98+x,22+y,wolfcol);
circle(100+x,20+y,5);
circle(60+x,20+y,10);
line(60+x,15+y,50+x,5+y);
line(50+x,5+y,55+x,18+y);
ellipse(60+x,60+y,0,360,20,30);
line(67+x,90+y,90+x,130+y);
line(53+x,90+y,30+x,130+y);
line(80+x,60+y,120+x,80+y);
ellipse(120+x,70+y,180,360,10,10);
floodfill(101+x,21+y,wolfcol);
floodfill(61+x,19+y,wolfcol);
floodfill(60+x,60+y,wolfcol);
setcolor(15);
return 4;
}

void chickens() {
	setcolor(14);
	setfillstyle(9, 14);
	line(getmaxx()/2 - 190, getmaxy()/2 - 40, (getmaxx()/2 - 190) + 50, getmaxy()/2 - 40);
	/* start of left up chicken */
	ellipse(getmaxx()/2 - 165, getmaxy()/2 - 48, 0, 360, 20, 8);
	floodfill(getmaxx()/2 - 165, getmaxy()/2 - 48,14);
	circle(getmaxx()/2 - 150, getmaxy()/2 - 60, 7);
	floodfill(getmaxx()/2 - 150, getmaxy()/2 - 60, 14);
	/* end of chicken */
	line(180, 200, 255, 249);//line

	setcolor(15);
	setfillstyle(9, 15);
	line(getmaxx()/2 + 190, getmaxy()/2 - 40, (getmaxx()/2 + 190) - 50, getmaxy()/2 - 40);
	/* start of right up chicken */
	ellipse(getmaxx()/2 + 165, getmaxy()/2 - 48, 0, 360, 20, 8);
	floodfill(getmaxx()/2 + 165, getmaxy()/2 - 48,15);
	circle(getmaxx()/2 + 150, getmaxy()/2 - 60, 7);
	floodfill(getmaxx()/2 + 150, getmaxy()/2 - 60, 15);
	/* end of chicken */
	line(458, 200, 385, 249);//line

	setcolor(4);
	setfillstyle(9, 4);

	line(getmaxx()/2 - 190, getmaxy()/2 + 20, (getmaxx()/2 - 190) + 50, getmaxy()/2 + 20);
	/* start of left down chicken */
	ellipse(getmaxx()/2 - 165, getmaxy()/2 + 12, 0, 360, 20, 8);
	floodfill(getmaxx()/2 - 165, getmaxy()/2 + 12,4);
	circle(getmaxx()/2 - 150, getmaxy()/2, 7);
	floodfill(getmaxx()/2 - 150, getmaxy()/2, 4);
	/* end of chicken */
	line(180, 260, 255, 270);//line


	line(getmaxx()/2 + 190, getmaxy()/2 + 20, (getmaxx()/2 + 190) - 50, getmaxy()/2 + 20);
	/* start of right down chicken */
	ellipse(getmaxx()/2 + 165, getmaxy()/2 + 12, 0, 360, 20, 8);
	circle(getmaxx()/2 + 150, getmaxy()/2, 7);
	/* end of chicken */
	line(458,  260, 386, 270);//line
}
void best(int bestscore)
{
char name[20];
name[0]=NULL;
int i;

FILE *fPtr;
int oldbest=0;
bestscore--;//Временная подпрвка лучшего рез-та
setcolor(3);
rectangle(250,200,400,280);
setfillstyle(1,3);
floodfill(320,240,3);


if((fPtr=fopen("file.txt","r"))==NULL)//schitivaem proshliy luchsiy rezultat
{setcolor(15);
outtextxy(280,225,"First Game?");
}
else
{
   fscanf(fPtr,"%d",&oldbest);
   printf("%d \n",bestscore);

fclose(fPtr);

}


if(oldbest>bestscore)
{
setcolor(15);
outtextxy(290,230,"Try Again");
getch();
clrscr();
cleardevice();
}
else
{

if((fPtr=fopen("file.txt","w+"))==NULL)//esli uslovie vipoln
printf("File could not to be opened\n");
else
{
setcolor(15);
outtextxy(280,205,"You did it");
outtextxy(265,215,"Enter your name");

char *s;
char w;
s=&w;
	for(;;)
	{
		*s=getch();
		if (*s==13 || *s==27)
			break;
		else
		{
		strncat(name,s,1);
		outtextxy(300,240,name);
		}
	}
}

fprintf(fPtr,"%d ",bestscore);
fprintf(fPtr,"%s ",name);
}
fclose(fPtr);
clrscr();
cleardevice();
}

void action() {
  int key=up_left;
  int wtype=0; //1-vlvv 2-vpvv 3-vlvn 4-vpvn
int buf=-1;
time_t t;
  cleardevice();
  vlvv(255,200,7);
  chickens();

	while(key != bios_esc)
	{
	if(buf<0)
	{
	srand((unsigned) time(&t));
	buf=rand()%4;
	}
	buf=egg(buf);
	switch(wtype) {
	      case 1:	vlvv(255,200,BLACK); break;
	      case 2:	vpvv(255,200,BLACK); break;
	      case 3:	vlvn(255,200,BLACK); break;
	      case 4:	vpvn(255,200,BLACK); break;
		      }
	switch(key) {
			case up_left: wtype=vlvv(255,200,7); break;
			case up_right: wtype=vpvv(255,200,7); break;
			case down_left:	wtype=vlvn(255,200,7); break;
			case down_right: wtype=vpvn(255,200,7);	break;
			default:  switch(wtype){
						case 1: key=up_left; wtype=vlvv(255,200,7); break;
						case 2: key=up_right; wtype=vpvv(255,200,7); break;
						case 3: key=down_left; wtype=vlvn(255,200,7); break;
						case 4: key=down_right; wtype=vpvn(255,200,7);	break;
						}
		      }


		if(key != 0 && (key != up_left || key != up_right))
		       key = bioskey(0);


	if(wtype==0)
	vlvv(255,200,BLACK);

	
	}

	best(bestscore);
	cleardevice();
  menutext();
  active_item(61);

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

/* Splash befor the game
  for(i=0;i<260;i+=20) {
		cleardevice();
		back_pic();
		woolf(290-i, 200);
		two_chickens(250-i, 300);
		delay(100);
  }
/*-----------------------*/

  menu();

  closegraph();
}
