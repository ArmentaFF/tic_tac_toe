#include <iostream>
#include <cstdlib>   // Para limpiar la pantalla
using namespace std;

// Mostrar el tablero
void mostrarTablero(char tablero[3][3]) {
    cout << "\n";
    cout << " " << tablero[0][0] << " | " << tablero[0][1] << " | " << tablero[0][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << tablero[1][0] << " | " << tablero[1][1] << " | " << tablero[1][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << tablero[2][0] << " | " << tablero[2][1] << " | " << tablero[2][2] << "\n\n";
}

// Verificación si hay un ganador 
bool verificarGanador(char tablero[3][3], char simbolo) {
    // Filas y columnas
    for (int i = 0; i < 3; i++) {
        if ((tablero[i][0] == simbolo && tablero[i][1] == simbolo && tablero[i][2] == simbolo) ||
            (tablero[0][i] == simbolo && tablero[1][i] == simbolo && tablero[2][i] == simbolo))
            return true;
    }

    // Diagonales
    if ((tablero[0][0] == simbolo && tablero[1][1] == simbolo && tablero[2][2] == simbolo) ||
        (tablero[0][2] == simbolo && tablero[1][1] == simbolo && tablero[2][0] == simbolo))
        return true;

    return false;
}

// Iniciar juego 
void jugarPartida() {
    char tablero[3][3];
    int turno;
    char simbolo;
    int posicion;
    bool fin;

    do {  
        // Asignar números a casillas del 1-9
        char num = '1';
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                tablero[i][j] = num++;

        turno = 1;
        fin = false;

        // Ciclo para el juego
        while (!fin) {
            system("clear");
            mostrarTablero(tablero);

            simbolo = (turno == 1) ? 'X' : 'O';
            cout << "Turno del jugador " << turno << " (" << simbolo << ")\n";
            cout << "Elige una posicion (1-9): ";
            cin >> posicion;

            // Validación
            while (posicion < 1 || posicion > 9) {
                cout << "Posicion invalida. Ingresa un numero del 1 al 9: ";
                cin >> posicion;
            }

            int fila = (posicion - 1) / 3;
            int columna = (posicion - 1) % 3;

            // Casilla ocupada
            if (tablero[fila][columna] == 'X' || tablero[fila][columna] == 'O') {
                cout << "Casilla ocupada. Presiona Enter para continuar...";
                cin.ignore();
                cin.get();
                continue; //Para que el jugador no pierda su turno
            }
            
            tablero[fila][columna] = simbolo;

            // Verificar ganador
            if (verificarGanador(tablero, simbolo)) {
                system("clear");
                mostrarTablero(tablero);
                cout << "¡Jugador " << turno << " (" << simbolo << ") gana!\n";
                fin = true;
            } else {
                // Verificar empate
                bool lleno = true;
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        if (tablero[i][j] != 'X' && tablero[i][j] != 'O')
                            lleno = false;

                if (lleno) {
                    system("clear");
                    mostrarTablero(tablero);
                    cout << "Empate. No quedan mas movimientos.\n";
                    fin = true;
                }
            }

            turno = (turno == 1) ? 2 : 1;
        }

        // Preguntar si se quiere jugar otra vez
        char respuesta;
        do {
            cout << "\n¿Deseas jugar de nuevo? (s/n): ";
            cin >> respuesta;
            respuesta = (respuesta == 'S') ? 's' : respuesta;
        } while (respuesta != 's' && respuesta != 'n');

        if (respuesta == 'n')
            break;

    } while (true); //Reinicia la partida
}

// Programa principal
int main() {
    int opcion;

    do {
        system("clear");
        cout << "===== MENU PRINCIPAL =====\n";
        cout << "1. Iniciar juego\n";
        cout << "2. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        // Validación rudimentaria
        while (opcion < 1 || opcion > 2) {
            cout << "Opcion invalida. Ingresa 1 o 2: ";
            cin >> opcion;
        }

        if (opcion == 1)
            jugarPartida();
        else if (opcion == 2)
            cout << "\nSaliendo del programa...\n";

    } while (opcion != 2);

    return 0;
}