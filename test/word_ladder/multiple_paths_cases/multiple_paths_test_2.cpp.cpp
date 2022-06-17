// author: Wang, Liao
// date: 2022-6
// description:
//      This test case will check a generated ladders from "charge" to "comedo":
//          - check if the ladders size is 4
//          - check if the first ladder size is 23
//          - check if the ladders is sorted
//          - check if the ladders is same as the expected ladders
//          - check if each two words in each ladder are adjacent


#include <comp6771/word_ladder.hpp>

#include <string>
#include <vector>

#include "catch2/catch.hpp"

TEST_CASE("charge -> comedo") {
	auto const english_lexicon = ::word_ladder::read_lexicon("./test/word_ladder/english.txt");
	auto const ladders = ::word_ladder::generate("charge", "comedo", english_lexicon);

	CHECK(std::size(ladders) == 4);
	CHECK(std::size(ladders[0]) == 23);

	auto expected = std::vector<std::vector<std::string>>{{
	"charge", "change", "changs", "chants", "chints", "chines", "chined",
  "coined", "coiner", "conner", "conger", "conges", "conies", "conins",
  "coning", "coming", "homing", "hominy", "homily", "homely", "comely",
  "comedy", "comedo" }, { "charge", "change", "changs", "chants", "chints",
  "chines", "chined", "coined", "coiner", "conner", "conger", "conges",
  "conies", "conins", "coning", "honing", "homing", "hominy", "homily",
  "homely", "comely", "comedy", "comedo" }, { "charge", "change", "changs",
  "chants", "chints", "chines", "chined", "coined", "conned", "conner",
  "conger", "conges", "conies", "conins", "coning", "coming", "homing",
  "hominy", "homily", "homely", "comely", "comedy", "comedo" }, { "charge",
  "change", "changs", "chants", "chints", "chines", "chined", "coined",
  "conned", "conner", "conger", "conges", "conies", "conins", "coning",
  "honing", "homing", "hominy", "homily", "homely", "comely", "comedy",
  "comedo" } };
	CHECK(ladders == expected);

	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

    // check if each two words in each ladder are adjacent
    for (auto const& ladder : ladders) {
        for (auto i = ladder.begin(); std::next(i) != ladder.end(); ++i) {
            CHECK(word_ladder::is_adjacent(*i, *std::next(i)));
        }
    }
}
