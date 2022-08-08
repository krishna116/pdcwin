set(TargetList
test1
test2
)

foreach(tgt ${TargetList})
    add_executable(${tgt} ${tgt}.cpp)
    target_link_libraries(${tgt} PRIVATE pdcurser)
endforeach()




