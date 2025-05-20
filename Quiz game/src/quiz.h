#pragma once
#include <string>
#include <vector>
#include <chrono>

struct Question {
    std::string question;
    std::vector<std::string> options;
    int correctIndex;
};

class Quiz {
public:
    Quiz(const std::string& filename);
    void start();

private:
    std::vector<Question> questions;
    int score = 0;
    int attempts = 0;

    void loadQuestions(const std::string& filename);
    void askQuestion(const Question& q);
    void showSummary();
};
