set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTORCC ON )

set( TARGET_NAME uppu-mono-dc )

file( GLOB_RECURSE ENERCOM_HEADERS src/*.h)
file( GLOB_RECURSE ENERCOM_SOURCES src/*.cpp)
file( GLOB_RECURSE ENERCOM_RCFILES res/*.qrc)

find_package( Qt5 COMPONENTS Core Qml Quick REQUIRED )

add_executable( ${TARGET_NAME} ${ENERCOM_HEADERS} ${ENERCOM_SOURCES} ${ENERCOM_RCFILES} )

target_link_libraries( ${TARGET_NAME} Qt5::Core Qt5::Qml Qt5::Quick )

target_link_libraries( ${TARGET_NAME} SimDS )

target_include_directories( ${TARGET_NAME} PRIVATE src)
