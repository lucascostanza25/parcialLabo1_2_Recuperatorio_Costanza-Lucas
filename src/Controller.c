/*
 * Controller.c
 *
 *  Created on: 26 jun. 2021
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libros.h"
#include "parser.h"
#include "UTN.h"

int controller_loadFromText(char* path , LinkedList* listaLibros)
{
	int retorno=-1;
	FILE* pArchivo=fopen(path, "r");

	if(path!=NULL && listaLibros!=NULL)
	{
		if(pArchivo!=NULL)
		{
			parser_LibroFromText(pArchivo, listaLibros);
			retorno=0;
		}
		fclose(pArchivo);
	}

	return retorno;
}

int controller_ListLibro(LinkedList* listaLibros)
{
	int retorno=-1;
	int i;
	int auxId;
	char auxTitulo[120];
	char auxAutor[100];
	float auxPrecio;
	char auxEditorial[100];
	eLibro* auxLibro;

	if(listaLibros!=NULL)
	{
		ll_map(listaLibros, descuento_libro);
		printf("ID  | TITULO                                            | AUTOR            | PRECIO    | EDITORIAL \n");

		for(i=0; i<ll_len(listaLibros); i++)
		{
			auxLibro=ll_get(listaLibros, i);
			getId_libro(auxLibro, &auxId);
			getTitulo_libro(auxLibro, auxTitulo);
			getAutor_libro(auxLibro, auxAutor);
			getPrecio_libro(auxLibro, &auxPrecio);
			getEditorial_libro(auxLibro, auxEditorial);

			printf("%-5d %-50s %-18s %-12.2f %-18s\n", auxId, auxTitulo, auxAutor, auxPrecio, auxEditorial);
		}
		retorno=0;
	}

	return retorno;
}

int controller_sortLibro(LinkedList* listaLibros)
{
	int retorno=-1;

	if(listaLibros!=NULL)
	{
		ll_sort(listaLibros, sortAutor_libro, 0);
		retorno=0;
	}

	return retorno;
}

int controller_saveAsText(char* path , LinkedList* listaLibros)
{
	int retorno=-1;
	int i;
	FILE* pArchivo;
	eLibro* libroGuardado;

	if(listaLibros!=NULL && path!=NULL)
	{
		pArchivo=fopen(path, "w");
		if(pArchivo!=NULL)
		{
			fprintf(pArchivo, "id,titulo,autor,precio,editorialId\n");
			for(i=0; i<ll_len(listaLibros); i++)
			{
				libroGuardado=(eLibro*)ll_get(listaLibros, i);
				fprintf(pArchivo, "%d, %s, %s, %f, %s\n", libroGuardado->id, libroGuardado->titulo, libroGuardado->autor, libroGuardado->precio, libroGuardado->editorial);
				retorno=0;
			}
			fclose(pArchivo);
		}
	}

	return retorno;
}
