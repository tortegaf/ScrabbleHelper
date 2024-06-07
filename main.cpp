#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Diccionario.h"
#include "Palabra.h"
#include "Grafo.h"
#include "Trie.h"

using namespace std;

Diccionario diccionario;
bool diccionarioInicializado = false;
Diccionario diccionarioInverso;
bool diccionarioInversoInicializado = false;
Grafo grafo;
bool grafoInicializado = false;
Trie trieDiccionario;
bool trieDiccionarioInicializado = false;
Trie trieDiccionarioInverso;
bool trieDiccionarioInversoInicializado = false;

void imprimir();
void inicializar(const std::string& nombreArchivo);
void iniciarinverso(const std::string& nombreArchivo);
void puntaje_palabra(const std::string& palabra);
void iniciar_arbol(const std::string& nombreArchivo);
void iniciar_arbol_inverso(const std::string& nombreArchivo);
void palabras_por_prefijo(const std::string& prefijo);
void palabras_por_sufijo(const std::string& sufijo);
void grafo_de_palabras();
void posibles_palabras(const std::string& letras);

int main() {
    cout << "=======================================" << endl;
    cout << "\033[1;37m     Bienvenido a la Interfaz de:   \033[0m" << endl;
    cout << "=======================================" << endl;
    cout << "\033[1;37m                    _     _     _       \033[0m" << endl;
    cout << "\033[1;37m ___  ___ _ __ __ _| |__ | |__ | | ___  \033[0m" << endl;
    cout << "\033[1;37m/ __|/ __| '__/ _` | '_ \\| '_ \\| |/ _ \\ \033[0m" << endl;
    cout << "\033[1;37m\\__ \\ (__| | | (_| | |_) | |_) | |  __/ \033[0m" << endl;
    cout << "\033[1;37m|___/\\___|_|  \\__,_|_.__/|_.__/|_|\\___| \033[0m" << endl;
    cout << "\033[1;37m                                         \033[0m" << endl;
    cout << "\033[1;37m      _    _      _                    \033[0m" << endl;
    cout << "\033[1;37m     | |  | |    | |                   \033[0m" << endl;
    cout << "\033[1;37m     | |__| | ___| |_ __   ___ _ __    \033[0m" << endl;
    cout << "\033[1;37m     |  __  |/ _ \\ | '_ \\ / _ \\ '__|   \033[0m" << endl;
    cout << "\033[1;37m     | |  | |  __/ | |_) |  __/ |      \033[0m" << endl;
    cout << "\033[1;37m     |_|  |_|\\___|_| .__/ \\___|_|      \033[0m" << endl;
    cout << "\033[1;37m                   | |                 \033[0m" << endl;
    cout << "\033[1;37m                   |_|                 \033[0m" << endl;
    cout << "\033[1;37m                                         \033[0m" << endl;
    cout << "=======================================" << endl;





    bool r = true;
    while (r) {
        cout << "\n\033[1;34mIngrese un comando: \033[0m";
        string comandon;
        getline(cin, comandon);
        size_t pos = comandon.find(' ');
        string comando = comandon.substr(0, pos);
        string especifico = comandon.substr(pos + 1);

        if (comando == "inicializar") {
            inicializar(especifico);
        } 
        else if (comando == "iniciar_inverso") {
            iniciarinverso(especifico);
        } 
        else if (comando == "puntaje") {
            puntaje_palabra(especifico);
        } 
        else if (comando == "ayuda") {
            imprimir();
        } 
        else if (comando == "salir") {
            r = false;
        } 
        else if (comando == "iniciar_arbol") {
            iniciar_arbol(especifico);
        } 
        else if (comando == "iniciar_arbol_inverso") {
            iniciar_arbol_inverso(especifico);
        } 
        else if (comando == "palabras_por_prefijo") {
            palabras_por_prefijo(especifico);
        } 
        else if (comando == "palabras_por_sufijo") {
            palabras_por_sufijo(especifico);
        } 
        else if (comando == "grafo_de_palabras") {
            grafo_de_palabras();
        } 
        else if (comando == "posibles_palabras") {
            posibles_palabras(especifico);
        } 
        else {
            cout << "\033[1;31m[ERROR]: \033[0mEl comando no existe, digite 'ayuda' para saber los comandos." << endl;
        }
    }
    cout << "\033[1;32mFin de juego\033[0m" << endl;
    return 0;
}

void imprimir() {
    cout << "\033[1;37m" << endl; 
    cout << "=======================================" << endl;
    cout << "|          Lista De Comandos          |" << endl;
    cout << "=======================================" << endl;
    cout << "                                       " << endl;

    cout << "\033[1;32m* inicializar (nombre del archivo)\033[0m" << endl;
    cout << "  Inicializa el diccionario con el archivo especificado." << endl;
    cout << "                                       " << endl;
    cout << "\033[1;33m  [USO]:\033[0m inicializar archivo.txt" << endl;
    cout << endl;

    cout << "\033[1;32m* iniciar_inverso (nombre del archivo)\033[0m" << endl;
    cout << "  Inicializa el diccionario inverso con el archivo especificado." << endl;
    cout << "                                       " << endl;
    cout << "\033[1;33m  [USO]:\033[0m iniciar_inverso archivo.txt" << endl;
    cout << endl;

    cout << "\033[1;32m* puntaje palabra\033[0m" << endl;
    cout << "  Muestra el puntaje de la palabra especificada." << endl;
    cout << "                                       " << endl;
    cout << "\033[1;33m  [USO]:\033[0m puntaje palabra" << endl;
    cout << "\033[1;33m  [EJEMPLO]:\033[0m puntaje apple" << endl;
    cout << endl;

    cout << "\033[1;32m* iniciar_arbol (nombre del archivo)\033[0m" << endl;
    cout << "  Inicializa el trie del diccionario con el archivo especificado." << endl;
    cout << "                                       " << endl;
    cout << "\033[1;33m  [USO]:\033[0m iniciar_arbol archivo.txt" << endl;
    cout << endl;

    cout << "\033[1;32m* iniciar_arbol_inverso (nombre del archivo)\033[0m" << endl;
    cout << "  Inicializa el trie inverso del diccionario con el archivo especificado." << endl;
    cout << "                                       " << endl;
    cout << "\033[1;33m  [USO]:\033[0m iniciar_arbol_inverso archivo.txt" << endl;
    cout << endl;

    cout << "\033[1;32m* palabras_por_prefijo prefijo\033[0m" << endl;
    cout << "  Muestra palabras que comienzan con el prefijo especificado." << endl;
    cout << "                                       " << endl;
    cout << "\033[1;33m  [USO]:\033[0m palabras_por_prefijo prefijo" << endl;
    cout << "\033[1;33m  [EJEMPLO]:\033[0m palabras_por_prefijo app" << endl;
    cout << endl;

    cout << "\033[1;32m* palabras_por_sufijo sufijo\033[0m" << endl;
    cout << "  Muestra palabras que terminan con el sufijo especificado." << endl;
    cout << "                                       " << endl;
    cout << "\033[1;33m  [USO]:\033[0m palabras_por_sufijo sufijo" << endl;
    cout << "\033[1;33m  [EJEMPLO]:\033[0m palabras_por_sufijo ple" << endl;
    cout << endl;

    cout << "\033[1;32m* grafo_de_palabras\033[0m" << endl;
    cout << "  Construye el grafo de palabras desde el diccionario." << endl;
    cout << "                                       " << endl;
    cout << "\033[1;33m  [USO]:\033[0m grafo_de_palabras" << endl;
    cout << endl;

    cout << "\033[1;32m* posibles_palabras letras\033[0m" << endl;
    cout << "  Muestra posibles palabras que se pueden construir con las letras especificadas." << endl;
    cout << "                                       " << endl;
    cout << "\033[1;33m  [USO]:\033[0m posibles_palabras letras" << endl;
    cout << "\033[1;33m  [EJEMPLO]:\033[0m posibles_palabras lim?" << endl;
    cout << endl;

    cout << "\033[1;32m* salir\033[0m" << endl;
    cout << "  Sale del programa." << endl;
    cout << "                                       " << endl;
    cout << "\033[1;33m  [USO]:\033[0m salir" << endl;
    cout << "                                       " << endl;
    cout << "=======================================" << endl;
    cout << "\033[0m";
}



void inicializar(const std::string& nombreArchivo) {
    if (diccionarioInicializado) {
        cout << "\033[1;33m[INFO]:\033[0m Diccionario ya ha sido inicializado." << endl;
    } else if (!diccionario.cargarDesdeArchivo(nombreArchivo)) {
        cout << "\033[1;31m[ERROR]:\033[0m Error al abrir o procesar el archivo." << endl;
    } else {
        diccionarioInicializado = true;
        cout << "\033[1;32m[ÉXITO]:\033[0m Diccionario cargado correctamente." << endl;
    }
}



void iniciarinverso(const std::string& nombreArchivo) {
    if (diccionarioInversoInicializado) {
        cout << "\033[1;33m[INFO]:\033[0m Diccionario inverso ya ha sido inicializado." << endl;
    } else if (!diccionarioInverso.cargarDesdeArchivoInverso(nombreArchivo)) {
        cout << "\033[1;31m[ERROR]:\033[0m Error al abrir o procesar el archivo." << endl;
    } else {
        diccionarioInversoInicializado = true;
        cout << "\033[1;32m[ÉXITO]:\033[0m Diccionario inverso cargado correctamente." << endl;
    }
}



void puntaje_palabra(const std::string& palabra) {
    if (!diccionarioInicializado && !diccionarioInversoInicializado) {
        cout << "\033[1;31m[ERROR]:\033[0m Ningún diccionario ha sido inicializado. Por favor, inicialice al menos un diccionario primero." << endl;
        return;
    }

    string palabraNormal = palabra;
    transform(palabraNormal.begin(), palabraNormal.end(), palabraNormal.begin(), ::tolower);

    string palabraInversa = palabraNormal;
    reverse(palabraInversa.begin(), palabraInversa.end());

    bool existeEnNormal = diccionarioInicializado && diccionario.palabraExiste(palabraNormal);
    bool existeEnInverso = diccionarioInversoInicializado && diccionarioInverso.palabraExiste(palabraInversa);

    if (!existeEnNormal && !existeEnInverso) {
        cout << "\033[1;31m[ERROR]:\033[0m Palabra no válida o no existe en ningún diccionario." << endl;
        return;
    }

    Palabra objPalabra(palabraNormal);
    cout << "\033[1;32m[ÉXITO]:\033[0m La palabra '" << palabra << "' tiene un puntaje de " << objPalabra.calcularPuntaje() << endl;
}



void iniciar_arbol(const std::string& nombreArchivo) {
    if (trieDiccionarioInicializado) {
        cout << "\033[1;33m[INFO]:\033[0m El árbol del diccionario ya ha sido inicializado." << endl;
        return;
    }

    if (!diccionario.cargarDesdeArchivo(nombreArchivo)) {
        cout << "\033[1;31m[ERROR]:\033[0m El archivo " << nombreArchivo << " no existe o no puede ser leído." << endl;
        return;
    }

    for (const auto& palabra : diccionario.obtenerPalabras()) {
        trieDiccionario.insert(palabra);
    }

    trieDiccionarioInicializado = true;
    cout << "\033[1;32m[ÉXITO]:\033[0m El árbol del diccionario se ha inicializado correctamente." << endl;
}



void iniciar_arbol_inverso(const std::string& nombreArchivo) {
    if (trieDiccionarioInversoInicializado) {
        cout << "\033[1;33m[INFO]:\033[0m El árbol del diccionario inverso ya ha sido inicializado." << endl;
        return;
    }

    if (!diccionarioInverso.cargarDesdeArchivoInverso(nombreArchivo)) {
        cout << "\033[1;31m[ERROR]:\033[0m El archivo " << nombreArchivo << " no existe o no puede ser leído." << endl;
        return;
    }

    for (const auto& palabra : diccionarioInverso.obtenerPalabras()) {
        trieDiccionarioInverso.insert(palabra);
    }

    trieDiccionarioInversoInicializado = true;
    cout << "\033[1;32m[ÉXITO]:\033[0m El árbol del diccionario inverso se ha inicializado correctamente." << endl;
}



void palabras_por_prefijo(const std::string& prefijo) {
    if (!trieDiccionarioInicializado) {
        cout << "\033[1;31m[ERROR]:\033[0m El árbol del diccionario no ha sido inicializado." << endl;
        return;
    }

    auto palabras = trieDiccionario.wordsWithPrefix(prefijo);
    if (palabras.empty()) {
        cout << "\033[1;31m[ERROR]:\033[0m Prefijo '" << prefijo << "' no pudo encontrarse en el diccionario." << endl;
    } else {
        cout << "\033[1;32m[ÉXITO]:\033[0m Las palabras que inician con este prefijo son:" << endl;
        for (const auto& palabra : palabras) {
            Palabra objPalabra(palabra);
            cout << "\033[1;34m" << palabra << "\033[0m (Longitud: " << palabra.length() << ", Puntaje: " << objPalabra.calcularPuntaje() << ")" << endl;
        }
    }
}



void palabras_por_sufijo(const std::string& sufijo) {
    if (!trieDiccionarioInversoInicializado) {
        cout << "\033[1;31m[ERROR]:\033[0m El árbol del diccionario inverso no ha sido inicializado." << endl;
        return;
    }

    string sufijoLower = sufijo;
    transform(sufijoLower.begin(), sufijoLower.end(), sufijoLower.begin(), ::tolower);
    reverse(sufijoLower.begin(), sufijoLower.end());

    auto palabras = trieDiccionarioInverso.wordsWithPrefix(sufijoLower);
    if (palabras.empty()) {
        cout << "\033[1;31m[ERROR]:\033[0m Sufijo '" << sufijo << "' no pudo encontrarse en el diccionario." << endl;
    } else {
        cout << "\033[1;32m[ÉXITO]:\033[0m Las palabras que terminan con este sufijo son:" << endl;
        for (const auto& palabraInversa : palabras) {
            string palabra = palabraInversa;
            reverse(palabra.begin(), palabra.end());
            Palabra objPalabra(palabra);
            cout << "\033[1;34m" << palabra << "\033[0m (Longitud: " << palabra.length() << ", Puntaje: " << objPalabra.calcularPuntaje() << ")" << endl;
        }
    }
}



void grafo_de_palabras() {
    if (!diccionarioInicializado) {
        cout << "\033[1;31m[ERROR]:\033[0m Inicialice el diccionario primero." << endl;
        return;
    }

    for (const auto& palabra : diccionario.obtenerPalabras()) {
        grafo.agregarPalabra(palabra);
    }

    grafoInicializado = true;
    cout << "\033[1;32m[ÉXITO]:\033[0m Grafo construido correctamente." << endl;
}



void posibles_palabras(const std::string& letras) {
    if (!grafoInicializado) {
        cout << "\033[1;31m[ERROR]:\033[0m Inicialice el grafo primero." << endl;
        return;
    }

    auto posibles = grafo.obtenerPosiblesPalabras(letras);
    if (posibles.empty()) {
        cout << "\033[1;31m[ERROR]:\033[0m No se encontraron posibles palabras." << endl;
    } else {
        cout << "\033[1;32m[ÉXITO]:\033[0m Las posibles palabras a construir con las letras " << letras << " son:" << endl;
        for (const auto& palabra : posibles) {
            Palabra objPalabra(palabra);
            cout << "\033[1;34m" << palabra << "\033[0m (Longitud: " << palabra.length() << ", Puntaje: " << objPalabra.calcularPuntaje() << ")" << endl;
        }
    }
}
