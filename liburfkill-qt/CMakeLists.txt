#Set the correct compiler options
IF(CMAKE_SIZEOF_VOID_P EQUAL 4)
   # 32 bit
   MESSAGE(STATUS "Detected that you use a 32 bit processor.")
ELSE(CMAKE_SIZEOF_VOID_P EQUAL 4)
   # 64 bit (well, anything else than 32 bit, but someone use something else than 32 or 64 bit ?)
   set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
   MESSAGE(STATUS "Detected that you use a 64 bit processor. Added -fPIC to the CXX_FLAGS.")
ENDIF(CMAKE_SIZEOF_VOID_P EQUAL 4)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${CMAKE_CURRENT_BINARY_DIR} 
    ${QT_QTCORE_INCLUDE_DIR} 
    ${QT_QTDBUS_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/liburfkill-qt
)

set(liburfkill_qt_SRCS
    client.cpp
    device.cpp
    killswitch.cpp
)

set(liburfkill_qt_HDRS 
    urfkill.h 
    enum.h 
    client.h 
    device.h 
    killswitch.h
)

set(liburfkill_qt_MOCS 
    client.h 
    device.h 
    killswitch.h
)

QT4_WRAP_CPP(MOCS ${liburfkill_qt_MOCS})

add_library(urfkill-qt SHARED ${liburfkill_qt_SRCS} ${MOCS})

target_link_libraries(urfkill-qt ${QT_QTCORE_LIBRARY} ${QT_QTDBUS_LIBRARY})

install(TARGETS urfkill-qt DESTINATION ${LIB_INSTALL_DIR})

install(FILES ${liburfkill_qt_HDRS} DESTINATION include/liburfkill-qt)
