target_sources(ticket_recognition_jcpp PUBLIC
        com_bfh_ticket_Matcher.cpp
        com_bfh_ticket_Ticket.cpp
        com_bfh_ticket_MetadataReader.cpp
        com_bfh_ticket_Metadata.cpp
        com_bfh_ticket_TicketMatch.cpp)

target_sources(ticket_recognition_jcpp PRIVATE
        helper.cpp)