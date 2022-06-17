#include <comp6771/word_ladder.hpp>

#include <string>
#include <vector>

#include "catch2/catch.hpp"

TEST_CASE("work -> play") {
	auto const english_lexicon = ::word_ladder::read_lexicon("./test/word_ladder/english.txt");
	// check the exception message
	auto ladders = ::word_ladder::generate("work", "play", english_lexicon);
	auto expected = std::vector<std::vector<std::string>>{
	   {"work", "fork", "form", "foam", "flam", "flay", "play"},
	   {"work", "pork", "perk", "peak", "pean", "plan", "play"},
	   {"work", "pork", "perk", "peak", "peat", "plat", "play"},
	   {"work", "pork", "perk", "pert", "peat", "plat", "play"},
	   {"work", "pork", "porn", "pirn", "pian", "plan", "play"},
	   {"work", "pork", "port", "pert", "peat", "plat", "play"},
	   {"work", "word", "wood", "pood", "plod", "ploy", "play"},
	   {"work", "worm", "form", "foam", "flam", "flay", "play"},
	   {"work", "worn", "porn", "pirn", "pian", "plan", "play"},
	   {"work", "wort", "bort", "boat", "blat", "plat", "play"},
	   {"work", "wort", "port", "pert", "peat", "plat", "play"},
	   {"work", "wort", "wert", "pert", "peat", "plat", "play"}};
	CHECK(ladders == expected);
	// check the ladders is sorted
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));
}