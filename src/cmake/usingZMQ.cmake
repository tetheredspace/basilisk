  find_package(zmq CONFIG REQUIRED)
  list(APPEND CUSTOM_DEPENDENCIES zmq::zmq)
  set(CMAKE_INCLUDE_CURRENT_DIR TRUE)