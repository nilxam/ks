set(ks_SRCS
    main.cpp
    test.cpp
)

kde4_add_executable(ks ${ks_SRCS})

target_link_libraries(ks ${KDE4_KDEUI_LIBS} ${LibUrfkillQt_LIBRARIES})

install(TARGETS ks ${INSTALL_TARGETS_DEFAULT_ARGS})
