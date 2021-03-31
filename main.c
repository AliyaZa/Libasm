/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:43:27 by nhill             #+#    #+#             */
/*   Updated: 2021/03/31 16:03:40 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
char		*ft_strdup(const char *s1);

int		main(void)
{
	char *s = "Hello";
	char *s1 = "This feature allows\nyou to have the text\nformatted in a very\nsimple way: the\ntext will be wrapped,\nso that no lines\nexceed a maximum number\nof characters per line,\nunless there is a longer\nstring of non-whitespace\ncharacters.";
	char *s2 = "\0";
	char *s3 = "\0";
	char *s4 = "Hello";
	char *s5 = "\xff\xff";
	char *s6 = "\xff";
	char dst[256];
	char dst1[256];
	char arr[500];
	char arr1[500];
	char buf[500];
	char buf1[500];
	char mas[500];
	char mas1[500];
	int fd;
	int fd1;
	ssize_t ret;
	ssize_t ret1;

	printf("		FT_STRLEN:\nft_strlen = %zu		strlen = %zu\n", ft_strlen(s), strlen(s));
	printf("ft_strlen = %zu		strlen = %zu\n", ft_strlen(s1), strlen(s1));
	printf("ft_strlen = %zu		strlen = %zu\n", ft_strlen(s2), strlen(s2));

	printf("\n		FT_STRCPY:\nft_strcpy = %s	strcpy = %s\n", ft_strcpy(dst, s), strcpy(dst1, s));
	printf("ft_strcpy = %s	strcpy = %s\n", ft_strcpy(dst, s1), strcpy(dst1, s1));
	printf("ft_strcpy = %s	strcpy = %s\n", ft_strcpy(dst, s2), strcpy(dst1, s2));

	printf("\n		FT_STRCMP:\nft_strcmp = %d		strcmp = %d\n", ft_strcmp(s, s1), strcmp(s, s1));
	printf("ft_strcmp = %d		strcmp = %d\n", ft_strcmp(s2, s3), strcmp(s2, s3));
	printf("ft_strcmp = %d		strcmp = %d\n", ft_strcmp(s2, s), strcmp(s2, s));
	printf("ft_strcmp = %d		strcmp = %d\n", ft_strcmp(s, s3), strcmp(s, s3));
	printf("ft_strcmp = %d		strcmp = %d\n", ft_strcmp(s, s4), strcmp(s, s4));
	printf("ft_strcmp = %d		strcmp = %d\n", ft_strcmp(s1, s), strcmp(s1, s));
	printf("ft_strcmp = %d		strcmp = %i\n", ft_strcmp(s5, s6), strcmp(s5, s6));

	printf("\n		FT_WRITE:\n");
	fd = open ("example.txt", O_WRONLY);
	fd1 = open ("example2.txt", O_WRONLY);
	write(1, "ft_write = ", 11);
	if (ft_write(1, s, ft_strlen(s)) == - 1)
		printf("\nERRNO = %s\n", strerror(errno));
	write(1, "	write = ", 9);
	if (write(1, s, strlen(s)) == -1)
		printf("\nERRNO = %s\n", strerror(errno));
	if (ft_write(fd, s1, ft_strlen(s1)) == write(fd1, s1, strlen(s1)))
	printf("\nWritten in files\nft_write in example.txt	write in example2.txt\nCheck it out!\n");
	printf("ft_write = %zi		write = %zi\n", ret = ft_write(20, "char", 4),  ret1 = write(20, "char", 4));
	if (ret == -1)
		printf("ERRNO = %s\n", strerror(errno));
	if (ret1 == -1)
		printf("ERRNO = %s\n", strerror(errno));

	printf("\n		FT_READ:\n");
	fd = open("ft_strlen.s", O_RDONLY);
	printf("ft_read = %zi\n%s",ft_read(fd, arr, 10), arr);
	fd = open("ft_strlen.s", O_RDONLY);
	printf("\nread = %zi\n%s\n",read(fd, arr1, 10), arr1);
	printf("Please enter something\n");
	printf("ft_read = %zi\n", ft_read(STDIN_FILENO, buf, 10));
	printf("read = %zi\n", read(STDIN_FILENO, buf1, 10));
	fd = open("1.tx", O_RDONLY);
	printf("ft_read = %zi\n", ret = ft_read(fd, mas, 10));
	if (ret == -1)
		printf("ERRNO = %s\n", strerror(errno));
	fd = open("1.tx", O_RDONLY);
	printf("read = %zi\n", ret1 = read(fd, mas1, 10));
	if (ret1 == -1)
		printf("ERRNO = %s\n", strerror(errno));

	printf("\n		FT_STRDUP:\nft_strdup = %s	strdup = %s\n", ft_strdup(s), strdup(s));
	printf("ft_strdup = %s	strdup = %s\n", ft_strdup(s2), strdup(s2));
	printf("ft_strdup = %s\nstrdup = %s\n", ft_strdup(s1), strdup(s1));

	return (0);
}
