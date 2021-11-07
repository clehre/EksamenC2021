#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//int toDecimal(int *in);
int letterOccurenceCounter();
/*fikse med array i inputen og bruke strtol(in,NULL,16); istedenfor todec*/
int main(){
    int *ch =0,ch2 =0;
    long decimal = 0;

    //åpne filer for input/output
    FILE *fptrIn = fopen("hexdec", "r");
    FILE *fptrOut = fopen("toascii", "w");

    //check if file is found
    if(fptrIn == NULL || fptrOut == NULL){
        printf("File Not found");
        exit(1);
    }
    //while to read through file.
    while((int)(ch=fgetc(fptrIn))!=EOF){
        ch2 = fgetc(fptrIn);
        //printf("%c",ch)
        strncat((char*)&ch,(char*)&ch2,1);
        decimal = strtol((char*)&ch,NULL,16);
        //write to output stream
        fputc(decimal, fptrOut);
        printf("%c",decimal);
        

    }
    fclose(fptrIn);
    fclose(fptrOut);
    letterOccurenceCounter();
return 0;
}
int letterOccurenceCounter(){
    char* c;
    int counter[28];
    int tmp, i,character;
    memset(counter,0,sizeof(counter));
    printf("\n");
    FILE *fptrInput = fopen("toascii", "r");
      if(fptrInput == NULL) {
        printf("File Not found");
        exit(1);
    }
    while((int)(c=fgetc(fptrInput))!= EOF){
       tmp = toupper((int)c);
       tmp = (int)tmp-'A';
       if(tmp>=0 && tmp<=28)
            counter[tmp] += 1;
    } 
    
    
    for(i = 0; i<26; i+=2){
        character = i;        
        printf("%c = ", character+65);
        printf("%d\t",counter[i]);
        printf("%c = ", character+66);
        printf("%d\n",counter[i+1]);
    }
    return 0;

} 
