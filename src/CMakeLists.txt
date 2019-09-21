file(GLOB SRC_SOURCES "*.cpp")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# On ubuntu/debian do
# sudo apt-get install \
#    libjsoncpp-dev libjsoncpp-doc libjsoncpp1
#    rapidjson-dev rapidjson-doc

find_library(JSONCPP_LIBRARY jsoncpp)

add_executable(jsoncppexperiment ${SRC_SOURCES})
target_link_libraries(jsoncppexperiment
  ${JSONCPP_LIBRARY})
