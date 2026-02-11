#include <drogon/drogon.h>
#include <iostream>  // <--- Fondamentale per risolvere l'errore su cout e endl
#include "controllers/CalcolatoreController.h"

int main() {
    // Risolviamo l'errore C2653: ora il compilatore sa cos'è 'drogon'
    drogon::app().addListener("127.0.0.1", 8080);

    drogon::app().setThreadNum(4);

    // Risolviamo l'errore C2039: std::cout ora è riconosciuto grazie a <iostream>
    std::cout << "DEBUG: Server in fase di avvio su http://127.0.0.1:8080" << std::endl;

    drogon::app().run();
    return 0;
}