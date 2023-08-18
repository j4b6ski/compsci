#include <climits>
#include <iostream>

using namespace std;

const int n_max = 1024*1024;
int lazy[2*n_max];
int tree[2*n_max];

// funkcja push powinna tylko "poprawiac" drzewa 
// zawolanie wiele razy nie moze nic psuc
void push(int akt)
{
    // 1. zaktualizowac "tree" uzywajac wartosci w "lazy"
    tree[akt] += lazy[akt];
    
    // 2. zepchnac "lazy" do synow
    if (akt < n_max) // w lisciach nie spychamy (bo nie ma gdzie)
    {
        lazy[2*akt] += lazy[akt];
        lazy[2*akt+1] += lazy[akt];
    }
    // 3. zaktualizowalismy, wiec zostawiamy lazy[akt] == 0
    lazy[akt] = 0;
}

// dodaj wartosc na przedziale [zap_pocz, zap_kon]
// implementacja analogiczna do punkt-przedzial, ale dodajemy do lazy, zamiast do tree
// zawsze wolamy push na poczatku, bo musimy miec aktualne wartosci w tablicy "tree"
// (do aktualizacji rodzica przy wychodzeniu z trzeciej galezi ifa)
void add(int zap_pocz, int zap_kon, int wartosc, int akt=1, int akt_pocz=0, int akt_kon=n_max-1)
{
    push(akt); // zawsze push, bo jesli zostawimy lazy[akt] != 0, to chodzimy po nieaktualnych wartosciach

    // przedzial zapytania poza przedzialem aktualnym
    if (zap_kon < akt_pocz || akt_kon < zap_pocz)
    {
        return;
    }
    // przedzial aktualny zawiera sie calkowicie w przedziale zapytania
    else if (zap_pocz <= akt_pocz && akt_kon <= zap_kon)
    {
        lazy[akt] += wartosc;
        // zawsze zostawiamy lazy[akt] == 0 przed wyjsciem
        // skoro linijke wyzej dodalismy do lazy[akt], to musimy znowu push()
        push(akt); 
        /* albo: wersja alternatywna bez dodawania do lazy[akt] i bez push (ale powtarza czesc kodu z push):
         * // pamietamy ze musimy zostawic lazy[akt] == 0 przed wyjsciem
         * // wszystkie leniwe zmiany musza byc w synach
         * tree[akt] += wartosc;
         * if (akt < n_max)
         * {
         *    lazy[2*akt] += wartosc;
         *    lazy[2*akt+1] += wartosc;
         * }
         */
    }
    // przedzialy przecinaja sie / zapytania zawiera sie w aktualnym
    else
    {
        int akt_sro = (akt_pocz + akt_kon) / 2;
        add(zap_pocz, zap_kon, wartosc, 2*akt, akt_pocz, akt_sro); // lewy syn
        add(zap_pocz, zap_kon, wartosc, 2*akt + 1, akt_sro + 1, akt_kon); // prawy syn
        tree[akt] = max(tree[2*akt], tree[2*akt + 1]); // aktualizujemy rodzica tak samo jak w punkt-przedzial
    }
}

// znajdz maksimum na przedziale [zap_pocz, zap_kon]
// implementacja tak samo jak w punkt-przedzial jedyna zmiana to 
// zawsze wolamy push na poczatku, zeby miec aktualne wartosci w drzewie "tree"
int get_maks(int zap_pocz, int zap_kon, int akt=1, int akt_pocz=0, int akt_kon=n_max-1)
{
    push(akt); // zawsze push, bo jesli zostawimy lazy[akt] != 0, to chodzimy po nieaktualnych wartosciach

    if (zap_kon < akt_pocz || akt_kon < zap_pocz)
    {
        return INT_MIN;
    }
    else if (zap_pocz <= akt_pocz && akt_kon <= zap_kon)
    {
        return tree[akt];
    }
    else
    {
        int akt_sro = (akt_pocz + akt_kon) / 2;
        int lewy_wynik = get_maks(zap_pocz, zap_kon, 2*akt, akt_pocz, akt_sro);
        int prawy_wynik = get_maks(zap_pocz, zap_kon, 2*akt + 1, akt_sro + 1, akt_kon);
        return max(lewy_wynik, prawy_wynik);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // ...
}
