#include <stdio.h>
#include <string.h>

// Function to check if the name already exists in the phonebook
int name_exists(const char* name) {
    FILE *file = fopen("phonebook.txt", "r");
    if (!file) {
        perror("Failed to open phonebook.txt");
        return -1; // Error in opening file
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char file_name[100];
        int i = 0;

        // Extract name from the line
        while (line[i] != ',' && line[i] != '\0') {
            file_name[i] = line[i];
            i++;
        }
        file_name[i] = '\0'; // Null-terminate the file_name

        // Compare the extracted name with the input name
        if (strcmp(name, file_name) == 0) {
            fclose(file);
            return 1; // Name exists
        }
    }

    fclose(file);
    return 0; // Name does not exist
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <FullName,> <PhoneNumber>\n", argv[0]);
        return 1;
    }

    // Remove trailing comma from name if it exists
    char name[100];
    strncpy(name, argv[1], sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';

    int len = strlen(name);
    if (name[len - 1] == ',') {
        name[len - 1] = '\0';
    }

    // Check if the name already exists in the phonebook
    if (name_exists(name)) {
        printf("This person already exists in the phonebook.\n");
        return 0; // Don't add again
    }


    // Open phonebook file to append the new entry
    FILE* fp = fopen("phonebook.txt", "a");
    if (!fp) {
        perror("Failed to open phonebook.txt");
        return 1;
    }

    // Add the new entry to the phonebook
    fprintf(fp, "%s,%s\n", name, argv[2]);

    fclose(fp);
    return 0;
}
