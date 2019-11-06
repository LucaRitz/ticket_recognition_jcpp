

if (LINUX_BUILD)
    include("${Ticket_Recognition_DIR}/linux/TicketRecognitionConfig.cmake")
else(LINUX_BUID)
    include("${Ticket_Recognition_DIR}/windows/TicketRecognitionConfig.cmake")
endif (LINUX_BUILD)