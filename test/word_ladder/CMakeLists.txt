configure_file("english.txt" ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file("one_word.txt" ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file("empty.txt" ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

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
   TARGET word_ladder_test_diff_length
   FILENAME word_ladder_test_diff_length.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET word_ladder_test_bad_lexicon
   FILENAME word_ladder_test_bad_lexicon.cpp
   LINK word_ladder lexicon test_main
)

cxx_test(
   TARGET word_ladder_test_non_exist_word
   FILENAME word_ladder_test_non_exist_word.cpp
   LINK word_ladder lexicon test_main
)