# !/bin/bash
flex -l bibtex_to_xml_converter.l
yacc -vd bibtex_to_xml_converter.y
gcc lex.yy.c y.tab.c -lm -ll