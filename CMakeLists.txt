cmake_minimum_required(VERSION 3.1)

if (NOT WIN32)
	message(FATAL_ERROR "plugin-sdk is only for Windows")
endif()

project(plugin-sdk)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-m32 -fpermissive")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-s -O2")

file(GLOB SRC_SHARED
	shared/*.cpp
	shared/comp/*.cpp
	shared/comp/plugins/*.cpp
	shared/extensions/*.cpp
	shared/game/*.cpp
)

file(GLOB SRC_PLUGIN_III
	plugin_III/game_III/*.cpp
)

file(GLOB SRC_PLUGIN_VC
	plugin_vc/game_vc/*.cpp
)

file(GLOB SRC_PLUGIN_SA
	plugin_sa/game_sa/*.cpp
)

option(BUILD_GTAIII "Build GTA III plugin library" ON)
option(BUILD_GTAVC "Build GTA Vice City plugin library" ON)
option(BUILD_GTASA "Build GTA San Andreas plugin library" ON)

if(BUILD_GTAIII)
	add_library(plugin_III STATIC ${SRC_SHARED} ${SRC_PLUGIN_III})
	target_compile_definitions(plugin_III PRIVATE GTAIII PLUGIN_SGV_10EN _HAS_CXX17 RW)
	target_include_directories(plugin_III PRIVATE shared shared/comp shared/extender shared/extensions shared/game plugin_III plugin_III/game_III plugin_III/game_III/meta plugin_III/game_III/rw)
endif()

if(BUILD_GTAIII)
	add_library(plugin_vc STATIC ${SRC_SHARED} ${SRC_PLUGIN_VC})
	target_compile_definitions(plugin_vc PRIVATE GTAVC PLUGIN_SGV_10EN _HAS_CXX17 RW)
	target_include_directories(plugin_vc PRIVATE shared shared/comp shared/extender shared/extensions shared/game plugin_vc plugin_vc/game_vc plugin_vc/game_vc/meta plugin_vc/game_vc/rw)
endif()

if(BUILD_GTASA)
	add_library(plugin_sa STATIC ${SRC_SHARED} ${SRC_PLUGIN_SA})
	target_compile_definitions(plugin_sa PRIVATE GTASA PLUGIN_SGV_10US _HAS_CXX17 RW)
	target_include_directories(plugin_sa PRIVATE shared shared/comp shared/extender shared/extensions shared/game plugin_sa plugin_sa/game_sa plugin_sa/game_sa/meta plugin_sa/game_sa/rw)
endif()


