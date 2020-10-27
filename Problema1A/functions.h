#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
using namespace std;


int long_arch(string Nom_arch); //this function returns the number of characters in a text file
void crear_array(int lon, char *array); //Saves the content of a text file in a array
void con_texto_bina(char *array, char *array2);
void metodo_1(string Nom_arch,int semilla, int lon, char *array, char *array2);
void metodo_2(string Nom_arch,int semilla, int lon, char *array, char *array2);


#endif // FUNCTIONS_H
