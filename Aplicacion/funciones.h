#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int long_file(string filename); //Longitud del archivo

void create_array(string filename, int lon, char *array); //Crea un arreglo con lo del archivo

void create_array_ing(char *ced, char *clav, char *array2); //crea un arreglo con los valores ingresados

void text_binary(int lon, char *array, char *array2);//convierte texto a numeros binarios

void create_usu(string filename, char *cednew, char *clavnew, char *saldo);//Crea un archivo con el usuario a registrar

int consu_sal(string filename, int lon, char *array); // funcion que consulta el saldo

void binary_text(char *array, char *array2); //convierte un arreglo de binario a texto

int ent(char car[]); // convierte un arreglo de caracteres a entero

void file_actual(string filename, int lon, int newPs, char *newarray); // Funcion actualiza el saldo

char convertir(int num, char *array_conver);  //Convierte un entero a un arreglo de caracteres



#endif // FUNCIONES_H
