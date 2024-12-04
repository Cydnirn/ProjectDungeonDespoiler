########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(pdcurses_COMPONENT_NAMES "")
if(DEFINED pdcurses_FIND_DEPENDENCY_NAMES)
  list(APPEND pdcurses_FIND_DEPENDENCY_NAMES xorg)
  list(REMOVE_DUPLICATES pdcurses_FIND_DEPENDENCY_NAMES)
else()
  set(pdcurses_FIND_DEPENDENCY_NAMES xorg)
endif()
set(xorg_FIND_MODE "NO_MODULE")

########### VARIABLES #######################################################################
#############################################################################################
set(pdcurses_PACKAGE_FOLDER_RELEASE "/home/rei/.conan2/p/b/pdcur362f1989bea6d/p")
set(pdcurses_BUILD_MODULES_PATHS_RELEASE )


set(pdcurses_INCLUDE_DIRS_RELEASE "${pdcurses_PACKAGE_FOLDER_RELEASE}/include"
			"${pdcurses_PACKAGE_FOLDER_RELEASE}/include/xcurses")
set(pdcurses_RES_DIRS_RELEASE )
set(pdcurses_DEFINITIONS_RELEASE )
set(pdcurses_SHARED_LINK_FLAGS_RELEASE )
set(pdcurses_EXE_LINK_FLAGS_RELEASE )
set(pdcurses_OBJECTS_RELEASE )
set(pdcurses_COMPILE_DEFINITIONS_RELEASE )
set(pdcurses_COMPILE_OPTIONS_C_RELEASE )
set(pdcurses_COMPILE_OPTIONS_CXX_RELEASE )
set(pdcurses_LIB_DIRS_RELEASE "${pdcurses_PACKAGE_FOLDER_RELEASE}/lib")
set(pdcurses_BIN_DIRS_RELEASE )
set(pdcurses_LIBRARY_TYPE_RELEASE STATIC)
set(pdcurses_IS_HOST_WINDOWS_RELEASE 0)
set(pdcurses_LIBS_RELEASE XCurses)
set(pdcurses_SYSTEM_LIBS_RELEASE )
set(pdcurses_FRAMEWORK_DIRS_RELEASE )
set(pdcurses_FRAMEWORKS_RELEASE )
set(pdcurses_BUILD_DIRS_RELEASE )
set(pdcurses_NO_SONAME_MODE_RELEASE FALSE)


# COMPOUND VARIABLES
set(pdcurses_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${pdcurses_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${pdcurses_COMPILE_OPTIONS_C_RELEASE}>")
set(pdcurses_LINKER_FLAGS_RELEASE
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${pdcurses_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${pdcurses_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${pdcurses_EXE_LINK_FLAGS_RELEASE}>")


set(pdcurses_COMPONENTS_RELEASE )