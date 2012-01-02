/* ************************************************************************
*                                                                         *
*   Do calculation problems to sharpen the noggin                         *
*                                                                         *
*   Copyright (C) 2011 by Vernon Swanepoel                                *
*   vernon@sandcurves.com                                                 *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
*                                                                         *
***************************************************************************/

#include <stdio.h>
#include <ctype.h>                                  /* for isdigit and isalnum */
#include <stdlib.h>                                 /* for rand() */
#include <time.h>                                   /* for seeding rand() */
#include <unistd.h>                                 /* for sleep() */
#define FIRST_ARG 1                                 /* First commandline argument */
extern char stripdash(char *arg);
void help();
int main(int argc, char **argv)
{
  /* Ask user for the number of digits to enter 1 - 3 */

 
 /* Main as a big switch */
  if(argv[FIRST_ARG]){
    switch(stripdash(argv[FIRST_ARG])s){
      case 'a':                                /* addition */                  
        printf("got here 1\n");
        break;
      case 's':                                /* subtraction */
        printf("got here 2\n");
        break;
      case 'd':                                /* division */
        printf("got here 3\n");
        break;
      case 'm':                                /* multiplication */
        printf("got here 4\n");
        break;
      case 'e':                                /* everything */
        printf("got here 5\n");
        break;
      default:                                 /* help */
        help();
    }
  }
  else{
    help();
  }

  return(EXIT_SUCCESS);
}
void help()
{
  /* develop the help as the options develop in the program */
  printf("Help\n");
}
