#include <iostream>
#include <fstream>
#define DIM 20


using namespace std;
const string DATABASE= "serie_a.dat";int n=0;

struct Squadra
{
    char nome[20];
    int punti;
    char capocannoniere[20];
    int gol;
    int codice;
}squadre[DIM],lettur;




void input()
{int a;

    fstream miofile;
    miofile.open(DATABASE, ios::app | ios::binary);//apro il file

    do{
        fflush(stdin);//pulisco ram
        cout<<"Inserisci il codice della squadra:";
        cin>> squadre[n].codice;
        fflush(stdin);
        cout << "Inserisci squadra:";
       cin.getline(squadre[n].nome,20);//inserimento nome squadra
       cout << "Inserisci punti:";
       cin>>squadre[n].punti;//inserimento punti squadra
       fflush(stdin);//pulisco nuovamente ram
       cout << "Inserisci capocannoniere:";
       cin.getline(squadre[n].capocannoniere,20);//inserimento nome capocannoniere squadra
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
{ Squadra temp;

     for(int j=0; j<=n; j++)
         for(int k=j+1 ; k<n; k++)
            if(squadre[j].punti<squadre[k].punti)
            {
                temp= squadre[j];
                squadre[j]=squadre[k];
                squadre[k]=temp;
            }
cout<<"\t\t CLASSIFICA SERIE A"<<endl;

                for(int a=0;a<n;a++)
                    {
                        cout<<squadre[a].punti<<"   ";
                        cout<<squadre[a].nome<<endl;
                    }
}

void capocannonieri()
{ Squadra temp;

     for(int j=0; j<=n; j++)
         for(int k=j+1 ; k<n; k++)
            if(squadre[j].gol<squadre[k].gol)
            {
                temp=squadre[j];
                squadre[j]=squadre[k];
                squadre[k]=temp;
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
    miofile.open(DATABASE, ios::in  | ios::binary);
    if(!miofile)
        cout<<"Errore nell'apertura del file"<<endl;
    else
    {
     cout<<"\t\t\tSTAMPA DI TUTTE LE SQUADRE"<<endl;
        while(miofile.read((char*)&lettur,sizeof(lettur)))
        {
            if(lettur.nome[0]=='\0')
                break;

            cout<<"Nome:"<<lettur.nome<<endl<<"Punti: "<<lettur.punti<<endl
            <<"Capocannoniere: "<<lettur.capocannoniere<<endl<<"Gol: "<<lettur.gol<<endl;

        }

    }
    miofile.close();
    fflush(stdin);
}

void ricerca()
{
    int cod;long cont;int scelta;
    Squadra rice;
    fstream miofile;
    miofile.open(DATABASE,ios::in | ios::out | ios::binary);
    if(!miofile)
        cout<<"Errore nell'apertura del file"<<endl;

    else{
        cout<<"Inserisci il codice da cercare:";
        cin>>cod;

        cont=(cod-1)*(sizeof(rice));
        miofile.seekg(cont);
        miofile.read((char*)&rice,sizeof(rice));

        cout<<"Nome:"<<rice.nome<<endl<<"Punti:"<<rice.punti<<endl<<"Capocannoniere:"
        <<rice.capocannoniere<<endl<<"Gol:"<<rice.gol<<endl<<endl;

        cout<<"\n\n Vuoi modificare il record?(0=no/1=si)"<<endl;
        cin>>scelta;
        if(scelta==1)
            {
                cout<<"1.Nome \n2.Punti \n3.Capocannoniere \n4.Goal del capocannoniere"<<endl;
                cin>>scelta;
                switch(scelta)
                {
                    case 1: cout<<"Inserisci il nome modificato:";
                            fflush(stdin);
                            cin.getline(rice.nome,20);
                                break;

                    case 2:cout<<"Inserisci i punti modificati:";
                            fflush(stdin);
                            cin>>rice.punti;
                                break;

                    case 3:cout<<"Inserisci il nome del capocannoniere modificato:";
                            fflush(stdin);
                            cin.getline(rice.capocannoniere,20);
                                break;

                    case 4:cout<<"Inserisci il nome modificato:";
                            fflush(stdin);
                            cin>>rice.gol;
                                break;

                }
                 miofile.seekp(cont);
            miofile.write((char*)&rice, sizeof(rice));

            }

            else
            {
                 miofile.seekp(cont);
            miofile.write((char*)&rice, sizeof(rice));
                cout<<"vuoi eliminare una squadra?(0=no/1=si)"<<endl;
                cin>>scelta;
                rice.nome[0]='\0';
            }
    }
miofile.close();
}


int main()
{int scelta;

    do{
    cout << "1.Inserisci squadra" << endl;
    cout << "2.Classifica squadre" << endl;
    cout << "3.Classifica marcatori" << endl;
    cout << "4.Leggi" << endl;
    cout << "5.Ricerca"<<endl;
    cout << "6.Esci" << endl;
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

        case 5: ricerca();
                    break;

        case 6:cout << "Grazie di aver utilizzato questo programma!" << endl;
                break;
    }

    }while(scelta!=6);
    return 0;
}

