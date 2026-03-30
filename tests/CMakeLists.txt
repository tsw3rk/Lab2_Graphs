# CMakeLists.txt для тестов

# Используем Catch2 (легковесный, работает с MinGW)
# Можно заменить на GoogleTest при необходимости

include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(catch2)

# Исходники тестов
file(GLOB TEST_SOURCES "*.cpp")

add_executable(graph_tests ${TEST_SOURCES})
target_link_libraries(graph_tests PRIVATE graph_lib Catch2::Catch2WithMain)

# Регистрация тестов в CTest
include(CTest)
include(Catch)
catch_discover_tests(graph_tests)
