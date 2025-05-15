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

// Test d'attribution et de récupération d'éléments
int test_vector_set_get() {
    p_s_vector vec = vector_alloc(5);
    ASSERT(vec != NULL);
    ASSERT(vec->size == 5);

    // Vérification de l'attribution de valeurs dans le vecteur
    for (size_t i = 0; i < vec->size; i++) {
        ASSERT(vector_set(vec, i, (double)i) == VECTOR_SUCCESS);
    }

    // Vérification de la récupération des valeurs
    for (size_t i = 0; i < vec->size; i++) {
        double value;
        ASSERT(vector_get(vec, i, &value) == VECTOR_SUCCESS);
        ASSERT(value == (double)i);
    }

    // Libération de la mémoire
    ASSERT(vector_free(&vec) == VECTOR_SUCCESS);
    ASSERT(vec == NULL);

    return 0;
}

// Test d'insertion et suppression d'éléments
int test_vector_insert_erase() {
    p_s_vector vec = vector_alloc(5);
    ASSERT(vec != NULL);
    ASSERT(vec->size == 5);
    // Initialisation de valeurs dans le vecteur
    for (size_t i = 0; i < vec->size; i++) {
        ASSERT(vector_set(vec, i, (double)i) == VECTOR_SUCCESS);
    }

    // Insertion de la valeur 10.0 à l'index 2
    ASSERT(vector_insert(vec, 2, 10.0) == VECTOR_SUCCESS);
    double value;

    // Vérification de l'insertion
    ASSERT(vector_get(vec, 2, &value) == VECTOR_SUCCESS);
    ASSERT(value == 10.0);

    // Suppression de la valeur insérée
    ASSERT(vector_erase(vec, 2) == VECTOR_SUCCESS);

    // Vérification de la suppression
    ASSERT(vector_get(vec, 2, &value) == VECTOR_SUCCESS);
    ASSERT(value == 2.0);

    // Libération de la mémoire
    ASSERT(vector_free(&vec) == VECTOR_SUCCESS);
    ASSERT(vec == NULL);

    return 0;
}

// Test de la fonction vector_empty()
int test_vector_empty() {

    // Test vecteur nul
    p_s_vector vec = vector_alloc(0);
    ASSERT(vec != NULL);
    ASSERT(vec->size == 0);
    ASSERT(vector_empty(vec) == VECTOR_SUCCESS);
    // Libération de la mémoire
    ASSERT(vector_free(&vec) == VECTOR_SUCCESS);
    ASSERT(vec == NULL);

    // Test vecteur non nul
    vec = vector_alloc(5);
    ASSERT(vec != NULL);
    ASSERT(vec->size == 5);
    ASSERT(vector_set(vec, 0, 1.0) == VECTOR_SUCCESS);
    ASSERT(vector_empty(vec) == VECTOR_ERROR_NOT_EMPTY);
    // Libération de la mémoire
    ASSERT(vector_free(&vec) == VECTOR_SUCCESS);
    ASSERT(vec == NULL);

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

