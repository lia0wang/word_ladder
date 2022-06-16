#include <comp6771/word_ladder.hpp>

#include <string>
#include <vector>

#include "catch2/catch.hpp"

TEST_CASE("Test from and to with the different length") {
	auto const english_lexicon = ::word_ladder::read_lexicon("./test/word_ladder/english.txt");
	// check the exception message
	CHECK_THROWS_WITH(::word_ladder::generate("abler", "ablest", english_lexicon),
	                  "from and to must be the same length");
	CHECK_THROWS_WITH(::word_ladder::generate("", "ablest", english_lexicon),
	                  "from and to must be the same length");
}