#include "quiz.h"

int main() {
    Quiz quiz("questions/questions.json");
    quiz.start();
    return 0;
}
