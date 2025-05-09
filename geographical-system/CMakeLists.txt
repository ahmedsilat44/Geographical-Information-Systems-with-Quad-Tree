cmake_minimum_required(VERSION 3.19)
project(geographical-system LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
find_package(Python3 REQUIRED COMPONENTS Development)


set(PYTHON_ROOT "C:/Users/ahmed/AppData/Local/Programs/Python/Python313")
set(PYTHON_INCLUDE_DIR "${PYTHON_ROOT}/include")
set(CPYTHON_INCLUDE_DIR "${PYTHON_ROOT}/include/cpython")
set(INTERNAL_INCLUDE_DIR "${PYTHON_ROOT}/include/internal")
set(PYTHON_LIBRARY_DIR "${PYTHON_ROOT}/libs")
set(PYTHON_LIBRARY "${PYTHON_LIBRARY_DIR}/python313.lib")
set(NUMPY_INCLUDE_DIR "${PYTHON_ROOT}/Lib/site-packages/numpy")
set(PNUMPY_INCLUDE_DIR "${PYTHON_ROOT}/Lib/site-packages/numpy/_core/include")

# Include directories
include_directories(
    ${PYTHON_ROOT}
    ${PYTHON_INCLUDE_DIR}
    # ${CPYTHON_INCLUDE_DIR}
    # ${INTERNAL_INCLUDE_DIR}
    ${PNUMPY_INCLUDE_DIR}
    ${NUMPY_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/include  # Your local include folder if you have one
)

link_directories("${PYTHON_ROOT}/libs")




qt_standard_project_setup()

qt_add_executable(geographical-system
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui


    Box.h Box.cpp
    Point.h Point.cpp
    Quadtree.h Quadtree.cpp
    # Python.h

)

target_include_directories(geographical-system
    PRIVATE
    ${PYTHON_ROOT}
    ${PYTHON_INCLUDE_DIR}
    # ${CPYTHON_INCLUDE_DIR}
    # ${INTERNAL_INCLUDE_DIR}
    ${PNUMPY_INCLUDE_DIR}
    ${NUMPY_INCLUDE_DIR}
)
ADD_DEFINITIONS(-DQT_NO_KEYWORDS)

target_link_libraries(geographical-system
    PRIVATE
        Qt::Core
        Qt::Widgets
        ${PYTHON_LIBRARY}
)

include(GNUInstallDirs)

install(TARGETS geographical-system
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET geographical-system
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
