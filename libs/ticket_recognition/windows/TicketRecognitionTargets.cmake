add_library(ticket_recognition_lib SHARED IMPORTED)

set_property(TARGET ticket_recognition_lib APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ticket_recognition_lib PROPERTIES
        IMPORTED_IMPLIB_DEBUG "${Ticket_Recognition_DIR}/windows/lib/ticket_recognition_lib.lib"
        IMPORTED_LOCATION_DEBUG "${Ticket_Recognition_DIR}/windows/bin/ticket_recognition_lib.dll"
        )