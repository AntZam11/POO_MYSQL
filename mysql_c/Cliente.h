#pragma once
#include <mysql.h>
#include "ConexionBD.h"
# include <iostream>
#include <string>
#include "Persona.h"

using namespace std;
class Cliente: Persona{
private: string nit;

	   //constructor
public:
	Cliente() {
		
	}

	Cliente(string nom, string ape, string dir , int tel, string fn,string n) : Persona ( nom,ape,dir,tel,fn) {
		nit = n;



	}

	//metodos
	//set(modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDirecciones(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setfecha_nacimiento(string fn) { fecha_nacimiento = fn; }
	

	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDirecciones() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_nacimiento() { return fecha_nacimiento; }
	//metodos
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string t = to_string(telefono);    //pasar int a un string
			string insert = "INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento)VALUES('" + nit + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "');";
			const char* i = insert.c_str();                               //esta linea ejecuta el insert into.
			q_estado = mysql_query(cn.getconectar(), i);                         //esta linea ejecuta el insert into.
			if (!q_estado) {
				cout << "Ingreso Exitoso..." << endl;

			}
			else {
				cout << "xxxxError al Ingresar Informacion xxxx" << endl;
			}

		}
		else {
			cout << "xxxxError al Ingresar Informacion xxxx" << endl;
		}
		cn.cerrar_conexion();

	}


	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar ()) {
		string consulta = "select * from clientes";          // select, muestra los puestos _ endl while fila
		const char* c = consulta.c_str();
		q_estado = mysql_query(cn.getconectar(), c);
		if (!q_estado) {
			resultado = mysql_store_result(cn.getconectar());
			cout << "--------------Clientes-------------" << endl;
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << "," << fila[1] << ";"<<fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << ";" << endl;
			}

		}
		}
		else {
			cout << "xxxxError al Ingresar Informacion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

};

