#ifndef __HEADER__
#define __HEADER__

/****************************************************************************
 * 
 * FILE NAME:     header.h
 * 
 * DESCRIPTION:   all declarations of the queue function 
 *
 * DATE           NAEM            REFERENCE       REASION
 *
 *Copyrights 2015 Aricent Technolegies (Holdings) ltd
 *
 ***************************************************************************/

/***************************************************************************
 *			Header Files					   *
 ***************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/***************************************************************************
 *			MACRO DECLARATIONS  				   *
 ***************************************************************************/

#define SUCCESS 0
#define FAILURE 1

#define MAX 80
#define DELIM " "

extern int count_file_lines(char *filename);
extern char **read_file(char *ffname);
extern char *file_process(char **file_line, char *suffix, int line_count);
extern void write_file(char *file_string);

#endif
