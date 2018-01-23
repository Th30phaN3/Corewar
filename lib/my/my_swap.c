int		my_swap(int *a, int *b)
{
  int		save;

  save = *a;
  *a = *b;
  *b = save;
}
