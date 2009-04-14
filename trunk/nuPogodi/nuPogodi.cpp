//============================================================================
// Name        : nuPogodi.cpp
// Author      : xolvo & David
// Version     :
// Copyright   :
// Description :
//============================================================================

/* TODO list for this project
	1. Переделать фон   --complete
	2. Вставить музыку   --complete
	3. Сделать лучший результат   --complete
	4. Изменить сканирование движения   --complete
	5. Исправить Devid на David   --complete
	6. Подумать о реализации игры	--complete
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
int speed =300;
int sou=100;    //Переменная частоты звука
int y_opt = 141;
int option_flag = -1;

enum {UP_ARROW=72, LEFT_ARROW=75, DOWN_ARROW=80, RIGHT_ARROW=77, ESC=27, ENTER=13};
enum bios_keis {bios_up = 18432, bios_right = 19712, bios_down = 20480, bios_left = 19200, bios_esc = 283, bios_enter = 7181,
		up_left = 7777, down_left = 11386, up_right = 10279, down_right = 13615};

void action();
void text(int y);

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
	arc(265,252,0,180,6);
	arc(375,254,0,180,6);
	arc(266,272,0,180,6);
	arc(375,272,0,180,6);
	arc(270,330,0,180,6);
	arc(373,330,0,180,6);

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
	arc(265,252,0,180,6);
	arc(375,254,0,180,6);
	arc(266,272,0,180,6);
	arc(375,272,0,180,6);
	    arc(270,330,0,180,6);
	    arc(373,330,0,180,6);
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
	arc(265,252,0,180,6);
	arc(375,254,0,180,6);
	arc(266,272,0,180,6);
	arc(375,272,0,180,6);
	    arc(270,330,0,180,6);
	    arc(373,330,0,180,6);
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
	arc(265,252,0,180,6);
	arc(375,254,0,180,6);
	arc(266,272,0,180,6);
	arc(375,272,0,180,6);
	    arc(270,330,0,180,6);
	    arc(373,330,0,180,6);
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
if (buf>29)
buf=-25;
delay(speed);

return buf+10;
}




int isstart(int y) {
	int value=0;

  if(y==61)
		value = 1;

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

void active_options_item(int y) {
  setfillstyle(9, 12);
  floodfill(251, y, 15);
}

void text(int y) {
  if(y==61) {
		outtextxy(240, 70, "Get READY!!!!!");
		delay(1000);
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
  if(y == 181) {
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
  /* нарисовать еще прямоугольник для опции */
  rectangle(30, 240, 200, 280);
  /*нарисовать главную область*/
  rectangle(230, 60, getmaxx()-50, getmaxy()-50);

  outtextxy(30, 10, "UP and DOWN arrow - for navigate");
  outtextxy(30, 20, "ENTER - for choice");
  outtextxy(30, 30, "ESC - for exit");

  outtextxy(35, 65, "Start the game");
  outtextxy(35, 125, "Hight score");
  outtextxy(35, 185, "Rules");
  outtextxy(35, 245, "Options");
}

void options_menu() {
  int arrow_opt_key = -1;


  cleardevice();

  do {
    /*нарисовать прямоугольник*/
    rectangle(250, 80, 420, 120);
    /*нарисовать второй прямоугольник*/
    rectangle(250, 140, 420, 180);
    /*нарисовать третий прямоугольник*/
    active_options_item(y_opt);//zakraska predidushego menu


    outtextxy(255, 85, "Low Perfomance");
    outtextxy(255, 145, "Normal Perfomance");



    active_options_item(y_opt);
    menutext();
    active_item(241);
    arrow_opt_key = arrow(arrow_opt_key);

    switch(arrow_opt_key) {
      case DOWN_ARROW:
	/* ======================================= */
	/* !!! ОЧЕНЬ НУЖНАЯ ДВОЙНАЯ ПРОВЕРКА !!!   */
	/* ======================================= */
	/* двойная проверка нужна, что бы вдруг при нажатии на */
	/* стрелку вверх не произшло прибавление 60 на последующем этапе */
	/* и экран не закрасился */
	if(y_opt >= 141)
	  y_opt = 21;

	active_options_item(y_opt += 60);
	cleardevice();
	break;

      case UP_ARROW:
	switch(y_opt) {
	  case 81:
	    y_opt=141; /* что бы исправить переход вниз */
	    active_options_item(y_opt);
	    cleardevice();
	  break;

	  case 141:
	    y_opt=81;
	    active_options_item(y_opt);
	    cleardevice();
	  break;




	}
      break;

      case ENTER:
	switch(y_opt) {
	  case 81:
	    speed = 100;
	  break;

	  case 141:
	    speed = 300;
	  break;

	}
      break;
    }
  } while(arrow_opt_key != ESC && arrow_opt_key != ENTER);

  cleardevice();
  menutext();
  active_item(241);
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
        /* ======================================= */
        /* !!! ОЧЕНЬ НУЖНАЯ ДВОЙНАЯ ПРОВЕРКА !!!   */
        /* ======================================= */
        /* двойная проверка нужна, что бы вдруг при нажатии на */
        /* стрелку вверх не произшло прибавление 60 на последующем этапе */
        /* и экран не закрасился */
        if(y >= 241)
	  y = 1;

        cleardevice();
        menutext();
        active_item(y+=60);
	//if(y >= 241)    /* т.к. пунктов меню всего 4 делаем так */
	  //y = 1;        /* для последующего сложения с 60 и получения правильных результатов */
      break;

      case UP_ARROW:
	switch(y) {
	  case 1:
	    y=181; /* что бы исправить переход вниз */
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
	    y=241;
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

	  case 241:
	    y=181;
	    cleardevice();
	    menutext();
	    active_item(y);
	  break;
	}
      break;

      case ENTER:
	text(y);

	if(y == 241)
	  options_menu();

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
int h;//kol-vo serdec
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

	//serdca//
	setcolor(12);
	for(h=0;h<200;h=h+45)
	{
	arc(400+h,40,0,180,10);
	arc(400+10+10+h,40,0,180,10);
	line(400-10+h,40,400+10+h,60);
	line(400+10+10+10+h,40,400+10+h,60);
	floodfill(400+h+10,42,12);
	}
	setcolor(15);
	rectangle(20,340,60,380);
	rectangle(40,420,80,460);
	rectangle(580,340,620,380);
	rectangle(600,420,560,460);
	setcolor(12);
	outtextxy(25,345,"A");
	outtextxy(45,425,"Z");
	outtextxy(585,345,"\'");
	outtextxy(565,425,"\/");
}
void best(int bestscore)
{
char name[20];
name[0]=NULL;
int bcnt=0,i,oldbest=0;
FILE *fPtr;
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
fclose(fPtr);

}


if(oldbest>bestscore)
{
setcolor(15);
outtextxy(295,210,"You Lose");
outtextxy(302,230,"Try to");
outtextxy(253,250,"Improve High score");
while (1)
if(getch()==ESC || getch()==ENTER)
break;

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
outtextxy(252,215,"Enter your name(10)");

char *s;
char w;
s=&w;
	while(bcnt<19)
	{
	*s=getch();
	bcnt++;
		if (*s==ESC || *s==ENTER)
			break;
		else
		{
			if(*s!=8)
			{
			strncat(name,s,1);
			setcolor(15);
			outtextxy(252,240,name);
			}
		}
		if(*s==8)//backspace
		{
		name[bcnt-2]=NULL;
		setcolor(3);
		bcnt=bcnt-2;
		for(i=8;i<16;i++)//stirka
			line(252+8*(bcnt-1)+i,240,252+8*(bcnt-1)+i,247);
		}
	 if(bcnt==19)
	 getch();
	}
}
fprintf(fPtr,"%d ",bestscore+1);
fprintf(fPtr,"%s ",name);
}
fclose(fPtr);
clrscr();
cleardevice();
}

void action() {
  int count=0;
  int key;
  int wtype = 1; //1-vlvv 2-vpvv 3-vlvn 4-vpvn
  int buf = -1;
  time_t t;

  cleardevice();
  vlvv(255,200,7);
  chickens();
  char bs[20];//char bestscore
  int fal=0;//oshibki
  switch(y_opt) {
		 case 81:
		    speed = 100;
			  break;

		 case 141:
		    speed = 300;
			  break;
		}
	while(key != bios_esc)
{
    if(buf<0) {
      srand((unsigned) time(&t));
      buf=rand()%4 + 1;
    }
    buf=egg(buf);

    if(key = bioskey(1)) {
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
      }

      switch(wtype){
	case 1: wtype=vlvv(255,200,7); break;
	case 2: wtype=vpvv(255,200,7); break;
	case 3: wtype=vlvn(255,200,7); break;
	case 4: wtype=vpvn(255,200,7);	break;
      }
    }

    if(wtype==buf-30) //Proverka na popadenie v korzinu
	{
	settextstyle(0, 0, 4);
	bestscore++;
	setcolor(BLACK);
	itoa(bestscore-1,bs,10);
	outtextxy(30,27,bs);
	setcolor(15);
	itoa(bestscore,bs,10);
	outtextxy(30,27,bs);
	switch(buf-30){
	case 1:arc(265,252,0,180,6); break;
	case 2:arc(375,254,0,180,6); break;
	case 3:arc(266,272,0,180,6); break;
	case 4:arc(375,272,0,180,6); break;
	}
	}
    if(buf-30>0 && wtype!=buf-30)//proverka osibok
    {
    fal++;
    setcolor(12);
    setfillstyle(0,12);
    floodfill(400+(fal-1)*45,42,12);
    setcolor(15);
    if( buf==31 || buf ==33)
    arc(270,330,0,180,6);
    if(buf==32 || buf ==34)
    arc(373,330,0,180,6);
    }
    count++;


     if(count%3==0)
      speed=speed-2;



    if(key != 0 && (key != up_left || key != up_right || key != down_left || key != down_right))
      key = bioskey(0);

	if(fal==5)
	key=bios_esc;

}
	settextstyle(0, 0, 1);
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
    getch();
    exit (-1);
  }

/* Splash befor the game*/
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