/*************************************************************************
	> File Name: main.c
	> Author: Anboqing
	> Mail:750145240@qq.com 
	> Created Time: 2014年03月24日 星期一 20时26分53秒
 ************************************************************************/

#include "include.h"
/**
int preProcess(){

}
*/

int main(int argc,char **argv){
	char buf[BUFF_LEN];
	char outName[STR_LEN] = "out.dat";
	char pattern[BUFF_LEN];
	char *cmd,*firstArg,*secondArg,*pStr,*pT;
	if(argc<1){
		printf("please input a filename as argument\n");
		return -1;
	}

	cleanToken(argv[1],outName);

	while((cmd = fgets(buf,sizeof(buf),stdin))!=NULL){
		firstArg = strtok(cmd," ");
		secondArg = strtok(NULL,"\n");
		/*对模式串也进行处理再传进去*/
		/*preProcess(secondArg);   */
		puts(secondArg);
		if(strcmp(firstArg,"wc")==0){
			pStr = secondArg;
			while(!isalpha(*pStr)){
				pStr++;
			}
			switch(*pStr){
				case 'l':
					printf(" the file %s has %d lines\n",argv[1],getLines(outName));
					break;
				case 'w':
					printf(" the file %s has %d Words\n",argv[1],getWords(outName));
					break;
				case 'c':
					printf(" the file %s has %d characters\n",argv[1],getCharacters(outName));
					break;
				default:
					puts("no such arguments \n");
					break;
			}
		}else if(strcmp(firstArg,"search")==0){
			search(argv[1],outName,secondArg);
		}
	}
	return 1;
}


