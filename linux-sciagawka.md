# ściągawka z podstaw Linuxa

## uruchamianie terminala

**WSL** - uruchamiamy skrótem "*Ubuntu on Windows*", lub alternatywnie w cmd/PowerShell/Win+R poleceniem `wsl`

**w64devkit** - uruchamiamy w rozpakowanym folderze program `w64devkit.exe`

## podstawy shella

W oknie terminala powinien uruchomić się tzw. "shell", czyli program który wykonuje wpisywane polecenia (zatwierdzane enterem). 
W naszym przypadku jest to `bash` (WSL), lub `sh` (w64devkit). 
Polecenia mogą być operacjami w specjalnym wbudowanym języku skryptowym, albo nazwami programów. 

Shell wykonuje polecenia w aktualnym *katalogu roboczym* (*working directory*).

| polecenie | opis |
| --------- | ---- |
| `pwd` | program `pwd` (**p**rint **w**orking **d**irectory) wypisuje ścieżkę katalogu roboczego |
| `ls`  | program `ls` (**l**i**s**t) wypisuje listę plików w katalogu roboczym | 

Historię wykonywanych poleceń można przeglądać strzałkami w górę/dół.

### argumenty pozycyjne 

Uruchamianym programom można podawać *argumenty pozycyjne*, na przykład:

| polecenie | opis |
| --------- | ---- |
| `ls .`    | wypisuje katalog roboczy |
| `ls ..`   | wypisuje katalog wyżej |
| `ls ../..`| wypisuje dwa katalogi wyżej |
| `ls /`    | wypisuje *katalog główny* (*root directory*) - korzeń systemu plików |
| `ls ~`    | wypisuje *katalog domowy* aktualnego użytkownika (*home directory*)<br>wpisanie symbolu tyldy (~) na polskiej klawiaturze trzeba zatwierdzić spacją |

<!---
Ścieżki mogą, ale nie muszą, być zakończone znakiem `/`.
Niektóre programy (ale nie program `ls`) rozróżniają ścieżki kończące się `/` jako katalogi, a pozostałe jako pliki.

| polecenie | opis |
| --------- | ---- |
| `ls ./`       | wypisuje katalog roboczy |
| `ls ../`      | wypisuje katalog wyżej |
| `ls ../../`   | wypisuje dwa katalogi wyżej |
--->

### flagi

Niektóre programy rozróżniają argumenty poprzedzone pojedynczym (`-`) lub podwójnym (`--`) myślnikiem (*dash*) jako *flagi* (lub *opcje*). 
Po niektórych flagach czasem podaje się *wartość*, oddzieloną spacją lub znakiem `=`.

Najczęstszą flagą jest `--help`, zwykle nie przyjmuje wartości:

| polecenie | opis |
| --------- | ---- |
| `ls --help` | wypisuje instrukcje do programu `ls` |

W większości programów kolejność flag nie ma znaczenia, ale często wszystkie flagi muszą znajdować się przed argumentami pozycyjnymi.


Niektóre programy pozwalają podawać wiele tzw. *flag krótkich* (jednoliterowych) poprzedzonych tym samym pojedynczym myślnikiem (`-`). 
Czasami flagi krótkie mają też odpowiadające *flagi długie*.
 Poniższe polecenia są równoważne:

| polecenie | opis |
| --------- | ---- |
| `ls -al ~`      | wypisuje szczegółową listę plików w katalogu domowym, w tym pliki "ukryte" (o nazwach zaczynających się od `.`) |
| `ls -la ~`      |
| `ls -a -l ~`    |
| `ls -l -a ~`    |
| `ls --all -l ~` |
| `ls -l --all ~` |

### autouzupełnianie
Podczas pisania przydatne jest autouzupełnianie klawiszem \<tab\>

`ls -al /h` + \<tab\> = `ls -al /home/`

jeśli nie ma jednoznacznego zakończenia, pokazuje się lista wszystkich możliwości

### dostęp do plików z Windowsa

| polecenie | opis |
| --------- | ---- |
| `ls -al /mnt/c` | lokacja dysku C na WSL |
| `ls -al C:/`    | lokacja dysku C na w64devkit<br>(w tym przypadku `C:/` jest też katalogiem głównym `/`) |

### zmiana aktualnego katalogu

Program `cd` (**c**hange **d**irectory) zmienia aktualny katalog (wypisywany poleceniem `pwd`)

| polecenie | opis |
| --------- | ---- |
| `cd ..` | wejście do katalogu wyżej ("wyjście" z aktualnego katalogu) |
| `cd test` | wejście do podkatalogu "test" w aktualnym katalogu, tzw. *ścieżka względna* (ang. *relative path*) |
| `cd ../test` | wejście do katalogu "test" w katalogu wyżej, nadal ścieżka względna |
| `cd /` | wejście do katalogu głównego
| `cd /home/user/test` | wejście do katalogu /home/user/test, tzw. *ścieżka bezwzględna* (ang. *absolute path*) |

## interakcja z systemem plików

| polecenie | opis |
| --------- | ---- |
| `echo "Hello World!"` | program `echo` wypisuje podane argumenty na wyjście standardowe (*standard output*)
| `echo "Hello World!" > hello.txt` | operator `>` pozwala *przekierować* (*redirect*) wyjście standardowe programu do pliku |
| `cat hello.txt` | program `cat` (con**cat**enate) wypisuje zawartości podanych plików na wyjście standardowe |
| `mv hello.txt hello` | program `mv` (**m**o**v**e) zmienia nazwę pliku<br> rozszerzenia plików (np `.txt`) nie są obowiązkowe w Linuxie |
| `cp hello hello2` | program `cp` (**c**o**p**y) tworzy kopię pliku |
| `mkdir katalog` | program `mkdir` (**m**a**k**e **dir**ectory) tworzy katalog |
| `mv hello hello2 katalog` | program `mv` służy także do przenoszenia plików do innego katalogu<br>ostatni argument pozycyjny jest ścieżką katalogu docelowego|
| `echo "Goodbye World!" > katalog/goodbye`<br>`diff katalog/hello katalog/goodbye` | program `diff` (**diff**erence) wypisuje różnice między podanymi plikami |
| `rm katalog/hello2`| program `rm` (**r**e**m**ove) usuwa plik (**bezpowrotnie** - w Linuxie nie ma kosza!) |
| `rm -r katalog` | program `rm` z flagą -r (--**r**ecursive) usuwa katalog wraz z całą zawartością (**bezpowrotnie**), pytając dla każdego pliku o potwierdzenie |
| `rm -rf katalog` | (**ostrożnie!**) program `rm` z flagą -f (--**f**orce) **nie pyta o potwierdzenie** (przydatne przy usuwaniu katalogów z wieloma plikami)

## programy z windowsa

Zarówno w WSL jak w64devkit można uruchamiać programy z windowsa

`notepad.exe hello.txt`

(Tylko na WSL) dostępny jest prosty edytor tekstu w terminalu

`nano hello.txt`

## kompilacja i uruchamianie programów C++

Programy C++ kompilujemy programem `g++` (GNU  C++ compiler).
Domyślna nazwa skompilowanego programu to `a.out`.
Programy w Linuxie nie muszą mieć żadnego konkretnego rozszerzenia (np. `.exe`).
Plik uruchamiamy jako program poprzedzając jego ścieżkę względną przez `./` :
```
g++ hello.cpp
./a.out
```
lub podając ścieżkę bezwzględną
```
g++ hello.cpp
/home/user/a.out
```

Programy `.exe` skompilowane naszym ulubionym IDE (np. Code::Blocks) uruchamiamy w dokładnie ten sam sposób.

### najbardziej przydatne flagi do g++:

Wszystkie flagi `g++` są poprzedzone pojedynczym myślnikiem (`-`)

| polecenie | opis |
| --------- | ---- |
| `g++ -o hello` | kompiluje do pliku o nazwie `hello`, zamiast `a.out`<br>nazwa pliku jest wartością flagi `-o`|
| `g++ -std=c++17` | włącza standard C++17 (aktualnie używany na OI)<br>uwaga: symbol `=` w tym przypadku jest częścią flagi (nie oznacza jej wartości)|
| `g++ -Wall -Wextra` | włącza najważniejsze ostrzeżenia (warnings) |
| `g++ -g` | dołącza do programu symbole do debugowania |
| `g++ -O3` | włącza poziom 3 optymalizacji czasowej (używany na OI) |

### przekierowywanie wejścia i wyjścia

przekierowanie pliku na *wejście standardowe* (*standard input*) z użyciem operatora `<`
```
echo "test" > input
./hello < input
``````

przekierowanie tekstu na wejście standardowe z użyciem operatora `|` (*pipe*), bez pliku pośredniego
```
echo "test" | ./hello
```

przekierowanie tekstu na wejście + przekierowanie wyjścia do pliku
```
echo "test" | ./hello > out
cat out
```

# dalsza nauka

Dla zainteresowanych nauką Linuxa gorąco polecam trzecie wydanie książki [*How Linux Works*](https://nostarch.com/howlinuxworks3) autorstwa Briana Warda.
Rozdział 2 szczegółowo opisuje podstawy terminala i wiele innych przydatnych na co dzień poleceń.
