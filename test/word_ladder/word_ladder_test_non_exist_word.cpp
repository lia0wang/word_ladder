#include <comp6771/word_ladder.hpp>

#include <string>
#include <vector>

#include "catch2/catch.hpp"

TEST_CASE("Test when from or to is not in the lexicon") {
	auto const english_lexicon = ::word_ladder::read_lexicon("./test/word_ladder/english.txt");
	// check the exception message
	CHECK_THROWS_WITH(::word_ladder::generate("myname", "iswang", english_lexicon),
	                  "from and to must be in the lexicon");
	CHECK_THROWS_WITH(::word_ladder::generate("", "", english_lexicon),
	                  "from and to must be in the lexicon");
}