#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "e4c.h"

/**
    *   - `#RuntimeException`
     *     - `#NotEnoughMemoryException`
     *     - `#AssertionException`
     *     - `#IllegalArgumentException`
     *     - `#InputOutputException`
    */

//                   name                       default message                supertype
E4C_DEFINE_EXCEPTION(LogicException           , "logic error."              , RuntimeException);
E4C_DEFINE_EXCEPTION(TypeException            , "type error."               , RuntimeException);
E4C_DEFINE_EXCEPTION(SyntaxException          , "syntax error."             , RuntimeException);
E4C_DEFINE_EXCEPTION(CallException            , "call error."               , RuntimeException);
E4C_DEFINE_EXCEPTION(CastException            , "cast error."               , RuntimeException);
E4C_DEFINE_EXCEPTION(AllocException           , "alloc error."              , RuntimeException);
E4C_DEFINE_EXCEPTION(FunctionCallException    , "function_call error."      , RuntimeException);
E4C_DEFINE_EXCEPTION(DomainException          , "domain error"              , LogicException);
E4C_DEFINE_EXCEPTION(ArgumentException        , "invalid_argument error"    , LogicException);
E4C_DEFINE_EXCEPTION(LengthException          , "length error"              , LogicException);
E4C_DEFINE_EXCEPTION(OutOfRangeException      , "out_of_range error"        , LogicException);


#endif
