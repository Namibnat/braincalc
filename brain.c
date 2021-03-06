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


#include <ctype.h>                    /* for isdigit() */
#include <stdlib.h>
#include <time.h>                     /* for now just for seeding rand() */
#include "brain.h"
int cal_add(int num1, int num2);
int cal_sub(int num1, int num2);
int cal_mul(int num1, int num2);
int cal_div(int num1, int num2);
extern void help();
int main(int argc, char **argv)
{
  double time_spent;               /* To add time */
  int time_spent_m, time_spent_s;  /* To add time */
  time_t begin, end;               /* To add time */
  int i, r, n1, n2;
  int rounds, maxnum; /* rounds is how many iterations of the game there will be
                         maxnum is the biggest values used in the sums */
  int score = 0;
  /* initial settings for rounds & turns */
  rounds = (argv[1] && isdigit(argv[1][0])) ? atoi(argv[1]) : ROUNDS;
  maxnum = (argv[2] && isdigit(argv[2][0])) ? atoi(argv[2]) : MAXNUM;
  /* start the timer */
  begin = time(NULL);
  /* return HOWTO instead of play */
  if(argv[1] && (argv[1][0] == 'h')){
    help();
    return 0;
  }
  /* the main dispach switch */
  srand ( (unsigned)time ( NULL ) );
  for(i = 0; i < rounds; i++){
    r = rand() % 4;
    n1 = rand() % maxnum;
    n2 = rand() % maxnum;
    switch(r){
    case 0: /* addition */
      score += cal_add(n1, n2);
      break;
    case 1: /* subtraction - call function with biggest number first,
                             so we don't need to have negatives in the answer */
      score += (n1 >= n2) ? cal_sub(n1, n2) : cal_sub(n2, n1);
      break;
    case 2: /* multiplication */
      score += cal_mul(n1, n2);
      break;
    case 3: /* division - we avoid 0 in the division, just to simplify things
                          like subtraction, we also use the bigger val divided by the smaller */
      while(n1 == 0 || n2 == 0){
	n1 = rand() % MAXNUM;
	n2 = rand() % MAXNUM;
      }
      score += (n1 >= n2) ? cal_div(n1, n2) : cal_sub(n2, n1);
      break;
    default: /* catch imposible */
      printf("Something isn't working rights\n");
      return 0;
    }
  }
  /* end timer */
  end = time(NULL);
  time_spent = difftime(end, begin);
  time_spent_m = (int)(time_spent)/60;
  time_spent_s = (int)(time_spent)%60;

  /* Report */
  printf("\n");
  printf("You got %d out of %d in %d ", score, rounds, time_spent_m);
  printf("%s", (time_spent_m == 1)?"minute":"minutes");
  printf(", %d ", time_spent_s);
  printf("%s", (time_spent_s == 1)?"second":"seconds");
  if((rounds - score) < 4){
    printf("!");
  }
  else{
    printf(".");
  }
  printf("\n\n");
  return 0;
}
/* the next for functions do the main game play
   score - returns 1 if the user gets right, zero for wrong
   usrans - user answer
   in division we also have a remainder,
   rather than using decimals in the values
*/
int cal_add(int num1, int num2)
{
  int answer, n, c, i, usrans, score;
  score = 0;
  answer = num1 + num2;
  printf("%d + %d = ", num1, num2);
  usrans = 0;
  n = 1;
  for(i = 0;((c = getchar()) && isdigit(c) && c != EOF); i++){
    usrans = n * usrans + (c - '0');
    n *= 10;
  }
  (usrans == answer) ? (printf("    right!\n")) && score++ : (printf("    wrong\n"));
  return score;
}
int cal_sub(int num1, int num2)
{
  int answer, n, c, i, usrans, score;
  score = 0;
  answer = num1 - num2;
  printf("%d - %d = ", num1, num2);
  usrans = 0;
  n = 1;
  for(i = 0;((c = getchar()) && isdigit(c) && c != EOF); i++){
    usrans = n * usrans + (c - '0');
    n *= 10;
  }
  (usrans == answer) ? (printf("    right!\n")) && score++ : printf("    wrong\n");
  return score;
 }
int cal_mul(int num1, int num2)
{
  int answer, n, c, i, usrans, score;
  score = 0;
  answer = num1 * num2;
  printf("%d x %d = ", num1, num2);
  n = 1;
  usrans = 0;
  for(i = 0;((c = getchar()) && isdigit(c) && c != EOF); i++){
    usrans = n * usrans + (c - '0');
    n *= 10;
  }
  (usrans == answer) ? (printf("    right!\n")) && score++ : printf("    wrong\n");
  return score;
}
int cal_div(int num1, int num2)
{
  int answer, n, c, i, usrans, score;
  int remainder, usrrem;
  score = 0;
  answer = num1 / num2;
  remainder = num1 % num2;
  printf("%d / %d = ", num1, num2);
  n = 1;
  usrans = usrrem = 0;
  for(i = 0;((c = getchar()) && isdigit(c) && c != EOF); i++){
    usrans = n * usrans + (c - '0');
    n *= 10;
  }
  if(remainder != 0){
    printf("\b remainder ");
    for(i = 0;((c = getchar()) && isdigit(c) && c != EOF); i++){
      usrrem = n * usrrem + (c - '0');
      n *= 10;
    }
  }
  (usrans == answer && usrrem == remainder) ? (printf("    right!\n")) && score++ : printf("    wrong\n");
  return score;
}
