configure_file("english.txt" ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

cxx_test(
   TARGET multiple_paths_test_1
   FILENAME multiple_paths_cases/multiple_paths_test_1.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET multiple_paths_test_2
   FILENAME multiple_paths_cases/multiple_paths_test_2.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET multiple_paths_test_3
   FILENAME multiple_paths_cases/multiple_paths_test_3.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET multiple_paths_test_4
   FILENAME multiple_paths_cases/multiple_paths_test_4.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET error_inputs_test
   FILENAME error_cases/error_inputs_test.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET simple_test_1
   FILENAME simple_cases/simple_test_1.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET simple_test_2
   FILENAME simple_cases/simple_test_2.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET simple_test_3
   FILENAME simple_cases/simple_test_3.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET word_ladder_test_benchmark
   FILENAME word_ladder_test_benchmark.cpp
   LINK word_ladder lexicon test_main
)