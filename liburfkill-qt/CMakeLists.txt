#Set the correct compiler options
IF(CMAKE_SIZEOF_VOID_P EQUAL 4)
   # 32 bit
   MESSAGE(STATUS "Detected that you use a 32 bit processor.")
ELSE(CMAKE_SIZEOF_VOID_P EQUAL 4)
   # 64 bit (well, anything else than 32 bit, but someone use something else than 32 or 64 bit ?)
   set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
   MESSAGE(STATUS "Detected that you use a 64 bit processor. Added -fPIC to the CXX_FLAGS.")
ENDIF(CMAKE_SIZEOF_VOID_P EQUAL 4)

include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${QT_INCLUDES})

set(liburfkill_qt_SRCS
    client.cpp
    device.cpp
    killswitch.cpp
)

QT4_AUTOMOC(${liburfkill_qt_SRCS})

add_library(urfkill-qt SHARED ${liburfkill_qt_SRCS})

target_link_libraries(urfkill-qt ${QT_QTCORE_LIBRARY} ${QT_QTDBUS_LIBRARY})

install(TARGETS urfkill-qt DESTINATION ${LIB_INSTALL_DIR})

install(FILES urfkill.h
    client.h
    device.h
    killswitch.h
    enum.h 
    DESTINATION 
    include/liburfkill-qt COMPONENT Devel)
