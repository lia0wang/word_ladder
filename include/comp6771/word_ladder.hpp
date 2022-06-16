// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#ifndef COMP6771_WORD_LADDER_HPP
#define COMP6771_WORD_LADDER_HPP

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <string>
#include <vector>

namespace word_ladder {
	[[nodiscard]] auto read_lexicon(std::string const& path) -> std::unordered_set<std::string>;

	// Given a start word and destination word, returns all the shortest possible paths from the
	// start word to the destination, where each word in an individual path is a valid word per the
	// provided lexicon. Pre: ranges::size(from) == ranges::size(to) Pre: valid_words.contains(from)
	// and valid_words.contains(to)
	[[nodiscard]] auto generate(std::string const& from,
	                            std::string const& to,
	                            std::unordered_set<std::string> const& lexicon)
	   -> std::vector<std::vector<std::string>>;
	[[nodiscard]] auto
	get_new_lexicon(std::string const& from, std::unordered_set<std::string> const& lexicon)
	   -> std::unordered_set<std::string>;
	[[nodiscard]] auto is_adjacent(std::string const& word1, std::string const& word2) -> bool;
	[[nodiscard]] auto has_error(std::string const& from,
	                             std::string const& to,
	                             std::unordered_set<std::string> const& lexicon) -> bool;
	[[nodiscard]] auto BFS_build_graph(std::string const& src,
	                                   std::string const& dest,
	                                   std::unordered_set<std::string> lexicon)
	   -> std::unordered_map<std::string, std::vector<std::string>>;
	[[nodiscard]] auto
	BFS_get_paths(std::string const src,
	              std::string const dest,
	              std::unordered_map<std::string, std::vector<std::string>> const graph)
	   -> std::vector<std::vector<std::string>>;

} // namespace word_ladder

#endif // COMP6771_WORD_LADDER_HPP
