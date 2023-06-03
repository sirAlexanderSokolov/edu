cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project (helloworldXXL VERSION 1.0.0)
set (SOURCES main.cpp)

#=====================================================
# опции проекта
option(IMPROVED_ALLOC   "Включить аллокатор от google"      OFF)
option(DEBUG            "Режим отладки"                     OFF)

message (STATUS "Аллокация памяти tcmalloc :  ${IMPROVED_ALLOC}")
message (STATUS "Режим отладки:               ${DEBUG}")
#=====================================================
# сборка
add_executable(${PROJECT_NAME} ${SOURCES})
#=====================================================
# поиск библиотек
find_package(Boost COMPONENTS 
# program_options
# thread 
# system 
# chrono 
REQUIRED)

# find_library(PTREAD_LIBRARY pthread REQUIRED)   #POSIX thread
# find_library(RT_LIBRARY rt REQUIRED)            #POSIX.1b  Realtime Extension
# find_library(DL_LIBRARY dl REQUIRED)            #Dynamic link
#=====================================================
# линковка
target_link_libraries(${PROJECT_NAME} 
${Boost_LIBRARIES}
# ${PTREAD_LIBRARY}
# ${RT_LIBRARY}
# ${DL_LIBRARY}
)
#=====================================================
# флаги компилятора
add_definitions(-Wall -fPIC -fmessage-length=0 -Wextra -pedantic -c -W -Wfatal-errors -std=c++17)
#=====================================================
if(IMPROVED_ALLOC)
  find_library(GMALLOC tcmalloc)
  if(GMALLOC)
    message (STATUS "Сборка с tcmalloc: ${GMALLOC}")
    add_definitions(-ltcmalloc)
  else()
    message (STATUS "Библиотека tcmalloc не найдена")
  endif()
endif()
#=====================================================
if (DEBUG)
  add_definitions(-O0 -g3 -DDEBUG)
  message (STATUS "Сборка в режиме отладки")
else()
  add_definitions(-O3 -g3 )
endif()
#=====================================================
# Генерация run файла
configure_file(run.sh.in run.sh @ONLY)
#=====================================================