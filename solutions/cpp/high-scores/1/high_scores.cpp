#include "high_scores.h"
#include <algorithm>

namespace arcade {

    std::vector<int> HighScores::list_scores() {
        // TODO: Return all scores for this session.
        return scores;
    }

    int HighScores::latest_score() {
        // TODO: Return the latest score for this session.
        return scores[scores.size() - 1];
    }

    int HighScores::personal_best() {
        // TODO: Return the highest score for this session.

        int bestScore = scores[0];

        for (auto s : scores) {
            if (s > bestScore) {
                bestScore = s;
            }
        }

        return bestScore;
    }

    std::vector<int> HighScores::top_three() {
        // TODO: Return the top 3 scores for this session in descending order.

        std::vector<int> sorted = scores; // so we do not mutate the original vector
        std::sort(sorted.begin(), sorted.end(), std::greater<int>());

        size_t count = std::min(sorted.size(), size_t{ 3 });
        std::vector<int> topThree(sorted.begin(), sorted.begin() + count);


        return topThree;
    }

}  // namespace arcade
