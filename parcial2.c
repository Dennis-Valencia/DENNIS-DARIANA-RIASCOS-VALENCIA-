#include <iostream>//Dylan Andres Arboleda Ferrin y dennis dariana riascos
#include <cstring>

using namespace std;

struct Nodo {
    int codigo;
    char nombre[30];
    int edad;
    char sexo;
    char razon[50];
    Nodo* siguiente;
};

Nodo* cola = NULL;
Nodo* historial = NULL;
Nodo* temporal = NULL;
Nodo* auxiliar = NULL;

void insertarCliente() {
    temporal = (Nodo*)malloc(sizeof(Nodo));
    
    cout << "Ingrese el c\u00f3digo del cliente: ";
    cin >> temporal->codigo;
    cin.ignore();
    cout << "Nombre: ";
    cin.getline(temporal->nombre, 30);
    cout << "Edad: ";
    cin >> temporal->edad;
    cout << "Sexo (M/F): ";
    cin >> temporal->sexo;
    temporal->sexo = toupper(temporal->sexo);
    cin.ignore();
    cout << "Raz\u00f3n de la llamada: ";
    cin.getline(temporal->razon, 50);
    
    temporal->siguiente = NULL;
    
    if (!cola) {
        cola = temporal;
    } else {
        auxiliar = cola;
        while (auxiliar->siguiente) {
            auxiliar = auxiliar->siguiente;
        }
        auxiliar->siguiente = temporal;
    }
    
    cout << "Cliente a\u00f1adido con \u00e9xito!" << endl;
}

void listarClientes() {
    auxiliar = cola;
    if (!auxiliar) {
        cout << "No hay clientes en espera." << endl;
        return;
    }

    cout << "\nClientes en espera:" << endl;
    while (auxiliar) {
        cout << "C\u00f3digo: " << auxiliar->codigo << endl;
        cout << " | Nombre: " << auxiliar->nombre << endl;
        cout << " | Edad: " << auxiliar->edad << endl;
        cout << " | Sexo: " << auxiliar->sexo << endl;
        cout << " | Raz\u00f3n: " << auxiliar->razon << endl;
        auxiliar = auxiliar->siguiente;
    }
}

void contarClientes() {
    int contador = 0;
    auxiliar = cola;
    while (auxiliar) {
        contador++;
        auxiliar = auxiliar->siguiente;
    }
    cout << "Clientes en espera: " << contador << endl;
}

void registrarEnHistorial(Nodo* cliente) {
    cliente->siguiente = historial;
    historial = cliente;
}

void procesarCliente() {
    if (!cola) {
        cout << "No hay clientes para atender." << endl;
        return;
    }

    temporal = cola;
    cola = cola->siguiente;

    if (temporal->edad < 18) {
        cout << "No se puede atender a menores de edad." << endl;
        temporal->siguiente = cola;
        cola = temporal;
        return;
    }

    registrarEnHistorial(temporal);
    
    cout << "Cliente atendido: " << temporal->nombre << endl;
}

void mostrarHistorial() {
    auxiliar = historial;
    if (!auxiliar) {
        cout << "No hay historial de atenciones." << endl;
        return;
    }

    cout << "\nHistorial de atenciones:" << endl;
    while (auxiliar) {
        cout << "C\u00f3digo: " << auxiliar->codigo << " | Nombre: " << auxiliar->nombre
             << " | Edad: " << auxiliar->edad << " | Sexo: " << auxiliar->sexo
             << " | Raz\u00f3n: " << auxiliar->razon << endl;
        auxiliar = auxiliar->siguiente;
    }
}

void revertirAtencion() {
    if (!historial) {
        cout << "No hay atenciones previas para revertir." << endl;
        return;
    }

    temporal = historial;
    historial = historial->siguiente;
    temporal->siguiente = cola;
    cola = temporal;

    cout << "Se ha revertido la \u00faltima atenci\u00f3n." << endl;
}

int main() {
    int opcion;
    do {
        cout << "\nMENU" << endl;
        cout << "1. A\u00f1adir cliente a la cola" << endl;
        cout << "2. Ver clientes en espera" << endl;
        cout << "3. Contar clientes en espera" << endl;
        cout << "4. Atender al siguiente cliente" << endl;
        cout << "5. Ver historial de atenciones" << endl;
        cout << "6. Revertir \u00faltima atenci\u00f3n" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opci\u00f3n: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1: insertarCliente(); break;
            case 2: listarClientes(); break;
            case 3: contarClientes(); break;
            case 4: procesarCliente(); break;
            case 5: mostrarHistorial(); break;
            case 6: revertirAtencion(); break;
            case 7: cout << "Saliendo del sistema..." << endl; break;
            default: cout << "Opci\u00f3n inv\u00e1lida. Intente de nuevo." << endl;
        }
    } while (opcion != 7);
    
    return 0;
}