// author: Wang, Liao
// date: 2022-6
// description:
//      This Test is to check the error cases when the inputs are incorrect:
//          - The from and to with different length
//          - The from or to is not in the lexicon
//          - The lexicon is less than 2 words

#include <comp6771/word_ladder.hpp>

#include <unordered_set>
#include <string>
#include <vector>

#include "catch2/catch.hpp"

TEST_CASE("test error inputs") {
	auto const english_lexicon = ::word_ladder::read_lexicon("./test/word_ladder/english.txt");
	auto const empty_lexicon = std::unordered_set<std::string>{};
	auto const one_word_lexicon = std::unordered_set<std::string>{"work"};

	SECTION("test from and to with the different length") {
		SECTION("from is empty", "[none] -> ablest") {
			CHECK_THROWS_WITH(::word_ladder::generate("", "ablest", english_lexicon),
			                  "from and to must be the same length");
		}
		SECTION("to is empty", "ablest -> [none]") {
			CHECK_THROWS_WITH(::word_ladder::generate("ablest", "", english_lexicon),
			                  "from and to must be the same length");
		}
		SECTION("from and to are with the different length", "abler -> ablest") {
			CHECK_THROWS_WITH(::word_ladder::generate("abler", "ablest", english_lexicon),
			                  "from and to must be the same length");
		}
	}

	SECTION("test when from or to is not in the lexicon") {
		SECTION("from is not in the lexicon", "myname -> aaliis") {
			CHECK_THROWS_WITH(::word_ladder::generate("myname", "aaliis", english_lexicon),
			                  "from and to must be in the lexicon");
		}
		SECTION("to is not in the lexicon", "aaliis -> myname") {
			CHECK_THROWS_WITH(::word_ladder::generate("aaliis", "myname", english_lexicon),
			                  "from and to must be in the lexicon");
		}
		SECTION("from and to are both not in the lexicon", "myname -> iswang") {
			CHECK_THROWS_WITH(::word_ladder::generate("myname", "iswang", english_lexicon),
			                  "from and to must be in the lexicon");
		}
		SECTION("from and to are both empty", "[none] -> [none]") {
			CHECK_THROWS_WITH(::word_ladder::generate("", "", english_lexicon),
			                  "from and to must be in the lexicon");
		}
	}

	SECTION("test with a bad lexicon") {
		SECTION("lexicon is empty", "work -> play") {
			CHECK_THROWS_WITH(::word_ladder::generate("work", "play", empty_lexicon),
			                  "lexicon must contain at least 2 words");
		}
		SECTION("lexicon only contains one word", "work -> play") {
			CHECK_THROWS_WITH(::word_ladder::generate("work", "play", one_word_lexicon),
			                  "lexicon must contain at least 2 words");
		}
		SECTION("lexicon only contains one word", "aahs -> aals") {
			CHECK_THROWS_WITH(::word_ladder::generate("aahs", "aals", one_word_lexicon),
			                  "lexicon must contain at least 2 words");
		}
	}
}