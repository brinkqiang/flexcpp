// Generated by Flexc++ V0.7.1~pre on Sat, 19 Mar 2011 09:20:59 +0100

#ifndef Scanner_H_INCLUDED_
#define Scanner_H_INCLUDED_

// $insert baseclass_h
#include "scannerbase.h"


class Scanner: public ScannerBase
{
    std::istream &d_iStream;
    std::string d_p;

    public:
        Scanner() = default;
        explicit Scanner(std::istream &iStream, std::ostream &out = std::cout);

        // $insert lexFunctionDecl
        int lex();
        std::string const &pattern() const;
        void clearPattern();

    private:
        void pushStream();

        int lex__();
        int executeAction__(int ruleNr);

        void preCode__();   // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts
};

inline void Scanner::pushStream()
{
    pushStream__(match().substr(0, leng()-1));
}

inline void Scanner::clearPattern()
{
    d_p.clear();
}

inline void Scanner::preCode__()    // optionally replace by your own code
{}

inline Scanner::Scanner(std::istream &iStream, std::ostream &oStream)
:
    ScannerBase(iStream, oStream),
    d_iStream(iStream)
{}

// $insert inlineLexFunction
inline int Scanner::lex()
{
    return lex__();
}

inline std::string const &Scanner::pattern() const
{
    return d_p;
}

#endif // Scanner_H_INCLUDED_
