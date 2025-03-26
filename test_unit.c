#include <stdio.h>
#include "vector.h"

// Macro pour les tests unitaires
#define ASSERT(condition) do { \
    if (!(condition)) { \
        fprintf(stderr, "Assertion échouée dans %s:%d: %s\n", __FILE__, __LINE__, #condition); \
        return 1; \
    } \
} while (0)

// Test d'allocation et de libération de mémoire
int test_vector_alloc_free() {
    p_s_vector vec = vector_alloc(5);
    ASSERT(vec != NULL);
    ASSERT(vec->size == 5);

    VectorStatus status = vector_free(&vec);
    ASSERT(status == VECTOR_SUCCESS);
    ASSERT(vec == NULL);

    return 0;
}

// Test d'insertion et de récupération d'éléments (à compléter par les étudiants)
int test_vector_set_get() {
    // À compléter
    return 0;
}

// Test d'insertion et suppression d'éléments (à compléter par les étudiants)
int test_vector_insert_erase() {
    // À compléter
    return 0;
}

// Test de la fonction vector_empty() (à compléter par les étudiants)
int test_vector_empty() {
    // À compléter
    return 0;
}

// Fonction principale exécutant les tests
int main() {
    int failed = 0;

    printf("Exécution des tests unitaires...\n");

    failed += test_vector_alloc_free();
    failed += test_vector_set_get();
    failed += test_vector_insert_erase();
    failed += test_vector_empty();

    if (failed == 0) {
        printf("Tous les tests ont réussi ! \n");
    } else {
        printf("Échecs détectés dans %d test(s). \n", failed);
    }

    return failed;
}

