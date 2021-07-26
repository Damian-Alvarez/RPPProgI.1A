#include <stdio.h>
#include <stdlib.h>
#define TAM 5
typedef struct
{
    int id;
    char procesador[25];
    char marca[20];
    float precio;
} eNotebook;



void mostrarNotebook(eNotebook notebook);
void mostrarNotebooks(eNotebook lista[], int tam);
void ordenarNotebook(eNotebook lista[], int tam);


int main()
{
    float precio;
    float iva;

    printf("Introduzca el precio de un producto:");
    scanf("%f", &precio);
    iva = precio * 0.21;
    printf("\nEl precio con IVA es de: %.2f\n\n",precio + iva);
    printf("\nEl precio sin IVA es de: %.2f\n\n",precio);






    eNotebook notebooks[TAM]=
    {
        {1212, "Intel T3500","Acer",120000},
        {1415, "Core i7","Asus",600000},
        {5451, "AMD Ryzen 5 ","HP",60000},
        {4571, "intel i7","Dell",110000},
        {1815, "Pentium Silver "," Lenovo",85000},
    };

    mostrarNotebooks(notebooks,TAM);
    ordenarNotebook(notebooks,TAM);
    mostrarNotebooks(notebooks,TAM);


    return 0;
}



void mostrarNotebook(eNotebook notebook)
{

    printf("%d %25s %10s  %2.f\n"
           ,notebook.id
           ,notebook.procesador
           ,notebook.marca
           ,notebook.precio
          );
}



void mostrarNotebooks(eNotebook lista[], int tam)
{


    printf("                Listado de notebooks\n");
    printf("\nId              Procesador         Marca    Precio");

    for(int i=0; i<tam; i++)
    {
        mostrarNotebook(lista[i]);
    }
    printf("\n\n");
}


void ordenarNotebook(eNotebook lista[], int tam)
{
    eNotebook auxNotebook;
    for(int i=0; i<tam-1; i++ )
    {
        for(int j= i+1; j<tam; j++)
        {
            if( (strcmp(lista[i].marca,lista[j].marca)<0)|| ((strcmp(lista[i].marca,lista[j].marca)==0) && lista[i].precio<lista[j].precio) )
            {
                auxNotebook= lista[i];
                lista[i]=lista[j];
                lista[j]= auxNotebook;
            }
        }
    }
}
