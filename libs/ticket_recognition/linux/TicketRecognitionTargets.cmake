add_library(ticket_recognition_lib SHARED IMPORTED)

set_property(TARGET ticket_recognition_lib PROPERTY IMPORTED_LOCATION "${Ticket_Recognition_DIR}/linux/bin/libticket_recognition_lib.so")