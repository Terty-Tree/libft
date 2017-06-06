#include <string.h>
#include <stdio.h>

#include "libft.h"

void	print_res(char *func, char *src, char *dst, size_t size, size_t (*f)(char *, const char *, size_t))
{
	printf("%s(\"%s\", \"%s\", %zu):\n", func, src, dst, size);
	size_t result = f(dst, src, size);
	printf("(%zu) %s\n", result, dst);
}

int	main(void)
{
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
		result = ft_strlcat(dst1, src, 5);
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
	}
}
