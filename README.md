
**Maszyna Turinga** 
===================

### Ignacy Pstrągowski, Iga Szczepańska 

Przedmiotem naszego projektu było zaprojektowanie symulatora **Maszyny
Turinga** używając języka C. Zgodnie z podanymi intrukcjami oraz danymi,
program wykona odpowiednie działania na wzór funkcjonowania Maszyny
Turinga.



## Instrukcja instalacji

Program wykorzystuje bibliotekę *conio2.h*. W związku z tym konieczne
będzie jej zainstalowanie oraz użycie *Code::Blocks* lub *DevC++*.
Poniżej znajduje się instrukcja dla Code::Blocks.

1.  Aby zainstalować bibliotekę *conio2.h* należy pobrać [pliki
    ZIP](https://drive.google.com/file/d/10zTCd2c7i7yccB2tQRz2sKM6JU0YYV9j/view)
    i rozpakować je.
2.  Następnie otworzyć folder *include* i skopiować pliki.
3.  Wejść w folder Program files \> Code::Blocks \> MinGW \> include i
    wkleić skopiowane pliki.
4.  To samo należy powtórzyć z folderem *lib*.
5.  Teraz trzeba otworzyć program Code::Blocks.
6.  Wejść w Settings \> Compiler \> Linker Settings
7.  Dodać Add \"libconio.a\"

Teraz mamy zainstalowaną potrzebną bibliotekę.

## Opis działania symulatora

Najpierw zaczynamy od wyboru czy chcemy sami stworzyć tabelę z
instrukcjami,ściągnąć ją z pliku txt czy zobaczyć przykładowe działanie
Maszyny.\
\
![pierwszy\_krok](https://github.com/igxsz/symulator-maszyny-touringa/blob/main/1.png)\
\
Jeśli wybraliśmy pierwszą opcję - wczytanie tabeli z pliku, program
pobierze odpowiednie dane i uzupełni tabelę.\
Jeśli wybraliśmy drugą opcję - stworzenie własnej tabeli, program zapyta
nas o ilość stanów oraz znaków dla maszyny. Dla podanych danych stworzy
tabelę i poprosi o uzupełnienie jakie znaki ma rozpoznawać.\
Tak wygląda uzupełniona tabela instrukcji:\
\
![drugi\_krok](https://github.com/igxsz/symulator-maszyny-touringa/blob/main/2.png)\
\
Następnie musimy podać ciąg znaków, na którym Maszyna ma pracować.\
Dla przykładu *0021011*.\
\
![trzeci\_krok](https://github.com/igxsz/symulator-maszyny-touringa/blob/main/5.png)\
\
Po wcisnięciu klawisza Enter, Maszyna zacznie swoją pracę.\
\
![trzeci\_krok](https://github.com/igxsz/symulator-maszyny-touringa/blob/main/3.png)\
\
Po zakończeniu pracy, zobaczymy końcowy wynik oraz gdzie zatrzymała się
głowica. Dodatkowo program poda liczbę wykonanych kroków i stan końcowy.
Na tym etapie możemy skończyć - wciskając *N* lub wcisnąć *T* i podać
kolejny ciąg znaków.\
Jeśli wybierzemy *T* i podamy ciag znaków, Maszyna wykona dokładnie
takie same kroki i zwróci odpowiedni wyniki.\
\
![czwarty\_krok](https://github.com/igxsz/symulator-maszyny-touringa/blob/main/4.png)


