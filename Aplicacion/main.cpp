#include "funciones.h"

#include <iostream>

using namespace std;

int main()
{
    int opcion=1,opcion2=1;

    while(opcion !=0)
    {
    cout<<"******* Aplicacion de banco ********"<<endl;
    cout<<"Presione 1 para ingresar como administrador "<<endl;
    cout<<"Presione 2 para ingresar como usuario corriente "<<endl;
    cout<<"Presione 0 para salir "<<endl;

    cin>>opcion;

   switch(opcion)
    {
      case 1:{

       int  ptr, n = long_file("sudo.txt");
       char array[n];
       char array2[n*8+1];
       char array3[n*8+1];
       char ced[n*8+1];
       char clav[n*8+1];
       char saldo[n*8+3];
       char cednew[n*8+1];
       char clavnew[n*8+1];

       cout<<"Ingrese numero de cedula: ";
       cin>>ced;
       cout<<"Ingrese clave: ";
       cin>>clav;

       create_array("sudo.txt", n, array);
       array[n] = '\0';

       create_array_ing(ced, clav, array2);
       array2[n*8] = '\0';

       text_binary(n, array2, array3);
       array3[n*8] = '\0';

       ptr = strcmp(array, array3); //me retorna 0 si son iguales y -1 si son diferentes

       if (ptr == 0){
           cout<<"TU INGRESO COMO ADMINISTRADOR FUE EXITOSO!"<<endl;
           cout<<"Ingrese numero de cedula a registrar: ";
           cin>>cednew;
           cout<<"Ingrese clave a registrar: ";
           cin>>clavnew;
           cout<<"Ingrese salgo: ";
           cin>>saldo;
           create_usu("file_us.txt", cednew, clavnew, saldo);

           cout<<"Tu registro fue exitoso!"<<endl;
       }

       else cout<<"NO FUE VALIDO TU INGRESO COMO ADMINISTRADOR"<<endl;

       break;
}

      case 2:{
       opcion2=1;
       while(opcion2!=0){

       cout<<"Ingrese 1 para consultar saldo"<<endl;
       cout<<"Ingrese 2 para retirar cantidad especifica"<<endl;
       cout<<"Ingrese 0 para salir al menu principal"<<endl;
       cin>>opcion2;

       switch(opcion2)
       {
        case 1:{
           int n=long_file("file_us.txt");
           char us[n],newarray[n];

           int p = consu_sal("file_us.txt", n, us);//funcion para consultar saldo
           us[n] = '\0';
           p=p - 1000;
           //cout<<peso<<endl;


           create_array("file_us.txt", n, newarray);
           newarray[n] = '\0';
           //cout<<newarray<<endl;
//           binary_text(newarray,newarray2);
//           cout<<newarray2<<endl;


           file_actual("file_us.txt", n, p, newarray); //Funcion para actualizar el saldo
           p = consu_sal("file_us.txt", n, us);//funcion para consultar saldo
           us[n] = '\0';
           cout<<"A su saldo se le ha descontado 1000$ por consulta "<<endl;

           cout<<"Su saldo es de: "<<p<<endl;


           //create_usu("file_us.txt", cednew, clavnew, peso);
            break;

        }
       case 2:{
           int can_dinero=0,peso=0;
           int n=long_file("file_us.txt");
           char us[n];
           char newarray[n];
           //char newarray2[n/8];
           cout<<"Ingrese la cantidad de dinero que desea retirar: ";
           cin>>can_dinero;
           cout<<endl<<"A su saldo se le ha descontado 1000$ por retiro"<<endl;

           peso = consu_sal("file_us.txt", n, us);//funcion para consultar saldo
           us[n] = '\0';
           peso=peso-can_dinero - 1000;
           //cout<<peso<<endl;


           create_array("file_us.txt", n, newarray);
           newarray[n] = '\0';
           //cout<<newarray<<endl;
//           binary_text(newarray,newarray2);
//           cout<<newarray2<<endl;


           file_actual("file_us.txt", n, peso, newarray); //Funcion para actualizar el saldo
                }
        }

                        }
       break;
                }



//    default:
//           cout<<"Opcion no es valida"<<endl;
//           break;

    return 0;
    }
    }
}
