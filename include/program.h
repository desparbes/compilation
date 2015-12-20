#ifndef PROGRAM_H
#define PROGRAM_H

#define MAXSIZE 50

static void format_ll(char *base)
{
    char *s = strstr(base, ".cmr");
    if (s != NULL)
	s[0] = '\0';    
}

void generate_code(char *code)
{
    char *file_name_cp = strdup(file_name);
    char *base = basename(file_name_cp);
    char *path;
    format_ll(base);
    asprintf(&path, "build/%s.ll", base); 
    FILE *f = fopen(path, "w");
    if (f)
	fputs(code, f);
    else
	fprintf(stderr, "Could not open %s\n", path);
    free(path);
    free(file_name_cp);
}


#endif //PROGRAM_H
