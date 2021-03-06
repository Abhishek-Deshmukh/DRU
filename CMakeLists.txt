#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 3.8...3.18)
if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif ()
set(CMAKE_CXX_STANDARD 14) # Works in recent cmakes
project(DRU)
add_compile_options(-fdiagnostics-color=always)
#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if (WITH_GEANT4_UIVIS)
    find_package(Geant4 REQUIRED ui_all vis_all)
else ()
    find_package(Geant4 REQUIRED)
endif ()

#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
# Setup include directory for this project
#
include(${Geant4_USE_FILE})

add_library(geant_lib INTERFACE)
target_include_directories(geant_lib INTERFACE ${Geant4_INCLUDE_DIRS})
target_compile_options(geant_lib INTERFACE ${Geant4_DEFINITIONS})
target_compile_definitions(geant_lib INTERFACE G4USE_STD11)
target_link_libraries(geant_lib INTERFACE ${Geant4_LIBRARIES})


#----------------------------------------------------------------------------
# Find ROOT (required package)
find_package(ROOT REQUIRED)

add_library(root_lib INTERFACE)
target_include_directories(root_lib INTERFACE ${ROOT_INCLUDE_DIRS})
target_compile_options(root_lib INTERFACE ${ROOT_DEFINITIONS})
target_link_libraries(root_lib INTERFACE ${ROOT_LIBRARIES})

#----------------------------------------------------------------------------
# Find CRY
add_library(CRY INTERFACE)
# target_include_directories(CRY INTERFACE /home/mercury/downloads/CRY/cry_v1.7/src)
target_include_directories(CRY INTERFACE $ENV{CRY_path}/src)

#----------------------------------------------------------------------------
# Locate sources and headers for this project
# NB: headers are included so they will show up in IDEs
#
include_directories(${PROJECT_SOURCE_DIR}/include
        ${Geant4_INCLUDE_DIR}
        ${ROOT_INCLUDE_DIRS})
# file(GLOB cry_sources /home/mercury/downloads/CRY/cry_v1.7/src/*)
file(GLOB cry_sources $ENV{CRY_path}/src/*)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_library(main_lib ${cry_sources} ${sources} ${headers})
target_include_directories(main_lib PUBLIC include)
target_link_libraries(main_lib root_lib geant_lib CRY)

#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
#
add_executable(DRU DRU.cc)
target_link_libraries(DRU PUBLIC main_lib)

#----------------------------------------------------------------------------
# Copy all scripts to the build directory, i.e. the directory in which we
# build DRU. This is so that we can run the executable directly because it
# relies on these scripts being in the current working directory.
#
set(DRU_SCRIPTS
        # DRU.in
        # DRU.out
        init_vis.mac
        run1.mac
        run2.mac
        vis.mac
        # CRY_file
        ./objs/Donut.obj
        ./objs/Coin.obj
        ./objs/InnerHousing.obj
        ./objs/OuterHousing.obj
        ./SNOLABBackgrounds/total-gamma.dat
        ./multi.sh
        )

foreach (_script ${DRU_SCRIPTS})
    configure_file(
            ${PROJECT_SOURCE_DIR}/${_script}
            ${PROJECT_BINARY_DIR}/${_script}
            COPYONLY
    )
endforeach ()

#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS DRU DESTINATION bin)
