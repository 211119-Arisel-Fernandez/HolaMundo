#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

int dia_boletos, adultos, adultos_my, ninos = 0;
int precio_adulto = 10;
int precio_adulto_my = 8;
int precio_ninos = 5;
int tipo_boleto, total_boletos;
int deacuerdo = 0;

int texto [] = {1,2,3}; 
int opc [3]; 

void diasBoletos(){
    cout<<"Escribe los boletos que se usaran en el dia de hoy"<<endl;
    cout<<"Boletos de adultos"<<endl;
    cin>>adultos;
    cout<<"Boletos adultos MAYORES"<<endl;
    cin>>adultos_my;
    cout<<"Boletos niños"<<endl;
    cin>>ninos;

    total_boletos = adultos + adultos_my + ninos;


}

void archivoCreacion(){  // funcion de crecion de archivo de texto nuevo 
    ofstream boletos;
    time_t tmFecha = time(NULL);
    boletos.open("boletosDia.txt",ios::out);
    if(boletos.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    diasBoletos();
    boletos<<"Archivo creado"<<endl;
    char* strFecha = ctime(&tmFecha);
    boletos<<strFecha<<endl;
    boletos<<"Introducidos el dia de hoy"<<endl;
    boletos<<"adultos"<<":"<<adultos<<endl;
     boletos<<"adultos_Mayores"<<":"<<adultos_my<<endl;
     boletos<<"Niños"<<":"<<ninos<<endl;
    boletos.close();
}

void archivoAniadir(){  // funcion de archivo aca tomamos algun archivo reciente y añadimos nuevos datos
	ofstream boletos;
    string texto;
    time_t tmFecha = time(NULL);

    boletos.open("boletosDia.txt",ios::app);
    if(boletos.fail()){
        cout<<"Archivo no existe";
        exit(1);
    }
    
    diasBoletos();
    boletos<<"Datos nuevos creados"<<endl;
    char* strFecha = ctime(&tmFecha);
    
    boletos<<strFecha<<endl;
    boletos<<"boletos introduccidos el dia de hoy"<<endl;
    boletos<<"adultos"<<":"<<adultos<<endl;
    boletos<<"adultos_Mayores"<<":"<<adultos_my<<endl;
    boletos<<"Niños"<<":"<<ninos<<endl;

    boletos.close();
}


void archivoLeer(){  // funcion leer aca mostramos la informacion en consola que contiene todo el programa
    ifstream boletos;
    string texto;
    boletos.open("boletosDia.txt",ios::in); 
    if(boletos.fail()){
        cout<<"Error no se puede abrir el archivo";
        exit(1);
    }

    while(!boletos.eof()){
        getline(boletos,texto);
        cout<<texto<<endl;

    }
    boletos.close();

}





void menuArchivos(){
    int datos;
    cout<<"Bienvenido"<<endl;
    cout<<texto[0]<<".-Crear nuevo archivo de datos"<<endl; 
    cout<<texto[1]<<".-Utilizar uno hecho (introducir mas datos)"<<endl;
    cout<<texto[2]<<".-Ver los resultados del documento"<<endl; 
    cin>>datos;
    switch(datos){
        case 1:
        archivoCreacion();
        break;
        
        case 2:
        archivoAniadir();
        break;
        
        case 3:
        archivoLeer();
        break;
    }

}


void introducirBoletos(){
    cout<<opc[0]<<".-adulto"<<endl; 
    cout<<opc[1]<<".-adulto mayor"<<endl;
    cout<<opc[2]<<".-niños"<<endl;
    cout<<"Introduce el tipo de boleto"<<endl; 
    cin>>tipo_boleto;

}


void validar_boletos(){
    cout<<"Estas de acuerdo"<<endl;
    cout<<"1.-SI o 2.-NO"<<endl;
    cin>>deacuerdo;


    if (deacuerdo == 1)
    {
        introducirBoletos();
    }
    else
    {
        diasBoletos();
    }

}





void opcion(){
    switch (tipo_boleto)
    {
    case 1:
    int blts_adultos;
    cout<<"introduce No. boletos adultos"<<endl;
    cin>> blts_adultos;
    adultos = adultos - blts_adultos;
    precio_adulto = precio_adulto * blts_adultos;
        break;

    case 2:
    int blts_adultos_my;
    cout<<"introduce No. boletos adultos mayores"<<endl;
    cin>>blts_adultos_my;
    adultos_my = adultos_my - blts_adultos_my;
    precio_adulto_my = precio_adulto_my * blts_adultos_my;
        break;

    case 3:
    int blts_ninos;
    cout<<"introduce No. boletos niños"<<endl;
    cin>>blts_ninos;
    ninos = ninos - blts_ninos;
    precio_ninos = precio_ninos * blts_ninos;
        break;

    default:
    cout<<"Boletos no encotrados"<<endl;
        break;
    }

}



void total(){
    int total_dinero =0;
    cout<<"boletos restantes de adultos son :"<<adultos<<endl;
    cout<<"Dinero Total de adultos es :"<<precio_adulto<<endl;
    cout<<"Boletos restantes de adultos mayores :"<<adultos_my<<endl;
    cout<<"Dinero Total de adultos Mayores es :"<<precio_adulto_my<<endl;
    cout<<"Boletos restantes de niños :"<<ninos<<endl;
    cout<<"Dinero Total de Niños es :"<<precio_ninos<<endl;

    total_dinero = precio_adulto + precio_adulto_my + precio_ninos;


    cout<<"el dinero en total es :"<<total_dinero<<endl;


}



int main()
{
    menuArchivos();
    int salir = 0;
    do
    {
        validar_boletos();
        opcion();
    } while (deacuerdo != 1);
    do
    {
        introducirBoletos();
        opcion();
        cout<<"desea salir"<<endl;
        cout<<"1.-si o 2.-no"<<endl;
        cin>>salir;
    } while (salir == 2);

    total();


    return 0;
}
