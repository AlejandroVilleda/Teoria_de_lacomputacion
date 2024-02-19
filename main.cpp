/**
 * Villeda Patricio Arón Alejandro
 * 5BM1
 * Teoría de la Computación
 * Código 1: Introducción a los autómatas finitos. Cadenas y lenguajes
 * Sistema operativo: Ubuntu 22.04 LTS
 **/


#include <iostream>
#include <random>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>

void generarLenguaje(unsigned int *numeroEjecucion);
void generarLenguaje_Aleatorio(unsigned int *numeroEjecucion);
bool generarCadenas(std::string &resultado, std::vector<char> &cadena);

int main()
{
    std::string nombreArchivo = "xdg-open Lenguajes_generados.txt"; // Para distribuciones linux
    //std::string nombreArchivo = "Lenguajes_generados.txt";        // Para windows
    unsigned int numeroEjecucion = 1;
    unsigned short int Respuesta;
    bool Terminar = false;

    do
    {
        std::cout<< "***************MENU***************"<< std::endl;
        std::cout<< "[1]. Ingresar valor N"<< std::endl;
        std::cout<< "[2]. Generar valor N aleatorio"<< std::endl;
        std::cout<< "[3]. Visualizar lenguaje generado"<< std::endl;
        std::cout<< "[4]. Salir"<< std::endl;
        std::cout<< "Respuesta: ";
        std::cin>> Respuesta;
        {}
        switch(Respuesta)
        {
            case 1: generarLenguaje(&numeroEjecucion); break;
            case 2: generarLenguaje_Aleatorio(&numeroEjecucion); break;
            case 3: system(nombreArchivo.c_str()); break;
            case 4: std::cout<< "Ejecucion terminada"; Terminar = true; break;
            default: break;
        }
    }   while(!Terminar);
    return 0;
}


void generarLenguaje(unsigned int *numeroEjecucion)
{
    int N;
    std::ofstream Archivo;
    std::string Cadenas;
    bool Terminar = false;

    Archivo.open("Lenguajes_generados.txt", std::ios::app);
    if(!Archivo.is_open()) EXIT_FAILURE;
    Archivo<< "Ejecucion "<< *numeroEjecucion<< ":"<< std::endl; Archivo<< "{";

    std::cout<< "Valor de N: ";
    std::cin>> N;
    std::cout<< "{";
    // Algoritmo para lenguaje
    for(int n = 1; n <= N; n++)
    {
        // Generando cadenas
        int aux = n - 1;
        std::vector<char> cadena;

        while(aux > 0)
        {
            cadena.push_back('a');
            aux--;
        }
        if(cadena.empty())
        {
            std::cout<< 'C'; Archivo<< "C";
            continue;
        }

        while(!Terminar)
        {
            std::cout<< ", "; Archivo<< ", ";
            bool terminado = generarCadenas(Cadenas, cadena);
            Archivo<< Cadenas; Cadenas.clear();
            Terminar = terminado;
        }

        Terminar = false;
    }


    Archivo<< "}\n\n"; std::cout<< "}"<< std::endl;

    Archivo.close();
    *numeroEjecucion = *numeroEjecucion + 1;
}


void generarLenguaje_Aleatorio(unsigned int *numeroEjecucion)
{
    std::ofstream Archivo;
    std::string Cadenas;
    bool Terminar = false;

    // Crear un generador de números aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());

    // Definir el rango deseado
    std::uniform_int_distribution<> distribucion(1, 1000);

    // Generar un número aleatorio
    int N = distribucion(gen);


    Archivo.open("Lenguajes_generados.txt", std::ios::app);
    if(!Archivo.is_open()) EXIT_FAILURE;
    Archivo<< "Ejecucion "<< *numeroEjecucion<< ":"<< std::endl; Archivo<< "{";

    std::cout<< "\n{";

    // Algoritmo para generar el lenguaje
    for(int n = 1; n <= N; n++)
    {
        // Generando cadenas
        int aux = n - 1;
        std::vector<char> cadena;

        while(aux > 0)
        {
            cadena.push_back('a');
            aux--;
        }
        if(cadena.empty())
        {
            std::cout<< 'C'; Archivo<< "C";
            continue;
        }

        while(!Terminar)
        {
            std::cout<< ", "; Archivo<< ", ";
            bool terminado = generarCadenas(Cadenas, cadena);
            Archivo<< Cadenas; Cadenas.clear();
            Terminar = terminado;
        }

        Terminar = false;
    }


    Archivo<< "}\n\n"; std::cout<< "}"<< std::endl;

    Archivo.close();
    *numeroEjecucion = *numeroEjecucion + 1;
}


bool generarCadenas(std::string &resultado, std::vector<char> &cadena)
{
    bool Terminado = false;
    bool cambiar = true;

    // mostrando los simbolos contenidos en la cadena
    for(char simbolo: cadena) std::cout<< simbolo;

    // pasando la cadena por referencia para mostrarlo en el documento txt
    for(char simbolo: cadena)
    {
        resultado = resultado + simbolo;
    }


    for(short int i = cadena.size() - 1; i >= 0; i--)
    {
        char simbolo = cadena[i];
        if(simbolo == 'a')
        {
            cadena[i] = 'b';

            for(unsigned short int ii = i + 1; ii < cadena.size() && cambiar; ii++)
            {
                if(cadena[ii] != 'b')
                {
                    cambiar = false;
                }
            }

            if(cambiar && i < cadena.size() - 1)
            {
                for(unsigned short int ii = i + 1; ii < cadena.size(); ii++)
                {
                    cadena[ii] = 'a';
                }
            }

            Terminado = true;
            break;
        }

        Terminado = std::find(cadena.cbegin(), cadena.cend(), 'a') != cadena.cend();
    }

    return !Terminado;
}