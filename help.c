#include "brain.h"
void help(void)
{
  printf("A math skills game\n\n");
  printf("This game gives you simple math problems.\n");
  printf("Try to do each problem in the fastest time possible.\n\n");
  printf("In the division problems, the problem truncates\n");
  printf("the decimal part, so simply give the integer division,\n");
  printf("hit enter and give the remainder\n\n");
  printf("For example 3 / 2 is 1 (hit enter) with a remainder of 1.\n\n");
  printf("When running the game from, the game excepts two optional\n");
  printf("arguments\n");
  printf("* The first number will be the total number of\n");
  printf("  turns you want to have\n");
  printf("* the second is the highest\n");
  printf("  number you'd like to play with.\n\n");
  printf("If you only give 'h' for the first argument\n");
  printf("it returns this help\n\n");
  printf("Examples of how to run it:\n\n");
  printf("usr@machine:~/path/to/braincalc.git$ ./brain    # to run it normall \n");
  printf("usr@machine:~/path/to/braincalc.git$ ./brain h   # to print this help \n");
  printf("usr@machine:~/path/to/braincalc.git$ ./brain 10   # to play having 10 turns\n");
  printf("usr@machine:~/path/to/braincalc.git$ ./brain 10  20 # to play having 10 turns, with a maximum value of 20\n");
  printf("\n\n");
}
