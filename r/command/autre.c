#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void process_file(const char *filename, FILE *output_file) {
    FILE *input_file = fopen(filename, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier %s\n", filename);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input_file) != NULL) {
        fputs(buffer, output_file);
    }

    fclose(input_file);
}

void process_directory(const char *dirname, FILE *output_file) {
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du répertoire %s\n", dirname);
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

        if (entry->d_type == DT_DIR) {
            process_directory(path, output_file);
        } else if (entry->d_type == DT_REG) {
            process_file(path, output_file);
        }
    }

    closedir(dir);
}

int main0(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Utilisation: %s <répertoire_source> <fichier_destination>\n", argv[0]);
        return 1;
    }

    const char *source_dir = argv[1];
    const char *output_file_path = argv[2];

    FILE *output_file = fopen(output_file_path, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier de sortie %s\n", output_file_path);
        return 1;
    }

    process_directory(source_dir, output_file);

    fclose(output_file);

    printf("Le contenu des fichiers dans le répertoire %s a été écrit dans le fichier %s\n", source_dir, output_file_path);

    return 0;
}
