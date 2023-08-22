set(TARGET_NAME LayoutWidget)

file(GLOB_RECURSE SRCS LayoutSelectWidget.cpp GeometryWidget.cpp LayoutWidget.cpp)
file(GLOB_RECURSE HDRS *.h *.hpp)

message(DEBUG ${READER_HEADER_LIST} ${READER_SOURCE_LIST})

add_library(${TARGET_NAME} STATIC ${SRCS} ${HDRS})
target_link_libraries(${TARGET_NAME} PUBLIC Qt5::Core Qt5::Gui Qt5::Widgets LayoutReader)
target_include_directories(${TARGET_NAME} PUBLIC ${SHARED_INCLUDE_DIRS})