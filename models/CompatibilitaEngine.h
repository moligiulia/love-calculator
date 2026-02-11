#pragma once 
#include <string> 
#include <algorithm> 
#include <cmath> 

class CompatibilitaEngine {
private:
    // Converte il testo in minuscolo per rendere i calcoli stabili
    static std::string toLower(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

public:
    static double calcola(std::string n1, std::string n2) {
        if (n1.empty() || n2.empty()) return 0.0;

        std::string s1 = toLower(n1);
        std::string s2 = toLower(n2);

        // --- SEZIONE 1: LE TUE ECCEZIONI (Priorità Assoluta) ---

        // Casi Speciali (1.000.000%)
        if ((s1 == "iris" && s2 == "edoardo") || (s1 == "edoardo" && s2 == "iris") ||
            (s1 == "emma" && s2 == "giorgia") || (s1 == "giorgia" && s2 == "emma") ||
            (s1 == "giulia" && s2 == "jilari") || (s1 == "jilari" && s2 == "giulia") ||
            (s1 == "giulia" && s2 == "emma") || (s1 == "emma" && s2 == "giulia") ||
            (s1 == "giulia" && s2 == "beatrice") || (s1 == "beatrice" && s2 == "giulia") ||
            (s1 == "giulia" && s2 == "benedetta") || (s1 == "benedetta" && s2 == "giulia") ||
            (s1 == "giulia" && s2 == "chiara") || (s1 == "chiara" && s2 == "giulia") ||
            (s1 == "giulia" && s2 == "iris") || (s1 == "iris" && s2 == "giulia") ||
            (s1 == "giulia" && s2 == "anna") || (s1 == "anna" && s2 == "giulia") ||
            (s1 == "giulia" && s2 == "viola") || (s1 == "viola" && s2 == "giulia") ||
            (s1 == "giulia" && s2 == "rebecca") || (s1 == "rebecca" && s2 == "giulia")) {
            return 1000000.0;
        }

        // Casi da 0%
        if ((s1 == "jilari" && s2 == "edoardo") || (s1 == "edoardo" && s2 == "jilari") ||
            (s1 == "jilari" && s2 == "robert") || (s1 == "robert" && s2 == "jilari") ||
            (s1 == "benedetta" && s2 == "riccardo") || (s1 == "riccardo" && s2 == "benedetta")) {
            return 0.0;
        }

        // Casi da 30%
        if ((s1 == "beatrice" && s2 == "david") || (s1 == "david" && s2 == "beatrice") ||
            (s1 == "chiara" && s2 == "mattia") || (s1 == "mattia" && s2 == "chiara")) {
            return 30.0;
        }

        // --- SEZIONE 2: NUOVO ALGORITMO "TURBO" (Gamma ampia 1-99%) ---

        // Uniamo i nomi in ordine alfabetico per garantire che A+B dia lo stesso risultato di B+A
        std::string combinata = (s1 < s2) ? (s1 + s2) : (s2 + s1);

        // Creiamo un hash (un numero unico basato sulle lettere)
        unsigned long long hash = 5381;
        for (char c : combinata) {
            // Formula matematica per "mischiare" i caratteri in modo imprevedibile
            hash = ((hash << 5) + hash) + c;
        }

        // Trasformiamo l'hash in un punteggio tra 1 e 99
        double punteggioBase = (hash % 99) + 1;

        // Piccola correzione "logica": se le iniziali sono uguali, diamo un piccolo bonus
        if (s1[0] == s2[0]) punteggioBase += 7;

        // Usiamo clamp per assicurarci di non toccare mai lo 0 o il 100 
        // (che sono riservati alle tue eccezioni sopra)
        return std::clamp(punteggioBase, 1.0, 99.0);
    }
};