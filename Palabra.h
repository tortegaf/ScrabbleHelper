#ifndef PALABRA_H
#define PALABRA_H

#include <string>
#include "Diccionario.h"

class Palabra {
private:
    std::string texto;

public:
    Palabra(const std::string& texto);
    bool esValida(const Diccionario& diccionario) const;
    int calcularPuntaje() const;
};

#endif
