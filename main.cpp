// #include <iostream>
// #include <vector>
// #include <cstdlib>

// using namespace std;
// // Definición de la clase Pieza
// class Ficha {
// public:
//     enum class Color { Blanco, Negro };

//     struct Pieza {
//         std::string codigo;
//         std::vector<std::pair<int, int>> movimientos;
//     };

//     static const std::unordered_map<char, Pieza> piezas;

//     static const Pieza& obtenerPieza(char tipo, Color color) {
//         char clave = std::tolower(tipo);
//         if (piezas.count(clave) > 0) {
//             const auto& pieza = piezas.at(clave);
//             return (color == Color::Blanco) ? pieza : invertirColor(pieza);
//         }
//         throw std::runtime_error("Pieza inválida");
//     }

// private:
//     static const Pieza& invertirColor(const Pieza& pieza) {
//         static Pieza piezaInvertida;
//         piezaInvertida.codigo = pieza.codigo;
//         piezaInvertida.movimientos.reserve(pieza.movimientos.size());
//         for (const auto& movimiento : pieza.movimientos) {
//             piezaInvertida.movimientos.emplace_back(-movimiento.first, -movimiento.second);
//         }
//         return piezaInvertida;
//     }
// };

// const std::unordered_map<char, Ficha::Pieza> Ficha::piezas = {
//     //blancas
//     {'p', {"\u265F", {{0, 1}}}},  // Peón
//     {'t', {"\u265C", {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}}},  // Torre
//     {'c', {"\u265E", {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}}}},  // Caballo
//     {'a', {"\u265D", {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}}},  // Alfil
//     {'r', {"\u265B", {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}}},  // Reina
//     {'R', {"\u265A", {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}}}  // Rey
// };

// const std::unordered_map<char, Ficha::Pieza> Ficha::piezas = {
//     //Negras
//     {'p', {"\u2659", {{0, 1}}}},  // Peón
//     {'t', {"\u2656", {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}}},  // Torre
//     {'c', {"\u2658", {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}}}},  // Caballo
//     {'a', {"\u2657", {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}}},  // Alfil
//     {'r', {"\u2655", {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}}},  // Reina
//     {'R', {"\u2654", {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}}}  // Rey
// };

// // Otras clases de piezas (Torre, Caballo, Alfil, etc.) se pueden implementar de manera similar

// // Definición de la clase Tablero
// class Tablero {
// public:
//     Tablero() {
//         // Inicializa el tablero con las piezas en su posición inicial
//         string blancas = "\u2588";
//         string negras = " ";
//         // Tablero base
//         string tabla[10][10] = {
//             {{" 8 "}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}},
//             {{" 7 "}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}},
//             {{" 6 "}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}},
//             {{" 5 "}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}},
//             {{" 4 "}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}},
//             {{" 3 "}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}},
//             {{" 2 "}, {"\u2659"}, {"\u2659"}, {"\u2659"}, {"\u2659"}, {"\u2659"}, {"\u2659"}, {"\u2659"}, {"\u2659"}},
//             {{" 1 "}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}},
//             {{"   "}, {" A "}, {" B "}, {" C "}, {" D "}, {" E "}, {" F "}, {" H "}, {" G "}},
//         };
//     }

//     void imprimir(string tabla[][]) const {

//         string blancas = "\u2588";
//         string negras = " ";
//         // Tablero base
//         string tabla[10][10] = {
//             {{" 8 "}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}},
//             {{" 7 "}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}},
//             {{" 6 "}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}},
//             {{" 5 "}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}},
//             {{" 4 "}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}},
//             {{" 3 "}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}},
//             {{" 2 "}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}},
//             {{" 1 "}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}},
//             {{"   "}, {" A "}, {" B "}, {" C "}, {" D "}, {" E "}, {" F "}, {" H "}, {" G "}},
//         };

//         // Imprimir las coordenadas
//         for (int i = 0; i < 9; ++i) {
//             for (int j = 0; j < 9; ++j) {
//                 // std::cout << "(" << coordenadas[i][j] << ") ";

//                 if (j == 0) {
//                     cout << tabla[i][j];
//                 } else if (i == 8) {
//                     cout << tabla[i][j];
//                 }

//                 if(i != 8 && j != 0){
//                     if (j % 2 == 0) {
//                         if (i % 2 != 0) {
//                             cout  << "\u2588" << tabla[i][j] << "\u2588";
//                         } else {
//                             cout << " " << " " << " ";
//                         }
//                     }
//                     else {
//                         if (i % 2 == 0) {
//                             cout << "\u2588" << tabla[i][j] << "\u2588";
//                         } else {
//                             cout << " " << " " << " ";
//                         }
//                     }
//                 }
//             }
//             std::cout << std::endl;
//         }
//     }

// private:
//     Pieza* tablero[8][8];
// };

// //////////////////////////////////////////////////////////////////////////////
// // Función para limpiar la pantalla en Windows
// void limpiarPantallaWindows() {
//     system("cls");
// }

// // Función para limpiar la pantalla en Linux y macOS
// void limpiarPantallaLinux() {
//     system("clear");
// }
// //////////////////////////////////////////////////////////////////////////////


// int main() {
//     Tablero tablero;
//     bool isWindows = false; // Cambia a true si estás en Windows

//     while (true) {
//         // Limpia la pantalla según el sistema operativo
//         if (isWindows) {
//             limpiarPantallaWindows();
//         } else {
//             limpiarPantallaLinux();
//         }

//         tablero.imprimir();

//         // Pausa para dar tiempo al jugador a ver el estado del tablero
//         cout << "Presiona Enter para continuar...";
//         cin.ignore(); // Espera a que se presione Enter
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>

using namespace std;

class Ficha {
public:
    enum class Color { Blanco, Negro };

    struct Pieza {
        std::string codigo;
        std::vector<std::pair<int, int>> movimientos;
    };

    static const std::unordered_map<char, Pieza> piezas;

    static const Pieza& obtenerPieza(char tipo, Color color) {
        char clave = std::tolower(tipo);
        if (piezas.count(clave) > 0) {
            const auto& pieza = piezas.at(clave);
            return (color == Color::Blanco) ? pieza : invertirColor(pieza);
        }
        throw std::runtime_error("Pieza inválida");
    }

private:
    static const Pieza& invertirColor(const Pieza& pieza) {
        static Pieza piezaInvertida;
        piezaInvertida.codigo = pieza.codigo;
        piezaInvertida.movimientos.reserve(pieza.movimientos.size());
        for (const auto& movimiento : pieza.movimientos) {
            piezaInvertida.movimientos.emplace_back(-movimiento.first, -movimiento.second);
        }
        return piezaInvertida;
    }
};

const std::unordered_map<char, Ficha::Pieza> Ficha::piezas = {
    //blancas
    {'p', {"\u2588\u265F\u2588", {{0, 1}}}},  // Peón
    {'t', {"\u2588\u265C\u2588", {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}}},  // Torre
    {'c', {"\u2588\u265E\u2588", {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}}}},  // Caballo
    {'a', {"\u2588\u265D\u2588", {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}}},  // Alfil
    {'r', {"\u2588\u265B\u2588", {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}}},  // Reina
    {'R', {"\u2588\u265A\u2588", {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}}},  // Rey

    //Negras
    {'P', {" \u2659 ", {{0, 1}}}},  // Peón
    {'T', {" \u2656 ", {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}}},  // Torre
    {'C', {" \u2658 ", {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}}}},  // Caballo
    {'A', {" \u2657 ", {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}}},  // Alfil
    {'RN', {" \u2655 ", {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}}},  // Reina
    {'RY', {" \u2654 ", {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}}}  // Rey
};

class Tablero {
public:
    Tablero() {}

    void imprimir() const {
        string blancas = "\u2588\u2588\u2588";
        string negras = "   ";
        // Tablero base
        string tabla[10][10] = {
            {{" 8 "}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}},
            {{" 7 "}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}},
            {{" 6 "}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}},
            {{" 5 "}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}},
            {{" 4 "}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}},
            {{" 3 "}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}},
            {{" 2 "}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}},
            {{" 1 "}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}},
            {{"   "}, {" a "}, {" b "}, {" c "}, {" d "}, {" e "}, {" f "}, {" g "}, {" h "}}
        };

        // string tabla[10][10] = {
        //     {{" 8 "}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}},
        //     {{" 7 "}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}},
        //     {{" 6 "}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}},
        //     {{" 5 "}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}},
        //     {{" 4 "}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}},
        //     {{" 3 "}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}},
        //     {{" 2 "}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}},
        //     {{" 1 "}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}, {negras}, {blancas}},
        //     {{"   "}, {" a "}, {" b "}, {" c "}, {" d "}, {" e "}, {" f "}, {" g "}, {" h "}}
        // };

        // Colocar piezas en el tablero
    //     for (const auto& [posicion, ficha] : piezas_) {
    //         int fila = 8 - (posicion / 10);
    //         int columna = posicion % 10;
    //         tabla[fila][columna] = ficha;
    //     }

    //     // Imprimir el tablero
    //     for (int fila = 0; fila < 10; ++fila) {
    //         for (int columna = 0; columna < 10; ++columna) {
    //             cout << tabla[fila][columna];
    //         }
    //         cout << endl;
    //     }
    // }
        // Colocar las piezas blancas
    tabla[1][1] = Ficha::piezas.at('t').Pieza;
    tabla[1][2] = Ficha::piezas.at('c').Pieza;
    tabla[1][3] = Ficha::piezas.at('a').Pieza;
    tabla[1][4] = Ficha::piezas.at('r').Pieza;
    tabla[1][5] = Ficha::piezas.at('R').Pieza;
    tabla[1][6] = Ficha::piezas.at('a').Pieza;
    tabla[1][7] = Ficha::piezas.at('c').Pieza;
    tabla[1][8] = Ficha::piezas.at('t').Pieza;
    for (int i = 1; i <= 8; i++) {
        tabla[2][i] = Ficha::piezas.at('p').Pieza;
    }
    
    // Colocar las piezas negras
    tabla[8][1] = Ficha::piezas.at('T').Pieza;
    tabla[8][2] = Ficha::piezas.at('C').Pieza;
    tabla[8][3] = Ficha::piezas.at('A').Pieza;
    tabla[8][4] = Ficha::piezas.at('RN').Pieza;
    tabla[8][5] = Ficha::piezas.at('RY').Pieza;
    tabla[8][6] = Ficha::piezas.at('A').Pieza;
    tabla[8][7] = Ficha::piezas.at('C').Pieza;
    tabla[8][8] = Ficha::piezas.at('T').Pieza;
    for (int i = 1; i <= 8; i++) {
        tabla[7][i] = Ficha::piezas.at('P').Pieza;
    }
    
    // Imprimir tablero
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << tabla[i][j];
        }
        std::cout << std::endl;
    }
}

private:
    std::unordered_map<int, std::string> piezas_;
};

int main() {
    Tablero tablero;
    tablero.imprimir();

    return 0;
}