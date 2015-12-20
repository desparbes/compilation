enum {
    INT_T,
    PTRI_T,
    FLOAT_T,
    PTRF_T,
    VOID_T
};

typedef struct gen_s {
    char *code;
    int type;
    char *var;
    char* id;
} gen_t;
