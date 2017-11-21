/*
** EPITECH PROJECT, 2017
** scan.c
** File description:
** <..>
*/

#include "my_getopt.h"

int in_optstring(const char *optstring, char c)
{
	int	i = 0;

	while (optstring[i] != '\0') {
		if (optstring[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int has_arg(const char *optstring, char c)
{
	int	i = 0;

	while (optstring[i] != '\0') {
		if (optstring[i] == c && optstring[i + 1] == ':')
			return (1);
		++i;
	}
	return (0);
}

int in_arg(char const *argv)
{
	int	i = 0;

	while (argv[i] != '\0') {
		if (argv[i] == my_optopt)
			return (i);
		++i;
	}
	return (0);
}
