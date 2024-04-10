#include <iostream>
#include <string>
#include <bitset>
using namespace std;

//Booth algorithm (diseñado por el Arleondo2 aka Arnol )
int Multiplicar(int multiplicando, int multiplicador , int bits) {
    int resultado, B_Multiplier ;
    int multiplicandoAbs = abs(multiplicando);
    int multiplicadorAbs = abs(multiplicador);
    int producto = 0;

    //para numeros de 32 y 64 bits funciona sin errores (falta testear 128)
    for (int i = 0; i < bits; i++) {
        B_Multiplier = multiplicadorAbs & 1;
        if (B_Multiplier == 1) {
            producto = producto + multiplicandoAbs;
        }
        multiplicandoAbs <<= 1;
        multiplicadorAbs >>= 1;
    }

    if ((multiplicando < 0) ^ (multiplicador < 0)) {
        resultado = -producto;
    }
    else {
        resultado = producto;
    }

    return resultado;
}

//Convertores a binario
string Conv_Binario_16(int n ){
    return bitset<16>(n).to_string();
}
string Conv_Binario_32(int n ) {
    return bitset<32>(n).to_string();
}
string Conv_Binario_64(int n ) {
    return bitset<64>(n).to_string();
}


int main() {
    string check;
    while (check!="N") {
        int Number1, Number2 , cant_bit;
        cout<<"Ingresar cantidad de bits (16,32,64):";
        cin>>cant_bit;

        cout << "Ingrese el primer numero (decimal):";
        cin >> Number1;

        cout << "Ingrese el segundo numero (decimal):";
        cin >> Number2;

        int product = Multiplicar(Number1, Number2, cant_bit);

        cout << "Resultado de la multiplication:" << product << endl;
        if (cant_bit==16){
            cout << "Resultado en binario:" << Conv_Binario_16(product) << endl;
        }
        else if (cant_bit==32){
            cout << "Resultado en binario:" << Conv_Binario_32(product) << endl;
        }
        else if (cant_bit==64){
            cout << "Resultado en binario:" << Conv_Binario_64(product) << endl;
        }
        else {
            cout<<"Implementacion faltante de valores +64 bits"<< endl;
        }

        cout<<"Desea continuar ??, Y para si , N para no:\t";
        cin>>check;
    }
}
//Va a dar error solo en el caso que cuando pida los numeros le pases cualquier cosa que no sean numeros
