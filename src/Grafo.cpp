#include "Grafo.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>

void Grafo::agregarPalabra(const std::string& palabra) {
    for (const auto& entrada : adyacencias) {
        if (esAdyacente(entrada.first, palabra)) {
            adyacencias[entrada.first].insert(palabra);
            adyacencias[palabra].insert(entrada.first);
        }
    }
    adyacencias[palabra];
}

bool Grafo::esAdyacente(const std::string& palabra1, const std::string& palabra2) const {
    if (palabra1.size() != palabra2.size()) return false;
    int diferencia = 0;
    for (size_t i = 0; i < palabra1.size(); ++i) {
        if (palabra1[i] != palabra2[i]) {
            ++diferencia;
            if (diferencia > 1) return false;
        }
    }
    return diferencia == 1;
}

std::vector<std::string> Grafo::obtenerPosiblesPalabras(const std::string& letras) const {
    std::vector<std::string> resultado;
    for (const auto& palabra : adyacencias) {
        if (contieneTodasLetras(palabra.first, letras)) {
            resultado.push_back(palabra.first);
        }
    }
    return resultado;
}

bool Grafo::contieneTodasLetras(const std::string& palabra, const std::string& letras) const {
    std::multiset<char> letrasSet(letras.begin(), letras.end());
    int comodines = letrasSet.count('?');

    for (char c : palabra) {
        auto it = letrasSet.find(c);
        if (it != letrasSet.end()) {
            letrasSet.erase(it);
        } else if (comodines > 0) {
            --comodines;
        } else {
            return false;
        }
    }
    return true;
}
