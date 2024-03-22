#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mydata.h"  // Include the header to access declarations
#define TABLE_SIZE 1000

#define MAX_SUBJECT_LENGTH 50
#define MAX_SUBJECTS 100
#define MAX_CHARACTERS 100

typedef struct {
    char name[MAX_SUBJECT_LENGTH];
    int quantity;
} Subject;

typedef struct {
    char name[MAX_SUBJECT_LENGTH];
    char location[MAX_SUBJECT_LENGTH];
    Subject subjects[MAX_SUBJECTS];
    int num_subjects;
} Character;

void initializeCharacter(Character characters[], int *num_characters, const char *name, const char *start_location) {
    Character new_character;
    strcpy(new_character.name, name);
    strcpy(new_character.location, start_location);
    new_character.num_subjects = 0;
    characters[(*num_characters)++] = new_character;
}

void addSubject(Character characters[], const int num_characters, const char *character_name, const char *subject_name, const int quantity) {
    for (int i = 0; i < num_characters; i++) {
        if (strcmp(characters[i].name, character_name) == 0) {
            Character *character = &characters[i];
            if (character->num_subjects < MAX_SUBJECTS) {
                strcpy(character->subjects[character->num_subjects].name, subject_name);
                character->subjects[character->num_subjects].quantity = quantity;
                character->num_subjects++;
                printf("Added %d %s to %s's inventory.\n", quantity, subject_name, character_name);
            } else {
                printf("%s's inventory is full. Cannot add more subjects.\n", character_name);
            }
            return;
        }
    }
    printf("Character %s not found.\n", character_name);
}

void displayInventory(Character characters[], const int num_characters, const char *character_name) {
    for (int i = 0; i < num_characters; i++) {
        if (strcmp(characters[i].name, character_name) == 0) {
            printf("%s's Inventory:\n", character_name);
            printf("Location: %s\n", characters[i].location);
            printf("Subjects:\n");
            for (int j = 0; j < characters[i].num_subjects; j++) {
                printf("%s: %d\n", characters[i].subjects[j].name, characters[i].subjects[j].quantity);
            }
            return;
        }
    }
    printf("Character %s not found.\n", character_name);
}

void changeLocation(Character characters[], const int num_characters, const char *character_name, const char *new_location) {
    for (int i = 0; i < num_characters; i++) {
        if (strcmp(characters[i].name, character_name) == 0) {
            strcpy(characters[i].location, new_location);
            printf("%s's location updated to %s.\n", character_name, new_location);
            return;
        }
    }
    printf("Character %s not found.\n", character_name);
}

void increaseSubjectQuantity(Character characters[], const int num_characters, const char *character_name, const char *subject_name, const int increase) {
    for (int i = 0; i < num_characters; i++) {
        if (strcmp(characters[i].name, character_name) == 0) {
            for (int j = 0; j < characters[i].num_subjects; j++) {
                if (strcmp(characters[i].subjects[j].name, subject_name) == 0) {
                    characters[i].subjects[j].quantity += increase;
                    printf("Increased %s's %s quantity by %d.\n", character_name, subject_name, increase);
                    return;
                }
            }
            printf("%s does not have subject %s in inventory.\n", character_name, subject_name);
            return;
        }
    }
    printf("Character %s not found.\n", character_name);
}

int getSubjectQuantity(Character characters[], const int num_characters, const char *character_name, const char *subject_name) {
    for (int i = 0; i < num_characters; i++) {
        if (strcmp(characters[i].name, character_name) == 0) {
            for (int j = 0; j < characters[i].num_subjects; j++) {
                if (strcmp(characters[i].subjects[j].name, subject_name) == 0) {
                    return characters[i].subjects[j].quantity;
                }
            }
            printf("%s does not have subject %s in inventory.\n", character_name, subject_name);
            return -1; // Return a negative value to indicate subject not found
        }
    }
    printf("Character %s not found.\n", character_name);
    return -1; // Return a negative value to indicate character not found
}

int main() {
    Character characters[MAX_CHARACTERS]; // Array to store characters
    int num_characters = 0; // Keep track of the current number of characters

    // Initialize characters and add to the array
    initializeCharacter(characters, &num_characters, "Frodo", "Shire");
    addSubject(characters, num_characters, "Frodo", "Ring", 1);
    addSubject(characters, num_characters, "Frodo", "Sword", 2);
    initializeCharacter(characters, &num_characters, "Frodov2", "Shirev2");
    addSubject(characters, num_characters, "Frodov2", "Ring", 12);
    addSubject(characters, num_characters, "Frodov2", "Sword", 24);
    // Example usage: Change location of a character
    changeLocation(characters, num_characters, "Frodo", "Mordor");
    changeLocation(characters, num_characters, "Frodov2", "Mordorv2");


    // Example usage: Increase subject quantity for a character
    increaseSubjectQuantity(characters, num_characters, "Frodo", "Sword", 3);
    increaseSubjectQuantity(characters, num_characters, "Frodov2", "Sword", 3);


    // Display inventory of the character
    displayInventory(characters, num_characters, "Frodov2");

    // Get subject quantity for a character
    printf("Frodo has %d Rings.\n", getSubjectQuantity(characters, num_characters, "Frodo", "Ring"));
    printf("Frodo has %d Swords.\n", getSubjectQuantity(characters, num_characters, "Frodo", "Sword"));
    printf("Frodov2 has %d Swords.\n", getSubjectQuantity(characters, num_characters, "Frodov2", "Sword"));


    return 0;
}
