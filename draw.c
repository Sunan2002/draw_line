#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

 // Octants III, IV, V, VI
  if (x1 < x0){
    draw_line(x1, y1, x0, y0, s, c);
  }

  //Octants I,II, VII, VIII
  else {

    int x = x0;
    int y = y0;
    int A = y1 - y0;
    int B = -1 * (x1 - x0);

    if (A >= 0 && A <= -B){
      int d = 2 * A + B;
      while (x <= x1){
        plot(s, c, x, y);
        x++;
        d += 2 * A;
        if(d >= 0){
  	       y++;
  	       d += 2 * B;
        }
      }
    }

    else if(A >= 0  && A >= -B){
      int d = A + 2 * B;
      while (y <= y1){
        plot(s, c, x, y);
        y++;
        d += 2 * B;
        if(d <= 0){
  	       x++;
  	       d += 2 * A;
        }
      }
    }

    else if (A <= 0 && A <= B){
      int d = A - 2 * B;
      while (y >= y1){
        plot(s, c, x, y);
        y--;
        d -= 2 * B;
        if (d >= 0){
  	       x++;
  	       d += 2 * A;
        }
      }
    }

    else if (A <= 0 && A >= B){
      int d = 2 * A - B;
      while (x <= x1){
        plot(s, c, x, y);
        x++;
        d += 2 * A;
        if (d <= 0){
  	       y--;
  	       d -= 2 * B;
        }
      }
    }

  }
}








