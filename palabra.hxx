#include "Palabra.h"
#include <algorithm>

Palabra::Palabra(const std::string& texto) : texto(texto) {}



bool Palabra::esValida(const Diccionario& diccionario) const {
    
    return diccionario.palabraExiste(texto);
}

int Palabra::calcularPuntaje() const {
    static const std::unordered_map<char, int> puntajes = {
        {'a', 1}, {'b', 3}, {'c', 3}, {'d', 2}, {'e', 1},
        {'f', 4}, {'g', 2}, {'h', 4}, {'i', 1}, {'j', 8},
        {'k', 5}, {'l', 1}, {'m', 3}, {'n', 1}, {'o', 1},
        {'p', 3}, {'q', 10}, {'r', 1}, {'s', 1}, {'t', 1},
        {'u', 1}, {'v', 4}, {'w', 4}, {'x', 8}, {'y', 4}, {'z', 10}
    };
    int puntaje = 0;
    for (char c : texto) {
        puntaje += puntajes.at(c); 
    }
    return puntaje;
}

