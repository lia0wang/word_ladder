// author: Wang, Liao
// date: 2022-6
// description:
//      This simple test case will check a generated ladders from "at" to "it":
//          - check if the ladders size is one
//          - check if the ladders is sorted
//          - check if the ladders contains the expected ladders
//          - check if the two words are adjacent

#include <comp6771/word_ladder.hpp>

#include <string>
#include <vector>

#include <catch2/catch.hpp>

TEST_CASE("at -> it") {
	auto const english_lexicon = word_ladder::read_lexicon("./test/word_ladder/english.txt");
	auto const ladders = word_ladder::generate("at", "it", english_lexicon);

	CHECK(std::size(ladders) == 1);
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));
	auto expected = std::vector<std::vector<std::string>>{{"at", "it"}};
	CHECK(ladders == expected);
	CHECK(word_ladder::is_adjacent("at", "it"));
}
