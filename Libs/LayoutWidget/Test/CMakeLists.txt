set(TARGET_NAME layout-widget)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# file(GLOB_RECURSE SRCS *.cpp *.c)
# file(GLOB_RECURSE HDRS *.hpp *.h)

set(LWDSRCS ../Impl/LayerSelectWidget.cpp ../Impl/GeometryWidget.cpp ../Impl/LayoutWidget.cpp  widget.test.cpp)
set(LWDHDRS ../../../Include/PaintData.hpp ../../../Include/LayerSelectWidget.hpp ../../../Include/GeometryWidget.hpp ../../../Include/LayoutWidget.hpp)

# set(SRCS ${SRCS} ${LWDSRCS})
# set(HDRS ${HDRS} ${LWDHDRS})

add_executable(${TARGET_NAME} ${LWDSRCS} ${LWDHDRS})

target_link_libraries(${TARGET_NAME} PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets  LayoutReader LayoutWidget)
target_include_directories(${TARGET_NAME} PUBLIC ${SHARED_INCLUDE_DIRS})