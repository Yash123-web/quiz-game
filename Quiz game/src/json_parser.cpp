#include "quiz.h"
#include <fstream>
#include <nlohmann/json.hpp>

std::vector<Question> parseQuestionsFromJSON(const std::string& filename) {
    std::vector<Question> questions;
    std::ifstream file(filename);
    nlohmann::json j;
    file >> j;

    for (const auto& item : j) {
        Question q;
        q.question = item["question"];
        q.options = item["options"].get<std::vector<std::string>>();
        q.correctIndex = item["answer"];
        questions.push_back(q);
    }

    return questions;
}
