file(REMOVE_RECURSE
  "_doxygen"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/suite.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
