# C++ Command Line Quiz Application

A simple, interactive command-line quiz application written in C++. This application presents users with multiple-choice questions and tracks their score.

## Features

- Multiple-choice questions with automatic scoring
- Input validation to handle incorrect entries
- Progress tracking through the quiz
- Final score summary at completion
- Clean console-based user interface

## Requirements

- C++ compiler with C++11 support (g++, clang++, MSVC, etc.)
- Standard C++ libraries

## Installation

1. Clone this repository or download the source code:
   ```
   git clone https://github.com/yourusername/cpp-quiz-app.git
   ```
   
2. Navigate to the project directory:
   ```
   cd cpp-quiz-app
   ```
   
3. Compile the program:
   ```
   g++ -o quiz_app quiz_app.cpp
   ```
   
   For Windows users with MSVC:
   ```
   cl /EHsc /std:c++14 quiz_app.cpp /Fe:quiz_app.exe
   ```

## Usage

Run the compiled program:

```
./quiz_app
```

For Windows:
```
quiz_app.exe
```

Follow the on-screen prompts to answer each question by entering the number corresponding to your chosen answer.

## Customizing Questions

To modify the quiz questions, edit the `quizData` initialization in the `QuizApp` constructor. Each question consists of:

- Question text
- Vector of answer options
- Correct answer (must match one of the options exactly)

Example format:
```cpp
{
    "Your question text here?",
    {"Option 1", "Option 2", "Option 3", "Option 4"},
    "Option 2"  // The correct answer
}
```

## Project Structure

- `quiz_app.cpp`: Contains the entire application code
  - `Question` struct: Defines the structure for quiz questions
  - `QuizApp` class: Manages the quiz flow and user interaction
  - `main()`: Entry point that creates and runs the quiz

## Future Enhancements

Possible improvements to consider:

- Loading questions from external files (JSON, CSV, etc.)
- Adding timer functionality
- Supporting different question types (true/false, fill-in-the-blank)
- Implementing difficulty levels
- Adding color to the console output
- Creating a statistics tracking system

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- Original concept based on a Python Tkinter implementation
- Inspired by educational quiz applications

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.
