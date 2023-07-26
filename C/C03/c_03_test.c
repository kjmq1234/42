#include <stdio.h>
#include "ex00/ft_strcmp.c"
#include "ex01/ft_strncmp.c"
#include "ex02/ft_strcat.c"
#include "ex03/ft_strncat.c"
#include "ex04/ft_strstr.c"
#include "ex05/ft_strlcat.c"

int main() {
	// Exercise 00
	printf("%d ", ft_strcmp("Hello", "World") < 0);
	printf("%d ", ft_strcmp("World", "Hello") > 0);
	printf("%d ", ft_strcmp("Hello", "Hello") == 0);
	printf("%d ", ft_strcmp("Hello", "Hello ") < 0);
	printf("%d ", ft_strcmp("Hello ", "Hello") > 0);
	printf("%d ", ft_strcmp("", "") == 0);
	printf("%d ", ft_strcmp("", "\200") < 0);
	printf("%d\n\n", ft_strcmp("\200", " ") > 0);

	// Exercise 01
	printf("%d ", ft_strncmp("Hello", "Hi", 2) < 0);
	printf("%d ", ft_strncmp("Hello", "Hi", 1) == 0);
	printf("%d ", ft_strncmp("Hello", "World", 0) == 0);
	printf("%d ", ft_strncmp("Hello^", "Hello$", 5) == 0);
	printf("%d ", ft_strncmp(" ", "\200", 1) < 0);
	printf("%d ", ft_strncmp(" ", "\200", 0) == 0);
	printf("%d ", ft_strncmp("Hello", "Hello", 424242424) == 0);
	printf("%d\n\n", ft_strncmp("Hello ", "Hello", 424242424) > 0);

	// Exercise 02
	char arr[50];
	for (int i = 0; i < 50; ++i)
		arr[i] = '#';
	arr[0] = '\0';
	printf("%s\n", ft_strcat(arr, "Hello "));
	printf("%s\n", ft_strcat(arr, "World!"));
	printf("%s\n\n", ft_strcat(arr, ""));

	// Exercise 03
	for (int i = 0; i < 50; ++i)
		arr[i] = '#';
	arr[0] = '\0';
	printf("%s\n", ft_strncat(arr, "Hello World!", 6));
	printf("%s\n", ft_strncat(arr, "World!", 0));
	printf("%s\n\n", ft_strncat(arr, "World!", 424242424));

	// Exercise 04
	printf("%s", ft_strstr("", ""));
	printf("%s\n", ft_strstr("Hello World!", ""));
	printf("%s\n", ft_strstr("Hello World!", "World!"));
	printf("%s\n", ft_strstr("Hello World!", " "));
	printf("%s", ft_strstr("Hello World!", "o"));
	printf("%s\n", ft_strstr("Hello World!", "!"));
	printf("%p ", ft_strstr("Hello World!", "#"));
	printf("%p ", ft_strstr("Hello World!", "h"));
	printf("%p ", ft_strstr("Hello World!", "!#"));
	printf("%p ", ft_strstr("Hello World!", "Hello#"));
	printf("%p\n\n", ft_strstr("Hello World!", "Hello World!!"));
	
	// Exercise 05
	for (int i = 0; i < 50; ++i)
		arr[i] = '#';
	arr[0] = '\0';
	int len = ft_strlcat(arr, "", 50);
	printf("%s %d\n", arr, len);
	len = ft_strlcat(arr, "Hello ", 50);
	printf("%s %d\n", arr, len);
	len = ft_strlcat(arr, "World!", 50);
	printf("%s %d\n", arr, len);
	len = ft_strlcat(arr, "", 50);
	printf("%s %d\n", arr, len);
	len = ft_strlcat(arr, "42", 0);
	printf("%s %d\n", arr, len);
	len = ft_strlcat(arr, "42", 3);
	printf("%s %d\n", arr, len);
	len = ft_strlcat(arr, "\nHello World!", 20);
	printf("%s %d\n", arr, len);
	len = ft_strlcat(arr, "World!", 20);
	printf("%s %d\n", arr, len);
	len = ft_strlcat(arr, "\nHello World!", 42);
	printf("%s %d\n", arr, len);
	for (int i = 31; i < 42; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
