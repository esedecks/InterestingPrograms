#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LINE_SIZE 1024

char* decimalAbinario(int decimal){
	int divisor = 2, cociente = 0, residuo = 0,dividendo = 0 ; 
	if( decimal == 0) 
		return "0";
	char* binario = malloc(sizeof(char)*64); 
	dividendo = decimal ; 
	
	cociente = dividendo / divisor ; 
	residuo = dividendo % divisor; 
	int contador = 0 ;
	*(binario+contador)  =  residuo + '0'  ; 
	while(cociente != 0){
		contador++;
		dividendo = cociente; 
		cociente = dividendo / divisor ; 
		residuo = dividendo % divisor;
		*(binario+contador)  = residuo + '0'; 
	}
	*(binario+contador+1) = '\0'; 
	int lon = strlen ( binario) ; 
	char aux [lon]; 
	int i = 0,z = lon-1; 	
	strcpy(aux, binario); 
	int c= 0 ; 
	for( i= z; i>=0; i--){
		*(binario + i) = *(aux+c);
		c++;
	}
return binario; 
}
int main(int argc, char **argv)
{
    FILE *f;
    char line[LINE_SIZE],*pointer=NULL;
    if (argc < 2 || !(f = fopen(argv[1], "r"))) {
        fprintf(stderr, "Unable to open file argument\n");
        return 1;
    }
    while (fgets(line, LINE_SIZE, f)) { 
		  if(line[0] == '\n')
			  continue;
		  int value = atoi(line);
		  fprintf(stdout,"%s\n", decimalAbinario(value)); 
    }
    
    if (ferror(f)) {
        perror("I/O Error");
    }
    return 0;
}
