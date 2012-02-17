#include "generator.ih"

void Generator::debug(ostream &out) const
{
    if (!d_debug)
        return;

    key(out);

    out << indent << "if (s_debug__)\n" <<
           indent << "    " << flush;

    if (*d_line.rbegin() != '+')
        out <<  "s_out__ << " << d_line << " << \"\\n\" << dflush__;\n";
    else
    {
        d_line.resize(d_line.length() - 1);
        out <<  "s_out__ << " << d_line << ";\n";
    }
}
