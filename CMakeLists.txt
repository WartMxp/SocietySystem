cmake_minimum_required(VERSION 3.16)

project(SocietySystem VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 自行添加的适配
set(CMAKE_PREFIX_PATH "D:/Qt/6.9.0/mingw_64")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Sql)

set(PROJECT_SOURCES
        main.cpp
        Interface.cpp
        Interface.h
        Interface.ui
        SocietiesSql.cpp
        SocietiesSql.h
        Login.cpp
        Login.h
        Login.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SocietySystem
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Login.h Login.cpp Login.ui

        SocietiesSql.h SocietiesSql.cpp
        Regist.h Regist.cpp Regist.ui
        Struct.h
        Addstudent.h Addstudent.cpp Addstudent.ui
        Addsociety.h Addsociety.cpp Addsociety.ui
        Addactivity.h Addactivity.cpp Addactivity.ui

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SocietySystem APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SocietySystem SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SocietySystem
            ${PROJECT_SOURCES}
        )
    endif()
endif()
# 自行编译的段落
target_link_libraries(SocietySystem PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Sql
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SocietySystem)
endif()
set_target_properties(SocietySystem PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SocietySystem
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SocietySystem)
endif()
