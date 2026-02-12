#include <drogon/drogon.h>
#include <iostream>
#include "controllers/CalcolatoreController.h"

int main() {
    // CORRETTO: 0.0.0.0 permette a Render di vedere il server
    drogon::app().addListener("0.0.0.0", 8080);

    drogon::app().setThreadNum(4);

    // AGGIORNATO: Cambiamo anche qui per coerenza con i log di Render
    std::cout << "DEBUG: Server in fase di avvio su http://0.0.0.0:8080" << std::endl;

    drogon::app().run();
    return 0;
}