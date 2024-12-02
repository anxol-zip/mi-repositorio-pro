import random
import unicodedata

class Hangman:
    def __init__(self, difficulty):
        self.difficulty_map = {
            "easy": ["taco", "sol", "gato", "flor"],
            "medium": ["mercado", "cactus", "tijeras", "pelota"],
            "hard": ["quetzal", "mezcal", "esfinge", "crisalida"]
        }
        self.difficulty = difficulty
        self.word = self._normalize(random.choice(self.difficulty_map[difficulty]))
        self.word_length = len(self.word)
        self.display_word = ["_"] * self.word_length
        self.remaining_attempts = 6
        self.correct_guesses = 0
        self.status = "ongoing"

    def _normalize(self, text):
        return ''.join(
            c.lower() for c in unicodedata.normalize('NFD', text)
            if unicodedata.category(c) != 'Mn'
        )

    def guess(self, letter):
        if self.status != "ongoing":
            return {"message": "Game already finished", "status": self.status}

        letter = self._normalize(letter)
        if len(letter) != 1:
            return {"message": "Invalid input. Please enter one letter."}

        if letter in self.display_word:
            return {"message": "Letter already guessed."}

        correct = False
        for i, char in enumerate(self.word):
            if char == letter and self.display_word[i] == "_":
                self.display_word[i] = letter
                self.correct_guesses += 1
                correct = True

        if not correct:
            self.remaining_attempts -= 1

        if self.correct_guesses == self.word_length:
            self.status = "won"
            return {"message": "Congratulations! You've guessed the word.", "status": self.status}

        if self.remaining_attempts == 0:
            self.status = "lost"
            return {"message": f"Game Over. The word was: {self.word}", "status": self.status}

        return {
            "message": "Correct!" if correct else "Incorrect!",
            "display_word": "".join(self.display_word),
            "remaining_attempts": self.remaining_attempts,
            "status": self.status
        }
