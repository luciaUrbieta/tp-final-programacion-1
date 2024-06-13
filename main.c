#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	char letras[4];
	char numeros[4];
} Patente;

typedef struct {
	Patente patente;
	char marca[20];
	char modelo[15];
	int anio;
	int kms;
	int dniTitular;
	float precioDeAdquisicion;
} AutoArchivo;

typedef struct {
	int dni;
	char nombre[30];
	int telefono;
	char direccion[20];
	char rol[10]; //comprador o vendedor
} Persona;

typedef struct {
	Patente patente;
	char marca[20];
	char modelo[15];
	int anio;
	int kms;
	Persona Titular;
	float precioDeAdquisicion;
} Auto;

typedef struct {
	int dia;
	int mes;
	int anio;
} Fecha;

typedef struct {
	Fecha fecha;
	Patente autoAVender;
	float precioVenta;
	float ganancia;
	int dniComprador;
	int dniVendedor;
} Venta;

void login(char contrasenia[25]);

Patente cargarPatente();
int validarLetras(char letras[]);
int validarNumeros(char numeros[]);
int validarCantidad(char cadena[]);

void cargarAuto(char AutoArchivo []);

// contraseña: autosmdp

int main()
{
    char archivoAutos [] = "autos.bin";
    char archivoPersonas [] = "personas.bin";
    char archivoVentas [] = "ventas.bin";
/*
    char contrasenia[25];
    login();
*/
/*
    Patente patente;
    patente = cargarPatente();
    puts(patente.letras);
    puts(patente.numeros);
*/

    cargarAuto(archivoAutos);


    return 0;
}

// 1.

void login(char contrasenia[25]){

    printf("\nIngrese la contrasenia: ");
    fflush(stdin);
    gets(contrasenia);

    if(strcmp(contrasenia, "autosmdp") == 0){
        menu();
    } else {
        printf("\nContrasenia incorrecta, vuelva a intententar.");
//        login();
    }
}

//2
void menu(){

    char seleccion;

    printf("Presione 1 para cargar un auto: \n");

    return seleccion;
}
//3.
/*
typedef struct {
	char letras[3];
	char numeros[3];
} Patente;
*/

Patente cargarPatente(){

    Patente patente;
    char letras[4];
    char numeros[4];
    int validacionLetras=0;
    int validacionNumeros=0;
    int validacionCantidadL=0;
    int validacionCantidadN=0;

    do{
        printf("Ingrese las letras de la patente: \n");
        fflush(stdin);
        gets(letras);
        validacionLetras=validarLetras(letras);
        validacionCantidadL=validarCantidad(letras);
        if(validacionLetras==1 && validacionCantidadL==1){
            strcpy(patente.letras, letras);
        }
    }while(validacionLetras==0 || validacionCantidadL==0);

    do{
        printf("Ingrese los numeros de la patente: \n");
        fflush(stdin);
        gets(numeros);
        validacionNumeros=validarNumeros(numeros);
        validacionCantidadN=validarCantidad(numeros);
        if(validacionNumeros==1 && validacionCantidadN==1){
            strcpy(patente.numeros, numeros);
        }
    }while(validacionNumeros==0 || validacionCantidadN==0);

    printf("Patente cargada con exito :) \n");

    return patente;
}

int validarLetras(char letras[]){

    int validacionLetras=1;

    for(int i=0; i<3; i++){
        if(!isalpha(letras[i])){
            validacionLetras=0;
        }
    }

    if(validacionLetras==0){
        printf("Error. Todos los caracteres ingresados deben ser letras. \n");
    }

    return validacionLetras;
}

int validarNumeros(char numeros[]){

    int validacionNumeros=1;

    for(int i=0; i<3; i++){
        if(!isdigit(numeros[i])){
            validacionNumeros=0;
        }
    }

    if(validacionNumeros==0){
        printf("Error. Todos los caracteres ingresados deben ser numeros. \n");
    }

    return validacionNumeros;
}

int validarCantidad(char cadena[]){

    int validacionCantidad=1;

    if (strlen(cadena) != 3) {
        validacionCantidad=0;
        printf("Error. Debe ingresar 3 caracteres. \n");
    }

    return validacionCantidad;
}

/*
typedef struct {
	Patente patente;
	char marca[];
	char modelo[];
	int año;
	int kms;
	Persona Titular;
	float precioDeAdquisición;
} Auto;
*/

void cargarAuto(char AutoArchivo []){

 //   FILE *archivo = fopen(AutoArchivo, "rb");

    Auto nuevoAuto;

    Patente patente;
    patente=cargarPatente();

    nuevoAuto.patente=patente;

    puts(nuevoAuto.patente.letras);



}

void cargarPatenteLetras(Patente aux){
    char patenteAux[3];
    printf("\nIngrese las primeras 3 letras de la patente del auto: ");
    fflush(stdin);
    scanf("%s", &patenteAux);
    for(int i = 0;i < 3; i++){
//        isAlpha(patenteAux);
}

}
