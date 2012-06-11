include_directories(
    ${CMAKE_SOURCE_DIR} 
    ${CMAKE_CURRENT_BINARY_DIR} 
    ${QT_QTCORE_INCLUDE_DIR} 
    ${QT_QTGUI_INCLUDE_DIR} 
    ${QT_QTDBUS_INCLUDE_DIR} 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/liburfkill-qt
)

set(ks_SRCS
    main.cpp
    test.cpp
)

set(ks_HDRS 
    test.h
)

set(ks_MOCS 
    test.h
)

QT4_WRAP_CPP(MOCS ${ks_MOCS})

add_executable(ks ${ks_SRCS} ${MOCS})

target_link_libraries(ks
    ${QT_QTCORE_LIBRARY} 
    ${QT_QTGUI_LIBRARY} 
    ${QT_QTDBUS_LIBRARY} 
    urfkill-qt
)

install(TARGETS ks RUNTIME DESTINATION bin)
