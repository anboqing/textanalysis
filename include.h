/*************************************************************************
	> File Name: include.h
	> Author: Anboqing
	> Mail:750145240@qq.com 
	> Created Time: 2014年03月24日 星期一 20时27分11秒
 ************************************************************************/
#ifndef _TEXT_ANALYSIS_
#define	_TEXT_ANALYSIS_

#include<stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>             	//用perror输出错误

#define STR_LEN 1024
#define BUFF_LEN 1024

int getLines(char *fileName);
int getCharacters(char*name);
int getWords(char *fileName);
int search(char *origin,char *pattern);
int strCleanToken(char *);
int cleanToken(char *,char *);
int topWord(char *,char *);

#endif
