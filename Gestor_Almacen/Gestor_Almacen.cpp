#include <iostream>
#include<list>
#include<string>
#include <fstream>
#include <cstdlib>//usar el "cls"
#include <algorithm> //usar el transform

using namespace std;

struct Producto {
    string  Nombre, Marca;
    float Precio = 0;
    int Unidades = 0, Categoria = 0;
};

string cate[]{ "Comida","Herramientas","Ropa","Tecnologia","Juguetes" };


//Funciones Principales
void Agregar_Producto(std::list<Producto>& Almacen);
void Mostrar_Inventario(std::list<Producto>& Almacen);
void Buscar_Producto(std::list<Producto>& Almacen);
void Modificar_Producto(std::list<Producto>& Almacen);
void Eliminar_Producto(std::list<Producto>& Almacen);
void Generar_Reporte(std::list<Producto>& Almacen);
void Suma_Total_Productos(std::list<Producto>& Almacen);
void Buscar_por_Categoria(std::list<Producto>& Almacen);

//Funciones para funcionamiento correcto las funciones principales 
int Verificar_numero();
float Verificar_numero_float();
void Pausa();
void mostrar(std::list<Producto>& Almacen);
int Verificar_Rango(int a, int b);


int main()
{
    std::list<Producto> Almacen;
    int x = 0;
    do {
        system("cls");
        //Menu de opciones
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "+++++++++++++++++++++++ Sistema de Inventario ++++++++++++++++++++++++" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << endl;
        cout << "Agregar Producto....................................................1" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "Mostrar Inventario..................................................2" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "Buscar Producto.....................................................3" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "Modificar Producto..................................................4" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "Eliminar Producto...................................................5" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "Suma Total de Productos.............................................6" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "Buscar por Categoria................................................7" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "Generar Reporte.....................................................8" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "Salir...............................................................9" << endl;
        cout << "---------------------------------------------------------------------" << endl;

        x = Verificar_Rango(1, 9);
        system("cls");


        switch (x) {
        case 1:
            Agregar_Producto(Almacen);
            break;
        case 2:
            Mostrar_Inventario(Almacen);
            break;
        case 3:
            Buscar_Producto(Almacen);
            break;
        case 4:
            Modificar_Producto(Almacen);
            break;
        case 5:
            Eliminar_Producto(Almacen);
            break;
        case 6:
            Suma_Total_Productos(Almacen);
            break;
        case 7:
            Buscar_por_Categoria(Almacen);
            break;
        case 8:
            Generar_Reporte(Almacen);
            break;
        }


    } while (x != 9);
    return 0;
}

//Funciones Principales -------------------------------------------------------------------------------------------------------------------------------------------------
void Agregar_Producto(std::list<Producto>& Almacen) {
    Producto aux;
    int x = 0;
    do {
        cout << "//////////////////////////////////////////////////// Registro del Producto ////////////////////////////////////////////////////" << endl << endl;
        cout << "Ingrese el nombre del producto: ";
        getline(cin, aux.Nombre);
        transform(aux.Nombre.begin(), aux.Nombre.end(), aux.Nombre.begin(), ::toupper);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Ingrese la Marca del Producto: ";
        getline(cin, aux.Marca);
        transform(aux.Marca.begin(), aux.Marca.end(), aux.Marca.begin(), ::toupper);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

        cout << "Ingrese Categoria COMIDA=1,HERRAMIENTAS=2,ROPA=3,TECNOLOGIA=4,JUGUETS=5" << endl;;
        aux.Categoria = Verificar_Rango(1, 5);
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Ingrese su precio: ";
        aux.Precio = Verificar_numero_float();
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Cantidad de unidades a ingresar: ";
        aux.Unidades = Verificar_numero();
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        Almacen.push_back(aux);
        cout << "Producto Ingresado..." << endl;
        cout << "Ingresar otro producto:SI=1 NO=0. " << endl;
        x = Verificar_Rango(0, 1);
        system("cls");
    } while (x != 0);

    Pausa();

}
void Mostrar_Inventario(std::list<Producto>& Almacen) {
    cout << "//////////////////////////////////////////////////// Lista de Inventario ////////////////////////////////////////////////////" << endl << endl;
    if (Almacen.empty()) {
        cout << "La lista esta vacia...";
        Pausa();
        return;
    }
    for (auto& it : Almacen) {
        cout << "Nombre: " << it.Nombre << endl;
        cout << "Marca: " << it.Marca << endl;
        cout << "Categoria: " << cate[it.Categoria - 1] << endl;
        cout << "Precio de la unidad: " << it.Precio << endl;
        cout << "Cantidad en almacen: " << it.Unidades << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    }
    Pausa();
}
void Buscar_Producto(std::list<Producto>& Almacen) {
    string Nombre;
    cout << "//////////////////////////////////////////////////// Busqueda de Inventario ////////////////////////////////////////////////////" << endl << endl;
    if (Almacen.empty()) {
        cout << "La lista esta vacia..." << endl;;
        Pausa();
        return;
    }
    mostrar(Almacen);
    cout << "Ingrese nombre de producto: ";
    getline(cin, Nombre);
    transform(Nombre.begin(), Nombre.end(), Nombre.begin(), ::toupper);
    for (auto& it : Almacen) {
        if (it.Nombre == Nombre) {
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Nombre: " << it.Nombre << endl;
            cout << "Marca: " << it.Marca << endl;
            cout << "Categoria: " << cate[it.Categoria - 1] << endl;
            cout << "Precio de la unidad: " << it.Precio << endl;
            cout << "Cantidad en almacen: " << it.Unidades << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            Pausa();
            return;

        }
    }
    cout << "Producto no encontrado: " << endl;
    Pausa();
}

void Modificar_Producto(std::list<Producto>& Almacen) {
    string Nombre;
    cout << "//////////////////////////////////////////////////// Modificar de Producto ////////////////////////////////////////////////////" << endl << endl;

    if (Almacen.empty()) {
        cout << "La lista esta vacia...";
        Pausa();
        return;
    }
    mostrar(Almacen);
    cout << "Ingrese nombre de producto: ";
    getline(cin, Nombre);
    transform(Nombre.begin(), Nombre.end(), Nombre.begin(), ::toupper);
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    for (auto& it : Almacen) {
        if (it.Nombre == Nombre) {

            cout << "Ingrese el nuevo nombre del producto: ";
            getline(cin, it.Nombre);
            transform(it.Nombre.begin(), it.Nombre.end(), it.Nombre.begin(), ::toupper);
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

            cout << "Ingrese la marca del producto: ";
            getline(cin, it.Marca);
            transform(it.Marca.begin(), it.Marca.end(), it.Marca.begin(), ::toupper);
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

            cout << "Ingrese Categoria COMIDA=1,HERRAMIENTAS=2,ROPA=3,TECNOLOGIA=4,JUGUETS=5" << endl;
            it.Categoria = Verificar_Rango(1, 5);
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

            cout << "Ingrese su precio: ";
            it.Precio = Verificar_numero_float();
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

            cout << "Cantidad de unidades a ingresar: ";
            it.Unidades = Verificar_numero();
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl;

            cout << "Producto modificado... " << endl;
            Pausa();
            return;
        }
    }

    cout << "Producto no encontrado..." << endl;
    Pausa();
}


void Eliminar_Producto(std::list<Producto>& Almacen) {
    string producto;
    int encontrado = 1;

    if (Almacen.empty()) {
        cout << "La lista esta vacia...";
        Pausa();
        return;
    }
    while (encontrado == 1) {
        cout << "//////////////////////////////////////////////////// Eliminacion de Producto ////////////////////////////////////////////////////" << endl << endl;
        mostrar(Almacen);
        cout << endl;
        
        cout << "Ingrese el nombre del producto a eliminar: ";
        getline(cin, producto);
        transform(producto.begin(), producto.end(), producto.begin(), ::toupper);
        
        for (auto it = Almacen.begin(); it != Almacen.end(); it++) {
            if (it->Nombre == producto) {
                Almacen.erase(it);
                cout << "Producto elimida de la lista..." << endl;
                Pausa();
                return;
            }
        }
        cout << "Producto no encontrado..." << endl;
        cout << "Desea volver a intentarlo SI=1, NO=0: ";
        encontrado = Verificar_Rango(0, 1);
        system("cls");

    }
}
void Generar_Reporte(std::list<Producto>& Almacen) {
    if (Almacen.empty()) {
        cout << "La lista esta vacia...";
        Pausa();
        return;
    }
    
    ofstream archivo("Reporte_Almacen.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo crear el archivo..." << endl;
        return;
    }

    archivo << "================= REPORTE DEl ALMACEN =================\n";
    archivo << "Productos Registrados: " << Almacen.size() << "\n";
    archivo << "=====================================================\n\n";

    for (const auto& it : Almacen) {
        archivo << "Nombre: " << it.Nombre << "\n"
            << "Marca: " << it.Marca << "\n"
            << "Categoria: " << cate[it.Categoria - 1] << "\n"
            << "Precio: " << it.Precio << "\n"
            << "Unidades: " << it.Unidades << "\n"

            << "-----------------------------------------------------\n";
    }

    archivo << "\n================= FIN DEL REPORTE =================\n";

    archivo.close();
    cout << "Reporte generado con exito: Reporte_Alamcen.txt\n";

}

void Suma_Total_Productos(std::list<Producto>& Almacen) {
    float total = 0;
    cout << "//////////////////////////////////////////////////// Suma monetaria total del inventario ////////////////////////////////////////////////////" << endl << endl;
    if (Almacen.empty()) {
        cout << "La lista esta vacia...";
        Pausa();
        return;
    }
    for (auto& it : Almacen) {
        total += (it.Precio*it.Unidades);
    }
    cout << "Suma Total: " << total << endl;
    Pausa();
}

void Buscar_por_Categoria(std::list<Producto>& Almacen) {
    int ca = 0;
    bool estado = false;
    cout << "//////////////////////////////////////////////////// Busqueda Por Categoria ////////////////////////////////////////////////////" << endl << endl;
    if (Almacen.empty()) {
        cout << "La lista esta vacia...";
        Pausa();
        return;
    }

    cout << "-------- Categoria: COMIDA=1,HERRAMIENTAS=2,ROPA=3,TECNOLOGIA=4,JUGUETS=5. --------" << endl;
    cout << "Ingresa la categoria." << endl;
    ca = Verificar_Rango(1, 5);

    cout <<endl<< "############# " << cate[ca - 1] << " #############" << endl;
    for (auto& it : Almacen) {
        if (it.Categoria == ca) {
            cout << "Nombre: " << it.Nombre << endl;
            cout << "Marca: " << it.Marca << endl;
            cout << "Categoria: " << cate[it.Categoria - 1] << endl;
            cout << "Precio de la unidad: " << it.Precio << endl;
            cout << "Cantidad en almacen: " << it.Unidades << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            estado = true;
        }
    }
    if (estado == false) {
        cout <<endl<< "No hay productos de esa categoria..." << endl;
    }
    cout << endl;
    Pausa();
}



//Funciones para el sistema-----------------------------------------------------------------------------------------------------------------------
int Verificar_numero() {
    int numero;
    while (true) {
        if (cin >> numero) {
            return numero;
        }
        else {
            cout << "------Entrada invalida. Solo se permiten numeros------" << endl;
            cout << "Ingrese solo numeros: ";
            cin.clear(); // limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia el buffer
        }
    }
}

float Verificar_numero_float() {
    float numero;
    while (true) {
        if (cin >> numero) {
            return numero;
        }
        else {
            cout << "------Entrada invalida. Solo se permiten numeros------" << endl;
            cout << "Ingrese solo numeros: ";
            cin.clear(); // limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia el buffer
        }
    }
}

void Pausa() {
    cout << endl<<"Presiona ENTER para continuar...";

    if (cin.peek() == '\n') {
        cin.get();  // Si ya hay un ENTER pendiente, lo consume
    }
    else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia basura
        cin.get();  // Espera un ENTER real
    }
}
    

void mostrar(std::list<Producto>& Almacen) {
    cout << "Lista Rapida de los productos: " << endl;
    cout << "------------------------------------" << endl;
    for (auto& it : Almacen) {
        cout << it.Nombre << " -- ";
    }
    cout << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
}

int Verificar_Rango(int a, int b) {
    int x = 0;
    while (true) { //Verificacion de Entrada
        cout << "Ingrese el numero de la opcion: ";
        if (cin >> x && x >= a && x <= b) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//Limpiar buffer
            return x;
        }
        cout << "Selcione una de las opciones..." << endl << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}