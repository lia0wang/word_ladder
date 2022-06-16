#include "comp6771/word_ladder.hpp"
#include <iostream>

// Please note: it's not good practice to test your code via a main function that does
//  printing. Instead, you should be using your test folder. This file should only really
//  be used for more "primitive" debugging as we know that working solely with test
//  frameworks might be overwhelming for some.

auto main() -> int {
	// auto const english_lexicon = word_ladder::read_lexicon("./test/word_ladder/fake_english.txt");
	auto const english_lexicon = word_ladder::read_lexicon("./test/word_ladder/english.txt");
	auto const ladders = word_ladder::generate("abler", "ablest", english_lexicon);
	// auto new_lexicon = word_ladder::get_new_lexicon("work", english_lexicon);

	// print the size of english lexicon
	// std::cout << new_lexicon.size() << std::endl;

	// debug here
	for (const auto& ladder : ladders) {
		for (const auto& word : ladder) {
			std::cout << word << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
