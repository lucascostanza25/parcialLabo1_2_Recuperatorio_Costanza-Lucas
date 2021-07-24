/*
 * Controller.h
 *
 *  Created on: 26 jun. 2021
 *      Author: Lucas
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* listaLibros);

int controller_ListLibro(LinkedList* listaLibros);

int controller_sortLibro(LinkedList* listaLibros);

int controller_saveAsText(char* path , LinkedList* listaLibros);

#endif /* CONTROLLER_H_ */
