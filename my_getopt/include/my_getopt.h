/*
** EPITECH PROJECT, 2017
** my_getopt.h
** File description:
** <..>
*/

#ifndef MY_GETOPT_H_
#define MY_GETOPT_H_

#include <stdlib.h>
#include <unistd.h>

struct optarg {
	char	*opt;
	int	no;
	struct optarg *next;
};

int my_getopt(int argc, char *argv[], const char *optstring);
int in_optstring(const char *optstring, char c);
int has_arg(const char *optstring, char c);
int in_arg(char const *argv);
int len(char const *str);
void my_puts(char *str);
int move_arr(char *av[], int pos);

extern char *my_optarg;
extern int my_optopt;
extern int my_optind;

#endif
