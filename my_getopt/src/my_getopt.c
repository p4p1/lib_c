/*
** EPITECH PROJECT, 2017
** my_getopt.c
** File description:
** the getopt function
*/

#include "my_getopt.h"
#include <stdio.h>

char *my_optarg = 0;
int my_optopt = 0;

static char *dup_str(char const *src)
{
	char	*str;
	int	i = 0;
	int	len = 0;

	if (src == 0)
		return (0);
	while (src[len] != '\0')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	while (src[i] != '\0') {
		str[i] = src[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

static void init_get_opt(char const *optstring)
{
	int	x = 0;

	if (my_optopt == 0 || !in_optstring(optstring, (char)my_optopt)) {
		my_optopt = *optstring;
		return;
	}
	for (x = 0; optstring[x] != '\0'; x++) {
		if (optstring[x] == my_optopt) {
			my_optopt = optstring[x + 1];
			break;
		}
	}
	if (my_optopt == ':') {
		my_optopt = optstring[x + 2];
	}
}

int my_getopt(int argc, char * const argv[], const char *optstring)
{
	int	i = 0;
	int	pos = 0;

	if (argc == 1)
		return (-1);
	init_get_opt(optstring);
	if (my_optopt == '\0')
		return (-1);
	while (i < argc) {
		if ((pos = in_arg(argv[i])) != 0)
			break;
		++i;
	}
	if (i == argc)
		return ('?');
	my_optopt = argv[i][pos];
	if (has_arg(optstring, (char)my_optopt))
		my_optarg = dup_str(argv[i + 1]);
	return (my_optopt);
}
