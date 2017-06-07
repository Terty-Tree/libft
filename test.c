#include <string.h>
#include <stdio.h>

#include "libft.h"

void	print_res(char *func, char *src, char *dst, size_t size, size_t (*f)(char *, const char *, size_t))
{
	printf("%s(\"%s\", \"%s\", %zu):\n", func, src, dst, size);
	size_t result = f(dst, src, size);
	printf("(%zu) %s\n", result, dst);
}

t_list	*mult_lst_content(t_list *lst)
{
	t_list	*ret;
	int		val;

	val = (lst && lst->content_size == sizeof(int)) ? *((int *)lst->content) * 2 : 0;
	ret = ft_lstnew(&val, sizeof(int));
	return (ret);
}

void	ft_lstprint(t_list *lst, void (*f)(t_list *))
{
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}

void	print_int(t_list *lst)
{
	if (lst)
		printf("%i\n", *((int *)lst->content));
}

int	main(void)
{
	/*
	// last char is '\0'
	{
	printf("Last char is \'\\0\'\n");
	char dst1[14] = "Hello, World!";
	char dst2[14] = "Hello, World!";
	char *src = "Test";
	size_t result;

	printf("strlcat(\"%s\", \"%s\", 14):\n", dst1, src);
	result = strlcat(dst1, src, 14);
	printf("(%zu) %s\n", result, dst1);
	printf("ft_strlcat(\"%s\", \"%s\", 14):\n", dst2, src);
	result = ft_strlcat(dst2, src, 14);
	printf("(%zu) %s\n", result, dst2);
	}
	printf("\n");

	// size < dst
	{
	printf("size < dst\n");
	char *dst1 = "Hello, World!";
	char *dst2 = "Hello, World!";
	char *src = "How you doin?";
	size_t result;

	printf("strlcat(\"%s\", \"%s\", 5):\n", dst1, src);
	result = strlcat(dst1, src, 5);
	printf("(%zu) %s\n", result, dst1);
	printf("ft_strlcat(\"%s\", \"%s\", 5):\n", dst2, src);
	result = ft_strlcat(dst2, src, 5);
	printf("(%zu) %s\n", result, dst2);
	}
	printf("\n");

	// unit-test
	{
	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff1[0xF00] = "there is no stars in the sky";
	char buff2[0xF00] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
	printf("max: %zu\n", max);
	size_t r1 = __builtin___strlcat_chk (buff1, str, max, __builtin_object_size (buff1, 2 > 1 ? 1 : 0));
	size_t r2 = ft_strlcat(buff2, str, max);

	printf("strlcat: %zu\nft_strlcat: %zu\n", r1, r2);
	printf("strlcat:\t%s\nft_strlcat:\t%s\n", buff1, buff2);
	}*/
	/*{
	   char	s1[4] = "";
	   char	s2[4] = "";
	   size_t	r1;
	   size_t	r2;
	   r1 = __builtin___strlcat_chk (s1, "thx to ntoniolo for this test !", 4, __builtin_object_size (s1, 2 > 1 ? 1 : 0));
	   r2 = ft_strlcat(s2, "thx to ntoniolo for this test !", 4);
	   printf("strlcat:\n(%zu) %s\nft_strlcat:\n(%zu) %s\n", r1, s1, r2, s2);
	   }*/
	/*{
		char *s1 = "MZIRIBMZIRIBMZE123";
		char *s2 = "MZIRIBMZE";
		size_t max = strlen(s2);
		printf("%s\n", ft_strnstr(s1, s2, max));
	}*/
	/*{
		t_list	*lst;
		t_list	*new;
		t_list	*tmp;
		int		num;

		lst = NULL;
		num = 0;
		tmp = ft_lstnew(&num, sizeof(int));
		printf("new created\n");
		ft_lstaddr(&lst, tmp);
		printf("added to rear\n");
		num += 2;
		tmp = ft_lstnew(&num, sizeof(int));
		printf("new created\n");
		ft_lstaddr(&lst, tmp);
		printf("added to rear\n");
		num += 2;
		tmp = ft_lstnew(&num, sizeof(int));
		printf("new created\n");
		ft_lstaddr(&lst, tmp);
		printf("added to rear\n");
		num += 2;
		tmp = ft_lstnew(&num, sizeof(int));
		printf("new created\n");
		ft_lstaddr(&lst, tmp);
		printf("added to rear\n");
		num += 2;
		tmp = ft_lstnew(&num, sizeof(int));
		printf("new created\n");
		ft_lstaddr(&lst, tmp);
		printf("added to rear\n");
		new = ft_lstmap(lst, &mult_lst_content);
		ft_lstprint(new, &print_int);
	}*/
	/*{
		char	buf2[] = "abcd";

		printf("%s\n", ft_strrchr(buf2, 'a'));
	}*/
	{
		char	*src = "";
		char	dst1[10] = "Hello!";
		char	dst2[10] = "Hello!";
		size_t	max = sizeof(dst1);
		size_t	r1;
		size_t	r2;
		r1 = strlcat(dst1, src, max);
		printf("strlcat:\n(%zu) %s\n", r1, dst1);
		r2 = ft_strlcat(dst2, src, max);
		printf("ft_strlcat:\n(%zu) %s\n", r2, dst2);
	}
	{
		char	*src = "Hello!";
		char	dst1[10] = "";
		char	dst2[10] = "";
		size_t	max = sizeof(dst1);
		size_t	r1;
		size_t	r2;
		r1 = strlcat(dst1, src, max);
		printf("strlcat:\n(%zu) %s\n", r1, dst1);
		r2 = ft_strlcat(dst2, src, max);
		printf("ft_strlcat:\n(%zu) %s\n", r2, dst2);
	}
}
