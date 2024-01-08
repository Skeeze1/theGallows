#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Функция для печати состояния виселицы
void printHangman(int tries) {
    if (tries >= 1) {
        cout << "   ___  " << endl;
    }
    if (tries >= 2) {
        cout << "  |   | " << endl;
    }
    if (tries >= 3) {
        cout << "  |   O " << endl;
    }
    if (tries == 4) {
        cout << "  |  /|\\ " << endl;
    }
    if (tries == 5) {
        cout << "  |  /|\\ " << endl;
        cout << "  |  /   " << endl;
    }
    if (tries >= 6) {
        cout << "  |  /|\\ " << endl;
        cout << "  |  / \\ " << endl;
    }
    cout << " _|_" << endl;
}

// Функция для печати текущего состояния слова
void printWordState(const string& word, const vector<bool>& guessedLetters) {
    cout << endl << "Слово: ";
    for (int i = 0; i < word.length(); i++) {
        if (guessedLetters[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Функция для обработки введенной буквы
bool processLetter(char letter, const string& word, vector<bool>& guessedLetters) {
    bool correctGuess = false;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter) {
            guessedLetters[i] = true;
            correctGuess = true;
        }
    }
    return correctGuess;
}

int main() {
    string word = "программирование"; // Слово, которое нужно угадать
    int maxTries = 6; // Максимальное количество попыток
    int tries = 0; // Текущее количество попыток
    vector<bool> guessedLetters(word.length(), false); // Вектор для отслеживания угаданных букв

    cout << "Добро пожаловать в игру \"Виселица\"!" << endl;
    cout << "Попробуйте угадать слово. У вас " << maxTries << " попыток." << endl;

    while (tries < maxTries) {
        printHangman(tries);
        printWordState(word, guessedLetters);

        cout << "Введите букву: ";
        char letter;
        cin >> letter;

        if (processLetter(letter, word, guessedLetters)) {
            cout << "Правильно! Буква \"" << letter << "\" есть в слове." << endl;
        } else {
            cout << "Неправильно! Буквы \"" << letter << "\" нет в слове." << endl;
            tries++;
        }

        bool wordGuessed = true;
        for (bool guessed : guessedLetters) {
            if (!guessed) {
                wordGuessed = false;
                break;
            }
        }

        if (wordGuessed) {
            cout << endl << "Поздравляем! Вы угадали слово \"" << word << "\"!" << endl;
            break;
        }
    }

    if (tries == maxTries) {
        cout << endl << "К сожалению, вы проиграли. Загаданное слово было \"" << word << "\"." << endl;
    }

    return 0;
}
