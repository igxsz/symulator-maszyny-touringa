
#include <stdio.h>

int main()
{
    char wyraz[90];
    int i=0;
    int tab[90];
    
    gets(wyraz);
    while(wyraz[i]!='\0')
        i++;
    printf("dlugosc %d\n", i);
    
    
    
    for(i=0; i<90; i++){
        if(wyraz[i]>=65 && wyraz[i]<=90){
        wyraz[i]+=32;
    }
    }
    
    if (wyraz[0]>=97 && wyraz[0]<=122) {
        wyraz[0]-=32;
    }
    
    
    
    printf("%s", wyraz);
    return 0;
}
/*if(wyraz[i]=111 || wyraz[i]=79) wyraz[i]==64;
        if(wyraz[i]=115 || wyraz[i]=83) wyraz[i]==36;
        if(wyraz[i]=97 || wyraz[i]=65) wyraz[i]=="4";
    }*/
    
    /*for(i=0; i<90; i++){
        if(wyraz[i]='a') wyraz[i]=='h';
    }
    for(i=0; i<90; i++){
        if(wyraz[i]='s') wyraz[i]=='$';
    }
    for(i=0; i<90; i++){
        if(wyraz[i]='o') wyraz[i]=='@';
    }*/