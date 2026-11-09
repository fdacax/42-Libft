/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedacax <fedacax@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:12:39 by fedacax           #+#    #+#             */
/*   Updated: 2026/11/09 18:59:19 by fedacax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>
#include <limits.h>
#include <unistd.h>

static int	g_tests = 0;
static int	g_failed = 0;

/* ---------------------------------------------------------- */
/*                         TEST HELPERS                       */
/* ---------------------------------------------------------- */

static void	test_result(const char *name, int success)
{
	g_tests++;
	if (success)
		printf("[OK]   %s\n", name);
	else
	{
		printf("[FAIL] %s\n", name);
		g_failed++;
	}
}

static int	same_string(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (s1 == s2);
	return (strcmp(s1, s2) == 0);
}

/* ---------------------------------------------------------- */
/*                       CHARACTER TESTS                      */
/* ---------------------------------------------------------- */

static void	test_characters(void)
{
	int	c;

	printf("\n===== CHARACTER FUNCTIONS =====\n");
	c = -1;
	while (c <= 255)
	{
		if (!!ft_isalpha(c) != !!isalpha(c))
			break ;
		c++;
	}
	test_result("ft_isalpha", c == 256);

	c = -1;
	while (c <= 255)
	{
		if (!!ft_isdigit(c) != !!isdigit(c))
			break ;
		c++;
	}
	test_result("ft_isdigit", c == 256);

	c = -1;
	while (c <= 255)
	{
		if (!!ft_isalnum(c) != !!isalnum(c))
			break ;
		c++;
	}
	test_result("ft_isalnum", c == 256);

	c = -1;
	while (c <= 255)
	{
		if (!!ft_isascii(c) != !!isascii(c))
			break ;
		c++;
	}
	test_result("ft_isascii", c == 256);

	c = -1;
	while (c <= 255)
	{
		if (!!ft_isprint(c) != !!isprint(c))
			break ;
		c++;
	}
	test_result("ft_isprint", c == 256);

	c = -1;
	while (c <= 255)
	{
		if (ft_toupper(c) != toupper(c))
			break ;
		c++;
	}
	test_result("ft_toupper", c == 256);

	c = -1;
	while (c <= 255)
	{
		if (ft_tolower(c) != tolower(c))
			break ;
		c++;
	}
	test_result("ft_tolower", c == 256);
}

/* ---------------------------------------------------------- */
/*                        STRING TESTS                         */
/* ---------------------------------------------------------- */

static void	test_strings(void)
{
	char	src[] = "Hello World";
	char	dst1[30];
	char	dst2[30];
	char	*expected;
	char	*result;
	int		ok;

	printf("\n===== STRING FUNCTIONS =====\n");

	test_result("ft_strlen", ft_strlen(src) == strlen(src));
	test_result("ft_strlen empty", ft_strlen("") == strlen(""));

	test_result("ft_strchr found",
		ft_strchr(src, 'W') == strchr(src, 'W'));
	test_result("ft_strchr not found",
		ft_strchr(src, 'x') == strchr(src, 'x'));
	test_result("ft_strchr null",
		ft_strchr(src, '\0') == strchr(src, '\0'));

	test_result("ft_strrchr found",
		ft_strrchr(src, 'l') == strrchr(src, 'l'));
	test_result("ft_strrchr not found",
		ft_strrchr(src, 'x') == strrchr(src, 'x'));
	test_result("ft_strrchr null",
		ft_strrchr(src, '\0') == strrchr(src, '\0'));

	test_result("ft_strncmp equal",
		ft_strncmp("Hello", "Hello", 5) == strncmp("Hello", "Hello", 5));
	test_result("ft_strncmp different",
		(ft_strncmp("Hello", "World", 5) > 0)
		== (strncmp("Hello", "World", 5) > 0));
	test_result("ft_strncmp zero",
		ft_strncmp("abc", "xyz", 0) == strncmp("abc", "xyz", 0));

	test_result("ft_strnstr found",
		ft_strnstr("Hello World", "World", 11) != NULL);
	test_result("ft_strnstr not found",
		ft_strnstr("Hello World", "xyz", 11) == NULL);
	test_result("ft_strnstr empty needle",
		ft_strnstr("Hello", "", 5) == "Hello");
	test_result("ft_strnstr limited length",
		ft_strnstr("Hello World", "World", 8) == NULL);

	bzero(dst1, sizeof(dst1));
	bzero(dst2, sizeof(dst2));
	expected = "Hello";
	result = ft_strdup(expected);
	test_result("ft_strdup", same_string(result, expected));
	free(result);

	ft_strlcpy(dst1, "Hello World", sizeof(dst1));
	test_result("ft_strlcpy content", same_string(dst1, "Hello World"));
	test_result("ft_strlcpy return",
		ft_strlcpy(dst2, "Hello", 3) == 5);
	test_result("ft_strlcpy truncation", same_string(dst2, "He"));

	bzero(dst1, sizeof(dst1));
	ft_strlcpy(dst1, "Hello", sizeof(dst1));
	result = ft_strjoin(dst1, " World");
	test_result("ft_strjoin", same_string(result, "Hello World"));
	free(result);

	result = ft_substr("Hello World", 6, 5);
	test_result("ft_substr normal", same_string(result, "World"));
	free(result);

	result = ft_substr("Hello", 2, 100);
	test_result("ft_substr length bigger than string",
		same_string(result, "llo"));
	free(result);

	result = ft_substr("Hello", 10, 5);
	test_result("ft_substr start out of bounds",
		same_string(result, ""));
	free(result);

	result = ft_strtrim("xxxHello Worldxxx", "x");
	test_result("ft_strtrim", same_string(result, "Hello World"));
	free(result);

	result = ft_strtrim("xxxxx", "x");
	test_result("ft_strtrim all characters", same_string(result, ""));
	free(result);

	result = ft_strtrim("Hello", "");
	test_result("ft_strtrim empty set", same_string(result, "Hello"));
	free(result);

	result = ft_itoa(0);
	test_result("ft_itoa zero", same_string(result, "0"));
	free(result);

	result = ft_itoa(42);
	test_result("ft_itoa positive", same_string(result, "42"));
	free(result);

	result = ft_itoa(-42);
	test_result("ft_itoa negative", same_string(result, "-42"));
	free(result);

	result = ft_itoa(INT_MIN);
	ok = same_string(result, "-2147483648");
	test_result("ft_itoa INT_MIN", ok);
	free(result);

	result = ft_itoa(INT_MAX);
	ok = same_string(result, "2147483647");
	test_result("ft_itoa INT_MAX", ok);
	free(result);

	test_result("ft_atoi normal",
		ft_atoi("42") == atoi("42"));
	test_result("ft_atoi negative",
		ft_atoi("-42") == atoi("-42"));
	test_result("ft_atoi spaces",
		ft_atoi("   +123abc") == atoi("   +123abc"));
	test_result("ft_atoi zero",
		ft_atoi("0") == atoi("0"));
	test_result("ft_atoi INT_MIN",
		ft_atoi("-2147483648") == atoi("-2147483648"));
	test_result("ft_atoi INT_MAX",
		ft_atoi("2147483647") == atoi("2147483647"));
}

/* ---------------------------------------------------------- */
/*                        MEMORY TESTS                         */
/* ---------------------------------------------------------- */

static void	test_memory(void)
{
	char	dst1[20];
	char	dst2[20];
	char	buf1[20];
	char	buf2[20];
	char	*ptr1;
	char	*ptr2;

	printf("\n===== MEMORY FUNCTIONS =====\n");

	ft_memset(dst1, 'A', 5);
	memset(dst2, 'A', 5);
	test_result("ft_memset", memcmp(dst1, dst2, 5) == 0);

	ft_bzero(dst1, sizeof(dst1));
	bzero(dst2, sizeof(dst2));
	test_result("ft_bzero",
		memcmp(dst1, dst2, sizeof(dst1)) == 0);

	ft_memcpy(dst1, "Hello", 6);
	memcpy(dst2, "Hello", 6);
	test_result("ft_memcpy",
		memcmp(dst1, dst2, 6) == 0);

	ft_memmove(buf1, "Hello World", 12);
	memmove(buf2, "Hello World", 12);
	ft_memmove(buf1 + 2, buf1, 5);
	memmove(buf2 + 2, buf2, 5);
	test_result("ft_memmove overlap forward",
		memcmp(buf1, buf2, 12) == 0);

	ft_memmove(buf1, "Hello World", 12);
	memmove(buf2, "Hello World", 12);
	ft_memmove(buf1, buf1 + 2, 5);
	memmove(buf2, buf2 + 2, 5);
	test_result("ft_memmove overlap backward",
		memcmp(buf1, buf2, 12) == 0);

	ptr1 = ft_memchr("Hello World", 'W', 11);
	ptr2 = memchr("Hello World", 'W', 11);
	test_result("ft_memchr found", ptr1 != NULL && ptr2 != NULL
		&& ptr1 - (char *)"Hello World"
		== ptr2 - (char *)"Hello World");

	test_result("ft_memchr not found",
		ft_memchr("Hello", 'x', 5) == memchr("Hello", 'x', 5));

	test_result("ft_memchr zero length",
		ft_memchr("Hello", 'H', 0) == memchr("Hello", 'H', 0));

	test_result("ft_memcmp equal",
		ft_memcmp("Hello", "Hello", 5) == memcmp("Hello", "Hello", 5));

	test_result("ft_memcmp different",
		(ft_memcmp("Hello", "World", 5) > 0)
		== (memcmp("Hello", "World", 5) > 0));

	test_result("ft_memcmp zero length",
		ft_memcmp("Hello", "World", 0) == memcmp("Hello", "World", 0));

	{
		char	*p1 = ft_calloc(5, sizeof(int));
		char	*p2 = calloc(5, sizeof(int));
		int		ok;

		ok = (p1 && p2 && memcmp(p1, p2, 5 * sizeof(int)) == 0);
		test_result("ft_calloc zero initialization", ok);
		free(p1);
		free(p2);
	}
}

/* ---------------------------------------------------------- */
/*                       EXTRA FUNCTIONS                      */
/* ---------------------------------------------------------- */

static char	map_char(unsigned int i, char c)
{
	(void)i;
	return (ft_toupper(c));
}

static void	iter_char(unsigned int i, char *c)
{
	(void)i;
	*c = ft_toupper(*c);
}

static void	test_extra(void)
{
	char	*result;
	char	str[] = "hello";
	char	**split;
	int		ok;

	printf("\n===== EXTRA FUNCTIONS =====\n");

	result = ft_strmapi("hello", map_char);
	test_result("ft_strmapi", same_string(result, "HELLO"));
	free(result);

	ft_striteri(str, iter_char);
	test_result("ft_striteri", same_string(str, "HELLO"));

	split = ft_split("Hello World 42", ' ');
	ok = (split && split[0] && split[1] && split[2]
			&& !split[3]
			&& same_string(split[0], "Hello")
			&& same_string(split[1], "World")
			&& same_string(split[2], "42"));
	test_result("ft_split normal", ok);
	if (split)
	{
		free(split[0]);
		free(split[1]);
		free(split[2]);
		free(split);
	}

	split = ft_split("   Hello   World   ", ' ');
	ok = (split && split[0] && split[1] && !split[2]
			&& same_string(split[0], "Hello")
			&& same_string(split[1], "World"));
	test_result("ft_split multiple delimiters", ok);
	if (split)
	{
		free(split[0]);
		free(split[1]);
		free(split);
	}

	split = ft_split("xxxxx", 'x');
	ok = (split && !split[0]);
	test_result("ft_split only delimiters", ok);
	free(split);

	split = ft_split("", ' ');
	ok = (split && !split[0]);
	test_result("ft_split empty string", ok);
	free(split);
}

/* ---------------------------------------------------------- */
/*                    FILE DESCRIPTOR TESTS                   */
/* ---------------------------------------------------------- */

static void	test_fd(void)
{
	printf("\n===== FILE DESCRIPTOR FUNCTIONS =====\n");
	printf("Expected output below:\n");

	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Hello World\n", 1);
	ft_putendl_fd("Libft", 1);
	ft_putnbr_fd(42, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-42, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(INT_MIN, 1);
	ft_putchar_fd('\n', 1);

	test_result("File descriptor functions",
		1);
}

/* ---------------------------------------------------------- */
/*                       LINKED LIST TESTS                     */
/* ---------------------------------------------------------- */

static void	delete_content(void *content)
{
	free(content);
}

static void	*map_content(void *content)
{
	return (ft_strdup((char *)content));
}

static void	test_linked_lists(void)
{
	t_list	*lst;
	t_list	*node;
	t_list	*last;
	t_list	*mapped;

	printf("\n===== LINKED LIST FUNCTIONS =====\n");

	lst = NULL;
	test_result("ft_lstlast empty", ft_lstlast(lst) == NULL);

	node = ft_lstnew(ft_strdup("Hello"));
	test_result("ft_lstnew", node != NULL
		&& same_string(node->content, "Hello"));
	lst = node;

	node = ft_lstnew(ft_strdup("World"));
	ft_lstadd_back(&lst, node);
	test_result("ft_lstadd_back",
		lst->next == node && same_string(node->content, "World"));

	node = ft_lstnew(ft_strdup("42"));
	ft_lstadd_front(&lst, node);
	test_result("ft_lstadd_front", lst == node);

	test_result("ft_lstsize", ft_lstsize(lst) == 3);

	last = ft_lstlast(lst);
	test_result("ft_lstlast",
		last != NULL && same_string(last->content, "World"));

	mapped = ft_lstmap(lst, map_content, delete_content);
	test_result("ft_lstmap",
		mapped != NULL && ft_lstsize(mapped) == 3
		&& same_string(mapped->content, "42"));

	ft_lstiter(lst, (void (*)(void *))free);
	/*
	 * The list nodes are still allocated, but their contents
	 * were freed above. Clear the nodes without freeing content.
	 */
}

/* ---------------------------------------------------------- */
/*                            MAIN                            */
/* ---------------------------------------------------------- */

int	main(void)
{
	test_characters();
	test_strings();
	test_memory();
	test_extra();
	test_fd();
	test_linked_lists();

	printf("\n====================================\n");
	printf("TOTAL TESTS: %d\n", g_tests);
	printf("PASSED:      %d\n", g_tests - g_failed);
	printf("FAILED:      %d\n", g_failed);
	printf("====================================\n");

	if (g_failed > 0)
		return (1);
	return (0);
}

