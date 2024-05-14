#include <iostream>
#include <cstdint>
using namespace std;

//Estructura Flotante para trabajar con bits
struct Float {
    uint32_t sign;
    uint32_t exponent;
    uint32_t significand;
};

//Function de para multiplicar flotantes
Float multiplyFloats(Float a, Float b) {

    if (a.significand == 0 || b.significand == 0) {
        Float result = {0, 0, 0};
        return result;
    }

    int32_t Suma_exponentes = (int32_t)a.exponent - 127 + (int32_t)b.exponent - 127;
    int32_t Resultado_exponentes = 127 + Suma_exponentes;

    uint64_t Resultado_Significando = (uint64_t)a.significand * (uint64_t)b.significand;

    while ((Resultado_Significando >> 23) == 0) {
        Resultado_Significando <<= 1;
        Resultado_exponentes--;
    }

    if (Resultado_exponentes > 255) {
        cout << "Resultado: Overflow" << endl;
        Resultado_exponentes = 255;
        Resultado_Significando = (1ULL << 23) - 1;
    } else if (Resultado_exponentes < 0) {
        cout << "Resultado: Underflow" << endl;
        Resultado_exponentes = 0;
        Resultado_Significando = 0;
    }

    Float result{};
    result.sign = 0;
    result.exponent = static_cast<uint32_t>(Resultado_exponentes);
    result.significand = static_cast<uint32_t>(Resultado_Significando & 0x7FFFFF);
    return result;
}

int main() {
    float Numero_1, Numero_2;

    cout << "ingrese el primer valor en punto flotante: ";
    cin >> Numero_1;
    cout << "ingrese el segundo valor en punto flotante: ";
    cin >> Numero_2;

    Float Flotante_1 = {0, 127, *reinterpret_cast<uint32_t*>(&Numero_1)};
    Float Flotante_2 = {0, 127, *reinterpret_cast<uint32_t*>(&Numero_2)};

    Float resultado = multiplyFloats(Flotante_1, Flotante_2);

    cout << "resultado de la multiplication: " << endl;
    cout << "signo: " << resultado.sign << endl;
    cout << "exponente: " << resultado.exponent << endl;
    cout << "significando: " << resultado.significand << endl;

    float Resultado_Normal = Numero_1 * Numero_2;
    cout << "resultado nativo: " << Resultado_Normal << endl;

    return 0;
}