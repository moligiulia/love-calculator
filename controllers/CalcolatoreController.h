#pragma once
#include <drogon/HttpController.h>
#include "../models/CompatibilitaEngine.h"

using namespace drogon;

class CalcolatoreController : public HttpController<CalcolatoreController> {
public:
    METHOD_LIST_BEGIN
        ADD_METHOD_TO(CalcolatoreController::getCompatibilita, "/calcola", Get);
    METHOD_LIST_END

        void getCompatibilita(const HttpRequestPtr& req,
            std::function<void(const HttpResponsePtr&)>&& callback)
    {
        std::string nome1 = req->getParameter("n1");
        std::string nome2 = req->getParameter("n2");

        // 1. Chiamiamo il motore di calcolo
        double punteggioGrezzo = CompatibilitaEngine::calcola(nome1, nome2);
        int punteggioIntero = static_cast<int>(punteggioGrezzo); // Rimuove i decimali

        // 2. Creiamo l'oggetto JSON
        Json::Value ret;
        ret["risultato"] = "success";
        ret["punteggio"] = punteggioIntero;

        // --- CONTROLLO MESSAGGI  ---
        if (punteggioIntero >= 1000000) { 
            ret["messaggio"] = "Violentatevi(mi).";
        }
        else if (punteggioIntero == 30) {
            ret["messaggio"] = "Vorrei scoparti io ma 30 punti solo visto che il frocio mi sta minimamente simpatico.";
        }
        else if (punteggioIntero == 0) {
            ret["messaggio"] = "Ti vedo sai? Smettila meriti moooooooooolto di meglio.";
        }
        else if (punteggioIntero >= 75) {
            ret["messaggio"] = "Non aspettate altro che stuprarvi a vicenda.";
        }
        else if (punteggioIntero >= 50) {
            ret["messaggio"] = "Gne, non perfetti ma una botta non si schifa.";
        }
        else if (punteggioIntero >= 25) {
            ret["messaggio"] = "Decente ma ti andrebbe meglio su PornHub.";
        }
        else {
            ret["messaggio"] = "Amo nessuna speranza proprio, fatti me piuttosto.";
        }

        auto res = HttpResponse::newHttpJsonResponse(ret);
        res->addHeader("Access-Control-Allow-Origin", "*");
        callback(res);
    }
};