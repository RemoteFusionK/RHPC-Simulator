cmake_minimum_required (VERSION 3.19)
project (RHPC_Simulator)# Enter your Project Name
# Set Project Version Number, however if you do not have an idea keep as it is.
# This helps in creating version control for a project which has a repository tool like Git 
set (SimDeviceGUI_VERSION_MAJOR 1)
set (SimDeviceGUI_VERSION_MINOR 0)

# Get headers and sources files
# Be careful to change the sub project name accordingly at this step.
file(GLOB_RECURSE SimDeviceGUI_SOURCES "src/*.cpp" "src/*.ui") # Source consists of all .cpp files and .ui files if present in the folder
# If the source folder does not have a .ui file, please remove "src/*.ui" or it will give an error in compilation!
file(GLOB_RECURSE SimDeviceGUI_HEADERS "include/*.h" "include/*.hpp") # Include consists of all .h files
set(ROOT "${PROJECT_SOURCE_DIR}") # Keep as it is
file(GLOB_RECURSE SimDeviceGUI_RESOURCES "src/*.rc")
source_group(TREE ${ROOT} FILES ${SimDeviceGUI_SOURCES} ${SimDeviceGUI_HEADERS} ${SimDeviceGUI_RESOURCES})
# source group function will group all the files in a sub branch of the project tree for Qt or VS and finally for compilation.




# Keep this as it is
# ---- Qt configuration -----
IF(NOT QT_DEBUG)
	# Instruct CMake to run MOC automatically when needed. MOC is a compiler used by Qt
	cmake_policy(SET CMP0020 OLD)
	set(CMAKE_AUTOMOC ON)
	SET(CMAKE_AUTOUIC ON)
	SET(CMAKE_AUTORCC ON)
	set (CMAKE_PREFIX_PATH ${QT_DIR})
	find_package(Qt6Core)	#Update with Qt5 for previous version or future Qt version accordingly
	find_package(Qt6Widgets) #Update with Qt5 for previous version or future Qt version accordingly
	find_package(Qt6Gui) #Update with Qt5 for previous version or future Qt version accordingly
ELSE()
	set(CMAKE_AUTOMOC ON)
ENDIF()
#-----------------------------

set(ICON_PATH "src/RHPC_simdevice.ico")


# Keep as it is from below this line! Except at lines 62,65-76 update with installed version of Qt 
message("REVIEW INCLUDE FOLDERS HERE, MOST OF THEM SHOULD BE INHERITED")
include_directories("${PROJECT_SOURCE_DIR}/include"
					"${PROJECT_SOURCE_DIR}/ui"
)

IF(QT_DEBUG)
	INCLUDE_DIRECTORIES("${QT_DIR}/include"
						"${QT_DIR}/include/QtCore"
						"${QT_DIR}/include/QtWidgets")
	add_definitions(-DQT_DLL
                -DQT_CORE_LIB
                -DQT_GUI_LIB
                -DQT_WIDGETS_LIB)
	set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:CONSOLE")
	set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
	set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
ENDIF()

                    
add_definitions(-DUNICODE -DWIN32 -D_WINDOWS) 
 
# add the executable
add_executable(${PROJECT_NAME} ${SimDeviceGUI_SOURCES} ${SimDeviceGUI_HEADERS} ${SimDeviceGUI_RESOURCES})

IF(QT_DEBUG)
	target_link_libraries(${PROJECT_NAME} 
									  debug "${QT_DIR}/lib/qtmaind.lib"
                                      debug "${QT_DIR}/lib/Qt6Cored.lib"
                                      debug "${QT_DIR}/lib/Qt6Guid.lib"
                                      debug "${QT_DIR}/lib/Qt6Widgetsd.lib"
                                      optimized "${QT_DIR}/lib/qtmain.lib"
                                      optimized "${QT_DIR}/lib/Qt6Core.lib"
                                      optimized "${QT_DIR}/lib/Qt6Gui.lib"
                                      optimized "${QT_DIR}/lib/Qt6Widgets.lib")
ELSE()
	target_link_libraries(${PROJECT_NAME} 			Qt6::Widgets
													 Qt6::Core
													 Qt6::Gui
													 )
ENDIF(QT_DEBUG)


target_link_libraries(${PROJECT_NAME} cpp mymath)
#  trajectoryGeneration 

SET_TARGET_PROPERTIES( ${PROJECT_NAME}
    PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/../bin/"
)

# -------------------------------------------
# Create Debug and run configurations
# -------------------------------------------
clear_launcher(${PROJECT_NAME})
IF(NOT QT_DEBUG)
Message (STATUS "creating launchers for Debug Flavour")
create_target_launcher(${PROJECT_NAME} RUNTIME_LIBRARY_DIRS "${QT_DIR}/bin"
                                                            "${QT_DIR}/plugins/platforms"
                                                            "${CMAKE_CURRENT_BINARY_DIR}/../bin/Debug"
                                                            WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
                                                            )
ELSE()

Message(STATUS "No available launchers for QT_DEBUG mode")
ENDIF()

# Set the project in a solutions's folder    
SET_TARGET_PROPERTIES (${PROJECT_NAME} PROPERTIES FOLDER Main)
