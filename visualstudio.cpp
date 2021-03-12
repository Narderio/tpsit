#include <iostream>
#include <fstream>
#define DIM 15

using namespace std;
const string DATABASE= "serie_a.dat";int n=0;

struct Squadra
{
    string nome;
    int punti;
    string capocannoniere;
    int gol;
}squadre[DIM];




void input()
{int a;

    fstream miofile;
    miofile.open(DATABASE.c_str(),ios::app | ios::binary);//apro il file

    do{
        fflush(stdin);//pulisco ram
        cout << "Inserisci squadra:";
       getline(cin,squadre[n].nome);//inserimento nome squadra
       cout << "Inserisci punti:";
       cin>>squadre[n].punti;//inserimento punti squadra
       fflush(stdin);//pulisco nuovamente ram
       cout << "Inserisci capocannoniere:";
       getline(cin,squadre[n].capocannoniere);//inserimento nome capocannoniere squadra
       cout << "Inserisci numero goal:";
       cin>>squadre[n].gol;//inserimento gol del capocannoniere squadra
       n++;//aumento il contatore delle squadre presenti nel database

   if(n!=DIM)//se il numero delle squadre è diverso dal numero massimo
    {
        cout<<"Premere 1 per inserire la prossima squadra, altrimenti 0: ";//chiede se inserire oppure no un'altra squadra
        cin>>a;
    }
    else//altrimenti
        a=0;//setta il valore di "a" a 0 per uscire dal ciclo

    }while(a==1);

    if(!miofile)//se il file non è stato aperto

       cout<<"Errore apertura file!"<<endl;//errore

    else//altrimenti inserisce nel file tutte le squadre presenti nel database
    {
        for(int c=0;c<n;c++)
            miofile.write((char*)&squadre,sizeof(squadre));
            //miofile<<"Squadra:"<<squadre[c].nome<<";"<<"Punti:"<<squadre[c].punti<<";"<<"Capocannoniere:"<<squadre[c].capocannoniere<<";"<<"Goal:"<<squadre[c].gol<<";"<<endl;
    }

miofile.close();//chiusura file

}

void classifica()
{string tempstring;int tempint;

     for(int j=0; j<=n; j++)
         for(int k=j+1 ; k<n; k++)
            if(squadre[j].punti<squadre[k].punti)
            {
                tempint=squadre[j].punti;
                squadre[j].punti=squadre[k].punti;
                squadre[k].punti=tempint;

                tempstring=squadre[j].nome;
                squadre[j].nome=squadre[k].nome;
                squadre[k].nome=tempstring;

                tempint=squadre[j].gol;
                squadre[j].gol=squadre[k].gol;
                squadre[k].gol=tempint;

                tempstring=squadre[j].capocannoniere;
                squadre[j].capocannoniere=squadre[k].capocannoniere;
                squadre[k].capocannoniere=tempstring;
            }
cout<<"\t\t CLASSIFICA SERIE A"<<endl;

                for(int a=0;a<n;a++)
                    {
                        cout<<squadre[a].punti<<"   ";
                        cout<<squadre[a].nome<<endl;
                    }
}

void capocannonieri()
{string tempstring;int tempint;

     for(int j=0; j<=n; j++)
         for(int k=j+1 ; k<n; k++)
            if(squadre[j].gol<squadre[k].gol)
            {
                tempint=squadre[j].punti;
                squadre[j].punti=squadre[k].punti;
                squadre[k].punti=tempint;

                tempstring=squadre[j].nome;
                squadre[j].nome=squadre[k].nome;
                squadre[k].nome=tempstring;

                tempint=squadre[j].gol;
                squadre[j].gol=squadre[k].gol;
                squadre[k].gol=tempint;

                tempstring=squadre[j].capocannoniere;
                squadre[j].capocannoniere=squadre[k].capocannoniere;
                squadre[k].capocannoniere=tempstring;
            }
cout<<"\t\t CLASSIFICA MARCATORI SERIE A"<<endl;
                for(int a=0;a<n;a++)
                    {
                        cout<<squadre[a].gol<<"   ";
                        cout<<squadre[a].capocannoniere<<"   ";
                        cout<<squadre[a].nome<<endl;
                    }

}

void lettura()
{string stringa;
int a=0;

    fstream miofile;
    miofile.open(DATABASE.c_str(),ios::in | ios::binary);
    if(!miofile)
        cout<<"Errore nell'apertura del file";
    else
    {
     cout<<"\t\t\tSTAMPA DI TUTTE LE SQUADRE"<<endl;
        while(miofile.read((char*)&squadre,sizeof(squadre)))
        {
            cout<<"Nome:"<<squadre[a].nome<<endl<<"Punti: "<<squadre[a].punti<<endl
            <<"Capocannoniere: "<<squadre[a].capocannoniere<<endl<<"Gol: "<<squadre[a].gol<<endl;
        a++;
        }

    }
    miofile.close();
    fflush(stdin);
}


int main()
{int scelta;

    do{
    cout << "1.Inserisci squadra" << endl;
    cout << "2.Classifica squadre" << endl;
    cout << "3.Classifica marcatori" << endl;
    cout << "4.Leggi" << endl;
    cout << "5.Esci" << endl;
    cin>>scelta;
    switch(scelta)
    {
        case 1:input();
                    break;

        case 2:classifica();
                    break;

        case 3:capocannonieri();
                break;

        case 4: lettura();
                    break;

        case 5:cout << "Grazie di aver utilizzato questo programma!" << endl;
                break;
    }

    }while(scelta!=5);
    return 0;
}
 <
