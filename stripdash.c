char stripdash(char *arg) /* if the args have dashes, strip them */
{
  int i;
  for(i = 0; arg[i] == '-'; i++)
    ;
  return arg[i];
}
