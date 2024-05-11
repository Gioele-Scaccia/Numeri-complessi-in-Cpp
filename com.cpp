#include <iostream>
using namespace std;

struct complesso{
    float num;
    bool complesso;
    int posizione = 99;
};

bool complesso_o_no()
{
    int a;
    do{
    cout << "Se il numero inserito e' complesso scrivere '1', senno scrivere '2'\n>";
    cin >> a;
    }while(a < 1 || a > 2);
    switch (a) {
        case 1:
            return true;
            break;
        case 2:
            return false;
            break;
    }
}

string piuMeno(float n)
{
    if(n < 0)
    {
        return "";
    }
    return "+";
}

int main() {
    int scelta,n;
    do {
    cout << "1 - Somma\n2 - Moltiplicazione\n3 - Divisione\n>";
    cin >> scelta;
    }while(scelta < 1 || scelta > 4);
    switch(scelta) {
        case 1: { // somma
            do{
            cout << "Quanti numeri?\n>";
            cin >> n;
            }while(n<2);
            complesso somma[n];
            for (int i=0;i<n;i++)
            {
                cout << "Inserisci un numero\n>";
                cin >> somma[i].num;
                somma[i].complesso = complesso_o_no();
            }
            for (int i=1;i<n;i++)
            {
                if (somma[i].complesso == somma[i-1].complesso)
                {
                    somma[i].num = somma[i].num + somma[i-1].num;
                    if (somma[i-1].posizione != 99)
                    {
                        somma[i].posizione = somma[i-1].posizione;
                    }
                }
                else
                {
                    somma[i].posizione = i-1;
                    if (somma[i-1].posizione != 99)
                    {
                        somma[i].num = somma[i].num + somma[somma[i-1].posizione].num;
                    }
                }
            }
            n=n-1;
            if (somma[n].complesso == true)
            {
                cout << "Parte immaginaria : " << somma[n].num << "\n";
                if (somma[n].complesso != somma[n-1].complesso) cout << "\nParte reale : " << somma[n-1].num;
            }
            else
            {
                cout << "Parte reale : " << somma[n].num;
                if (somma[n-1].complesso != somma[n].complesso) cout << "\nParte immaginaria : " << somma[n-1].num;
            }
            }break;
        case 2: {
            bool siono = false;
            int n,m;
            do{
            cout << "Quanti numeri saranno nella prima parentesi?\n>";
            cin >> n;
            }while(n<1);
            complesso prima[n];
            for (int i=0;i<n;i++)
            {
                cout << "Inserisci un numero\n>";
                cin >> prima[i].num;
                prima[i].complesso = complesso_o_no();
            }
            do{
            cout << "Quanti numeri saranno nella seconda parentesi?\n>";
            cin >> m;
            }while(m<1);
            complesso seconda[m];
            for (int i=0;i<m;i++)
            {
                cout << "Inserisci un numero\n>";
                cin >> seconda[i].num;
                seconda[i].complesso = complesso_o_no();
            }
            cout << "( ";
            for (int i=0;i<n;i++)
            {
                cout << piuMeno(prima[i].num) << prima[i].num;
                if (prima[i].complesso == true)
                {
                    cout << "J";
                }
                //cout << " ";
            }
            cout << " ) * ( ";
            for (int i=0;i<m;i++)
            {
                cout << piuMeno(seconda[i].num) << seconda[i].num;
                if (seconda[i].complesso == true)
                {
                    cout << "J";
                }
                //cout << " ";
            }
            cout << " ) = ";
            complesso risultato[m*n];
            for (int i=0;i<m;i++)
            {
                for (int j=0;j<n;j++)
                {
                    risultato[i*n+j].num=prima[j].num * seconda[i].num;
                    if (prima[j].complesso == 1 && seconda[i].complesso == 1)
                    {
                    risultato[i*n+j].num=risultato[i*n+j].num * -1;
                    risultato[i*n+j].complesso = false;
                    }
                    else if (prima[j].complesso == true && seconda[i].complesso == false || prima[j].complesso == false && seconda[i].complesso == true)
                    {
                        risultato[i*n+j].complesso=true;
                    }
                    else 
                    {
                        risultato[i*n+j].complesso = false;
                    }
                    /*
                    cout << "\n" << prima[j].num << " (" << prima[j].complesso << ") "<< " * " << seconda[i].num << " (" << seconda[i].complesso << ") " " = ";
                    cout << risultato[i*n+j].num;
                    if (risultato[i*n+j].complesso == true)
                    {cout << "Complesso";
                    cout << risultato[i*n+j].complesso;
                    }
                    if (risultato[i*n+j].complesso == false)
                    {cout << "Reale";
                    cout << risultato[i*n+j].complesso;
                    }
                    */
                    
                }
            }
            for (int i=1;i<n*m;i++)
            {
                if (risultato[i].complesso == risultato[i-1].complesso)
                {
                    risultato[i].num = risultato[i].num + risultato[i-1].num;
                    if (risultato[i-1].posizione != 99)
                    {
                        risultato[i].posizione = risultato[i-1].posizione;
                    }
                }
                else
                {
                    risultato[i].posizione = i-1;
                    if (risultato[i-1].posizione != 99)
                    {
                        risultato[i].num = risultato[i].num + risultato[risultato[i-1].posizione].num;
                    }
                }
            }
            


            n=n*m-1;
            cout << piuMeno(risultato[n].num) << risultato[n].num;
            if (risultato[n].complesso == true)
            {
                cout <<"J";
            }
            if (risultato[n].complesso != risultato[n-1].complesso)
            {
                cout << piuMeno(risultato[n-1].num) << risultato[n-1].num;
                if (risultato[n-1].complesso == true)
                {
                cout <<"J";
                }
            }
            else
            {
                if (risultato[risultato[n].posizione].complesso != risultato[n].complesso && risultato[risultato[n].posizione].complesso != risultato[n-1].complesso)
                {
                cout << piuMeno(risultato[risultato[n].posizione].num) << risultato[risultato[n].posizione].num;
                if (risultato[risultato[n].posizione].complesso == true)
                {
                cout <<"J";
                }
                }
            }


        }break;
        case 3: {
            float salva;
            complesso dividendo[2];
            complesso divisore[2];
            cout << "Parte immaginaria del dividendo:\n>";
            cin >> dividendo[0].num;
            dividendo[0].complesso = true;
            cout << "Parte reale del dividendo:\n>";
            cin >> dividendo[1].num;
            dividendo[1].complesso = false;
            cout << "Parte immaginaria del divisore:\n>";
            cin >> divisore[0].num;
            divisore[0].complesso = true;
            do{
            cout << "Parte reale del divisore:\n>";
            cin >> divisore[1].num;
            }while(divisore[1].num == 0);
            divisore[1].complesso = false;
            cout << "(" << piuMeno(dividendo[0].num) << dividendo[0].num << "J" << piuMeno(dividendo[1].num) << dividendo[1].num << ") / (" << piuMeno(divisore[0].num);
            cout << divisore[0].num << "J" << piuMeno(divisore[1].num) << divisore[1].num << ") = ";
            if (divisore[0].num == 0)
            {
                dividendo[0].num = dividendo[0].num / divisore[1].num;
                dividendo[1].num = dividendo[1].num / divisore[1].num;
                cout << "Parte immaginaria: " << dividendo[0].num;
                cout << "\nParte reale: " << dividendo[1].num;
            }
            else
            {
                salva=dividendo[0].num; // ho bisogno di una variabile di comodo perche' dopo tutti e 4 vengono usati
                cout << (dividendo[0].num * divisore[1].num) + (dividendo[1].num * divisore[0].num * -1) << "\n";
                dividendo[0].num = (dividendo[0].num * divisore[1].num) + (dividendo[1].num * divisore[0].num * -1);
                // * -1 perche' si moltiplica il dividendo per il divisore con la parte immaginaria negata, con questo abbiamo trovato la parte immaginaria del dividendo
                dividendo[1].num = (salva * divisore[0].num) + (dividendo[1].num * divisore[1].num); // qua vengono usati, con questo troviamo la parte reale del dividendo
                /*
                cout << "\n A"<< dividendo[0].num;
                cout << "\n B"<< dividendo[1].num;
                cout << "\n F"<< salva*divisore[0].num;
                */
                divisore[0].num = (divisore[0].num * divisore[0].num) + (divisore[1].num * divisore[1].num);
                //dopo si deve elevare alla seconda il divisore, facendo diventare la parte immaginaria in reale
                dividendo[0].num = dividendo[0].num / divisore[0].num; // parte immaginaria finale
                dividendo[1].num = dividendo[1].num / divisore[0].num; // parte reale finale
                //cout << "Parte immaginaria: " << dividendo[0].num;
                //cout << "\nParte reale: " << dividendo[1].num;
                cout << dividendo[1].num << piuMeno(dividendo[0].num)<< dividendo[0].num << "J";
            }
            
        }break;
    }
}