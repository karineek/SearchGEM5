
// Modification timestamp: 2023-08-04 14:35:59
// Original Source: https://barnyard.syr.edu/quickies/led.c

#include <stdlib.h>
#include <stdio.h>

#define MAX_DIGITS 32
#define NO_MAIN


/* Print the top line of the digit d into buffer.
   Does not null terminate buffer. */

void topline(int d, char *p){

   *p++ = ' ';
   switch(d){

      /* all these have _ on top line */

      case 0:
      case 2:
      case 3:
      case 5:
      case 7:
      case 8:
      case 9:
         *p++ = '_';
         break;
      default:
         *p++=' ';

   }
   *p++=' ';
}

/* Print the middle line of the digit d into the buffer.
   Does not null terminate. */

void midline(int d, char *p){

   switch(d){

      /* those that have leading | on middle line */

      case 0:
      case 4:
      case 5:
      case 6:
      case 8:
      case 9:
         *p++='|';
         break;
      default:
         *p++=' ';
   }
   switch(d){

      /* those that have _ on middle line */

      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 8:
      case 9:
         *p++='_';
         break;
      default:
         *p++=' ';

   }
   switch(d){

      /* those that have closing | on middle line */

      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 7:
      case 8:
      case 9:
         *p++='|';
         break;
      default:
         *p++=' ';

   }
}

/* Print the bottom line of the digit d. Does not null terminate. */

void botline(int d, char *p){


   switch(d){

      /* those that have leading | on bottom line */

      case 0:
      case 2:
      case 6:
      case 8:
         *p++='|';
         break;
      default:
         *p++=' ';
   }
   switch(d){

      /* those that have _ on bottom line */

      case 0:
      case 2:
     