#include "ft_qsort.h" 

void ft_voidswap(void *v1, void *v2, int size)
{
	void *sp;
	
	sp = (void *)ft_memalloc(size);
	ft_memcpy(sp, v1, size);
	ft_memcpy(v1, v2, size);
	ft_memcpy(v2, sp, size);
	free(sp);
}

void ft_insertion_sort(void *base, size_t n, size_t size, int (*cmp)(const void *, const void *))
{
	int i;
	int j;
	void *tmp;

	i = 1;
	tmp = (void *)ft_memalloc(size);
	while (i < n)
	{
		ft_memcpy(tmp, base + i * size, size);
		j = i - 1;
		while (j >= 0 && cmp(tmp, base + j * size) < 0)
		{
			ft_memcpy(base + (j + 1) * size, base + j * size, size);
			j--;
		}
		ft_memcpy(base + (j + 1) * size, tmp, size);
		i++;
	}
}

void ft_qsort(void *base, size_t n, size_t size, int (*cmp)(const void *, const void *))
{
	int i;
	int j;
	int ipos;

	i = 0;
	j = n;
	if (n <= QSORT_CUTOFF)
		return;
	ipos = rand()%n;
	ft_voidswap(base, base + ipos * size, size);
    while (1)
	{
		i++;
		while (cmp(base + size * i, base) < 0 && i < n)
			i++;
		j--;
		while (cmp(base + size * j, base) > 0)
			--j;
		if (i > j)
			break;
		ft_voidswap(base + size*i, base + size * j, size);
	}
	if (j != 0)
		ft_voidswap(base, base+size*j, size);
 	if (j > 0)
		ft_qsort(base, j, size, cmp);
	ft_qsort(base + size * (j + 1), n - 1 - j, size, cmp);
}