#include "my.h"
#include <stdlib.h>
#include <stdio.h>

void		*error_malloc(char *s)
{
  my_putstr(s);
  return (NULL);
}
