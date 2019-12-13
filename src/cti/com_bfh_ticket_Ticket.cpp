#include <com_bfh_ticket_Ticket.h>

#include <include/ticket.hpp>
#include <include/text.hpp>
#include <include/bounding_box.hpp>
#include <include/point.hpp>
#include <include/ticket_image.hpp>

using cti::Ticket;
using cti::Text;
using cti::BoundingBox;
using cti::Point;

/*
 * Class:     com_bfh_ticket_Ticket
 * Method:    delete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_bfh_ticket_Ticket_delete(JNIEnv* env, jobject object, jlong pointer) {
    auto* ticket = reinterpret_cast<Ticket*>(pointer);
    for (auto text : ticket->texts()) {
        delete &text->boundingBox();
        delete text;
    }
    delete &ticket->texts();
    delete ticket;
}