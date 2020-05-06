/*

 * Clase.h

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


#include <time.h>

 short Recibir(void){
   return (Leer_Puerto)(info.puerto);
	 }

void Enviar(void){

(Enviar_Puerto)(info.puerto,0xff - info.datos);
printf("<font color='magenta'>hilo1: 1 envio Puerto<font><br>");
Sleep(2);
     printf("<H3 class='text-primary'>Dato Enviado</H3>\n");
printf("<font color='red'>hilo1: 2 imprimir titulo<font><br>");
Sleep(2);
	 printf("<h5 class='text-muted'>Puerto 0x%X, Dato Enviado = 0x%X</h5>" ,info.puerto,info.datos);
	 printf("<font color='brown'>hilo1:Fin imprimir datos<font><br>");
	 _endthread();
}

void Binario(void){
    short binario[4];
  short dec = 0xff - Recibir();
  short x;
  for(x = 0; x < 4; x++){
      binario[x] = dec % 2;
 dec /= 2;
 printf("%d",binario[x]);
  }
}
     
void Fecha(void){
   time_t tiempo = time(NULL);
   //ctime(&tiempo);
  struct tm *struct_tiempo = localtime(&tiempo);
  strftime(info.fecha_actual, 22, "%d/%m/%Y (%H:%M:%S)", struct_tiempo);
}


void Escribir(void){
FILE *log = fopen("Libreria/Datos.log", "a");
printf("<font color='cyan'>hilo2: 1 Abrir Archivo<font><br>");
Sleep(2);
Fecha();
fprintf(log,"<td>0x%X</td><td>0x%X</td><td>%s</td>\n", info.puerto, info.datos,info.fecha_actual);
printf("<font color='blue'>hilo2: 2 Escribir Archivo<font><br>");
Sleep(2);
fclose(log);
printf("<font color='indigo'>hilo2:Fin cerrar archivo<font><br>");
_endthread();
}

void Leer(void){
char datos [58];
short filas = 1;
FILE *log = fopen("Libreria/Datos.log", "r");
                if (log == NULL) {
                    printf("<div class='alert alert-danger'><strong>Error!</strong> El Archivo Log no Existe </div>");
                } else { 
                        printf("<div class='table-responsive'>");
			 printf("<table class='table table-bordered table-hover'>");
			 
     printf("<tr align='center' class='bg-info text-primary' align=center> <td><strong>Puerto</strong></td>");
     printf("<td><strong>Dato</strong></td>");
     printf("<td><strong>Fecha</strong></td>");
     printf("<td><strong>Borrar</strong></td></tr>");


while(fgets(datos,58,log) != NULL){
       printf("<tr class='text-muted' align='center'>%s <td><button class='btn btn-danger btn-xs' onclick='Fila(%d);'>Borrar</button></td></tr>",datos,filas-1);
fseek(log,filas*57+filas++,SEEK_SET);
   }                  
                     printf("</table></div>");
                    fclose(log);
                }
}


void Borrar(void){
  FILE *log = fopen("Libreria/Datos.log", "r" );
    if (log == NULL) {
                    printf("<div class='alert alert-danger'><strong>Error!</strong> El Archivo Log no Existe </div>");
                } else { 
      fclose(log);
      if(remove("Libreria/Datos.log") == 0 ){   
      printf( "<div class='alert alert-success'><strong>Archivo Borrado</strong></div>" );
      FILE *log = fopen("Libreria/Datos.log", "a");
      fclose(log);
Leer();
      }else{  
      printf("<div class='alert alert-danger'><strong>Error!</strong> El Archivo NO Pudo ser Borrado</div>");
   }
     }
     }
     
   void Linea(void){
        if(rename("Libreria/Datos.log", "Libreria/Datos.tmp") == 0) {
   
   FILE *tmp = fopen("Libreria/Datos.tmp", "r" );
	 FILE *log = fopen("Libreria/Datos.log", "a" );
	
	
	short letra;
	short fila = info.row;
	
	if(fila == 0){
	fseek(tmp,58,SEEK_SET);
	}
		short salto = 58 * fila;
	while ((letra=fgetc(tmp))!= EOF) {                                      
    if(ftell(tmp) == salto){
	 fseek(tmp,58,SEEK_CUR);
	}     
   fputc(letra,log);              
}
      fclose(tmp);
      fclose(log);
remove("Libreria/Datos.tmp");
 printf("El Registro #%d ha sido Eliminado",fila+1);
   }else{
          printf("Error! El Registro no pudo ser Eliminado");
         }
        }  
     
void Salir(void){
	 FreeLibrary(link);
}
    
