#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*Leer datos*/
void leerDatos(int &victoriaJugador, int &victoriaIA)
{
    ifstream archivo("piedra_papel_tijera.txt");
    if (archivo.is_open())
    {
        archivo >> victoriaJugador;
        archivo >> victoriaIA;
        archivo.close();
    }
    else
    {
        /*Si el archivo no existe*/
        victoriaJugador = 0;
        victoriaIA = 0;
    }
}

/*Guardar datos*/
void guardarDatos(int victoriaJugador, int victoriaIA)
{
    ofstream archivo("piedra_papel_tijera.txt");
    if (archivo.is_open())
    {
        archivo << victoriaJugador << "\n";
        archivo << victoriaIA << "\n";
        archivo.close();
    }
    else
    {
        std::cout << "No se puede abrir el archivo para guardad datos" << std::endl;
    }
}

/*Dificultades*/
void dificultadFacil(string opcion, int &victoriaJugador, int &victoriaIA)
{
    /*Dificultad fácil: 75% ganar, 20% empate, 5% perder*/
    int eleccionIA = rand() % 100;

    if (eleccionIA <= 75) /*Victoria del Jugador*/
    {
        if (opcion == "tijera")
        {
            std::cout << "Tú: " << opcion << std::endl;
            std::cout << "IA: papel" << std::endl;
            std::cout << "¡Tú ganas!";

            /*Guardar la victoria*/
            victoriaJugador++;
        }
        else if (opcion == "papel")
        {
            std::cout << "Tú: " << opcion << std::endl;
            std::cout << "IA: piedra" << std::endl;
            std::cout << "¡Tú ganas!";

            /*Guardar la victoria*/
            victoriaJugador++;
        }
        else
        {
            std::cout << "Tú: " << opcion << std::endl;
            std::cout << "IA: tijera" << std::endl;
            std::cout << "¡Tú ganas!";

            /*Guardar la victoria*/
            victoriaJugador++;
        }
    }
    else if (eleccionIA <= 95) /*Empates*/
    {
        if (opcion == "piedra")
        {
            std::cout << "Tú: " << opcion << std::endl;
            std::cout << "IA: piedra" << std::endl;
            std::cout << "¡Empate!";
        }
        else if (opcion == "papel")
        {
            std::cout << "Tú: " << opcion << std::endl;
            std::cout << "IA: papel" << std::endl;
            std::cout << "¡Empate!";
        }
        else {
            std::cout << "Tú: " << opcion << std::endl;
            std::cout << "IA: tijera" << std::endl;
            std::cout << "¡Empate!";
        }
    }
    else /*Victoria IA*/
    {
        if (opcion == "tijera")
        {
            std::cout << "Tú: " << opcion << std::endl;
            std::cout << "IA: piedra" << std::endl;
            std::cout << "¡IA gana!";

            /*Guardar la victoria*/
            victoriaIA++;
        }
        else if (opcion == "papel")
        {
            std::cout << "Tú: " << opcion << std::endl;
            std::cout << "IA: tijera" << std::endl;
            std::cout << "¡IA gana!";

            /*Guardar la victoria*/
            victoriaIA++;
        }
        else
        {
            std::cout << "Tú: " << opcion << std::endl;
            std::cout << "IA: papel" << std::endl;
            std::cout << "¡IA gana!";

            /*Guardar la victoria*/
            victoriaIA++;
        }
    }
}

void dificultadMedia(string opcion, int &victoriaJugador, int &victoriaIA)
{
    /*33.33% en los tres casos, creamos un array y la opción de la IA*/
    int eleccionIA = rand() % 3;

    string opcionesIA[3] = {"piedra", "papel", "tijera"};
    string eleccionIATexto = opcionesIA[eleccionIA];

    /*Comparar elección IA con la elección del jugador*/
    if (eleccionIATexto == opcion)
    {
        std::cout << "Tú: " << opcion << std::endl;
        std::cout << "IA: " << eleccionIATexto << std::endl;
        std::cout << "¡Empate!" << std::endl;
    }
    else if ((eleccionIATexto == "piedra" && opcion == "tijera") ||
             (eleccionIATexto == "papel" && opcion == "piedra") ||
             (eleccionIATexto == "tijera" && opcion == "papel"))
    {
        std::cout << "Tú: " << opcion << std::endl;
        std::cout << "IA: " << eleccionIATexto << std::endl;
        std::cout << "¡IA gana!" << std::endl;

        /*Guardar la victoria*/
        victoriaIA++;
        guardarDatos(victoriaJugador, victoriaIA);
    }
    else
    {
        std::cout << "Tú: " << opcion << std::endl;
        std::cout << "IA: " << eleccionIATexto << std::endl;
        std::cout << "¡Tú ganas!" << std::endl;

        /*Guardar la victoria*/
        victoriaJugador++;
        guardarDatos(victoriaJugador, victoriaIA);
    }
}

void dificultadDificil(string opcion, int &victoriaJugador, int &victoriaIA)
{
    /*Dificultad difícil: 5% ganar, 20% empate, 75% perder*/
    int eleccionIA = rand() % 100;

    /*Victoria del Jugador*/
    if (eleccionIA <= 3)
    {
        std::cout << "Tú: " << opcion << std::endl;
        std::cout << "IA: tijera" << std::endl;
        std::cout << "¡Tú ganas!" << std::endl;

        /*Guardar la victoria*/
        victoriaJugador++;
        guardarDatos(victoriaJugador, victoriaIA);
    }
    else
    {
        /*Empates*/
        string opcionesIA[2] = {"piedra", "papel"};
        string eleccionIATexto = opcionesIA[rand() % 2]; /*Elecciones al azar*/

        /*Victoria de la IA*/
        if (eleccionIATexto == opcion)
        {
            std::cout << "Tú: " << opcion << std::endl;
            std::cout << "IA: " << eleccionIATexto << std::endl;
            std::cout << "¡Empate!" << std::endl;
        }
        else if ((eleccionIATexto == "piedra" && opcion == "tijera") ||
                 (eleccionIATexto == "papel" && opcion == "piedra") ||
                 (eleccionIATexto == "tijera" && opcion == "papel"))
        {
            std::cout << "Tú: " << opcion << std::endl;
            std::cout << "IA: " << eleccionIATexto << std::endl;
            std::cout << "¡IA gana!" << std::endl;

            /*Guardar la victoria*/
            victoriaIA++;
            guardarDatos(victoriaJugador, victoriaIA);
        }
        else /*Victoria del jugador*/
        {
            std::cout << "Tú: " << opcion << std::endl;
            std::cout << "IA: " << eleccionIATexto << std::endl;
            std::cout << "¡Tú ganas!" << std::endl;

            /*Guardar la victoria*/
            victoriaJugador++;
            guardarDatos(victoriaJugador, victoriaIA);
        }
    }
}

int main()
{
    /*Inicializar el generador de números aleatorios con el tiempo actual*/
    srand(time(0));

    /*Variables*/
   bool salir = false;
   int victoriaJugador, victoriaIA;
   string opcion;

    while (!salir)
    {
        /*Leer datos, otra vez*/
        leerDatos(victoriaJugador, victoriaIA);

        /* Elegir dificultad*/
        int dificultad;

        std::cout << "Eliga una dificultad:" << std::endl;
        std::cout << "1 → Fácil" << std::endl;
        std::cout << "2 → Medio" << std::endl;
        std::cout << "3 → Difícil" << std::endl;
        std::cout << "4 → Imposible" << std::endl;
        std::cout << "5 → Abandonar aplicación" << std::endl;
        std::cout << "Elige → ";
        std::cin >> dificultad;

        switch (dificultad)
        {
        case 1: /*Fácil*/
            std::cout << "Piedra" << std::endl;
            std::cout << "Papel" << std::endl;
            std::cout << "Tijera" << std::endl;
            std::cout << "¿Tu opcion? → ";
            std::cin >> opcion;

            /*Nos aseguramos que "opcion" esta en minusculas*/
            for (char &c : opcion)
            {
                c = tolower(c);
            }

            /*Llamamos a la dificultad*/
            dificultadFacil(opcion, victoriaJugador, victoriaIA);
            break;

        case 2:/*Medio*/
            std::cout << "Piedra" << std::endl;
            std::cout << "Papel" << std::endl;
            std::cout << "Tijera" << std::endl;
            std::cout << "¿Tu opción? → ";
            std::cin >> opcion;

            /*Nos aseguramos que "opcion" esta en minusculas*/
            for (char &c : opcion)
            {
                c = tolower(c);
            }

            /*Llamamos a la dificultad*/
            dificultadMedia(opcion, victoriaJugador, victoriaIA);
            break;

        case 3: /*Díficil*/
            std::cout << "Piedra" << std::endl;
            std::cout << "Papel" << std::endl;
            std::cout << "Tijera" << std::endl;
            std::cout << "¿Tu opción? → ";
            std::cin >> opcion;

            /*Nos aseguramos que "opcion" esta en minusculas*/
            for (char &c : opcion)
            {
                c = tolower(c);
            }

            /*Llamamos a la dificultad*/
            dificultadDificil(opcion, victoriaJugador, victoriaIA);
            break;
        
        case 4: /*Imposible*/
            std::cout << "Piedra" << std::endl;
            std::cout << "Papel" << std::endl;
            std::cout << "Tijera" << std::endl;
            std::cout << "¿Tu opción? → ";
            std::cin >> opcion;

            /*Nos aseguramos que "opcion" esta en minusculas*/
            for (char &c : opcion)
            {
                c = tolower(c);
            }

            /*Vamos a hacer que el jugador no pueda ganar*/
            if (opcion == "piedra")
            {
                std::cout << "Tú: " << opcion << std::endl;
                std::cout << "IA: papel" << std::endl;
                std::cout << "¡IA gana!" << std::endl;

                /*Guardar la victoria*/
                victoriaIA++;
                guardarDatos(victoriaJugador, victoriaIA);

            }
            else if (opcion == "papel")
            {
                std::cout << "Tú: " << opcion << std::endl;
                std::cout << "IA: tijera" << std::endl;
                std::cout << "¡Ia gana!" << std::endl;

                /*Guardar la victoria*/
                victoriaIA++;
                guardarDatos(victoriaJugador, victoriaIA);

            }
            else if (opcion == "tijera")
            {
                std::cout << "Tú: " << opcion << std::endl;
                std::cout << "IA: piedra" << std::endl;
                std::cout << "¡IA gana!" << std::endl;

                /*Guardar victoria*/
                victoriaIA++;
                guardarDatos(victoriaJugador, victoriaIA);

            }
            else
            {
                std::cout << "Opción no valida. Por favor, ingrese: 'pieda', 'papel' o 'tijera'" << std::endl;
            }
            break;

        case 5: /*Salir*/
            std::cout << "\nCerrando aplicación" << std::endl;
            salir = true;
            break;
        
        default:
            std::cout << "Número erroneo. Por favor, ingrese: '1', '2', '3' o '4'" << std::endl;
            break;
        }
        break;
    
    /*Resultados de las partidas*/
    std::cout << "\nResultados finales: " << std::endl;
    std::cout << "Tus victorias: " << victoriaJugador << std::endl;
    std::cout << "Victorias IA: " << victoriaIA << std::endl;
    
    }
   return 0;
}