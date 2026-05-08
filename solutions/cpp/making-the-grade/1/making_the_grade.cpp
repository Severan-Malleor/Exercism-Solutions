#include <array>
#include <string>
#include <vector>
#include <cmath>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {

    std::vector<int> rounded_scores{};
    
    for (int i{ 0 }; i < student_scores.size(); ++i) {
        rounded_scores.emplace_back(std::floor(student_scores[i]));
    }

    return rounded_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int failures{ 0 };
    
    for (int i{ 0 }; i < student_scores.size(); ++i) {
        if (student_scores[i] <= 40) {
            failures++;
        }
    }
    
    return failures;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int increment = (highest_score - 40) / 4;
    return {41, 41 + increment, 41 + 2 * increment, 41 + 3 * increment};
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {

    std::vector<std::string> rankings{};

    // to_string - Best for: Multi-digit integers (e.g., 123), negative numbers, and floating-point values. (slower / uses heap, but more flexible)
    // <int> + '0' - Best for: Converting a single-digit integer (\(0-9\)) into a single (faster, but limited)
    for (int i{ 0 }; i < student_scores.size(); ++i) {
        rankings.emplace_back(std::to_string(i + 1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]));
    }

    return rankings;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    
    for (int i{ 0 }; i < student_scores.size(); ++i) {
        if (student_scores[i] == 100) {
            return student_names[i];
        }
    }
    return "";
}
