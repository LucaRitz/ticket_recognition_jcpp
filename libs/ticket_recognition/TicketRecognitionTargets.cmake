add_library(ticket_recognition_lib SHARED IMPORTED)

set_property(TARGET ticket_recognition_lib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ticket_recognition_lib PROPERTIES
        IMPORTED_IMPLIB_RELEASE "${Ticket_Recognition_DIR}/lib/ticket_recognition_lib.lib"
        IMPORTED_LOCATION_RELEASE "${Ticket_Recognition_DIR}/bin/ticket_recognition_lib.dll"
        )