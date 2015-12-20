#ifndef LLVM_H
#define LLVM_H

char *get_type(int type)
{
    switch(type) {
    case INT_T:
	return "i32";
	break;
    case FLOAT_T:
	return "float";
	break;
    case PTRI_T:
	return "i32*";
	break;    
    case PTRF_T:
	return "float*";
	break;
    case VOID_T:
	return "void";
	break;
    default:
	return "unknown type";
	break;
    }
}

char *get_add(int type)
{
    switch(type) {
    case INT_T:
	return "add";
	break;
    case FLOAT_T:
	return "addf";
	break;
    default:
	return "unknown addition";
	break;
    }
}

char *get_sub(int type)
{
    switch(type) {
    case INT_T:
	return "sub";
	break;
    case FLOAT_T:
	return "fsub";
	break;
    default:
	return "unknown substraction";
	break;
    }
}

char *get_mul(int type)
{
    switch(type) {
    case INT_T:
	return "mul";
	break;
    case FLOAT_T:
	return "fmul";
	break;
    default:
	return "unknown multiplication";
	break;
    }
}

char *get_div(int type)
{
    switch(type) {
    case INT_T:
	return "sdiv";
	break;
    case FLOAT_T:
	return "fdiv";
	break;
    default:
	return "unknown division";
	break;
    }
}

#endif
