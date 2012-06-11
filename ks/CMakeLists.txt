set(ks_SRCS
    main.cpp
    test.cpp
)

add_executable(ks ${ks_SRCS})

target_link_libraries(ks
    ${QT_LIBRARIES} 
    ${QT_QTDBUS_LIBRARY} 
    urfkill-qt
)

install(TARGETS ks ${INSTALL_TARGETS_DEFAULT_ARGS})
