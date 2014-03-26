/*************************************************************************
	> File Name: analysis.c
	> Author: Anboqing
	> Mail:750145240@qq.com 
	> Created Time: 2014年03月24日 星期一 21时13分51秒
 ************************************************************************/

#include "include.h"

int getLines(char *fileName){
	int lines = 0;
	FILE *fpIn;
	char ch;
	fpIn = fopen(fileName,"r");
	if(!fpIn){
		perror("open failed\n");
		return -1;
	}
	while((ch = fgetc(fpIn))!=EOF){
		if(ch == '\n'){
			lines++;
		}
	}
	fclose(fpIn);
	return lines;
}
/*处理字符串(去标点，去多余空格，大写换小写)*/
int strCleanToken(char *pattern){
    char *p = pattern;
	char *buf = (char*)malloc(sizeof(char)*strlen(pattern)+1);
    char ch,pre = ' ';
    int i = 0;
	memset(buf,0,sizeof(char)*strlen(pattern)+1);
    while(*p!='\0'){
        if((*p>='a'&&*p<='z')||(*p>='A'&&*p<='Z')||(*p>='0'&&*p<='9')){
            if(*p>='A'&&*p<='Z'){
                ch = *p+32;
            }else{
                ch = *p;
            }
        }else{
            ch = ' ';
        }
		if(!(ch==' '&&pre==' ')){
			buf[i++] = ch;
		}
		pre = ch;
		p++;
    }
	buf[i] = '\0';
	memset(pattern,0,strlen(pattern)*sizeof(char));
	strcpy(pattern,buf);
	/*printf("pattern after process is :%s\n",pattern);*/
    return 1;
}

int cleanToken(char *inName,char *outName){
	FILE *fpIn,*fpOut;
	char ch;
	fpIn = fopen(inName,"r");
	fpOut = fopen(outName,"w");
	if(!fpIn||!fpOut){
		perror("open failed");
		return -1;
	}
	while((ch = fgetc(fpIn))!=EOF){
		if(isdigit(ch)||isalpha(ch)||ch==' '||ch=='\n'){
			if(isupper(ch)){
				ch = tolower(ch);
			}
			fputc(ch,fpOut);
		}else{
			fputc(' ',fpOut);
		}
	}
	fclose(fpIn);
	fclose(fpOut);
	return 1;
}
int getWords(char *fileName){
	int words = 0;
	FILE *fpIn;
	char ch;
	char pre = ' ';
	fpIn = fopen(fileName,"r");
	if(!fpIn){
		perror("open failed\n");
		return -1;
	}
	while((ch = fgetc(fpIn))!=EOF){
		if((pre==' '||pre=='\n')&&(isalpha(ch)||isdigit(ch))){
			words++;
		}	
		pre = ch;
	}
	fclose(fpIn);
	return words;
}

int getCharacters(char *fileName){
	int words = 0;
	FILE *fpIn;
	char ch;
	char pre = ' ';
	fpIn = fopen(fileName,"r");
	if(!fpIn){
		perror("open failed\n");
		return -1;
	}
	while((ch = fgetc(fpIn))!=EOF){
		words++;
	}
	fclose(fpIn);
	return words;
}

int bfFind(char *buf,char *pattern){
	int i,j,start;
	if(strlen(pattern)==0){
		printf("pattern is NULL");
		return 0;
	}
	start = 0;
	i = start;
	j = 0;
	while(i<strlen(buf)&&j<strlen(pattern)){
		if(buf[i]==pattern[j]){
			i++;
			j++;
		}	
		else{
			start++;
			i = start;
			j = 0;
		}
	}
	if(j==strlen(pattern)){
		puts("found\n");
		return i;
	}else{
		return 0;
	}
}

void printLine(char *originName,int line){
	FILE *fp;
	char ch;
	int num =0;
	char buf[BUFF_LEN];
	if(!(fp = fopen(originName,"r"))){
		perror("open origin:\n");
	}
	while((ch=fgetc(fp))!=EOF&&num<line){
		if(ch=='\n'){
			num++;
		}
	}
	/*这里指针要回退一个字符，不然会少读*/
	fseek(fp,-1,SEEK_CUR);
	fgets(buf,sizeof(buf),fp);
	puts(buf);
	fclose(fp);
}

int search(char *originName,char *pattern){
	int lineLength,lineNumber=0,i,flag = 1,count = 0;
	char buf[BUFF_LEN];
	char temp[BUFF_LEN];
	FILE *fpIn;
	strCleanToken(pattern);
	fpIn = fopen(originName,"r");
	if(!fpIn){
		perror("open file:");
		return -1;
	}
	while(NULL!=fgets(buf,sizeof(buf),fpIn)){
		memset(temp,0,sizeof(char)*BUFF_LEN);
		strcpy(temp,buf);
		strCleanToken(buf);
		if(i = bfFind(buf,pattern)){
			printf("line :%d col :%d\t",lineNumber,i);	
			puts(temp);
			flag = 0;
			count++;
		}
		lineNumber++;
	}
	if(flag){
		printf("not found\n");
	}
	printf("has result :%d\n",count);
	fclose(fpIn);
	return 1;
}

int topWord(char *filename,char *num){
	/* 输出频率最高的 num 个单词 */
	/* 对num进行处理（因为传进来的可能含有空格）*/
	int number;
	strCleanToken(num);
	number = atoi(num);
	/* 统计所有单词的频率，（去掉 a the 等无意义的词） */
	
	return 1;
}
