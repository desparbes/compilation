enum {
    INT_T,
    FLOAT_T
};

typedef struct gen_t {
    char *code;
    int type;
    char *var;
} gen_t;
