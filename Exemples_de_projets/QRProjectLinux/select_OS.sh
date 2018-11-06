
#!/bin/bash

echo -e "Choisissez votre OS (Linux ou MacOSX) \n"

read un_choix

if test "x$un_choix" = "xLinux"
  then
    rm -f Makefile
    ln -s Makefile-Linux Makefile
fi

if test "x$un_choix" = "xMacOSX"
  then
    rm -f Makefile
    ln -s Makefile-MacOSX Makefile
fi

