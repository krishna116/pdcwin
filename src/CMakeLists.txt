add_library(${PROJECT_NAME} STATIC
addch.c
addchstr.c
addstr.c
attr.c
beep.c
bkgd.c
border.c
clear.c
color.c
debug.c
delch.c
deleteln.c
getch.c
getstr.c
getyx.c
inch.c
inchstr.c
initscr.c
inopts.c
insch.c
insstr.c
instr.c
kernel.c
keyname.c
mouse.c
move.c
outopts.c
overlay.c
pad.c
panel.c
pdcclip.c
pdcdisp.c
pdcgetsc.c
pdckbd.c
pdcscrn.c
pdcsetsc.c
pdcutil.c
pdcwin.h
printw.c
refresh.c
scanw.c
scr_dump.c
scroll.c
slk.c
termattr.c
touch.c
util.c
window.c
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
${PDC_WIDE}
${PDC_FORCE_UTF8}
)

target_include_directories(${PROJECT_NAME}
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}>
)

# install -----------------------------------------------------------
include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)

install(
FILES 
    ${CMAKE_SOURCE_DIR}/include/curses.h
    ${CMAKE_SOURCE_DIR}/include/panel.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)

install(EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

include(CMakePackageConfigHelpers)
set(version ${PROJECT_VERSION})
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    VERSION "${version}"
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_SOURCE_DIR}/cmake/Config.cmake.txt
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)