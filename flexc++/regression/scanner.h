// Generated by Flexc++ V0.7.1~pre on Sat, 19 Mar 2011 09:20:59 +0100

#ifndef Scanner_H_INCLUDED_
#define Scanner_H_INCLUDED_

// $insert baseclass_h
#include "scannerbase.h"


class Scanner: public ScannerBase
{
    std::istream &d_iStream;
    std::ostream &d_oStream;
    std::string d_p;
    size_t d_line;
    long long d_offset;

    public:
        Scanner() = default;
        explicit Scanner(std::istream &iStream, std::ostream &out = std::cout);

        // $insert lexFunctionDecl
        int lex();
        std::string const &pattern() const;

    private:
        int lex__();
        int executeAction__(int ruleNr);

        void preCode__();   // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts
};

inline void Scanner::preCode__()    // optionally replace by your own code
{
    if (lineno() != d_line)
    {
        d_line = lineno();

        long long offset = d_iStream.tellg();
        d_iStream.seekg(d_offset);

        std::string line;
        getline(d_iStream, line);
        if (not line.empty())
            d_oStream << "\n"
                        "Input line " << d_line << ": " << line << '\n';

        d_offset = d_iStream.tellg();
        d_iStream.seekg(offset);
    }
}

inline Scanner::Scanner(std::istream &iStream, std::ostream &oStream)
:
    ScannerBase(iStream, oStream),
    d_iStream(iStream),
    d_oStream(oStream),
    d_line(0),
    d_offset(0)
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