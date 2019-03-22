#include <iostream>
#include <fstream>
#include <string.h>
// Matricea a este o matrice de tridimensionala;
// a[i][j][k]=k de la starea i la starea j se marge cu k-'a'+1; unde k este litera din alfabet
using namespace std;
struct AFN
{
    int numarInitiale;
    int  numarFinale;
    int  caractereAlfabet;
    int  numarStari;
};
// citim datele din fisier si consturim matricea de adiacenta pentru AFN;
void creareGraf(int a[20][20][20],int stariFinale[100],char vectorCaractere[100], AFN &afn)
{
    // citim datele din fisier;
    ifstream f("AFN.txt");
    f>>afn.numarStari;
    f>>afn.caractereAlfabet;
    f>>afn.numarInitiale;
    f>>afn.numarFinale;
    cout<<" numar stari totale "<<afn.numarStari<<endl;
    cout<<" caracater alfabet "<<afn.caractereAlfabet<<endl;
    cout<<" numar stari initiale "<<afn.numarInitiale<<endl;
    cout<<" numar stari finale "<<afn.numarFinale<<endl;
    int nr=0;
    while(nr<afn.numarFinale)
    {
        f>>stariFinale[nr];
        nr++;
    }
    int nr1=0;
    while(nr1<afn.caractereAlfabet)
    {
     f>>vectorCaractere[nr1];
     nr1++;
    }
    for(int i=0; i<nr; i++)
    {
        cout<<" Stare finala  "<<i<<" -> "<< stariFinale[i]<<endl;
    }
    // initializare matrice cu 0;
    for(int i=0; i<afn.numarStari; i++)
        for(int j=0; j<afn.numarStari; j++)
         for(int k=0;k<afn.caractereAlfabet;k++)
        {

            a[i][j][k]=0;
        }
    // citim starile si litera ;
    int x,y;
    while(f>>x && f>>y)
    {
        char c;
        f>>c;
   //     cout<<c<<" ";
        a[x][y][c-'a'+1]=c-'a'+1;
        cout<< x <<" "<<y<<" "<<c-'a'+1<<" "<< c<<endl;
    }
    //afisare matrice;
    for(int i=0; i<afn.numarStari; i++)
    {
        cout<<endl;
        for(int j=0; j<afn.numarStari; j++)
         {
           cout<<endl;
           for(int k=0;k<=afn.caractereAlfabet;k++)
                cout<<a[i][j][k]<<" ";
         }
    }
    cout<<endl;
}
// Cautare daca o stare este stare finala;
int cautare(int stariFinale[100],AFN afn, int x)
{
    for(int i=0; i<afn.numarFinale; i++)
        if(stariFinale[i]==x)
            return 1;
    return 0;
}
// Verificare acceptare cuvant
void acceptareCuvant(int a[20][20][20],int stariFinale[100], AFN afn, char cuv[100], int pozitie, int stare, int &ok,int nr)
{
    // conditie de oprire a recursivitatii;
    if(pozitie==nr)
    {
        if(cautare(stariFinale,afn,stare)==1)
        {
            cout<<" Acceptat "<<endl;
            ok=1;

        }
    }
    else // daca nu am ajuns la final parcurgem cu un for, si verificam , daca avem cu a/b sau a si b plecam la alta stare, daca nu se ajunge la final, se reintoarce prin recursivitatea pe alt drum;
    {
        // verificam daca se trece cu litera cuv[pozitie];
        for(int i=0; i<afn.numarStari && ok==0; i++)
            if(a[stare][i][cuv[pozitie]-'a'+1]==cuv[pozitie]-'a'+1)
            {
                cout<<"Stare initiala "<<stare<<" stare finala "<<i<<" pozitie pe cuvant "<<pozitie<<" "<<endl;
                // reapelam cu stare initiala noua == stare finala veche, adica cu i;
                acceptareCuvant(a,stariFinale,afn,cuv,pozitie+1,i,ok,nr);
                cout<< " Reintoarcere "<<endl;
            }
    }
}
int main()
{
    int a[20][20][20]; // matrice tridimensioanala in care memoram starile si litera cu care se trece
    int stariFinale[100]; // matrice unde avem starile finale;
    char vectorCaractere[100]; // vector caractere;
    AFN afn; // variabila unde avem informatiile afn-ului;
// alfabetul peste care lucram;
    creareGraf(a,stariFinale,vectorCaractere,afn); // apelam crearea matricei tridimensionale;
    char cuv[100]="bbb";
    int ok=0;
    int nr=strlen(cuv); // lungimea cuvantului;
    acceptareCuvant(a,stariFinale,afn,cuv,0,0,ok,nr);
    // daca ok ramane 0, inseamna ca pe orice drum am mers, nu am ajuns la rezultat, prin urmare cuvantul nu este acceptat;
    if(ok==0)
        cout<<" Neacceptat ";


    // verificare cuvant vid
    if(cautare(stariFinale,afn,0)==1) cout<< " Cuvantul vid este acceptat "<<endl;
       else cout<<" Cuvantul vid nu este acceptat ";
}
