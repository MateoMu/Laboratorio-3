#include "functions.h"
#include "functions.cpp"
#include <iostream>

using namespace std;

int main() {

    string Archivo1, Archivo2;
    int metodo, semilla;

    cout<<"Por favor ingrese el nombre del archivo de texto de entrada: "<<endl;
    cin>>Archivo1;
    cout<<"Por favor ingrese el nombre del archivo de texto de salida: "<<endl;
    cin>>Archivo2;
    cout<<"Por favor ingrese el metodo de codificacion (1/2): "<<endl;
    cin>>metodo;
    cout<<"Ingrese la semilla: "<<endl;
    cin>>semilla;


    int n = long_arch(Archivo1);
    char array[n];
    char array2[n*8+1];
    char array3[n*8+1];    
    crear_array(Archivo1, n, array);
    array[n] = '\0';
    con_texto_bina(array, array2);
    array2[n*8] = '\0';    

    if(metodo == 1){
        metodo_1(Archivo2,semilla, n, array2, array3);
    }
    else{
        metodo_2(Archivo2,semilla, n, array2, array3);
    }


    return 0;
}
