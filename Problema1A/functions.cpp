#include "functions.h"
#include <fstream>

using namespace std;


int long_arch(string Nom_arch){

    ifstream archivo;
    char letra;
    int lon = 0;
    archivo.open(Nom_arch, ios::in); //Abrimos el archivo
    archivo.get(letra);
    if (archivo.is_open()){
        while(!archivo.eof()){  //Longitud del archivo
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

void crear_array(string Nom_arch, int lon, char *array){

    ifstream archivo;
    char letra;
    archivo.open(Nom_arch, ios::in);
    archivo.get(letra);
    array[lon]='\0';
    if (archivo.is_open()){
        while(!archivo.eof()){
            for(int i=0; i<lon; i++){ //Ingresa el contenido del archivo al arreglo array
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

void con_texto_bina(char *array, char *array2){

    int j=0, bin, resultado, c, n;

    for(int i=0;array[i]!='\0';i++){
        c=((i+1)*8)-1;
        n = array[i];
        while (n>0){
            bin = n%2;
            if (bin == 0){
                array2[c] = '0';
                c--;
                j++;
            }
            else{
                array2[c] = '1';
                c--;
                j++;
            }
            n /= 2;
        }
        if(j<8){
            resultado = 8-j;
            for(int k=0; k<resultado; k++){
                array2[(i*8)+k] = '0';
            }
        }
        j=0;
    }
}

void metodo_1(string Nom_arch,int semilla, int lon, char *array, char *array2){

    int tam = lon*8, k = 0, lim_s = semilla, aux = 2;

    for(int l=0; l<lon*8; l++) array2[l] = array[l];
    array2[tam] = '\0';


    for(int i=0; i<semilla; i++){ //Ajustar los caracteres en los primeros bloques
        if(array[i] == '0'){
            array2[i] = '1';
        }
        else{
            if(array[i] == '1'){
                array2[i] = '0';
            }
        }
    }

    for(int j=0;j<=tam;j+=semilla){ // cuenta los ceros y unos de cada bloque
        int ceros=0, unos=0;
        for(k=lim_s-semilla; k<lim_s;k++){
            if (array[k]=='0'){
                ceros++;
            }
            else{
                if(array[k]=='1'){
                    unos++;
                }
            }
        }
        lim_s = semilla*aux;//variable que separa al final de cada bloque (al que corresponda )
        aux++;

        if(ceros == unos){
            for(int c=0; c < semilla; c++, k++){
                if (array[k] == '0'){
                    array2[k] = '1';
                }
                else{
                    if (array[k]== '1'){
                        array2[k] = '0';
                    }
                }
            }
        }

        if(ceros > unos){
            for(;k+1<lim_s; k+=2){
                if (array[k+1] == '0'){

                    array2[k+1] = '1';
                }
                else{
                    if (array[k+1]== '1'){
                        array2[k+1] = '0';
                    }
                }
            }
        }

        if(ceros < unos){
            for(;k+1<lim_s; k+=3){
                if (array[k+1] == '0'){
                    array2[k+1] = '1';
                }
                else{
                    if (array[k+1]== '1'){
                        array2[k+1] = '0';
                    }
                }
            }
        }
    }
    for (int i=0;i<tam;i++){

    }
//    cout<<array<<endl;
//    cout<<array2<<endl;



    fstream f;
    f.open(Nom_arch,ios_base::out);

    f<<"El archivo en binario seria: "<<'\n';
    for (int i=0;i<tam;i++){
        f<<array[i];
    }
    f<<'\n';
    f<<"El archivo codificado seria: "<<'\n';
    for (int i=0;i<tam;i++){
        f<<array2[i];
    }
    f.close();
}

void metodo_2(string Nom_arch,int semilla, int lon, char *array, char *array2){

    int tam = lon*8, k = 0;
    int sob = ((lon*8)%semilla);
    array2[tam] = '\0';

    for(int j=0; j<tam-sob; j+=semilla){
        for(k=j; k<j+semilla;k++){

            if(k==(j+semilla)-1){
                array2[j] = array[k];
            }
            else{
                array2[k+1] = array[k];
            }
        }
    }


    if(sob != 0){
        for(int i=(tam)-sob; i<tam; i++){

            if(i==tam-1){
                array2[tam-sob] = array[tam-1];
            }
            else{
                array2[i+1] = array[i];
            }
        }
    }

//    cout<<array2<<endl;

    fstream f;
    f.open(Nom_arch,ios_base::out);

    f<<"El archivo en binario seria: "<<'\n';
    for (int i=0;i<tam;i++){
        f<<array[i];
    }
    f<<'\n';
    f<<"El archivo codificado seria: "<<'\n';
    for (int i=0;i<tam;i++){
        f<<array2[i];
    }
    f.close();
}
