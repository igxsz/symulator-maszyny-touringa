//Ignacy Pstr¹gowski i Iga Szczepañska
#include <stdlib.h>
#include <stdio.h>
#include <conio2.h>
#define NULL 0

/*
MASZYNA TURINGA

FUNKCJE Z BIBLIOTEKI CONIO.H, KTÓRE S¥ U¯YTE W PROGRAMIE:
getch(); - pobiera input klawisza (jest trochê jak scanf, ale bez potrzeby dodatkowego wciœniêcia entera)
gotoxy(x,y); - przenosi kursor do miejsca o danych wspó³rzêdnych
clrscr(); - czyœci ekran terminala i przenosi kursor na wspó³rzêdne x=0, y=0
textbackground(); - zmienia kolor t³a z czarnego na dowolny inny
*/

int i,j,dl,p,q,z,zn[500],v=0;
char cb[500],cb2[500],cbmt[500];
char stan[500][500];
char cyfra[500][500];
char ruch[500][500];


void polZnaki(char* tab)
{
	char a='¹',c='æ',e='ê',l='³',s='œ',o='ó',z='¿',zz='Ÿ',n='ñ';
    for(;*tab!=NULL;++tab)
    {
    	if(*tab==a) *tab=(char)165;
    	if(*tab==c) *tab=(char)134;
		if(*tab==e) *tab=(char)169;
    	if(*tab==l) *tab=(char)136;
    	if(*tab==n) *tab=(char)228;
    	if(*tab==o) *tab=(char)162;
    	if(*tab==s) *tab=(char)152;
    	if(*tab==z) *tab=(char)190;
    	if(*tab==zz) *tab=(char)171;
    }
}

void tabela()
{
	printf("Tabela instrukcji MT\n");
	printf("%c",218);
	for(i=0;i<z+1;i++)
	{
		printf("%c%c%c%c%c%c",196,196,196,196,196,194);
	}
	printf("%c%c%c%c%c%c\n",196,196,196,196,196,191);
	printf("%c M T ",179);
	for(j=0;j<z;j++)
	{
	    printf("%c  %c  ",179,zn[j]);
    }
    printf("%c  .  %c",179,179);
    printf("\n");
	for(i=0;i<q;i++)
	{
    	printf("%c",195);
	    for(j=0;j<z+1;j++)
    	{
     		printf("%c%c%c%c%c%c",196,196,196,196,196,197);
    	}
    	printf("%c%c%c%c%c%c\n",196,196,196,196,196,180);
    	printf("%c q.%d ",179,i);
    	for(j=0;j<z+1;j++)
	    {
	    	printf("%c %c%c%c ",179,stan[i][zn[j]],cyfra[i][zn[j]],ruch[i][zn[j]]);
    	}
    	printf("%c\n",179);
    }
	printf("%c",192);
	for(i=0;i<z+1;i++)
	{
		printf("%c%c%c%c%c%c",196,196,196,196,196,193);
	}
	printf("%c%c%c%c%c%c\n",196,196,196,196,196,217);
}

void ramka()
{
	printf("%c",218);
	for(i=0;i<dl+1;i++)
	{
		printf("%c%c%c%c",196,196,196,194);
	}
	printf("%c%c%c%c\n",196,196,196,191);
	printf("%c . %c",179,179);
	for(i=0;i<dl;i++)
	{
		printf(" %c %c",cb[i],179);
	}
	printf(" . %c\n",179);
	printf("%c",192);
	for(i=0;i<dl+1;i++)
	{
		printf("%c%c%c%c",196,196,196,193);
	}
	printf("%c%c%c%c\n",196,196,196,217);
}

wczytaj()
{
	FILE *plik;
    char tekst[500];
    plik=fopen("zapisInstrukcjiMT.txt", "r");
    q=-1; z=-2; i=0;
    if(plik==NULL)
    {
    	printf("Wymagany plik nie istnieje!");
    	v=1;
	}
    else while(!feof(plik))
	{
		if(fgets(tekst,500,plik)==NULL) break;
        if(q==-1)
        {
    	    while(tekst[i]!=NULL)
    	    {
    	    	zn[i]=tekst[i];
    	    	i++; z++;
			}
    	    zn[z]=0;
	    }
	    else
	    {
	    	i=3;
			while(tekst[i]!=NULL)
	    	{
	        	stan[q][zn[i/4]]=tekst[i];
	        	cyfra[q][zn[i/4]]=tekst[i+1];
	        	ruch[q][zn[i/4]]=tekst[i+2];
            	i=i+4;
			}
		}
	    q++;
    }
    fclose(plik);
    zn[z]=NULL;
}

zapisz()
{
	FILE *plik;
    plik=fopen("zapisInstrukcjiMT.txt","w+");
    for(i=0;i<z;i++)
	{
	    fprintf(plik,"%c",zn[i]);
    }
    fprintf(plik,".\n");
    for(i=0;i<q;i++)
    {
    	fprintf(plik,"q%d ",i);
		for(j=0;j<z+1;j++)
    	{
    		fprintf(plik,"%c%c%c ",stan[i][zn[j]],cyfra[i][zn[j]],ruch[i][zn[j]]);
		}
		fprintf(plik,"\n");
	}
    fclose(plik);
    printf("Plik zapisany!\n");
}

void cbkrop()
{
	cbmt[0]='.';
	for(i=0;i<dl;i++)
	{
		cbmt[i+1]=cb[i];
	}
	cbmt[dl+1]='.';
}

void glowica()
{
	int x=6,y=6,Q=0,qK=0,cfr,CFR;
	for(i=0;i<q;i++)
	{
		j=0;
		while(zn[j]!=0)
		{
			if(stan[i][zn[j]]>qK) qK=stan[i][zn[j]];
			j++;
		}
	}
	j=1; q=0; p=0;
	CFR=cbmt[j];
	while(q<qK)
	{
		q=Q;
		cfr=CFR;
		if(cfr=='.') cfr=0;
		Q=stan[q][cfr]-48;
		if(stan[q][cfr]==NULL) break;

		gotoxy(x+1,y-2);
	    if(cyfra[q][cfr]!=NULL) printf("%c",cyfra[q][cfr]);
	    else break;
	    cbmt[j]=cyfra[q][cfr];

	    gotoxy(x,y);
    	textbackground(12);
    	printf("   ");
    	textbackground(0);
    	if(ruch[q][cfr]=='R' || ruch[q][cfr]=='r')
    	{
			gotoxy(1,6);
     	    _sleep(200);
    	    gotoxy(x,y);
        	printf("   ");
        	x=x+4;
        	j++;
        	CFR=cbmt[j];
    	}
    	if(ruch[q][cfr]=='L' || ruch[q][cfr]=='l')
    	{
    	    gotoxy(1,6);
    	    _sleep(200);
    	    gotoxy(x,y);
        	printf("   ");
        	x=x-4;
        	j--;
        	CFR=cbmt[j];
    	}
    	p++;
    	//printf("\n\n\n\n\n\n q=%d  Q=%d  qK=%d  p=%d  cfr=%d x=%d j=%d",q,Q,qK,p,cfr,x,j); //getch();
	}
	gotoxy(x+1,y-2);
	printf("%c",cyfra[q-1][cfr]);
	gotoxy(1,7);
}

struct Przyklad
{
  char stan;
  char cyfra;
  char ruch;
};

int main() {

	struct Przyklad przyklad1={'0','0','R'}; struct Przyklad przyklad2={'0','1','R'};
    struct Przyklad przyklad3={'1','.','L'}; struct Przyklad przyklad4={'2','1','S'};
    struct Przyklad przyklad5={'1','0','L'}; struct Przyklad przyklad6={'2','1','S'};

	printf("Witaj w symulatorze Maszyny Turinga!\n\n");
	char napis0[]="Co chcesz zrobiæ?\n1. Wczytaæ tabelê z instrukcjami z pliku txt.\n2. Stworzyæ w³asn¹ tabelê.\n3. Zobaczyæ przyk³adowe dzia³anie Maszyny Turinga.\n\n";
	polZnaki(napis0); printf("%s",napis0);
	char ch;
	ch=getch();
	if(ch=='1')
	{
		wczytaj();
		if(v==1) return 0;
		if(q>10)
		{
			char napisEr[]="W pliku znajduje siê za du¿a liczba stanów!\n";
        	polZnaki(napisEr); printf("%s",napisEr);
        	return 0;
		}
		if(z>16)
		{
			char napisEr[]="W pliku znajduje siê za du¿a liczba ró¿nych znaków, które ma rozpoznawaæ maszyna!\n";
        	polZnaki(napisEr); printf("%s",napisEr);
        	return 0;
		}
		clrscr();
    	tabela();
	}
	else
	{
	if(ch=='3')
	{
		clrscr();
	    printf("Dodawanie 1 do liczby binarnej.\n\n");
        q=2; z=2; zn[0]='0'; zn[1]='1';
        stan[0][zn[0]]=przyklad1.stan; cyfra[0][zn[0]]=przyklad1.cyfra; ruch[0][zn[0]]=przyklad1.ruch;
        stan[0][zn[1]]=przyklad2.stan; cyfra[0][zn[1]]=przyklad2.cyfra; ruch[0][zn[1]]=przyklad2.ruch;
        stan[0][zn[2]]=przyklad3.stan; cyfra[0][zn[2]]=przyklad3.cyfra; ruch[0][zn[2]]=przyklad3.ruch;
        stan[1][zn[0]]=przyklad4.stan; cyfra[1][zn[0]]=przyklad4.cyfra; ruch[1][zn[0]]=przyklad4.ruch;
        stan[1][zn[1]]=przyklad5.stan; cyfra[1][zn[1]]=przyklad5.cyfra; ruch[1][zn[1]]=przyklad5.ruch;
        stan[1][zn[2]]=przyklad6.stan; cyfra[1][zn[2]]=przyklad6.cyfra; ruch[1][zn[2]]=przyklad6.ruch;
        tabela();
	}
	else
	{
	ch=='.';
	clrscr();
	char napis4[]="Stwórzmy tabelê z instrukcjami dla maszyny!\nIle stanów (q) chcesz utworzyæ?\n\n";
	polZnaki(napis4); printf("%s",napis4);
	scanf("%d",&q);
	while(q>10)
	{
		clrscr();
		printf("%s",napis4);
		printf("Wymagana mniejsza liczba.\n\n");
		scanf("%d",&q);
	}
	clrscr();
	char napis5[]="Ile ró¿nych znaków (nie licz¹c kropki) ma rozpoznawaæ maszyna?\n\n";
	polZnaki(napis5); printf("%s",napis5);
	scanf("%d",&z);
	while(z>16)
	{
		clrscr();
		printf("%s",napis5);
		printf("Wymagana mniejsza liczba.\n\n");
		scanf("%d",&z);
	}
	clrscr();
	tabela();
	char napis6[]="\nWpisz jakie znaki ma rozpoznawaæ maszyna, by umieœciæ je w tabeli.\n\n";
	polZnaki(napis6); printf("%s",napis6);
	for(i=0;i<z;i++)
	{
		zn[i]=getch();
	    gotoxy(6*i+10,3);
	    printf("%c",zn[i]);
	}
	clrscr();
	tabela();
	char napis7[]="\nTeraz uzupe³nij komórki tabeli odpowiednimi instrukcjami.\nPrzyk³ad: Jeœli chcesz wprowadziæ do podœwietlonej komórki instrukcjê (q0,0,R), wpisz 00R.\nJeœli chcesz pomin¹æ komórkê, naciœnij spacjê.\n\n";
	polZnaki(napis7); printf("%s",napis7);
	for(j=0;j<q;j++)
	{
	for(i=0;i<z+1;i++)
	{
		gotoxy(6*i+9,2*j+5);
		textbackground(1);
    	printf("   ");
    	gotoxy(6*i+9,2*j+5);
		stan[j][zn[i]]=getch();
		if(stan[j][zn[i]]!=' ')
		{
	    printf("%c",stan[j][zn[i]]);
	    cyfra[j][zn[i]]=getch();
	    printf("%c",cyfra[j][zn[i]]);
	    ruch[j][zn[i]]=getch();
	    printf("%c",ruch[j][zn[i]]);
	    }
	    gotoxy(6*i+9,2*j+5);
	    textbackground(0);
	    printf("%c%c%c",stan[j][zn[i]],cyfra[j][zn[i]],ruch[j][zn[i]]);
	}
	}
	clrscr();
	tabela();
	printf("\nTabela gotowa!\n\n");
	char napis1[]="Czy chcesz zapisaæ stworzone instrukcje w pliku txt? T/N";
	polZnaki(napis1); printf("%s\n\n",napis1);
	ch=getch();
	if(ch=='T' || ch=='t') zapisz();
	else ch='.';
    }
	}


	while(ch!='N' && ch!='n')
	{
	dl=0;
	clrscr();
	tabela();
	char napis[]="Podaj ci¹g znaków, by umieœciæ go na maszynie:\n\n";
	polZnaki(napis); printf("%s",napis);
    scanf("%s",&cb);
	while(cb[dl]!=NULL) dl++;
    while(dl>25)
	{
		clrscr();
		tabela();
		printf("%s",napis);
		char napisEr[]="D³ugoœæ podanego ci¹gu jest za du¿a!\n\n";
        polZnaki(napisEr); printf("%s",napisEr);
		scanf("%s",&cb);
		dl=0;
		while(cb[dl]!=NULL) dl++;
	}
    cbkrop();
    clrscr();
    printf("\n Symulator Maszyny Turinga\n");
    ramka();
	glowica();
	char napis8[]="\nLiczba wykonanych kroków:";
	polZnaki(napis8); printf("%s %d\n",napis8,p);
	char napis9[]="Stan koñcowy:";
	polZnaki(napis9); printf("%s q%d\n",napis9,q);
	char napi[]="Czy chcesz umieœciæ na maszynie inny ci¹g znaków? T/N";
	polZnaki(napi); printf("%s\n\n",napi);
	ch=getch();
    }

    return 0;
}
