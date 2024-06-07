#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>

class Grafo {
public:
    void agregarPalabra(const std::string& palabra);
    std::vector<std::string> obtenerPosiblesPalabras(const std::string& letras) const;
    bool esAdyacente(const std::string& palabra1, const std::string& palabra2) const;

private:
    std::unordered_map<std::string, std::unordered_set<std::string>> adyacencias;
    bool contieneTodasLetras(const std::string& palabra, const std::string& letras) const;
};

#endif // GRAFO_H
