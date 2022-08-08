cmake_minimum_required(VERSION 3.10)

project(pdcurser VERSION 3.9.0 LANGUAGES C CXX)

option(PDC_WIDE "Enable wide/unicode char." TRUE)
option(PDC_FORCE_UTF8 "Force using UTF8 char." TRUE)

add_subdirectory(src)
add_subdirectory(test)