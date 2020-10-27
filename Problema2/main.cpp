#include "functions.h"

using namespace std;

int main()
{
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

    int n = long_file(Archivo1);
    char array[n];
    char array2[n*8+1];
    char array3[n*8+1];

    create_array(Archivo1, n, array);
    array[n] = '\0';

    if(metodo == 1){
        metodo_1(Archivo2,semilla, n, array, array3);
        array2[n*8] = '\0';
        array3[n*8] = '\0';
    }
    else{
        metodo_2(Archivo2,semilla, n, array, array3);
        array2[n*8] = '\0';
        array3[n*8] = '\0';
    }



    binary_text("text_decod.txt", array3);

    return 0;
}
