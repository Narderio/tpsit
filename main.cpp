#include <iostream>
#include <fstream>
#define DIM 200



using namespace std;

 /*! \mainpage <CENTER> Gestione di una rubrica </CENTER>
    * \author <B> Narderio</B>
    * \version <B> V1.0 </B>
    * \date <B> Consegna progetto:   ti voglio bene 3000 </B>
    *
    * \section caratteristiche CARATTERISTICHE DEL PROGETTO
    *
    *  Il software permette di:
    * - prendere da input i contatti e inserirli in un file
    * - genera un file di testo denominato rubrica.dat
    * - leggere i contatti memorizzati nel file
    * - ricercare un contatto attraverso il codice
    * - modificare un contatto
    *
    *\section UML DIAGRAMMA UML DEL PROGETTO
    * <IMG SRC = "uml.jpg" ALT = "Diagramma UML del progetto"/>
    *
    *\section CLASS DIAGRAMMA DELLE CLASSI PRESENTI NEL PROGETTO
    *<IMG SRC = "classi.jpg" ALT = "Diagramma delle classi del progetto"/>
    */























const string DATABASE= "rubrica.dat";
int n=0;

struct Rubrica
{
    char nome[20];
    char cognome[20];
    int numero;
    int codice;
}contatti[DIM],lettur;



//! \class [FUNZIONI]

//! \relates FUNZIONI

/*! \fn input()
    \brief permette di inserire un contatto da input e lo scrive nel file
*/

void input()
{int a;

    fstream miofile;
    miofile.open(DATABASE, ios::app | ios::binary);

    do{
        fflush(stdin);

        cout<<"Inserisci il codice del contatto:";
        cin>> contatti[n].codice;

        fflush(stdin);
        cout << "Inserisci il nome del contatto:";
        cin.getline(contatti[n].nome,20);

       fflush(stdin);
       cout << "Inserisci il cognome del contatto:";
       cin.getline(contatti[n].cognome,20);

       fflush(stdin);
       cout << "Inserisci il numero del contatto:";
       cin>>contatti[n].numero;


       n++;

       if(n!=DIM)
        {
            cout<<"Premere 1 per inserire il prossimo contatto, altrimenti 0: ";
            cin>>a;
        }
        else
            a=0;

    }while(a==1);

    if(!miofile)
        cout<<"Errore apertura file!"<<endl;

    else
    {
        for(int c=0;c<n;c++)
            miofile.write((char*)&contatti,sizeof(contatti));
    }

miofile.close();

}


//! \relates FUNZIONI
/*! \fn lettura()
    \brief legge i contatti memorizzati
*/

void lettura()
{
    string stringa;
int a=0;

    fstream miofile;
    miofile.open(DATABASE, ios::in  | ios::binary);
    if(!miofile)
        cout<<"Errore nell'apertura del file"<<endl;
    else
    {
     cout<<"\t\t\tSTAMPA DI TUTTI I CONTATTI"<<endl;
        while(miofile.read((char*)&lettur,sizeof(lettur)))
        {
            if(lettur.nome[0]=='\0')
                break;

            cout<<"Nome:"<<lettur.nome<<endl<<"Cognome: "<<lettur.cognome<<endl
            <<"Numero: "<<lettur.numero<<endl<<"Codice: "<<lettur.codice<<endl<<endl<<endl;

        }

    }
    miofile.close();
    fflush(stdin);
}



//! \relates FUNZIONI
/*! \fn ricerca()
    \brief ricerca un contatto con possibilità di modificarlo
*/

void ricerca()
{
    int cod;long cont;int scelta;
    Rubrica rice;
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

        cout<<"Nome:"<<rice.nome<<endl<<"Cognome:"<<rice.cognome<<endl<<"Numero:"
        <<rice.numero<<endl<<endl;

        cout<<"\n\n Vuoi modificare il record?(0=no/1=si)"<<endl;
        cin>>scelta;

        if(scelta==1)
            {
                cout<<"1.Nome \n2.Cognome \n3.Numero \n4.Codice"<<endl;
                cin>>scelta;

                switch(scelta)
                {
                    case 1: cout<<"Inserisci il nome modificato:";
                            fflush(stdin);
                            cin.getline(rice.nome,20);
                                break;

                    case 2:cout<<"Inserisci il cognome modificato:";
                            fflush(stdin);
                            cin.getline(rice.cognome,20);
                                break;

                    case 3:cout<<"Inserisci il numero modificato:";
                            fflush(stdin);
                            cin>>rice.numero;
                                break;

                    case 4:cout<<"Inserisci il codice modificato:";
                            fflush(stdin);
                            cin>>rice.codice;
                                break;

                }
                 miofile.seekp(cont);
            miofile.write((char*)&rice, sizeof(rice));

            }
    }
miofile.close();
}




int main()
{
    //! \brief main nel quale tutto accade

    int scelta;
Rubrica contatti[DIM];

    do{
    cout << "1.Inserisci contatti" << endl;
    cout << "2.Leggi" << endl;
    cout << "3.Ricerca"<<endl;
    cout << "4.Esci" << endl;
    cin>>scelta;

    switch(scelta)
    {
        case 1:input();
                    break;

        case 2: lettura();
                    break;

        case 3: ricerca();
                    break;

        case 4:cout << "Grazie di aver utilizzato questo programma!" << endl;
                break;
    }

    }while(scelta!=4);
    return 0;
}

