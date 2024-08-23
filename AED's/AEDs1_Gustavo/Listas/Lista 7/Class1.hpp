#include <iostream>

using namespace std;


class Data
{
protected:
    int dia;
    int mes;
    int ano;

public:
    Data(void) {     //Q1.1
        dia = 01;
        mes = 01;
        ano = 0001;
    }

    Data(int dia, int mes, int ano){ //Q1.2
        this->dia=dia;
        this->mes=mes;
        this->ano=ano;
    }

    int getDia(){  //Q1.3
        return (dia);
    }

     int getMes(){  //Q1.3
        return (mes);
    }

    int getAno(){  //Q1.3
        return (ano);
    }

    void somarDias(int dia){  //Q1.4
        this->dia = this->dia+dia;
    }

    Data operator+(int dia){  //Q1.5
        this->dia = this->dia + dia;
    }

         friend std::ostream& operator<<(std::ostream& os, const Data& data) {  //Q1.6
        os << data.dia << '/' << data.mes << '/' << data.ano;
        return os;
    }


    void diferencaDias(Data b){  //Q1.7
        this->dia = this->dia - b.dia;
    }

    Data operator-(int dia){   //Q1.8
        this->dia = this->dia-dia;
    }
};