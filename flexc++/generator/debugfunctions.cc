#include "generator.ih"

void Generator::debugFunctions(std::ostream &out) const
{
    if (!d_debug)
        return;

    key(out);

    out << 
    "std::ostringstream " << d_baseclassScope << "s_out__;\n"
    "\n" 
    "std::ostream &" << d_baseclassScope << "dflush__(std::ostream &out)\n"
    "{\n"
    "    std::ostringstream &s_out__ = "
                            "dynamic_cast<std::ostringstream &>(out);\n"
    "\n"
    "    std::cout << \"    \" << s_out__.str() << std::flush;\n"
    "    s_out__.clear();\n"
    "    s_out__.str(\"\");\n"
    "    return out;\n"
    "}\n";
}

//        "std::string " << d_baseclassScope << "stype__(char const *pre, "
//                          "STYPE__ const &semVal, char const *post) const\n"
//        "{\n";
//
//        if (d_arg.option(0, "insert-stype"))
//            out <<
//            "    using namespace std;\n"
//            "    ostringstream ostr;\n"
//            "    ostr << pre << semVal << post;\n"
//            "    return ostr.str();\n";
//        else
//            out <<
//            "    return \"\";\n";
//        out << 
//        "}\n";

//    if (d_debug || d_print)
//        out <<
//        "std::string " << d_baseclassScope << "symbol__(int value) const\n"
//        "{\n"
//        "    using namespace std;\n"
//        "    ostringstream ostr;\n"
//        "    SMap::const_iterator it = s_symbol.find(value);\n"
//        "    if (it != s_symbol.end())\n"
//        "        ostr << \"`\" << it->second << \"'\";\n"
//        "    else if (isprint(value))\n"
//        "        ostr << \"`\" << static_cast<char>(value) << ""\"' "
//                                                    "(\" << value << \")\";\n"
//        "    else\n"
//        "        ostr << \"'\\\\x\" << setfill('0') << hex << setw(2) << "
//                                                        "value << \"'\";\n"
//        "    return ostr.str();\n"
//        "}\n"
//        "\n";
//
//    if (verbose)
//        out <<
//        "void " << d_baseclassScope << "errorVerbose__()\n"
//        "{\n"
//        "    std::cout << \"Parser State stack containing \" << "
//                                "(d_stackIdx__ + 1) << \" \"\n" <<
//        setw(70) << "" << "\"elements:\\n\"\n" <<
//        "                 \"Each line shows a stack index followed by the "
//                                            "value of that stack \"\n" <<
//        setw(70) << "" << "\"element\\n\";\n" <<
//        "    for (size_t idx = d_stackIdx__ + 1; idx--; )\n" <<
//        "       std::cout << std::setw(2) << idx << \": \" << \n"
//        "                    std::setw(3) << d_stateStack__[idx] << "
//                                                                "\"\\n\";\n"
//        "}\n";







