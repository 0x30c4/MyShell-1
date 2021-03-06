/* --------------------------- Include Guards ---------------------------- */

#ifndef EXECUTE_H
#define EXECUTE_H

/* ------------------------------ Includes ------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h> 
#include <glob.h>

#include<dirent.h>
#include<sys/stat.h>
#include<ctype.h>
#include<fnmatch.h>
#include "cmdtable.h"

/* --------------------------- Global Variables -------------------------- */

/* 
global command table 
*/
extern struct command_table cmd_table[25];
char cwd[1024];
/* --------------------------- Function Headers -------------------------- */

/*
execute the command
*/
void execute(int);

/*
execute simple command
*/
void execute_simple_command(int num);

/*
execute piped command
*/
void execute_pipe_command(int num);

/*
execute cmd when there is &&
*/
void execute_and_command(int num);

/*
execute cmd when there is ;
*/
void execute_chain_command(int num);


/*
Change directory to the given argument
*/
int change_directory(char ** arg);

void execute_and_command(int num);

/* sgown function */
void printdir(const char *name, char *string, int depth);

int searchfile(char *fname, char *str);

/*handler*/
void alrm_hndlr(int sno, siginfo_t *siginfo,void*context);
void handler(int sno);

/*tree command*/
void tree(char * name,int);
#endif 
