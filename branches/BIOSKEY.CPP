#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <bios.h>

enum {bios_up = 18432, bios_right = 19712, bios_down = 20480, bios_left = 19200, bios_esc = 283, bios_enter = 7181, 
			up_left = 7777, down_left = 11386, up_right = 10279, down_right = 13615};

void main() {
	void *egg;
  int gd, gm, error;
	int x=0, y=0;
	int key=-1;

  detectgraph (&gd, &gm);
  initgraph (&gd, &gm, "C:\\borlandc\\bgi");
  error = graphresult ();
	
	circle(getmaxx()/2, getmaxy()/2, 5);
	egg = malloc(imagesize(getmaxx()/2 - 5, getmaxy()/2 - 5, getmaxx()/2 + 5, getmaxy()/2 + 5));
	
	getimage(getmaxx()/2 - 5, getmaxy()/2 - 5, getmaxx()/2 + 5, getmaxy()/2 + 5, egg);
	cleardevice();
	
	 while(key != bios_esc) {
		putimage(0 + x, 0 + y, egg, XOR_PUT);		// Draw test object
		key = bioskey(1);
		
		switch(key) {
			case bios_right:
				putimage(0 + x, 0 + y, egg, XOR_PUT);		// Erase test object
				x += 10;
				putimage(0 + x, 0 + y, egg, XOR_PUT);		// Draw test object
			break;
			
			case bios_left:
				putimage(0 + x, 0 + y, egg, XOR_PUT);		// Erase test object
				x -= 10;
				putimage(0 + x, 0 + y, egg, XOR_PUT);		// Draw test object
			break;
		}
		
		delay(50);
		putimage(0 + x, 0 + y, egg, XOR_PUT);		// Erase test object
		y += 5;
		putimage(0 + x, 0 + y, egg, XOR_PUT);		// Draw test object
		delay(10);
		putimage(0 + x, 0 + y, egg, XOR_PUT);		// Erase test object
		
		if(y == 470)
			y = 0;
			
		if(key != 0 && (key != bios_left || key != bios_right)) {
			key = bioskey(0);
			putimage(0 + x, 0 + y, egg, XOR_PUT);		// Erase test object
			putimage(0 + x, 0 + y, egg, XOR_PUT);		// Draw test object
		}
	}
	
  printf("\n\ny = %d", y);
	delay(2000);
	closegraph();
}
