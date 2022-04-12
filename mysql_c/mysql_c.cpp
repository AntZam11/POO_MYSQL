// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
//#include <mysql.h>
#include <iostream>
#include "Cliente.h"

using namespace std;
//int q_estado;
int main()
{

    /* MYSQL* conectar;

     MYSQL_ROW fila;
     MYSQL_RES* resultado;
     conectar = mysql_init(0);
     conectar = mysql_real_connect(conectar, "localhost", "root", "device11", "database", 3306, NULL, 0); //conectar database
     if (conectar) {                                                   //conectar database
        // cout << "Conexion Exitosa..." << endl;
       string puesto;                                              //insertar datos_ end Ingreso exitoso
        cout << "ingrese puesto: ";
        cin >> puesto;
        string insert = "insert into puestos(puesto) values('" + puesto + "')";
        const char* i = insert.c_str();                               //esta linea ejecuta el insert into.
        q_estado = mysql_query(conectar,i);                         //esta linea ejecuta el insert into.
        if (!q_estado) {
            cout << "Ingreso Exitoso..." << endl;
        
        }
        string consulta = "select * from puestos";          // select, muestra los puestos _ endl while fila
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0]<<"," << fila[1]<<";" << endl;
            }

        }
     }
      
    
    else {
        cout << "xxxxError al consultar xxxx" << endl;
    }*/

    string nit, nombres, apellidos, direccion, fecha_nacimiento;
    int telefono;
    cout << "ingrese nit:";
    getline(cin, nit);
    cout << "Ingrese Nombres:";
    getline(cin,nombres);
    cout << "Ingrese Apellidos:";
    getline(cin, apellidos);
    cout << "Ingrese Direccion:";
    getline(cin, direccion);
    cout << "Ingrese Telefono:";
    cin >> telefono;
    cin.ignore();
    cout << "Ingrese Fecha de Nacimiento:";
    cin >> fecha_nacimiento;





    Cliente c = Cliente(nombres,apellidos,direccion,telefono,fecha_nacimiento,nit);
    c.crear();
    c.leer();

    system("pause");
        return 0;
}















// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
