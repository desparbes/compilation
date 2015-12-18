enum {
    INT_T,
    FLOAT_T,
    PTRI_T,
    PTRF_T,
    VOID_T
};

typedef struct gen_s {
    char *code;
    int type;
    char *var;
} gen_t;
