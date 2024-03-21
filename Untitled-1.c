#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1000
#define MAX_TOKENS 50

// Define the set of keywords
const char *keywords[] = {
    "buy", "from", "sell", "to", "go", "at", "has", "if", "less", "more", "than", "exit", "where", "total", "who",
    "NOBODY", "NOTHING", "NOWHERE", "and"
};

// Function to tokenize the input string
int tokenize(char *input, char *tokens[]) {
    const char delimiters[] = " ,.";
    char *token;
    int count = 0;

    // Tokenize the input string
    token = strtok(input, delimiters);
    while (token != NULL && count < MAX_TOKENS) {
        tokens[count++] = token;
        token = strtok(NULL, delimiters);
    }

    return count;
}

// Function to check if a token is a keyword
bool is_keyword(char *token) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Function to parse the input sentence
void parse_sentence(char *tokens[], int count) {
    bool valid = true;
    int i = 0;

    // Check for valid subject(s)
    while (i < count && !is_keyword(tokens[i])) {
        // Check if the subject contains only letters or underscores
        for (int j = 0; tokens[i][j] != '\0'; j++) {
            if (!isalpha(tokens[i][j]) && tokens[i][j] != '_') {
                valid = false;
                break;
            }
        }
        if (!valid) break;
        i++;
    }

    // Check if the next token is a keyword "buy" or "sell"
    if (i < count && (strcmp(tokens[i], "buy") == 0 || strcmp(tokens[i], "sell") == 0)) {
        i++;
        // Check for valid item(s)
        while (i < count && !is_keyword(tokens[i])) {
            // Check if the item contains only letters or underscores
            for (int j = 0; tokens[i][j] != '\0'; j++) {
                if (!isalpha(tokens[i][j]) && tokens[i][j] != '_') {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
            i++;
        }
        // Check for keyword "from" or "to"
        if (i < count && (strcmp(tokens[i], "from") == 0 || strcmp(tokens[i], "to") == 0)) {
            i++;
            // Check for valid subject
            if (i < count && !is_keyword(tokens[i])) {
                // Check if the subject contains only letters or underscores
                for (int j = 0; tokens[i][j] != '\0'; j++) {
                    if (!isalpha(tokens[i][j]) && tokens[i][j] != '_') {
                        valid = false;
                        break;
                    }
                }
                i++;
            } else {
                valid = false;
            }
        } else {
            valid = false;
        }
    } else {
        valid = false;
    }

    // Output result
    if (valid && i == count) {
        // Print parsed sentence
        for (int j = 0; j < count; j++) {
            printf("%s ", tokens[j]);
        }
        printf("\n");
    }
}
void parse_sentence(char *tokens[], int count) {
    // Print the tokens
    for (int i = 0; i < count; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");
}
int main() {
    char input[MAX_LENGTH];
    char *tokens[MAX_TOKENS];
    int count;

    // Read input until "exit" command is entered
    while (true) {
        // Read input sentence
        printf("Enter a sentence: ");
        fgets(input, MAX_LENGTH, stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Check if input is "exit" command
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Tokenize the input
        count = tokenize(input, tokens);

        // Parse the input sentence
        parse_sentence(tokens, count);
    }

    return 0;
}
