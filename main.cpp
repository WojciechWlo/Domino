#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <time.h>

using namespace std;

struct kamien
{
    int wartosc_1;
    int wartosc_2;
};
struct ciag
{
    kamien kamienie[28];
    int ilosc_kamieni=0;
};
struct gracz
{
    kamien kamienie[21];
    int ilosc_kamieni=0;
    bool czlowiek=true;
};
// ponizej znajduja sie wzorce dla klockow o roznych numerkach (numerki sa przedstawiane poprzez "trzy warstwy")
void wzorce_kamieni(int wzor, int warstwa)
{
    if(warstwa==0)
    {
        if(wzor==0)cout<<"|   ";
        else if(wzor==1)cout<<"|  *";
        else cout<<"|* *";
    }
    else if(warstwa==1)
    {
        if(wzor==0)cout<<"|   ";
        else if(wzor==1)cout<<"| * ";
        else cout<<"|* *";
    }
    else
    {
        if(wzor==0)cout<<"|   ";
        else if(wzor==1)cout<<"|*  ";
        else cout<<"|* *";
    }
}
//rysowanie ciagu klockow
void rysuj_ciag(kamien tab[], int ilosc)
{
    for(int i=0;i<ilosc;i++)cout <<"     ";
    cout << endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<ilosc;j++)
        {
            //jaki wzorzec dla jakiej liczby
            //zmienna i jest numerem warstwy
            if(i==0)
            {
                if(tab[j].wartosc_1==0 || tab[j].wartosc_1==1)wzorce_kamieni(0, i);
                else if(tab[j].wartosc_1==2 || tab[j].wartosc_1==3)wzorce_kamieni(1, i);
                else wzorce_kamieni(3, i);
            }
            else if(i==1)
            {
                if(tab[j].wartosc_1==0 || tab[j].wartosc_1==4 || tab[j].wartosc_1==2)wzorce_kamieni(0, i);
                else if(tab[j].wartosc_1==1 || tab[j].wartosc_1==3 || tab[j].wartosc_1==5)wzorce_kamieni(1, i);
                else wzorce_kamieni(2, i);
            }
            else if(i==2)
            {
                if(tab[j].wartosc_1==0 || tab[j].wartosc_1==1)wzorce_kamieni(0, i);
                else if(tab[j].wartosc_1==2 || tab[j].wartosc_1==3)wzorce_kamieni(1, i);
                else wzorce_kamieni(2, i);
            }
            if(i==0)
            {
                if(tab[j].wartosc_2==0 || tab[j].wartosc_2==1)wzorce_kamieni(0, i);
                else if(tab[j].wartosc_2==2 || tab[j].wartosc_2==3)wzorce_kamieni(1, i);
                else wzorce_kamieni(2, i);
            }
            else if(i==1)
            {
                if(tab[j].wartosc_2==0 || tab[j].wartosc_2==4 || tab[j].wartosc_2==2)wzorce_kamieni(0, i);
                else if(tab[j].wartosc_2==1 || tab[j].wartosc_2==3 || tab[j].wartosc_2==5)wzorce_kamieni(1, i);
                else wzorce_kamieni(2, i);
            }
            else if(i==2)
            {
                if(tab[j].wartosc_2==0 || tab[j].wartosc_2==1)wzorce_kamieni(0, i);
                else if(tab[j].wartosc_2==2 || tab[j].wartosc_2==3)wzorce_kamieni(1, i);
                else wzorce_kamieni(2, i);
            }
            cout <<"|";
        }
        cout << endl;
    }
    for(int i=0;i<ilosc;i++)cout <<"     ";
}
//funkcja polegajaca na dodawaniu losowych kamieni graczowi
bool dodawanie_losowych_kamieni(gracz &g, ciag ciag_kamieni, kamien *pula_kamieni)
{
    int los;
    //petla wykonujaca sie tak dlugo az zostanie wylosowany klocek pasujacy do ciagu lub kiedy skoncza sie klocki w puli
    do
    {
        do
        {
            los = rand()%28;
            for(int i=0;i<28;i++)
            {
                if(pula_kamieni[i].wartosc_1!=7)break;
                else if(i==27)return true;
            }
        }
        //"usuniecie" klocka z puli nastepuje przez zamiane jego pierwszej wartosci na 7.
        while(pula_kamieni[los].wartosc_1==7);
        g.kamienie[g.ilosc_kamieni]= pula_kamieni[los];
        g.ilosc_kamieni++;
        pula_kamieni[los].wartosc_1=7;
        for(int i=0;i<28;i++)
        {
            if(pula_kamieni[i].wartosc_1!=7)break;
            else if(i==27)return true;
        }
    }while(g.kamienie[g.ilosc_kamieni-1].wartosc_1!=ciag_kamieni.kamienie[0].wartosc_1 &&
           g.kamienie[g.ilosc_kamieni-1].wartosc_2!=ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1].wartosc_2 &&
           g.kamienie[g.ilosc_kamieni-1].wartosc_2!=ciag_kamieni.kamienie[0].wartosc_1 &&
           g.kamienie[g.ilosc_kamieni-1].wartosc_1!=ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1].wartosc_2 );
    return false;
}
//funkcja polegajaca na wyswietlaniu klockow gracza
void rysuj_kamienie_gracza(kamien tab[], int ilosc)
{
    for(int i=0;i<ilosc;i++)cout << " --- ";
    cout << endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<ilosc;j++)
        {
            if(i==0)
            {
                if(tab[j].wartosc_1==0 || tab[j].wartosc_1==1)wzorce_kamieni(0, i);
                else if(tab[j].wartosc_1==2 || tab[j].wartosc_1==3)wzorce_kamieni(1, i);
                else wzorce_kamieni(3, i);
            }
            else if(i==1)
            {
                if(tab[j].wartosc_1==0 || tab[j].wartosc_1==4 || tab[j].wartosc_1==2)wzorce_kamieni(0, i);
                else if(tab[j].wartosc_1==1 || tab[j].wartosc_1==3 || tab[j].wartosc_1==5)wzorce_kamieni(1, i);
                else wzorce_kamieni(2, i);
            }
            else if(i==2)
            {
                if(tab[j].wartosc_1==0 || tab[j].wartosc_1==1)wzorce_kamieni(0, i);
                else if(tab[j].wartosc_1==2 || tab[j].wartosc_1==3)wzorce_kamieni(1, i);
                else wzorce_kamieni(2, i);
            }
            cout <<"|";
        }
        cout << endl;
    }
    for(int i=0;i<ilosc;i++)cout << " --- ";
    cout << endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<ilosc;j++)
        {
            if(i==0)
            {
                if(tab[j].wartosc_2==0 || tab[j].wartosc_2==1)wzorce_kamieni(0, i);
                else if(tab[j].wartosc_2==2 || tab[j].wartosc_2==3)wzorce_kamieni(1, i);
                else wzorce_kamieni(2, i);
            }
            else if(i==1)
            {
                if(tab[j].wartosc_2==0 || tab[j].wartosc_2==4 || tab[j].wartosc_2==2)wzorce_kamieni(0, i);
                else if(tab[j].wartosc_2==1 || tab[j].wartosc_2==3 || tab[j].wartosc_2==5)wzorce_kamieni(1, i);
                else wzorce_kamieni(2, i);
            }
            else if(i==2)
            {
                if(tab[j].wartosc_2==0 || tab[j].wartosc_2==1)wzorce_kamieni(0, i);
                else if(tab[j].wartosc_2==2 || tab[j].wartosc_2==3)wzorce_kamieni(1, i);
                else wzorce_kamieni(2, i);

            }
            cout <<"|";
        }
        cout << endl;
    }
    for(int i=0;i<ilosc;i++)cout << " --- ";
    cout << endl;
    for(int i=0;i<ilosc;i++)
    {
        if(i<10)cout<<"  "<<i+1<<"  ";
        else cout<<"  "<<i+1<<" ";
    }
    cout<<endl;
}
//jesli klocek pasuje do ktoregos z ciagu ale ma numerki na odwrot, nastepuje zamiana ich miejsc (obrot klocka)
void zamien_wartosci(kamien &k)
{
    k.wartosc_1=k.wartosc_1+k.wartosc_2;
    k.wartosc_2=k.wartosc_1-k.wartosc_2;
    k.wartosc_1=k.wartosc_1-k.wartosc_2;
}
//dodanie klocka do ciagu
void dodaj_do_ciagu(ciag &ciag_kamieni, kamien kg, bool rodzaj)
{
    //rodzaj okresla do ktorego konca chcemy dodac klocek
    if(!rodzaj)
    {
        //lewy koniec
        ciag_kamieni.ilosc_kamieni++;
        for(int i=0;i<ciag_kamieni.ilosc_kamieni-1;i++)ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1-i]=ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-i-2];
        ciag_kamieni.kamienie[0]=kg;
    }
    else
    {
        //prawy koniec
        ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni]=kg;
        ciag_kamieni.ilosc_kamieni++;
    }
}
//usuwanie kamienia gracza
void usun_kamien_gracza(gracz &g, int wybrany)
{
    //w rzeczywistosci ten kamien nie jest usuwany. Przesuwaja sie z lewa na prawo a zmniejszenie zmiennej ilosc kamieni uniemozliwia nam usuniecie kamienia po prawej.
    //w przypadku jesli gracz otrzyma nowe kamienie, "niewidoczne kamienie mają po prostu zamienioną wartość"
    for(int i=wybrany;i<g.ilosc_kamieni-1;i++)g.kamienie[i]=g.kamienie[i+1];
    g.ilosc_kamieni--;
}
//sprawdzenie czy w posiadanych kamieniach jest przynajmniej jeden taki ktory pasuje do ciagu
bool sprawdzenie_kamieni(gracz g, ciag ciag_kamieni)
{
    for(int i=0; i<g.ilosc_kamieni;i++)
    {
        if(g.kamienie[i].wartosc_1==ciag_kamieni.kamienie[0].wartosc_1 ||
           g.kamienie[i].wartosc_2==ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1].wartosc_2 ||
           g.kamienie[i].wartosc_2==ciag_kamieni.kamienie[0].wartosc_1 ||
           g.kamienie[i].wartosc_1==ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1].wartosc_2 )
           return true;
    }
    return false;
}
//sprawdzenie czy JEDEN kamien pasuje do ciagu (w przypadku kiedy komputer nie wybral zadnego klocka poprzez losowosc, dobierany jest pierwszy lepszy klocek ktory pasuje do ciagu)
bool sprawdzenie_kamienia(gracz g, ciag ciag_kamieni, int i)
{
    if(g.kamienie[i].wartosc_1==ciag_kamieni.kamienie[0].wartosc_1 ||
       g.kamienie[i].wartosc_2==ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1].wartosc_2 ||
       g.kamienie[i].wartosc_2==ciag_kamieni.kamienie[0].wartosc_1 ||
       g.kamienie[i].wartosc_1==ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1].wartosc_2 )return true;
    return false;
}
//wybor kamienia przez komputer
int wybor_przez_komputer(gracz g,ciag ciag_kamieni)
{
    int los;
    for(int i=0;i<g.ilosc_kamieni;i++)
    {
        if(sprawdzenie_kamienia(g, ciag_kamieni, i))
        {
            los=rand()%2;
            if(los)return i;
        }
    }
    for(int i=0;i<g.ilosc_kamieni;i++)if(sprawdzenie_kamienia(g, ciag_kamieni, i))return i;
}
//funkcja liczaca oczka
void liczenie_oczek(gracz gracze[], int ilosc_graczy)
{
    int tab[4];
    int suma;
    for(int j=0;j<ilosc_graczy;j++)
    {
        suma=0;
        for(int i=0;i<gracze[j].ilosc_kamieni;i++)suma +=gracze[j].kamienie[i].wartosc_1+gracze[j].kamienie[i].wartosc_2;
        cout << "gracz nr. "<<j+1<<" ma "<<suma<<" oczek."<<endl;
        tab[j]=suma;
    }
    int maxi = tab[0];
    int mini = tab[0];

    for(int i=0;i<ilosc_graczy;i++)
    {
        if(tab[i]>maxi)maxi = tab[i];
        if(tab[i]<mini)mini = tab[i];
    }
    cout << "gracz(e) o najwyzszej liczbie oczek ("<<maxi<<"): "<<endl;
    for(int i=0;i<ilosc_graczy;i++)if(tab[i]==maxi)cout << "gracz nr. "<<i+1<<endl;
    cout << endl;
    cout << "gracz(e) o najnizszej liczbie oczek ("<<mini<<"): "<<endl;
    for(int i=0;i<ilosc_graczy;i++)if(tab[i]==mini)cout << "gracz nr. "<<i+1<<endl;
}
void inicjacja(int i_graczy, int i_graczy_komputerowych)
{
    kamien pula_kamieni[28];
    gracz  gracze[i_graczy];
    int x = 7;
    int y = 7;
    int i_kamien=0;
    for(int i=0;i<y;i++)
    {
        for(int j=i;j<x;j++)
        {
            pula_kamieni[i_kamien].wartosc_1=i;
            pula_kamieni[i_kamien].wartosc_2=j;
            i_kamien++;
        }
    }
    int los;
    for(int i=0; i<i_graczy;i++)
    {
        if(i>=i_graczy-i_graczy_komputerowych) gracze[i].czlowiek = false;
        for(int j=0;j<7;j++)
        {
            do
            {
                los = rand()%28;
            }
            while(pula_kamieni[los].wartosc_1==7);
            gracze[i].kamienie[j]= pula_kamieni[los];
            //wykluczanie wylosowanych kamieni polega na zast¹pieniu ich pierwszej wartoœci wartoœci¹ 7
            pula_kamieni[los].wartosc_1=7;
            gracze[i].ilosc_kamieni=7;
        }
    }
    //ciag - Tablica przechowuj¹ca wylazane kamienie
    ciag ciag_kamieni;
    //aktualny_gracz - indeks aktualnego gracza
    int aktualny_gracz = 0;
    //wybrany - wybrany klocek z posiadanych
    int wybrany;
    //wybrany_koniec - jeśli oba końce ciągu są takie same, możemy wybrać, do którego końca chcemy dołożyć klocek
    char wybrany_koniec;

    //--------------------------------Tutaj pierwszy gracz wykłada swój pierwszy dowolny kamień--------------------------------------

    // wyświetla ilość klocków dla każdego gracza
    for(int i=0;i<i_graczy;i++)cout <<"Gracz nr."<<i+1<<": "<<gracze[i].ilosc_kamieni<<" kamieni | ";
    cout << endl<<endl;
    //rysuje aktualne klocki pierwszego gracza
    rysuj_kamienie_gracza( gracze[aktualny_gracz].kamienie,  gracze[aktualny_gracz].ilosc_kamieni);
    cout <<"tura gracza nr 1. Wybierz pierwszy kamien: ";
    cin >> wybrany;
    wybrany--;
    ciag_kamieni.kamienie[0]= gracze[aktualny_gracz].kamienie[wybrany];
    usun_kamien_gracza(gracze[aktualny_gracz], wybrany);
    ciag_kamieni.ilosc_kamieni++;
    aktualny_gracz++;
    //nastapilo_losowanie - zmienna pomocnicza mowiaca czy w trakcie tury gracza doszło do losowania dodatkowych kamieni
    bool nastapilo_losowanie = false;
    // zamkniecie_gry - czy gracz dokonał zamknięcia gry
    bool zamkniecie_gry = false;
    //brak_kamieni - czy gracz pozbył się wszystkich swoich kamieni
    bool brak_kamieni = false;
    //komputer_dobral_kosci - czy komputer dobral kosci
    bool komputer_dobral_kosci=false;
    //niemozliwe_losowania - niemozliwe w sensie ze zarówno gracz nie ma możliwości losowania dodatkowych kamieni.
    //jesli zmienna równa sie ilosci graczy, to znaczy ze zaden nie ma mozliwosci wylozenia swoich kamieni. w takim przypadku gra konczy sie zliczaniem oczek
    int niemozliwe_losowania=0;
    //petla głowna
    while(true)
    {
        //petla w ktorej wykonuja sie operacje zwiazane z wykladaniem kamieni przez graczy. bedzie trwala dopoki gracz nie dokona prawidłowego wyboru,
        //petla moze wrocic na poczatek jesli w trakcie niemozliwego losowania, straci on kolejke i nastapi tura kolejnego gracza lub poprostu
        //dobrania kamieni przez gracza z mozliwoscia kontynuowania przez niego tej rundy.
        do{
            wybrany =0;
            nastapilo_losowanie=false;
            //zabezpieczenie zeby w przypadku powrotu do poczatku petli podczas tury (spowodowany dobieraniem kamieni) nie odswiezalo  znowu.
            if(!komputer_dobral_kosci)
            {
                system("cls");
                for(int i=0;i<i_graczy;i++)cout <<"Gracz nr."<<i+1<<": "<<gracze[i].ilosc_kamieni<<" kamieni | ";
                cout << endl;
                rysuj_ciag(ciag_kamieni.kamienie, ciag_kamieni.ilosc_kamieni);
                cout << endl;
            }
            //jesli graczem jest czlowiek to wyswietlają sie jego kamienie;
            if(gracze[aktualny_gracz].czlowiek)
            {
                system("cls");
                for(int i=0;i<i_graczy;i++)cout <<"Gracz nr."<<i+1<<": "<<gracze[i].ilosc_kamieni<<" kamieni | ";
                cout << endl;
                rysuj_ciag(ciag_kamieni.kamienie, ciag_kamieni.ilosc_kamieni);
                cout << endl;
                rysuj_kamienie_gracza( gracze[aktualny_gracz].kamienie,  gracze[aktualny_gracz].ilosc_kamieni);
                cout <<"Tura gracza nr "<<aktualny_gracz+1<<". ";
            }
            else
            {
                //zabezpieczenie zeby nie wyswietlalo się znowu przy dobraniu przez komputer kamieni.
                if(!komputer_dobral_kosci)
                {
                    cout <<"Tura gracza nr "<<aktualny_gracz+1<<". (Komputer)"<<endl;
                    system("pause");
                }
            }
            //sprawdzenie czy gracz moze wylozyc jakis kamien ktory by pasowal do ciagu
            if(!sprawdzenie_kamieni(gracze[aktualny_gracz], ciag_kamieni))
            {
                if(gracze[aktualny_gracz].czlowiek)
                {
                    cout <<endl<< "Nie posiadasz klockow ktorych moglbys uzyc! Musisz wylosowac nowe kamienie."<<endl;
                    system("Pause");
                }
                else komputer_dobral_kosci = true;
                if(!brak_kamieni && dodawanie_losowych_kamieni(gracze[aktualny_gracz], ciag_kamieni, pula_kamieni))brak_kamieni=true;
                if(brak_kamieni &&gracze[aktualny_gracz].czlowiek)cout << "brak kamieni do wylosowania."<< endl;
                //zmienna ta prawde mowiac okresla czy wykonal sie etap w ktorym gracz nie mial kamieni ktore moglby wylozyc
                nastapilo_losowanie = true;
            }
            //jesli gracz moze polozyc kamien LUB jesli podczas losowania otrzymal kamien ktory moze wylozyc (ale w tym przypadku kod przejdzie do poczatku petli zeby "wyczyscic ekran z komunikatow")
            if(!nastapilo_losowanie)
            {
                if(gracze[aktualny_gracz].czlowiek){
                    cout << "Wybierz kamien: ";
                    cin >> wybrany;
                }
                else{
                    wybrany = wybor_przez_komputer(gracze[aktualny_gracz],ciag_kamieni);
                    break;
                }
            }
            //jest to sytuacja w ktorej gracze nie mogą wykladac zadnych klockow a w puli nie ma juz nic.
            if(brak_kamieni && nastapilo_losowanie)
            {
                niemozliwe_losowania++;
                if(gracze[aktualny_gracz].czlowiek){
                    cout << "Tracisz kolejke"<<endl;
                    system("pause");
                }
                else komputer_dobral_kosci = false;
                aktualny_gracz++;
                if(aktualny_gracz>=i_graczy)aktualny_gracz=0;
            }
            //jesli zaden z graczy nie moze wykonac ruchu, petla sie konczy
            if(niemozliwe_losowania>=i_graczy)break;
        }while(wybrany<1 || wybrany> gracze[aktualny_gracz].ilosc_kamieni);
        //wybrany oznacza w rzeczywistosci indeks kamieni jakie gracz posiada, wgracz wpisuje liczbe o jeden wiekszą
        if(gracze[aktualny_gracz].czlowiek)wybrany--;
        //warunek pasowania kamienia do ciagu
        if(gracze[aktualny_gracz].kamienie[wybrany].wartosc_1==ciag_kamieni.kamienie[0].wartosc_1 ||
           gracze[aktualny_gracz].kamienie[wybrany].wartosc_2==ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1].wartosc_2 ||
           gracze[aktualny_gracz].kamienie[wybrany].wartosc_2==ciag_kamieni.kamienie[0].wartosc_1 ||
           gracze[aktualny_gracz].kamienie[wybrany].wartosc_1==ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1].wartosc_2 )
        {
            //jesli ktorykolwiek z graczy wylozy klocek, ponizza zmienna sie zeruje poniewaz mogl zostac wylozony kamien do ktorego gracze mogliby cos dolozyc (jest mozliwosc)
            niemozliwe_losowania=0;
            //warunek zamkniecia gry
            if ( gracze[aktualny_gracz].kamienie[wybrany].wartosc_1==ciag_kamieni.kamienie[0].wartosc_1 &&
                 gracze[aktualny_gracz].kamienie[wybrany].wartosc_2==ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1].wartosc_2 ||
                 gracze[aktualny_gracz].kamienie[wybrany].wartosc_2==ciag_kamieni.kamienie[0].wartosc_1 &&
                 gracze[aktualny_gracz].kamienie[wybrany].wartosc_1==ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1].wartosc_2)zamkniecie_gry=true;
            //sytuacja w ktorej oba konce maja ten sam numer
            if ( gracze[aktualny_gracz].kamienie[wybrany].wartosc_1==ciag_kamieni.kamienie[0].wartosc_1 &&
                 gracze[aktualny_gracz].kamienie[wybrany].wartosc_1==ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1].wartosc_2 ||
                 gracze[aktualny_gracz].kamienie[wybrany].wartosc_2==ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1].wartosc_2 &&
                 gracze[aktualny_gracz].kamienie[wybrany].wartosc_2==ciag_kamieni.kamienie[0].wartosc_1)
            {
                if(gracze[aktualny_gracz].czlowiek)
                {
                    do
                    {
                        cout << "Wybierz koniec do ktorego chcesz dolozyc kamien (l-lewy, p-prawy):" <<endl;
                        cin >> wybrany_koniec;
                        cout <<endl;
                    }while(wybrany_koniec!='l'&& wybrany_koniec!='p');
                }
                else
                {
                    int los=rand()%2;
                    if(los)wybrany_koniec='l';
                    else wybrany_koniec='p';
                }
                if(wybrany_koniec=='l')
                {
                    //wyjasnienie ponizej
                    if( gracze[aktualny_gracz].kamienie[wybrany].wartosc_1==ciag_kamieni.kamienie[0].wartosc_1)
                    {
                        zamien_wartosci(gracze[aktualny_gracz].kamienie[wybrany]);
                        dodaj_do_ciagu(ciag_kamieni,gracze[aktualny_gracz].kamienie[wybrany],0);
                    }
                    else if( gracze[aktualny_gracz].kamienie[wybrany].wartosc_2==ciag_kamieni.kamienie[0].wartosc_1)
                    {
                        dodaj_do_ciagu(ciag_kamieni,gracze[aktualny_gracz].kamienie[wybrany],0);
                    }
                }
                else
                {
                    //jeszcze nizej
                    if( gracze[aktualny_gracz].kamienie[wybrany].wartosc_2==ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1].wartosc_2)
                    {
                        zamien_wartosci(gracze[aktualny_gracz].kamienie[wybrany]);
                        dodaj_do_ciagu(ciag_kamieni,gracze[aktualny_gracz].kamienie[wybrany],1);
                    }
                    else if( gracze[aktualny_gracz].kamienie[wybrany].wartosc_1==ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1].wartosc_2)
                    {
                        dodaj_do_ciagu(ciag_kamieni,gracze[aktualny_gracz].kamienie[wybrany],1);
                    }
                }
            }
            //tutaj. są to rozne sytuacje w ktorych numery klockowmusialyby zostac "zamienione, oraz sprawdzenia do ktorego konca dany klocek moze pasowac"
            else if( gracze[aktualny_gracz].kamienie[wybrany].wartosc_1==ciag_kamieni.kamienie[0].wartosc_1)
            {
                zamien_wartosci(gracze[aktualny_gracz].kamienie[wybrany]);
                dodaj_do_ciagu(ciag_kamieni,gracze[aktualny_gracz].kamienie[wybrany],0);
            }
            else if( gracze[aktualny_gracz].kamienie[wybrany].wartosc_2==ciag_kamieni.kamienie[0].wartosc_1)
            {
                dodaj_do_ciagu(ciag_kamieni,gracze[aktualny_gracz].kamienie[wybrany],0);
            }
            else if( gracze[aktualny_gracz].kamienie[wybrany].wartosc_2==ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1].wartosc_2)
            {
                zamien_wartosci(gracze[aktualny_gracz].kamienie[wybrany]);
                dodaj_do_ciagu(ciag_kamieni,gracze[aktualny_gracz].kamienie[wybrany],1);
            }
            else if( gracze[aktualny_gracz].kamienie[wybrany].wartosc_1==ciag_kamieni.kamienie[ciag_kamieni.ilosc_kamieni-1].wartosc_2)
            {
                dodaj_do_ciagu(ciag_kamieni,gracze[aktualny_gracz].kamienie[wybrany],1);
            }
            usun_kamien_gracza(gracze[aktualny_gracz],wybrany);
            //warunek zakonczenia gry
            if(gracze[aktualny_gracz].ilosc_kamieni ==0 || zamkniecie_gry)
            {
                system("cls");
                for(int i=0;i<i_graczy;i++)cout <<"Gracz nr."<<i+1<<": "<<gracze[i].ilosc_kamieni<<" kamieni | ";
                cout<<endl;
                rysuj_ciag(ciag_kamieni.kamienie, ciag_kamieni.ilosc_kamieni);
                cout <<endl << "Wygral gracz nr "<<aktualny_gracz+1<<endl;
                if(gracze[aktualny_gracz].ilosc_kamieni ==0)cout << "Pozbyl sie wszystkich swoich kamieni."<<endl;
                if(zamkniecie_gry)cout << "Zamknal gre."<<endl;
                system("pause");
                break;
            }
            komputer_dobral_kosci = false;
            aktualny_gracz++;
            if(aktualny_gracz>=i_graczy)aktualny_gracz=0;
        }
        else if(niemozliwe_losowania>=i_graczy)
        {
            system("cls");
            cout <<"zaden z graczy nie moze wylozyc swoich kamieni. Nastapi podliczenie oczek z posiadanych kamieni: "<<endl;
            liczenie_oczek(gracze, i_graczy);
            system("pause");
            break;
        }
    }
}
void wybor_graczy()
{
    system("cls");
    //i_graczy - Zmienna odpowiadaj¹ca iloœci graczy. Pocz¹tkowa wartoœæ 2 ¿eby nie wyœwietli³ siê komunikat o b³êdnej iloœci graczy.
    int i_graczy = 2;
    //i_graczy_komputerowych - Zmienna odpowiadaj¹ca iloœci graczy komputerowych. Pocz¹tkowa wartoœæ 2 ¿eby nie wyœwietli³ siê komunikat o b³êdnej iloœci graczy komputerowych.
    int i_graczy_komputerowych=1;
    bool petla = true;
    while(true)
    {
        cout << "Podaj ilu ma byc graczy? <2;4>: ";
        cin >> i_graczy;
        system("cls");
        if(i_graczy <2 || i_graczy>4)cout <<"Bledna ilosc graczy!";
        else break;
    }
    //poni¿szy warunek w ramach tego, ¿e zawsze musi byæ przynajmniej jeden gracz komputerowy.
    if(i_graczy !=2)
    {
        while(true)
        {
            cout << "Podaj ilu ma byc graczy_komputerowych? <1;"<<i_graczy-1<<">: ";
            cin >> i_graczy_komputerowych;
            system("cls");
            if(i_graczy_komputerowych <1 || i_graczy_komputerowych>i_graczy-1)cout <<"Bledna ilosc graczy komputerowych!";
            else break;
        }
    }
    inicjacja(i_graczy, i_graczy_komputerowych);

}
void menu_glowne()
{
    system("cls");
    //opcja - Zmienna zawieraj¹ca numer opcji, któr¹ chcemy wybraæ. Pocz¹tkowo jest równa 1 (jedna z mo¿liwoœci) aby nie wyœwietli³ siê komunikat o b³êdnej opcji.
    char opcja='1';
    //petla - Zmienna decyduj¹ca o trwaniu pêtli.
    bool petla = true;
    while(petla)
    {
        system("cls");
        cout << "1) Zagraj w Domino"<<endl;
        cout << "2) Wyjdz" <<endl<<endl;
        if(opcja != '1' && opcja !='2')cout << "Wybrano nie wlasciwa opcje! ";
        cout << "Wybierz opcje: ";
        cin>>opcja;
        if(opcja == '1') wybor_graczy();
        else if(opcja == '2') petla = false;
    }
}
int main()
{
    srand(time(NULL));
    menu_glowne();
    return 0;
}
