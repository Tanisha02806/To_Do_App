cmake_minimum_required(VERSION 3.19)
project(ToDoList LANGUAGES CXX)

# Find required Qt 6 modules
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Multimedia MultimediaWidgets)


# Apply standard Qt setup (includes C++ standard, MOC, etc.)
qt_standard_project_setup()

# Add the main executable
qt_add_executable(ToDoList
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

# Link Qt libraries
target_link_libraries(ToDoList
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Multimedia
        Qt::MultimediaWidgets
)

# Installation rules
include(GNUInstallDirs)

install(TARGETS ToDoList
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Deployment script generation
qt_generate_deploy_app_script(
    TARGET ToDoList
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
