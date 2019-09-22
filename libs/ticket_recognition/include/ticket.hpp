#pragma once

#include "dllmacro.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace cti {
    class Text;
    class TicketImage;

    class Ticket {
    public:
        // TODO: maybe a vector of bounding boxes to be ignored in the matcher?
        // TODO: maybe a vector of bounding boxes to be used in the matcher to match on?
        Ticket(string name, TicketImage& image, vector<const Text>& texts) : name(name), image(image), texts(texts) {}
        Ticket(const Ticket& other) = delete;
        Ticket(Ticket&& other) = delete;
        Ticket& operator=(const Ticket& other) = delete;
        Ticket& operator=(Ticket&& other) = delete;

    private:
        const string name;
        const TicketImage& image;
        const vector<const Text>& texts;
    };

    // Auswertung pro version: Score für matching, Score für metadaten-extraktion


    // Sensitivität / Richtig-positiv-Rate / Empfindlichkeit / Trefferquote / Sensitivity / true positive rate / recall / hit rate
    // Anteil der korrekt als positiv klassifizierten Objekte an der Gesamtheit der tatsächlich positiven Objekte.
    // Anteil an tatsächlich zu erkennenden Tickets, welche auch erkannt wurden.
    // TP / (TP + FN)

    // Falsch-negativ-Rate / false negative rate / miss rate
    // Anteil der fälschlich als negativ klassifizierten Objekte an der Gesamtheit der tatsächlich positiven Objekte.
    // Anteil der fälschlicherweise nicht erkannten Tickets an der Gesamtheit der tatsächlich zu erkennenden Tickets.
    // FN / (TP + FN)


    // Spezifität / Richtig-negativ-Rate / kennzeichnende Eigenschaft / specificity / true negative rate / correct rejection rate
    // Anteil der korrekt als negativ klassifizierten Objekte an der Gesamtheit der in Wirklichkeit negativen Objekte.
    // Anteil der korrekterweise nicht erkannten Tickets an der Gesamtheit der tatsächlich nicht zu erkennenden Tickets.
    // TN / (TN + FP)

    // Falsch-positiv-Rate / Ausfallsrate / fallout / false positive rate
    // Anteil der fälschlich als positiv klassifizierten Objekte an, die in Wirklichkeit negativ sind.
    // Anteil der fälschlicherweise erkannten Tickets, welche in Wirklichkeit nicht zu erkennen sind.


    // Positiver Vorhersagewert / Relevanz / Wirksamkeit / Genauigkeit / precision / positive predictive value
    // Anteil der korrekt als positiv klassifizierten Ergenisse an der Gesamtheit der als positiv klassifizierten Ergebnisse.
    // Anteil der korrekterweise erkannten Tickets an der Gesamtheit der zu erkennenden Tickets.
    // TP / (TP + FP)

    // Negativer Vorhersagewert / Segreganz / Trennfähigkeit / negative predictive value
    // Anteil der korrekt als negativ klassifizierten Ergebnisse an der Gesamtheit der als negativ klassifizierten Ergebnisse.
    // Anteil der korrekterweise nicht erkannten Tickets an der Gesamtheit der nicht zu erkennenden Tickets.
    // TN / (TN + FN)


    // Vertrauenswahrscheinlichkeit / Treffergenauigkeit / accuracy
    // Anteil aller Objekte, welche korrekt klassifiziert wurden.
    // (TP + TN) / (TP + FP + TN + FN)


    // F1
    // Combines precision and recall
    // 2 * precision * recall / (precision + recall)

}
