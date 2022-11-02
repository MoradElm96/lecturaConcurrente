#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>

void contenidoFichero(void)
{

    
    FILE *fichero;
    
    char  caracteres[1000];


    fichero= fopen("fichero.txt", "r"); // abro el fichero para escritura

    if (fichero == NULL)
    {
        printf("no se ha podido abrir el fichero..\n");
        exit(-1);
    } // abro el fichero sólo para lectura
    printf("Contenido del fichero:\n");

    int contador=0;
   
    while(!feof(fichero))//feof comprueba el final del fichero, leeemos la linea con!
	{
        fgets(caracteres,1000,fichero);//linea, maximo 50 caracteres
        contador++;
	
	}
    
    //return c;

    rewind(fichero);//ponemos el cursor al principio del fichero
    fclose(fichero);
    

   int vocalA,vocalE,vocalI,vocalO,vocalU;
   char c;

    for (int i = 0; i < strlen(caracteres); i++)
    {
       c = caracteres[i];
        if(c=='a') vocalA++;
        if(c=='e') vocalE++;
        if(c=='i') vocalI++;
        if(c=='o') vocalO++;
        if(c=='u') vocalU++;

    }
    

    printf("la vocal a : %d \n", vocalA);
    printf("la vocal e : %d \n", vocalE);
    printf("la vocal i : %d \n", vocalI);
    printf("la vocal o : %d \n", vocalO);
    printf("la vocal u : %d \n", vocalU);

    
}


void main()
{

    pid_t pid_hijo1, pid_hijo2, pid_hijo3, pid_hijo4, pid_hijo5;

    /// HIJO1
    pid_hijo1 = fork();
    if (pid_hijo1 == 0)
    {

        printf("Soy el hijo 1 productor Mi padre es= %d, Mi PID= %d \n", getppid(), getpid());

        
       
       contenidoFichero();
       //contarVocales(contenidoFichero());

        sleep(2);
        exit(0);
    }

    /// HIJO 2
    pid_hijo2 = fork();
    if (pid_hijo2 == 0)
    {

        printf("Soy el hijo 2 consumidor Mi padre es= %d, Mi PID= %d \n", getppid(), getpid());
 
        sleep(2);
        exit(0);
    }

    /// HIJO 3
    pid_hijo3 = fork();
    if (pid_hijo3 == 0)
    {

        printf("Soy el hijo 3 consumidor Mi padre es= %d, Mi PID= %d \n", getppid(), getpid());

        sleep(2);
        exit(0);
    }

    /// HIJO 4
    pid_hijo4 = fork();
    if (pid_hijo4 == 0)
    {

        printf("Soy el hijo 4 consumidor Mi padre es= %d, Mi PID= %d \n", getppid(), getpid());

        sleep(2);
        exit(0);
    }

    /// HIJO 5
    pid_hijo5 = fork();
    if (pid_hijo5 == 0)
    {

        printf("Soy el hijo 5 consumidor Mi padre es= %d, Mi PID= %d \n", getppid(), getpid());

        sleep(2);
        exit(0);
    }

    // PADRE

    wait(NULL);
    printf("Proceso PADRE = %d, mi PID: %d \n", getppid(), getpid());

    exit(0);
}

// if (pid == 0)
// { // hijo 2

//     close(fd[1]);

//     printf("soy el proceso %d hijo 2 de %d\n", getpid(), getppid());

//     // Leemos del pipe

//     read(fd[0], buffer, sizeof(buffer));

//     for (int i = 0; i <= strlen(cadena); ++i)
//     {

//         if (buffer[i] == 'i')
//         {

//             buffer[i] = '1';
//         }
//         else if (buffer[i] == 's')
//         {

//             buffer[i] = '5';
//         }
//     }

//     printf("El hijo 2 lee del pipe: %s\n", buffer);
