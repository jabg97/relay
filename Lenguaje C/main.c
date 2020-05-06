/*
 * main.c
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

#include "Libreria/Conex.h"
#include "Libreria/Clase.h"

int main(void)
{

    HANDLE hilo[2]; 
     
 if(Inicio() == -1){
	return -1;
	}
     
	 switch(info.menu){
	 	
	 	case 1:
	 info.datos = Recibir();
	 printf("<H3 class='text-primary'>Dato Recibido</H3>\n");
     printf("<h5 class='text-muted'>Puerto 0x%X , Dato Actual = 0x%X ,Dato Real = 0x%X</h5>",info.puerto,info.datos,(0xff - info.datos));            
     break;
	 
	 case 2:
         hilo[0] = (HANDLE) _beginthread(Enviar,0,NULL); 
         WaitForSingleObject(hilo[0],2);
      hilo[1] = (HANDLE) _beginthread(Escribir,0,NULL);
         WaitForMultipleObjects(2, hilo, TRUE, INFINITE );
         
	 break;
	 
     case 3:
          Leer();
	 break;
	 
	 case 4:
        Binario();
	 break;
	 
	 case 5:
        Borrar();
	 break;
	 	 
	 	case 6:
      Linea();
	 break; 
	 	 
	 default:
printf("<div class='alert alert-danger'><strong>Error!</strong>Por Favor digite una Opcion Correcta");
		 break;
	 }	 
    Salir();

                return 0;
}
