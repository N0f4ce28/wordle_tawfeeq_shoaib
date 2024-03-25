#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORD_COUNT 2309

int main() {
    // Ouvrir le fichier contenant les mots Wordle
    FILE *file = fopen("bdd_wordle.txt", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    // Allouer de la mémoire pour stocker les mots
    char *word_list = (char *)malloc(MAX_WORD_COUNT * sizeof(char *));
    if (word_list == NULL) {
        perror("Erreur lors de l'allocation de mémoire");
        return 1;
    }

    // Initialiser la liste des mots
    for (int i = 0; i < MAX_WORD_COUNT; i++) {
        word_list[i] = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));
        if (word_list[i] == NULL) {
            perror("Erreur lors de l'allocation de mémoire");
            return 1;
        }
    }

    // Lire les mots du fichier et les stocker dans la liste
    int word_count = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        strcpy(word_list[word_count], word);
        word_count++;
    }

    // Fermer le fichier
    fclose(file);

    // Afficher les mots stockés dans la liste
    printf("Mots stockés :\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\n", word_list[i]);
    }

    // Libérer la mémoire allouée pour la liste des mots
    for (int i = 0; i < word_count; i++) {
        free(word_list[i]);
    }
    free(word_list);

    return 0;
}
