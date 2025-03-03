#include <iostream>
#include <vector>
#include <string>
#include <limits>

// Structure to represent a quiz question
struct Question {
    std::string questionText;
    std::vector<std::string> options;
    std::string answer;
};

class QuizApp {
private:
    std::vector<Question> quizData;
    int currentQuestion;
    int score;

public:
    QuizApp() {
        // Initialize quiz variables
        currentQuestion = 0;
        score = 0;

        // Initialize quiz data
        quizData = {
            {
                "What is the capital of France?",
                {"Paris", "London", "Rome", "Berlin"},
                "Paris"
            },
            {
                "Which planet is known as the Red Planet?",
                {"Earth", "Mars", "Jupiter", "Venus"},
                "Mars"
            },
            {
                "What is the largest ocean on Earth?",
                {"Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean"},
                "Pacific Ocean"
            },
            {
                "Who wrote 'Romeo and Juliet'?",
                {"William Shakespeare", "Charles Dickens", "J.K. Rowling", "Ernest Hemingway"},
                "William Shakespeare"
            },
            {
                "What is the smallest prime number?",
                {"0", "1", "2", "3"},
                "2"
            }
        };
    }

    void displayQuestion() {
        // Get the current question data
        Question questionData = quizData[currentQuestion];

        // Display the question text
        std::cout << "\n" << questionData.questionText << "\n\n";

        // Display the options
        for (size_t i = 0; i < questionData.options.size(); i++) {
            std::cout << (i + 1) << ". " << questionData.options[i] << "\n";
        }
        std::cout << "\n";
    }

    bool processAnswer() {
        Question questionData = quizData[currentQuestion];
        
        int choice;
        bool validInput = false;
        
        // Input validation loop
        while (!validInput) {
            std::cout << "Enter your answer (1-" << questionData.options.size() << "): ";
            
            if (std::cin >> choice) {
                if (choice >= 1 && choice <= static_cast<int>(questionData.options.size())) {
                    validInput = true;
                } else {
                    std::cout << "Invalid choice. Please enter a number between 1 and " 
                              << questionData.options.size() << ".\n";
                }
            } else {
                std::cin.clear(); // Clear error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                std::cout << "Invalid input. Please enter a number.\n";
            }
        }
        
        // Convert choice to zero-based index
        int index = choice - 1;
        
        // Check if the selected option is correct
        if (questionData.options[index] == questionData.answer) {
            std::cout << "Correct!\n";
            score++;
            return true;
        } else {
            std::cout << "Incorrect. The correct answer is: " << questionData.answer << "\n";
            return false;
        }
    }

    void runQuiz() {
        std::cout << "===== QUIZ APP =====\n";
        
        // Loop through all questions
        while (currentQuestion < static_cast<int>(quizData.size())) {
            // Display the current question
            displayQuestion();
            
            // Process the user's answer
            processAnswer();
            
            // Move to the next question
            currentQuestion++;
            
            // If not the last question, wait for user to press enter
            if (currentQuestion < static_cast<int>(quizData.size())) {
                std::cout << "\nPress Enter to continue to the next question...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
            }
        }
        
        // Display the final score
        std::cout << "\n===== Quiz Completed =====\n";
        std::cout << "You scored " << score << " out of " << quizData.size() << "\n";
    }
};

int main() {
    QuizApp app;
    app.runQuiz();
    
    std::cout << "\nThank you for taking the quiz!\n";
    
    return 0;
}
