#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define long 100

int main(int argc, char *argv[])
{

  char* buffer;
  char nuevo[long]; // long palabra reservada
  char co[]="_copy.c"; // es una constante porque no es macro
  char original[20]; // numero magico
  int  size; // no inicializada
  sprintf(original,"%s", argv[1]);//Enviar cadena de argv[1] a "original"
  // sprintf tiempo de ejecucion en el core 
FILE *fc = fopen(original, "rb");//lectura de bit "a que te refieres con lectura de bit?" fopen crea un apuntador al primer dato del string   
	if(!fc) // para cada if se necesita un else!! 
	{ 
		printf("\nError\n"); // Que tipos de errores puede retornar? 
    }//comprobar se haya abierto el archivo

		fseek(fc, 0L, SEEK_END); // donde validas el valor de retorno
		size=ftell(fc);//obtnemos el tamaño en caracteres del archivo y guardamos en variable size
		fseek(fc, 0, SEEK_SET); // donde validas el valor de retorno
        buffer = (char*)malloc(size*sizeof(char)+1);//tamaño de memoria dinamica

		fread(buffer, size, 1, fc);//Leer lo que hay en el archivo por bits

   for(int i=0; i < sizeof(original); i++)
   {
	   //ciclo para copiar el nombre del archivo
		if(original[i]== '.')
		{
           break;
        }

        nuevo[i] =  original[i];//variable "nuevo" para guardar el nombre del archivo

}
      strcat(nuevo, co);//unir "nuevo" con "co(_copy.c)"

		FILE  *fp = fopen(nuevo, "w");//Escritura
 
      fwrite(buffer, size, 1, fp);//Escritura del archivo nuevo 
      fclose(fp);
      fclose(fc);

  return 1;
}
