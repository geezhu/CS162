#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]) {
	int shift = 0;
	int words=0;
	int Line=0;
	int total_shift=0;
	int total_words=0;
	int total_Line=0;
	const int no_ch=0;
	const int hav_ch=1;//到达第一个字
	char ch;
	int word_head=hav_ch;
	FILE* fp=NULL;
	int i=1;
	if(argc==1){
		argc++;//just add an entry to loop
	}
	for(i=1;i<argc;i++){
		if(argv[i]==NULL){
			fp=stdin;
			argc--;//just return orginal
		}
		else if((fp=fopen(argv[i],"r"))==NULL){
			printf("Fail to open %s",argv[i]);
			continue;
		}
		shift = 0;
		words=0;
		Line=0;
		word_head=hav_ch;
		while(((ch=fgetc(fp))!=EOF)){
			shift++;
			if(ch==' '||ch=='\n'){
				word_head=hav_ch;
			}
			else if(word_head==hav_ch){//防止空格进入
				word_head=no_ch;//防止之后字符进入
				words++;
			}
			if(ch=='\n'){
				Line++;
			}
		}
		if(argc!=1){
			printf("%4d %4d %4d ",Line,words,shift);
			printf("%-10s\n",argv[i]);
		}
		else{
			printf("%7d %7d %7d ",Line,words,shift);
			printf("\n");
		}
		total_Line+=Line;
		total_words+=words;
		total_shift+=shift;
		if(fp!=NULL){
			fclose(fp);
		}
	}
	if(argc!=1){
		printf("%4d %4d %4d %-10s\n",total_Line,total_words,total_shift,"total");
	}
	return 0;
}
