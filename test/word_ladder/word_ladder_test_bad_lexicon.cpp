#include <comp6771/word_ladder.hpp>

#include <string>
#include <vector>

#include "catch2/catch.hpp"

TEST_CASE("Test when lexicon contains less than 2 words") {
	auto const lexicon_with_length_one = ::word_ladder::read_lexicon("./test/word_ladder/one_word.txt");
	// check the exception message
	CHECK_THROWS_WITH(::word_ladder::generate("work", "play", lexicon_with_length_one),
	                  "lexicon must contain at least 2 words");
    auto const empty_lexicon = ::word_ladder::read_lexicon("./test/word_ladder/empty.txt");
	// check the exception message
	CHECK_THROWS_WITH(::word_ladder::generate("work", "play", lexicon_with_length_one),
	                  "lexicon must contain at least 2 words");
}