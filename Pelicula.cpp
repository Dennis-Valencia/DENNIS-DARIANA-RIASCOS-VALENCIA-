#include <iostream>
#include <string>
using namespace std;

struct Pelicula {
    string titulo;
    string genero;
    float presupuesto;
    Pelicula* izquierda;
    Pelicula* derecha;
};

Pelicula* crearNodo(string titulo, string genero, float presupuesto) {
    Pelicula* nuevoNodo = new Pelicula();
    nuevoNodo->titulo = titulo;
    nuevoNodo->genero = genero;
    nuevoNodo->presupuesto = presupuesto;
    nuevoNodo->izquierda = nullptr;
    nuevoNodo->derecha = nullptr;
    return nuevoNodo;
}

Pelicula* insertar(Pelicula* raiz, string titulo, string genero, float presupuesto) {
    if (raiz == nullptr) {
        return crearNodo(titulo, genero, presupuesto);
    }
    if (presupuesto < raiz->presupuesto) {
        raiz->izquierda = insertar(raiz->izquierda, titulo, genero, presupuesto);
    } else {
        raiz->derecha = insertar(raiz->derecha, titulo, genero, presupuesto);
    }
    return raiz;
}

void preorden(Pelicula* raiz) {
    if (raiz != nullptr) {
        cout << "Título: " << raiz->titulo << ", Género: " << raiz->genero << ", Presupuesto: " << raiz->presupuesto << endl;
        preorden(raiz->izquierda);
        preorden(raiz->derecha);
    }
}

void posorden(Pelicula* raiz) {
    if (raiz != nullptr) {
        posorden(raiz->izquierda);
        posorden(raiz->derecha);
        cout << "Título: " << raiz->titulo << ", Género: " << raiz->genero << ", Presupuesto: " << raiz->presupuesto << endl;
    }
}

void mostrarArbol(Pelicula* raiz) {
    preorden(raiz);
}

int main() {
    Pelicula* raiz = nullptr;
    raiz = insertar(raiz, "Inception", "Ciencia Ficción", 160.0);
    raiz = insertar(raiz, "El Padrino", "Crimen", 6.0);
    raiz = insertar(raiz, "El Caballero de la Noche", "Acción", 185.0);
    raiz = insertar(raiz, "Tiempos Violentos", "Drama", 8.0);
    cout << "Contenido del árbol en preorden:" << endl;
    mostrarArbol(raiz);
    cout << "\nContenido del árbol en posorden:" << endl;
    posorden(raiz);
    return 0;
}