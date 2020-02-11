#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"


int main() {

screen s;
color c;

c.red = 0;
c.green = 255;
c.blue = 0;

/*
c.red = 0;
c.green = 0;
c.blue = 0;

int xorg = YRES/2;
int yorg = YRES/2;

clear_screen(s);


for (int i = 0; i < YRES; i++){
  for(int j = 0; j < XRES; j++){
    plot(s,c,i,j);
  }
}


for (int i = 0; i < YRES; i++){
  if (i == (YRES / 2) - (YRES % 2)){        
    c.red = 255;
    c.green = 0;
    c.blue = 0;
    draw_line(0, i, XRES-1, i, s, c);
    draw_line(i,0,i,YRES-1,s,c);
    draw_line(XRES, i, XRES, i, s, c);
    draw_line(i,YRES,i,YRES,s,c);

  }
  if (i % 19 == 0){
    c.red = 0;
    c.green = 0;
    c.blue = 255;
    draw_line(0, i, XRES-1, i, s, c);
    draw_line(i,0,i,YRES-1,s,c);
    draw_line(XRES, i, XRES, i, s, c);
    draw_line(i,YRES,i,YRES,s,c);
  }
}

c.red = 0;
c.green = 255;
c.blue = 0;

int curx;
int cury;

for(int i = 0; i < 100; i++){
  if (i % 2 == 0){
    curx = xorg + rand() % 15;
    cury = yorg + rand() % 150;
    draw_line(xorg, yorg, curx, cury, s, c);
    xorg = curx;
    yorg = cury;
  }
  else{
    curx = xorg + rand() % 15;
    cury = yorg - rand() % 150;
    draw_line(xorg, yorg, curx, cury, s, c);
    xorg = curx;
    yorg = cury;
  }
}

int oppx = XRES/2;
int oppy = YRES/2;
int xneg;
int yneg;

for (int i = 0; i < 1000; i++){
  if (i % 2 == 0){
    xneg = oppx - rand() % 15;
    yneg = oppy + rand() % 150;
    draw_line(oppx, oppy, xneg , yneg, s, c);
    oppx = xneg;
    oppy = yneg;
  }
  else{
    xneg = oppx - rand() % 15;
    yneg = oppy - rand() % 150;
    draw_line(oppx, oppy, xneg , yneg, s, c);
    oppx = xneg;
    oppy = yneg;
  }
}
*/



clear_screen(s);
//octants 1 and 5
draw_line(0, 0, XRES-1, YRES-1, s, c);
draw_line(0, 0, XRES-1, YRES / 2, s, c);
draw_line(XRES-1, YRES-1, 0, YRES / 2, s, c);

//octants 8 and 4
c.blue = 255;
draw_line(0, YRES-1, XRES-1, 0, s, c);
draw_line(0, YRES-1, XRES-1, YRES/2, s, c);
draw_line(XRES-1, 0, 0, YRES/2, s, c);

//octants 2 and 6
c.red = 255;
c.green = 0;
c.blue = 0;
draw_line(0, 0, XRES/2, YRES-1, s, c);
draw_line(XRES-1, YRES-1, XRES/2, 0, s, c);

//octants 7 and 3
c.blue = 255;
draw_line(0, YRES-1, XRES/2, 0, s, c);
draw_line(XRES-1, 0, XRES/2, YRES-1, s, c);

//horizontal and vertical
c.blue = 0;
c.green = 255;
draw_line(0, YRES/2, XRES-1, YRES/2, s, c);
draw_line(XRES/2, 0, XRES/2, YRES-1, s, c);


save_extension(s, "ascii.png");
save_ppm(s, "binary.ppm");
save_ppm_ascii(s, "ascii.ppm");
display(s);

return 0;

}
