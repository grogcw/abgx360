cmake_minimum_required(VERSION 3.21)
project(abgx360gui)

# Detect the operating system and adjust wxWidgets toolkit accordingly
if(WIN32)
    # Use the native MSW toolkit on Windows
    set(wxWidgets_CONFIG_OPTIONS --toolkit=msw)
elseif(APPLE)
    # Use Cocoa on macOS
    set(wxWidgets_CONFIG_OPTIONS --toolkit=osx_cocoa)
else()
    # Default to GTK3 on Linux/Unix
    set(wxWidgets_CONFIG_OPTIONS --toolkit=gtk3)
endif()

set(CMAKE_CXX_STANDARD 23)

include(CMakeRC.cmake)
cmrc_add_resource_library(foo-resources
        ALIAS foo::rc
        NAMESPACE foo
        abgx360gui/src/Images/logo_reloaded.png)

# Include source directory
include_directories(abgx360gui/src)
# Find wxWidgets
# Note that for MinGW users the order of libs is important!
# Require at least wxWidgets 3 for better compatibility
find_package(wxWidgets 3 REQUIRED net gl core base adv)
include(${wxWidgets_USE_FILE})

# Add executable
add_executable(abgx360gui
        abgx360gui/src/abgx360gui.cpp
        abgx360gui/src/abgx360gui.h
        abgx360gui/src/abgx360guiApp.cpp
        abgx360gui/src/abgx360guiApp.h)

# Link wxWidgets deps
# and for each of your dependent executable/library targets:
target_link_libraries(abgx360gui PRIVATE ${wxWidgets_LIBRARIES})
# Link resources
target_link_libraries(abgx360gui PRIVATE foo::rc)
