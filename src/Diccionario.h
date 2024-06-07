#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <string>
#include <set>
#include <vector>

class Diccionario {
private:
    std::set<std::string> palabras;

public:
    bool cargarDesdeArchivoInverso(const std::string& nombreArchivo);
    bool cargarDesdeArchivo(const std::string& nombreArchivo);
    bool palabraExiste(const std::string& palabra) const;
    std::vector<std::string> obtenerPalabras() const;
};

#endif
