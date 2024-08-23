#include <iostream>
#include <iomanip>
using namespace std;

class Hora
{

protected:
    int hora;
    int minuto;
    int segundo;

public:
    Hora()  // Q2.1
    { 
        hora = 00;
        minuto = 00;
        segundo = 00;
    }

    Hora(int hora, int minuto, int segundo)  // Q2.2
    {
        if (hora >= 0 && hora < 24)
        {
            this->hora = hora;
        }
        else
        {
            cout << "ERRO!: hora invalida";
        }

        if (minuto >= 0 && minuto < 60)
        {
            this->minuto = minuto;
        }
        else
        {
            cout << "ERRO!: minuto invalido";
        }

        if (segundo >= 0 && segundo < 24)
        {
            this->segundo = segundo;
        }
        else
        {
            cout << "ERRO!: segundo invalido";
        }
    }

    int getHora()  // Q2.3
    { 
        return (hora);
    }
    int getMinuto()
    {
        return (minuto);
    }
    int getSegundo()
    {
        return (segundo);
    }


     void acrescentarHorario(Hora horario){     //Q2.4
        this->hora = this->hora+horario.hora;
    }

    Hora operator+(Hora horario){     //Q2.5
        this->hora = this->hora + horario.hora;
    }

    Hora diferenca(Hora x){    //Q2.6
        Hora y;
        y.hora = this->hora - x.hora;
        y.minuto = this->minuto - x.minuto;
        y.segundo = this->segundo - x.segundo;

        return y;
    }

     Hora operator-(Hora x){   //Q2.7
        Hora y;
        y.hora = this->hora - x.hora;
        y.minuto = this->minuto - x.minuto;
        y.segundo = this->segundo - x.segundo;

        return y;

    }
    

      friend ostream& operator<<(ostream& os, const Hora& horario) {  //Q2.8
        os << setfill('0') << setw(2) << horario.hora << ":" << setw(2) << horario.minuto << ":" << setw(2) << horario.segundo;
        return os;
    } 

};