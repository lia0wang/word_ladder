#include "comp6771/word_ladder.hpp"

namespace word_ladder {

	// A method to check if word1 and word2 are adjacent.
	auto is_adjacent(std::string const& word1, std::string const& word2) -> bool {
		auto diff = 0;
		for (auto i = 0; i < word1.size(); ++i) {
			(word1[i] != word2[i]) ? ++diff : 0;
		}
		return diff == 1;
	}

	// A method to check the edge case errors.
	auto has_error(std::string const& from,
	               std::string const& to,
	               std::unordered_set<std::string> const& lexicon) -> bool {
		if (from.size() != to.size()) {
			throw std::invalid_argument("from and to must be the same length");
			return true;
		}
		if (lexicon.size() < 2) {
			throw std::invalid_argument("lexicon must contain at least 2 words");
			return true;
		}
		if (not lexicon.contains(from) or not lexicon.contains(to)) {
			throw std::invalid_argument("from and to must be in the lexicon");
			return true;
		}
		return false;
	}

	// A method to get a new lexicon which only contains the words having the same length as the from
	// word.
	auto get_new_lexicon(std::string const& from, std::unordered_set<std::string> const& lexicon)
	   -> std::unordered_set<std::string> {
		auto new_lexicon = std::unordered_set<std::string>{};
		for (auto it_word = lexicon.begin(); it_word != lexicon.end(); ++it_word) {
			if (it_word->size() == from.size()) {
				new_lexicon.insert(*it_word); // insert the value of it_word into the new lexicon
			}
		}
		return new_lexicon;
	}

	auto BFS_build_graph(std::string const& src,
	                     std::string const& dest,
	                     std::unordered_set<std::string> lexicon)
	   -> std::unordered_map<std::string, std::vector<std::string>> {
		auto graph = std::unordered_map<std::string, std::vector<std::string>>{};
		auto visited = std::unordered_set<std::string>{};
		auto queue = std::queue<std::string>{};
		lexicon.erase(src);
		visited.insert(src);
		queue.push(src);

		// iterate through the queue until the queue is empty.
		while (not queue.empty()) {
			// loop through the layer of the queue.
			for (auto i = queue.size(); i > 0; i--) {
				// get the current word
				auto curr_word = queue.front();
				queue.pop();

				// check if current word is the dest word
				if (curr_word == dest) {
					return graph;
				}

				// get the adjacent words list of the current words
				auto adjacent_words = std::vector<std::string>{};
				for (auto it_word = lexicon.begin(); it_word != lexicon.end(); ++it_word) {
					auto word = *it_word;
					if (word_ladder::is_adjacent(curr_word, word)) {
						adjacent_words.push_back(word); // add the adjacent word to the list
						if (not visited.contains(word)) {
							queue.push(word); // add the adjacent word to the queue for the next layer
							visited.insert(word); // now the adjacent word is visited
						}
					}
				}
				graph[curr_word] = adjacent_words;
			}

			// remove the visited words from the lexicon
			for (auto visited_word : visited) {
				lexicon.erase(visited_word);
			}
		}

		return graph;
	}

	auto BFS_get_paths(std::string const src,
	                   std::string const dest,
	                   std::unordered_map<std::string, std::vector<std::string>> const graph)
	   -> std::vector<std::vector<std::string>> {
		auto paths = std::vector<std::vector<std::string>>{};
		auto queue = std::queue<std::vector<std::string>>{};
		auto curr_path = std::vector<std::string>{};

		// add the src word to the current path
		curr_path.push_back(src);
		queue.push(curr_path);

		while (not queue.empty()) {
			// get the current path
			curr_path = queue.front();
			queue.pop();

			// get the last word in the current path
			auto last_word = curr_path.back();

			// check if the last word is the dest word
			if (last_word == dest) {
				paths.push_back(curr_path);
			}
			else if (graph.contains(last_word)) {
				auto neighbors = graph.at(last_word);
				for (auto it_neighbor = neighbors.begin(); it_neighbor != neighbors.end(); ++it_neighbor)
				{
					auto neighbor = *it_neighbor;
					auto new_path = curr_path;
					new_path.push_back(neighbor);
					queue.push(new_path);
				}
			}
		}
		std::sort(paths.begin(), paths.end()); // sor the paths in

		return paths;
	}

	auto generate(std::string const& from,
	              std::string const& to,
	              std::unordered_set<std::string> const& lexicon)
	   -> std::vector<std::vector<std::string>> {
		if (word_ladder::has_error(from, to, lexicon)) {
			return std::vector<std::vector<std::string>>{};
		}
		auto new_lexicon = word_ladder::get_new_lexicon(from, lexicon);
		auto const& graph = word_ladder::BFS_build_graph(from, to, new_lexicon);
		return word_ladder::BFS_get_paths(from, to, graph);
	}
} // namespace word_ladder