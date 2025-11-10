cmake_minimum_required(VERSION 3.19)
project(Calculator LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Qml)

qt_standard_project_setup()

qt_add_resources(RESOURCES resources.qrc)

qt_add_executable(Calculator
    WIN32 MACOSX_BUNDLE

    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    main.cpp
    ${RESOURCES}

)

target_link_libraries(Calculator
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Qml
)

include(GNUInstallDirs)

install(TARGETS Calculator
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Calculator
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
