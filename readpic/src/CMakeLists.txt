FIND_PACKAGE( OpenCV REQUIRED )

ADD_EXECUTABLE(readpic readpic.cpp)
TARGET_LINK_LIBRARIES(readpic OpenNI ${OpenCV_LIBS})
