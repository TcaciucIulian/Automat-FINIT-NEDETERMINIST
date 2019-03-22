# Automat-Finit
Implementare automat finit nedeterminist

Realizator : Tcaciuc Iulian-Marius
Coordonator : -


Documentatie:
 
  IMPLEMENTARE AUTOMAT FINIT NEDETERMINIST - AFN
  
  Cerinta : Pentru un automat finit si un cuvant dat, sa se decida daca acel cuvant apartine sau nu limbajului recunoscut de automat
    
  Descriere implementare:     

*  Matrice tridimensionala unde :
   -> a[i][j][k]== k unde k=c-'a'+1 , cu c = litera din alfabet

* Am ales o implementare recursiva, deoarece nu mai trebuie sa tin minte toate starile. Prin aceasta implementare, daca nu s-a ajuns la un raspuns, pe o cale, se reintoarce si incearca alta cale si tot asa pana se termina caile. Daca ajunge la rezultat, vom afisa cuvantul "acceptat" si atribuim variabilei de oprire valoarea 1, ca sa nu mai continue.In main, verificam daca literele cuvantului apartin limbajului, iar daca apartin, apelam functia acceptare. Daca in functia acceptare, variabila de oprire ramane la fel, atunci cuvantul nu este acceptat. 


  Explicarea metodelor:
   
  1. Functie de creare a matricei tridimensionale corespunzatoare automatului . In aceasta functie citim caractersticile automatului dat si initializam matricea.

void creareGraf(int a[20][20][20],int stariFinale[100], AFN &afn, alfabet alf) unde:
 -> a[20][20][20] | matrice tridimensionala unde memoram starile si litera;
-> stariFinale[100]  | vector unde memoram starile finale
-> afn | variabile cu informatiile despre AFN;
-> alf | literele din alfabet (a1,a2..); 

 2. Functie in care vedem daca o stare este stare finala. Se face o cautare a unei informatii intr-un vector. 

int cautare(int stariFinale[100],AFN afn, int x) unde :
-> int x | starea pe care o cautam sa vedem daca este finala

 3. Functie pentru verificare acceptare a unui cuvant dat de la tastatura. 
 
void acceptareCuvant(int a[20][20][20],int stariFinale[100], AFN afn, alfabet alf, char cuv[100], int pozitie, int stare, int &ok,int nr)

-> cuv[100] | cuvantul pe care il verificam;
->pozitie | pozitia din cuvant;
->stare | starea din care pornim pe matrice;
-> ok | daca e acceptat, ca sa ne oprim
-> nr | lungimea cuvantului dat

 Aceasta functie este una recursiva care se opreste atunci cand am ajuns la finalul cuvantului. Parcurgem litera cu litera, si reapelam recursivitatea avand ca stare initiala, fosta stare finala. Daca nu am ajuns pe drumul corect, se incearca alt drum. 
 
 4. Int main ()
  
  In main se apeleaza functiile si se verifica daca un cuvant vid este acceptat sau nu.
  
 
 Exemplu date intrare fisier :
5 ( numarStari)  2 (caractereAlfabet)  1 (numar stari initiale)  2 (numar stari finale)
0 (stare Finala 1) | memorate in vectorul "stariFinale"
2 (stare Finala 2)  | memorate in vectorul "stariFInale"
a b (litere alfabet)
 0 1 a 
 0 3 b
 1 2 a
 1 4 b
 2 2 a
 2 2 b
 3 0 b
 4 0 a 
 4 2 a
 4 3 a
