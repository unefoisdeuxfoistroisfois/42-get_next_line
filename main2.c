#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void test_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        printf("❌ Erreur d'ouverture de %s\n", filename);
        return;
    }

    printf("\n🔍 Test du fichier [%s] :\n", filename);
    char *line;
    int line_count = 1;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Ligne %d: [%s]\n", line_count++, line);
        free(line); // Libération systématique
    }

    close(fd);
    printf("✅ Fin du fichier %s\n", filename);
}

void test_stdin() {
    printf("\n📝 Test STDIN (tapez du texte puis CTRL+D) :\n");
    char *line;
    int line_count = 1;
    while ((line = get_next_line(0)) != NULL) { // FD 0 = stdin
        printf("Ligne %d: [%s]\n", line_count++, line);
        free(line);
    }
    printf("✅ Fin de STDIN\n");
}

int main(int argc, char **argv) {
    printf("=== TEST GNL (BUFFER_SIZE=%d) ===\n", BUFFER_SIZE);

    // 1. Tests avec fichiers
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            test_file(argv[i]);
        }
    } else {
        printf("\n⚠️  Aucun fichier spécifié, tests par défaut :\n");
        test_file("test1.txt"); // À créer avec différents cas
        test_file("empty.txt"); // Fichier vide
    }

    // 2. Test entrée standard (optionnel)
    // test_stdin();

    // 3. Test multi-FD (similaire à Francinette)
    printf("\n🧪 Test multi-FD :\n");
    int fd1 = open("f1.txt", O_RDONLY);
    int fd2 = open("f2.txt", O_RDONLY);
    
    char *line;
    line = get_next_line(fd1);
    printf("FD1-L1: [%s]\n", line);
    free(line);
    
    line = get_next_line(fd2);
    printf("FD2-L1: [%s]\n", line);
    free(line);
    
    close(fd1);
    close(fd2);
    printf("✅ Fin du test multi-FD\n");

    // 4. Vérification leaks mémoire statique
    printf("\n🔎 Vérification leaks mémoire statique :\n");
    line = get_next_line(42); // FD invalide
    if (line == NULL) printf("✔️  Gestion FD invalide OK\n");
    
    printf("\n=== FIN DES TESTS ===\n");
    return (0);
}
