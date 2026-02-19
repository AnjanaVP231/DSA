#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024

// Simplistic type size mapping (assuming typical 64-bit architecture)
int get_type_size(const char *type) {
    if (strstr(type, "char")) return 1;
    if (strstr(type, "short")) return 2;
    if (strstr(type, "int")) return 4;
    if (strstr(type, "float")) return 4;
    if (strstr(type, "double")) return 8;
    if (strstr(type, "long")) return 8;
    return 0;
}

// Check if a line starts with a data type
int starts_with_type(const char *line, char *type_buffer) {
    const char *types[] = {"int", "char", "float", "double", "long", "short"};
    int num_types = 6;
    
    for (int i = 0; i < num_types; i++) {
        // Check if line starts with type followed by space
        size_t len = strlen(types[i]);
        if (strncmp(line, types[i], len) == 0 && isspace(line[len])) {
            strcpy(type_buffer, types[i]);
            return 1;
        }
    }
    return 0;
}

// Parse the declaration part, e.g., "a, b[10], *c"
int calculate_memory(const char *type, char *decl_part) {
    int total = 0;
    int base_size = get_type_size(type);
    
    if (base_size == 0) return 0;

    // Use strtok to split by comma
    // Note: strtok modifies the string, so we operate on a copy if needed, 
    // but here decl_part is already a buffer we can modify.
    char *token = strtok(decl_part, ",;");
    
    while (token != NULL) {
        // Analyze each variable: "a", "b[10]", "*c"
        // 1. Check for pointer
        if (strchr(token, '*')) {
            total += 8; // Pointer size on 64-bit
            // Note: int *arr[10] would be array of pointers, this logic is simple for scalar pointers
            // Let's refine for arrays of pointers if brackets exist
        } else {
            // Not a pointer (or array of values)
            // 2. Check for array
            char *bracket_open = strchr(token, '[');
            char *bracket_close = strchr(token, ']');
            
            if (bracket_open && bracket_close) {
                 // It's an array
                *bracket_close = '\0';
                int count = atoi(bracket_open + 1);
                total += base_size * count;
            } else {
                // Scalar variable
                total += base_size;
            }
        }
        
        token = strtok(NULL, ",;");
    }
    
    return total;
}

int main(int argc, char *argv[]) {
    char filename[256];
    
    // Allow filename as argument or prompt
    if (argc == 2) {
        strcpy(filename, argv[1]);
    } else {
        printf("Enter filename to analyze: ");
        if (scanf("%s", filename) != 1) return 1;
    }

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    char line[MAX_LINE];
    char clean_line[MAX_LINE];
    int total_static_memory = 0;
    
    printf("\n--- Analyzing Static Memory ---\n");

    while (fgets(line, sizeof(line), file)) {
        // Remove leading whitespace
        char *ptr = line;
        while(isspace((unsigned char)*ptr)) ptr++;
        
        // Skip comments and preprocessor
        if (*ptr == '\0' || *ptr == '/' || *ptr == '#') continue; 
        
        // Copy to clean buffer to work with
        strcpy(clean_line, ptr);
        
        // Check for recognized type
        char type[20];
        if (starts_with_type(clean_line, type)) {
            // Found a declaration line
            // Pointer to start of variables (after type)
            char *vars = clean_line + strlen(type);
            
            int mem = calculate_memory(type, vars);
            
            // Remove newline for display
            char *nl = strchr(line, '\n');
            if(nl) *nl = 0;
            
            printf("Line: '%s' -> %d bytes\n", line, mem);
            total_static_memory += mem;
        }
    }

    fclose(file);
    printf("\n--------------------------------\n");
    printf("Total Static Memory Required: %d bytes\n", total_static_memory);

    return 0;
}
