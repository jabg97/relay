/*

 * Conex.h

 * 

 * Copyright 2016 Jaiver <Jaiver@JAIVER-PC>

 * 

 * This program is free software; you can redistribute it and/or modify

 * it under the terms of the GNU General Public License as published by

 * the Free Software Foundation; either version 2 of the License, or

 * (at your option) any later version.

 * 

 * This program is distributed in the hope that it will be useful,

 * but WITHOUT ANY WARRANTY; without even the implied warranty of

 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the

 * GNU General Public License for more details.

 * 

 * You should have received a copy of the GNU General Public License

 * along with this program; if not, write to the Free Software

 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,

 * MA 02110-1301, USA.

 * 

 * 

 */

#include <windows.h>
#include <stdio.h>

 typedef short _stdcall (*Puntero_Entrada)(short direccion);
 typedef void _stdcall (*Puntero_Salida)(short direccion, short datos);
     
          
     Puntero_Entrada Leer_Puerto;
     Puntero_Salida Enviar_Puerto;
     
      struct{
     short puerto;
     short datos;
     short menu;
     short row;
     char fecha_actual[22];
     } info;
     
     void *link;
     
 short Inicio(void){
     
     // Verificar Datos HTML
     char *get;
	printf("%s%c%c\n","Content-Type:text/html;charset=iso-8859-1",13,10);
	get = getenv("QUERY_STRING");
	
	if(get == NULL){
  		printf("<div class='alert alert-danger'><strong>Error!</strong> Envio de Datos desde el Formulario ha Fallado.</div>");
	return -1;
	}
	if(sscanf(get,"puerto=%i&datos=%i&menu=%i&row=%i",&info.puerto,&info.datos,&info.menu,&info.row)!=4){
  		printf("<div class='alert alert-danger'><strong>Error!</strong> Datos Invalidos, Solo se Permiten Valores Numeros.</div>");
	return -1;
	}
     
     //Cargar la Libreria Dll
     HINSTANCE dll = LoadLibrary("Libreria/inpout32.dll");


link = dll;

     if (link == NULL) {
          printf("<div class='alert alert-danger'><strong>Error!</strong> No se pudo Cargar la Libreria.</div>");
          return -1;
     }

// Obtener Direccion de Memoria de Los Procedimientos del Dll

     Leer_Puerto = (Puntero_Entrada) GetProcAddress(dll, "Inp32");

     if (Leer_Puerto == NULL) {
          printf("<div class='alert alert-danger'><strong>Error!</strong> No se pudo Obtener la Direccion del Procedimiento de Lectura.</div>");
          return -1;
     }
     
     Enviar_Puerto = (Puntero_Salida) GetProcAddress(dll, "Out32");

     if (Enviar_Puerto == NULL) {
          printf("<div class='alert alert-danger'><strong>Error!</strong> No se pudo Obtener la Direccion del Procedimiento de Envio.</div>");
          return -1;
     }
    
    return 0;
     }    
