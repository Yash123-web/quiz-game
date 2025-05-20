#include "quiz.h"
#include "timer.h"
#include "json_parser.cpp"
#include <iostream>
#include <iomanip>
#include <fstream>

Quiz::Quiz(const std::string& filename) {
    loadQuestions(filename);
}

void Quiz::loadQuestions(const std::string& filename) {
    questions = parseQuestionsFromJSON(filename);
}

void Quiz::start() {
    std::cout << "=== Welcome to the Quiz Game ===\n\n";

    for (const auto& q : questions) {
        askQuestion(q);
    }

    showSummary();
}

void Quiz::askQuestion(const Question& q) {
    std::cout << q.question << "\n";
    for (size_t i = 0; i < q.options.size(); ++i) {
        std::cout << i + 1 << ". " << q.options[i] << "\n";
    }

    Timer timer;
    timer.start();

    int choice;
    std::cout << "Your answer: ";
    std::cin >> choice;

    timer.stop();
    double timeTaken = timer.elapsedSeconds();

    ++attempts;

    if (choice - 1 == q.correctIndex) {
        std::cout << "✅ Correct!\n";
        ++score;
    } else {
        std::cout << "❌ Wrong! Correct answer was: " << q.options[q.correctIndex] << "\n";
    }

    std::cout << "⏱️ Time taken: " << std::fixed << std::setprecision(2) << timeTaken << "s\n\n";
}

void Quiz::showSummary() {
    std::cout << "\n=== Quiz Summary ===\n";
    std::cout << "Score: " << score << "/" << questions.size() << "\n";
    std::cout << "Attempts: " << attempts << "\n";

    // Save to leaderboard
    std::ofstream file("leaderboard.txt", std::ios::app);
    file << "Score: " << score << "/" << questions.size() << ", Attempts: " << attempts << "\n";
    file.close();
}
