configure_file("english.txt" ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

cxx_test(
   TARGET word_ladder_test1
   FILENAME word_ladder_test1.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET word_ladder_test_benchmark
   FILENAME word_ladder_test_benchmark.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET word_ladder_test_multiple_paths
   FILENAME word_ladder_test_multiple_paths.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET word_ladder_test_error_inputs
   FILENAME word_ladder_test_error_inputs.cpp
   LINK word_ladder lexicon test_main
)