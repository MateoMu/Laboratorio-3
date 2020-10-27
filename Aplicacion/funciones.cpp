#include "funciones.h"
#include <fstream>

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
    //cout<<array<<endl;
}

//Almacena el contenido ingresado de cedula y clave en un arreglo de char
void create_array_ing(char *cedula, char *clave, char *array){
    int lon_ced = strlen(cedula);
    int lon_cla = strlen(cedula);
    int lon = lon_ced+lon_cla+1;

    array[lon]='\0';
    cedula[lon_ced]='\0';
    clave[lon_cla]='\0';

    strcpy(array,cedula);
    strncat(array," ",lon);
    strncat(array,clave,lon);


//    cout<<array<<endl;
//    cout<<cedula<<endl;
//    cout<<clave<<endl;
}


//Convierte cualquier texto a binario. Recibe un arreglo con el contenido del archivo y un arreglo vacío donde almacenará el texto en binario.
void text_binary(int lon, char *array, char *array2){
    array2[lon] = '\0';
    int j=0, bin, resto, c, n;

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
            resto = 8-j;
            for(int k=0; k<resto; k++){
                array2[(i*8)+k] = '0';
            }
        }
        j=0;
    }
    //cout<<array<<endl;
    //cout<<array2<<endl;
}

void create_usu(string filename, char *cednew, char *clavnew, char *saldo){

    ofstream archivo;
    int lon;
    lon=strlen(cednew);
    lon+=strlen(clavnew);
    lon+=strlen(saldo);
    lon+=2;
    //cout<<lon<<endl;
    char eve_array[lon];
    char bin_array[lon*8];


    strcpy(eve_array,cednew);
    strcat(eve_array," ");
    strcat(eve_array,clavnew);
    strcat(eve_array," ");
    strcat(eve_array,saldo);

    //cout<<eve_array<<endl;

    text_binary( lon, eve_array, bin_array);
    bin_array[lon*8]='\0';



    //cout<<bin_array<<endl;

    archivo.open(filename);

    for (int i=0;i<=lon*8;i++){
        archivo<<bin_array[i];
    }
    archivo<<'\n';


}

int consu_sal(string filename, int lon, char *array){
    ifstream archivo;
    char letra;
    char array2[(lon/8)];
    char *ptr;
    char a[(lon/8)];
    int posi=0;


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
    binary_text(array,array2);
    array2[lon/8] = '\0';
    //cout<<array2<<endl;

    ptr = strrchr(array2, ' '); //Encuentra el ultimo caracter ' '
    posi= ptr-array2+1;   // posicion despues del caracter encontrado ' '
    //cout<<array2[posi]<<endl;

    for(int i=0;i<=(lon/8)-(ptr-array2+1);i++,posi++){
        a[i]=array2[posi];
    }

    int entero=ent(a);   //convierte el arreglo a de caracteres a entero
    //cout<<"Su saldo es de: "<<entero<<endl;

    return entero;



}

void binary_text(char *array, char *array2){


    int lon=strlen(array), sum=0;




    for(int j=0; j<=lon; j+=8){
        for(int k=j, l=7; k<j+8, l>=0; k++, l--){
            if(array[k] == '1'){
                    sum += pow(2, l);
            }
        }
        array2[j/8] = sum;
        sum=0;
    }
    //cout<<array2<<endl;


}
int ent(char car[]){
    int i=0,j=0,k=0;
    int res,resultado,fin=0;

    while (car[i]!='\0'){  //contamos la longitud de la cadena (i)
        i++;

    }
    i--;      //como llega hasta uno mas se le resta uno
    k=i;      // igualamos para multiplicarlos por las decimas
    for (j=0;j<=i;j++){
        res= int ((car[j])-48);  //conversion de cada nunero a entero
        resultado=res*pow(10,k); //conversion a las decimas
        fin=fin+resultado;       //suma de cada uno como decima
        k--;
    }

    return fin;
}

void file_actual(string filename, int lon, int newPs, char *newarray){
    ofstream archivo;
    char newarray2[lon/8], ent_car[lon/8];
    char *ptr,*ptr2;
    char ced[(lon/8)];
    int posi=0,posi2=0;

    binary_text(newarray,newarray2);
    newarray2[lon/8] = '\0';
    //cout<<array2<<endl;

    ptr = strchr(newarray2, ' '); //Encuentra el primer caracter ' '
    posi= ptr-newarray2;   // posicion del caracter encontrado ' '
    strncpy(ced, newarray2, posi); //Arreglo con la cedula
    ced[posi]='\0';
    posi+=1;
    ptr2 = strrchr(newarray2, ' ');
    posi2= ptr2-newarray2;
    char claves[posi2-posi];
    claves[posi2-posi]='\0';

    for(int i=0; posi<posi2;i++,posi++){ //Arreglo con clave
        claves[i]=newarray2[posi];
    }

    //cout<<strlen(claves)<<endl;



    convertir(newPs,ent_car); // convertimos el entero de los pesos a char

//Agregamos en eve_array todos los datos actualizados
    lon=strlen(ced);
    lon+=strlen(claves);
    lon+=strlen(ent_car);
    lon+=2;
    //cout<<lon<<endl;
    char eve_array[lon];
    char bin_array[lon*8];


    strcpy(eve_array,ced);
    strcat(eve_array," ");
    strcat(eve_array,claves);
    strcat(eve_array," ");
    strcat(eve_array,ent_car);

    //cout<<eve_array<<endl;

//Convertimos el arreglo con los datos actualizados a binario
    text_binary( lon, eve_array, bin_array);
    bin_array[lon*8]='\0';

    //cout<<bin_array<<endl;


 //Actualizamos el archivo .txt con los datos nuevos

    archivo.open(filename);

    for (int i=0;i<=lon*8;i++){
        archivo<<bin_array[i];
    }
    archivo<<'\n';



}

char convertir(int num, char *array_conver)//Body of the function
{
    int copia=num,digitos=0;//make a copy of the num for know how
    //many digits that it have

    while(copia>=1){//know the digits.
        copia=copia/10;
        digitos++;

    }
    int numeros[digitos];//make the array for put all the enter number.
    copia=num;//take every position of the num to put in the array numeros.
    for (int i=0;i<=digitos-1;i++)
    {
        numeros[digitos-i-1]=copia%10;//fill the array with every digit even int type
        copia=copia/10;
    }
    int *ap=numeros;//pointer to the array numbers
    char convertidos[digitos];//The array to return (int tranform to char)
    convertidos[digitos]='\0';
    for (int ii=0;ii<digitos;ii++)//every position of the array int put in convertidos type char
    {
        convertidos[ii]=(*(ap+ii))+48;
    }
    array_conver[strlen(convertidos)];
    array_conver[strlen(convertidos)]='\0';

    for (int j=0;j<strlen(convertidos);j++){
        array_conver[j]=convertidos[j];
    }
    //cout<<array_conver<<endl;
    return 0;
}
