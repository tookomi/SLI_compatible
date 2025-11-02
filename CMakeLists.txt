# CMakeList.txt: проект CMake для SLI_compatible; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (SLI_compatible "SLI_compatible.cpp" "SLI_compatible.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SLI_compatible PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
