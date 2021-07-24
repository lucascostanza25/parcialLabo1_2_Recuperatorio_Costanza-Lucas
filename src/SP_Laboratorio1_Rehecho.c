/*
 ============================================================================
 Name        : SP_Laboratorio1_Rehecho.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Libros.h"
#include "LinkedList.h"
#include "parser.h"
#include "UTN.h"

int main(void) {
	setbuf(stdout, NULL);
	int menu, menuGuardado;
	int flagArchivo=0;
	LinkedList* listaLibros=ll_newLinkedList();

	do
	{
		utn_getNumero(&menu, "-- SEGUNDO PARCIAL --\n"
				"\n1.Cargar archivo\n"
				"2.Listar libros ordenados\n"
				"3.Guardar lista mapeada\n"
				"0.Salir\n"
				"\nSeleccione una opcion: ", "", 0, 3, 2);
		system("cls");
		switch(menu)
		{
			case 1:
				if(controller_loadFromText("../Datos.csv", listaLibros)!=-1)
				{
					printf("Archivo cargado con exito!\n");
					flagArchivo=1;
				}
				else
				{
					printf("No se pudo cargar el archivo o no exite en el sistema!\n");
				}
				system("pause");
			break;

			case 2:
				if(flagArchivo==1)
				{
					controller_sortLibro(listaLibros);
					controller_ListLibro(listaLibros);
				}
				else
				{
					printf("Primero cargue los archivos!\n");
				}
				system("pause");
			break;

			case 3:
				if(flagArchivo==1)
				{
					utn_getNumero(&menuGuardado, "-- GUARDAR --\n"
							"Desea guardar el arhivo?\n"
							"\n0.Si"
							"\n1.No\n"
							"\nSeleccione una opcion: ", "Error, opcion incorrecta!\n", 0, 1, 2);
					if(menuGuardado==0)
					{
						system("cls");
						if(controller_saveAsText("../mapeado.csv", listaLibros)!=-1)
						{
							printf("Arhivo guardado con exito!\n");
						}
						else
						{
							printf("No se pudo guardar el archivo!\n");
						}
					}
				}
				else
				{
					printf("Primero cargue los archivos!\n");
				}
				system("pause");
			break;

			case 0:
				utn_getNumero(&menu, "Segudo que desea salir?\nCUIDADO! Todos los progresos no guardados se perderan\n"
						"\n0.Si\n"
						"1.No\n"
						"\nSeleccione una opcion: ", "Error, opcion incorrecta\n", 0, 1, 2);
			break;
		}
		system("cls");
	}while(menu!=0);
	return EXIT_SUCCESS;
}
