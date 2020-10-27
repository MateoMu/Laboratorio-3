#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;


//Longitud de un archivo de texto
int long_file(string filename) {

    ifstream archivo;
    char letra;
    int lon = 0;
    archivo.open(filename, ios::in);
    archivo.get(letra);
    if (archivo.is_open()){
        while(!archivo.eof()){
            lon++;
            archivo.get(letra);
        }
    }
    else{
        cout<<"Error de lectura."<<endl;
        exit(0);
    }
    archivo.close();
    return lon;
}

//Almacena el contenido de un archivo de texto en un arreglo tipo char. Recibe la longitud del archivo y un arreglo vacío.
void create_array(string filename, int lon, char *array){

    ifstream archivo;
    char letra;
    archivo.open(filename, ios::in);
    archivo.get(letra);
    array[lon]='\0';
    if (archivo.is_open()){
        while(!archivo.eof()){
            for(int i=0; i<lon; i++){
                array[i] = letra;
                archivo.get(letra);
            }
        }
    }
    else{
        cout<<"Error de lectura."<<endl;
        exit(0);
    }
    archivo.close();
//    cout<<array<<endl;
}

void metodo_1(string filename, int seed, int lon, char *array, char *array2){
    ofstream archivo;
    int tam = lon, k = 0, lim_s = seed, aux = 2;
    for(int l=0; l<lon*8; l++) array2[l] = array[l];
    array2[tam] = '\0';


    for(int i=0; i<seed; i++){ //Esto para cambia los valores en el primer bloque.
        if(array[i] == '0'){
            array2[i] = '1';
        }
        else{
            if(array[i] == '1'){
                array2[i] = '0';
            }
        }
    }

    for(int j=lim_s-seed; j<=tam; j+=seed){
        int ceros=0, unos=0;
        for(k=j; k<lim_s; k++){
            if (array2[k]=='0'){
                ceros++;
            }
            else{
                if(array2[k]=='1'){
                    unos++;
                }
            }
        }
        lim_s = seed*aux;//variable que se para al final de cada bloque (al que corresponda )
        aux++;

        if(ceros == unos){
            for(int l=k; l<lim_s ; l++){
                if(array[l] == '0'){
                    array2[l] = '1';
                }
                else{
                    if(array[l] == '1'){
                        array2[l] = '0';
                    }
                }
            }
        }

        if(ceros > unos){
            for(int l=k; l+1<lim_s; l+=2){
                if (array[l+1] == '0'){
                    array2[l+1] = '1';
                }
                else{
                    if(array[l+1] == '1'){
                        array2[l+1] = '0';
                    }
                }
            }
        }

        if(ceros < unos){
            for(int l=k; l+1<lim_s; l+=3){

                if (array[l+1] == '0'){
                    array2[l+1] = '1';
                }
                else{
                    if(array[l+1] == '1'){
                        array2[l+1] = '0';
                    }
                }
            }
        }
    }

    //cout<<array2<<endl;
    archivo.open(filename);
    archivo<<"El archivo codificado seria: "<<'\n';
    for (int i=0;i<tam;i++){
        archivo<<array[i];
    }
    archivo<<'\n';
    archivo<<"El archivo decodificado seria: "<<'\n';
    for (int i=0;i<tam;i++){
        archivo<<array2[i];
    }
    archivo.close();
}

void metodo_2(string filename, int seed, int lon, char *array, char *array2){
    ofstream archivo;
    int tam = lon, k = 0;
    int sob = ((tam)%seed);
    array2[tam] = '\0';
    //cout<<(sob)<<endl;
    for(int j=0; j<tam-sob; j+=seed){
        for(k=j; k<j+seed;k++){
            if(k==(j+seed)-1){
                array2[k] = array[j];
            }
            else{
                array2[k] = array[k+1];
            }
        }
    }


    if(sob != 0){
        for(int i=(tam)-sob; i<tam; i++){
            if(i==tam-1){
                array2[i] = array[tam-sob];
            }
            else{
                array2[i] = array[i+1];
            }
        }
    }

    //cout<<array2<<endl;
    archivo.open(filename);
    //archivo<<array2;
    //archivo.close();


    archivo<<"El archivo codificado seria: "<<'\n';
    for (int i=0;i<tam;i++){
        archivo<<array[i];
    }
    archivo<<'\n';
    archivo<<"El archivo decodificado seria: "<<'\n';
    for (int i=0;i<tam;i++){
        archivo<<array2[i];
    }
    archivo.close();
}

void binary_text(string filename, char *array){

    ofstream archivo;
    int lon=0, sum=0;

    for(int i=0; array[i] != '\0'; i++){
        lon++;
    }
    char array2[(lon/8)];
    array2[lon/8] = '\0';

    for(int j=0; j<lon; j+=8){
        for(int k=j, l=7; k<j+8, l>=0; k++, l--){
            if(array[k] == '1'){
                    sum += pow(2, l);
            }
        }
        array2[j/8] = sum;
        sum=0;
    }
    //cout<<array2<<endl;
    archivo.open(filename);
    archivo<<array2;

}

#endif // FUNCTIONS_H
