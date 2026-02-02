cmake_minimum_required(VERSION 3.15)
project(chessMTUCI LANGUAGES CXX)

# Явно указываем управляемый код
set(CMAKE_CXX_CLR_TARGET_TYPE "NET")

# Находим все исходные файлы
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "src/*.h")

# Создаем Windows приложение
add_executable(${PROJECT_NAME} WIN32 ${SOURCES} ${HEADERS})

# Указываем, что это .NET приложение с управляемой точкой входа
set_target_properties(${PROJECT_NAME} PROPERTIES
    COMMON_LANGUAGE_RUNTIME "NET"
    VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.7.2"
    VS_DOTNET_REFERENCES "System;System.Windows.Forms;System.Drawing;System.Data"
)

# Настройки для MSVC
if(MSVC)
    # Флаги компиляции для C++/CLI
    target_compile_options(${PROJECT_NAME} PRIVATE
        /clr
        /EHsc
    )
    
    # Подключаем .NET сборки
    target_compile_options(${PROJECT_NAME} PRIVATE
        /FU"System.dll"
        /FU"System.Windows.Forms.dll"
        /FU"System.Drawing.dll"
        /FU"System.Data.dll"
    )
    
    # Ключевое: указываем управляемую точку входа
    set_target_properties(${PROJECT_NAME} PROPERTIES
        LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:main"
    )
endif()