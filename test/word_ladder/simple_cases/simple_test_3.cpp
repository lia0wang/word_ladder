// author: Wang, Liao
// date: 2022-6
// description:
//      This simple test case will check a generated ladders from "awake" to "sleep":
//          - check if the ladders size is 2
//          - check if the ladders is sorted
//          - check if the ladders contains the expected ladders
//          - check if each two words in each ladder are adjacent

#include <comp6771/word_ladder.hpp>

#include <string>
#include <vector>

#include <catch2/catch.hpp>

TEST_CASE("awake -> sleep") {
	auto const english_lexicon = word_ladder::read_lexicon("./test/word_ladder/english.txt");
	auto const ladders = word_ladder::generate("awake", "sleep", english_lexicon);

	CHECK(std::size(ladders) == 2);

	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

	auto expected = std::vector<std::vector<std::string>>{
	   {"awake", "aware", "sware", "share", "sharn", "shawn", "shewn", "sheen", "sheep", "sleep"},
	   {"awake", "aware", "sware", "share", "shire", "shirr", "shier", "sheer", "sheep", "sleep"}};
	CHECK(ladders == expected);

	// check if each two words in each ladder are adjacent
	for (auto const& ladder : ladders) {
		for (auto i = ladder.begin(); std::next(i) != ladder.end(); ++i) {
			CHECK(word_ladder::is_adjacent(*i, *std::next(i)));
		}
	}
}
