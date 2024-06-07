#include "Diccionario.h"
#include <fstream>
#include <cctype>
#include <algorithm>
#include <iostream>

bool Diccionario::cargarDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::string linea;
    if (!archivo.is_open()) return false;
    palabras.clear();
    while (getline(archivo, linea)) {
        linea.erase(std::remove_if(linea.begin(), linea.end(), [](char c) { return !isalpha(c); }), linea.end());
        if (!linea.empty()) {
            std::transform(linea.begin(), linea.end(), linea.begin(), ::tolower);
            palabras.insert(linea);
        }
    }
    archivo.close();
    return true;
}

bool Diccionario::cargarDesdeArchivoInverso(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::string linea;
    if (!archivo.is_open()) return false;
    palabras.clear();
    while (getline(archivo, linea)) {
        linea.erase(std::remove_if(linea.begin(), linea.end(), [](char c) { return !isalpha(c); }), linea.end());
        std::transform(linea.begin(), linea.end(), linea.begin(), ::tolower);
        std::reverse(linea.begin(), linea.end());
        palabras.insert(linea);
    }
    archivo.close();
    return true;
}

bool Diccionario::palabraExiste(const std::string& palabra) const {
    return palabras.find(palabra) != palabras.end();
}

std::vector<std::string> Diccionario::obtenerPalabras() const {
    return std::vector<std::string>(palabras.begin(), palabras.end());
}
