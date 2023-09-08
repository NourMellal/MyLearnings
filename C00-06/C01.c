#include <stdio.h>
#include <unistd.h>
void ft_ultimate_ft(int *********nbr)
{
	int n;
	int *ptr1;
	int **ptr2;
	int ***ptr3;
	int ****ptr4;
	int *****ptr5;
	int ******ptr6;
	int *******ptr7;
	int ********ptr8;

	n = 42;
	ptr1 = &n;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	*nbr = ptr8;
}


void ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void ft_putstr(char *str)
{
	int i;
	i = 0;

	while (str[i])
		write(1, &str[i++], 1);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int tmp;
	int min;

	i = 0;
	if (!tab || size < 2)
		return;

	while(i < size)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[min] > tab[j])
				min = j;
			j++;
		}
		tmp = tab[i];
		tab[i] = tab[min];
		tab[min] = tmp;
		i++;
	}
}
/*
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\\\\\\\\\\\\\\\\\\\ ft_sort_int_tab.c main \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
int main(void) {
	int tab[] = {0, 1, 10, 3, 60, 5, 6, 7};
	int size = sizeof(tab) / sizeof(int);
	ft_sort_int_tab(tab, size);

	for (int i = 0; i < size; i++)
		printf("%d ", tab[i]);
}
*/
void ft_rev_int_tab(int *tab, int size)
{
	int end;
	int start;
	int tmp;

	start = 0;
	end = size - 1;

	while (end > start)
	{
		tmp = tab[end]; /* 0, 1, 2, 3, 4, 5, 6, 7 */
		tab[end] = tab[start];
		tab[start] = tmp;
		start++;
		end--;
	}
}
/*
////////////////////////////
ft_rev_int_tab main
///////////////////////////


int main(){
	int tab[] = {0, 1, 2, 3, 4, 5, 6, 7};
	int size = sizeof(tab) / sizeof(int);
	ft_rev_int_tab(tab, size);

	for (int i = 0; i < size; i++)
		printf("%d ", tab[i]);
}
*/
/*
////////////////////////////puts main /////////////////////////

// int main() {
// 	char *str = "Hello, World\n";
// 	ft_putstr(str);
// }
*/

/*   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    	////////////////////////////////////////////////////////
		/////////////////////ft_swap main//////////////////

int main(void)
{
	int n1 = 5;
	int n2 = 10;
	ft_swap(&n1, &n2);
	printf("n1 = %d\nn2 = %d\n", n1 , n2);
}
*/

/************************************************************************
 *
 *
 * ************************-ft_ultimate_ft main -*************************************
 * ////////////////////////////////////////////////////////////////
 *
int main()
{
	int n;
	int *ptr1;
	int **ptr2;
	int ***ptr3;
	int ****ptr4;
	int *****ptr5;
	int ******ptr6;
	int *******ptr7;
	int ********ptr8;
	int *********ptr9;

	n = 0;
	ptr1 = &n;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	ptr9 = &ptr8;

	ft_ultimate_ft(ptr9);
	printf("%d\n", *********ptr9);  // Should print 42

	return 0;
}
*/

