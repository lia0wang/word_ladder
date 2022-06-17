// author: Wang, Liao
// date: 2022-6
// description:
//      This test case will check a generated ladders from "atlases" to "cabaret":
//          - check if the ladders size is 840
//          - check if the first ladder size is 58
//          - check if the ladders is sorted
//          - check if each two words in each ladder are adjacent

#include <comp6771/word_ladder.hpp>

#include <string>
#include <vector>

#include "catch2/catch.hpp"

TEST_CASE("atlases -> cabaret") {
	auto const english_lexicon = ::word_ladder::read_lexicon("./test/word_ladder/english.txt");
	auto const ladders = ::word_ladder::generate("atlases", "cabaret", english_lexicon);

	CHECK(std::size(ladders) == 840);
	CHECK(std::size(ladders[0]) == 58);

	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

    // check if each two words in each ladder are adjacent
    for (auto const& ladder : ladders) {
        for (auto i = ladder.begin(); std::next(i) != ladder.end(); ++i) {
            CHECK(word_ladder::is_adjacent(*i, *std::next(i)));
        }
    }
}
