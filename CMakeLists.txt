cmake_minimum_required(VERSION 3.5)

project(Shopp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp



)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Shopp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        firstscreen.h firstscreen.cpp firstscreen.ui
        images.qrc
        user.h user.cpp user.ui
        Gender.h
        loginscreen.h loginscreen.cpp loginscreen.ui

        wallet.h wallet.cpp wallet.ui
        favorite.h favorite.cpp favorite.ui
        cartscreen.h cartscreen.cpp cartscreen.ui
        addresscreen.h addresscreen.cpp addresscreen.ui
        address.h address.cpp

        signupscreen.h signupscreen.cpp signupscreen.ui
        category.h category.cpp
        product.h product.cpp
        marketproduct.h marketproduct.cpp
        market.h market.cpp
        buysomethingscreen.h buysomethingscreen.cpp buysomethingscreen.ui
        creatingmarket.h creatingmarket.cpp



    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Shopp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Shopp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Shopp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Shopp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Shopp)
endif()
set_target_properties(Shopp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Shopp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Shopp)
endif()
