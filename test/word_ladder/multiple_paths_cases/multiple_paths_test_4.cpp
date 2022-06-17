// author: Wang, Liao
// date: 2022-6
// description:
//      This test case will check a generated ladders from "gimlets" to "coaming":
//          - check if the ladders size is 14
//          - check if the first ladder size is 19
//          - check if the ladders is sorted
//          - check if the ladders is same as the expected ladders
//          - check if each two words in each ladder are adjacent


#include <comp6771/word_ladder.hpp>

#include <string>
#include <vector>

#include "catch2/catch.hpp"

TEST_CASE("gimlets -> coaming") {
	auto const english_lexicon = ::word_ladder::read_lexicon("./test/word_ladder/english.txt");
	auto const ladders = ::word_ladder::generate("gimlets", "coaming", english_lexicon);

	CHECK(std::size(ladders) == 14);
	CHECK(std::size(ladders[0]) == 19);

	auto expected = std::vector<std::vector<std::string>>{ {
	"gimlets", "giblets", "riblets", "rillets", "billets", "ballets",
  "ballers", "bailers", "bailees", "bailies", "dailies", "dallies", "dollies",
  "collies", "collins", "codlins", "codling", "coaling", "coaming" }, {
  "gimlets", "giblets", "riblets", "rillets", "billets", "ballets", "ballers",
  "bailers", "bailees", "bailies", "dailies", "doilies", "dollies", "collies",
  "collins", "codlins", "codling", "coaling", "coaming" }, { "gimlets",
  "giblets", "riblets", "rillets", "billets", "billers", "ballers", "bailers",
  "bailees", "bailies", "dailies", "dallies", "dollies", "collies", "collins",
  "codlins", "codling", "coaling", "coaming" }, { "gimlets", "giblets",
  "riblets", "rillets", "billets", "billers", "ballers", "bailers", "bailees",
  "bailies", "dailies", "doilies", "dollies", "collies", "collins", "codlins",
  "codling", "coaling", "coaming" }, { "gimlets", "giglets", "guglets",
  "gullets", "bullets", "ballets", "ballers", "bailers", "bailees", "bailies",
  "dailies", "dallies", "dollies", "collies", "collins", "codlins", "codling",
  "coaling", "coaming" }, { "gimlets", "giglets", "guglets", "gullets",
  "bullets", "ballets", "ballers", "bailers", "bailees", "bailies", "dailies",
  "doilies", "dollies", "collies", "collins", "codlins", "codling", "coaling",
  "coaming" }, { "gimlets", "giglets", "wiglets", "willets", "billets",
  "ballets", "ballers", "bailers", "bailees", "bailies", "dailies", "dallies",
  "dollies", "collies", "collins", "codlins", "codling", "coaling", "coaming" }
  , { "gimlets", "giglets", "wiglets", "willets", "billets", "ballets",
  "ballers", "bailers", "bailees", "bailies", "dailies", "doilies", "dollies",
  "collies", "collins", "codlins", "codling", "coaling", "coaming" }, {
  "gimlets", "giglets", "wiglets", "willets", "billets", "billers", "ballers",
  "bailers", "bailees", "bailies", "dailies", "dallies", "dollies", "collies",
  "collins", "codlins", "codling", "coaling", "coaming" }, { "gimlets",
  "giglets", "wiglets", "willets", "billets", "billers", "ballers", "bailers",
  "bailees", "bailies", "dailies", "doilies", "dollies", "collies", "collins",
  "codlins", "codling", "coaling", "coaming" }, { "gimlets", "giglets",
  "wiglets", "willets", "wallets", "ballets", "ballers", "bailers", "bailees",
  "bailies", "dailies", "dallies", "dollies", "collies", "collins", "codlins",
  "codling", "coaling", "coaming" }, { "gimlets", "giglets", "wiglets",
  "willets", "wallets", "ballets", "ballers", "bailers", "bailees", "bailies",
  "dailies", "doilies", "dollies", "collies", "collins", "codlins", "codling",
  "coaling", "coaming" }, { "gimlets", "giglets", "wiglets", "willets",
  "willers", "billers", "ballers", "bailers", "bailees", "bailies", "dailies",
  "dallies", "dollies", "collies", "collins", "codlins", "codling", "coaling",
  "coaming" }, { "gimlets", "giglets", "wiglets", "willets", "willers",
  "billers", "ballers", "bailers", "bailees", "bailies", "dailies", "doilies",
  "dollies", "collies", "collins", "codlins", "codling", "coaling", "coaming" }
  };
	CHECK(ladders == expected);

	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

    // check if each two words in each ladder are adjacent
    for (auto const& ladder : ladders) {
        for (auto i = ladder.begin(); std::next(i) != ladder.end(); ++i) {
            CHECK(word_ladder::is_adjacent(*i, *std::next(i)));
        }
    }
}
