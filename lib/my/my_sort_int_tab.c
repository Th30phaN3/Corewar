void		my_sort_int_tab(int *tab, int size)
{
  int		check;
  int		save;
  int		i;

  check = 0;
  while (check == 0)
    {
      i = 0;
      check = 1;
      while (i < size - 1)
	{
	  if (tab[i] > tab[i + 1])
	    {
	      save = tab[i];
	      tab[i] = tab[i + 1];
	      tab[i + 1] = save;
	      check = 0;
	    }
	  i++;
	}
    }
}
