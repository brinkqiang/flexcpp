#include "generator.ih"

void Generator::classIH(ostream &out) const
{
    key(out);
    out << "#include \"" << d_options.implementationHeaderName() << "\"\n";
}
