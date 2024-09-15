#include <stdio.h>
#include <ctype.h>
#define max 30
int main() {
    FILE *file;
    char filename[max],c;
    int lines=1,words=0,spc=0,alpha=0,in_word=0;
    printf("Enter a Text File Name:(.txt formate)\n");
    scanf("%s",filename);
    file=fopen(filename,"r+");
    if(file==NULL){
        printf("Could not open file %s\n",filename);
        return 1;
    }
    while((c=fgetc(file))!=EOF){
        if(c=='@'||c=='#'||c=='$'||c=='&'||c=='%')
        spc++;
        else
        alpha++;
        if(isspace(c)){
            in_word=0;
        } 
		else if(!in_word){
            words++;
            in_word=1;
        }
        if(c=='\n'){
            lines++;
        }
    }
    fclose(file);
    printf("No. of Lines: %d\n", lines);
    printf("No. of Words: %d\n", words);
    printf("No. of Spacial Characters: %d\n",spc);
    printf("No. of Alphabets: %d\n",alpha);
    return 0;
}
