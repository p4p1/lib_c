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

int my_getopt(int argc, char * const argv[], const char *optstring);
int in_optstring(const char *optstring, char c);
int has_arg(const char *optstring, char c);
int in_arg(char const *argv);

extern char *my_optarg;
extern int my_optopt;

#endif
