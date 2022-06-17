// author: Wang, Liao
// date: 2022-6
// description:
//      This simple test case will check a generated ladders from "airplane" to "tricycle":
//          - check if the ladders size is zero
//          - check if the ladders is empty
//          - check if the two words are not adjacent

#include <comp6771/word_ladder.hpp>

#include <string>
#include <vector>

#include <catch2/catch.hpp>

TEST_CASE("airplane -> tricycle") {
	auto const english_lexicon = word_ladder::read_lexicon("./test/word_ladder/english.txt");
	auto const ladders = word_ladder::generate("airplane", "tricycle", english_lexicon);

	CHECK(std::size(ladders) == 0);
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));
	auto expected = std::vector<std::vector<std::string>>{};
	CHECK(ladders == expected);
	CHECK(not word_ladder::is_adjacent("airplane", "tricycle"));
}
