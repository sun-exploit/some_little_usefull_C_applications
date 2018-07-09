#!/bin/bash

# Auteur de ce script : Eric Bachard / 1er Avril 2015
# Licence : GPL v2
# voir : voir : http://www.gnu.org/licenses/gpl-2.0.html
#
# Ce script permet de créer un nouveau projet
# - choix du nom du projet
# - choix de la licence
# - choix de l'auteur original
# - inclusion de la date de création
# - création de l'arborescence (build / inc / sources / ressources
# - creation d'un Makefile utilisant les données précédemment choisies
# => adapter le Makefile à votre système d'exploitation
# - création d'un fichier d'en-tête .c
# - création automatique d'un script qui permet de créer des fichiers
# d'en-tête (nom / auteur / licence )
# - le nom du projet, l'auteur, la date, la licence + le lien 
# sont automatiquement insérés dans l'en-tête
# en incluant la protection contre l'inclusion multiple
# ajout de flags pour une compilation un peu plus sécurisée
# ajout de LD_FLAGS = -lm (édition de lien avec la libmath, surtout sous Linux
# TODO : des suggestions ?


current=`basename \`pwd\``
echo "truc = $current"

current_OS=`uname`
echo "current_OS = $current_OS"

if test "$current_OS" = "Darwin"
 then my_OS=MacOSX
else
 my_OS=Linux
fi

echo "my_OS contient $my_OS"
#exit

# valeurs par défaut
nom_du_projet="nouveau_projet"
licence="GPL v2"
licence_website="http://www.gnu.org/licenses/gpl-2.0.html"
# mettez votre nom
auteur="Eric Bachard"
date=`date`

function attente()
{
 echo "appuyer sur la touche entrée pour continuer ..."
 read
 clear
}

function afficher_valeurs_initiales()
{
 echo
 echo -e "Ce script permet de créer un nouveau projet"
 echo
 echo -e "Pour cela, il faut définir plusieurs choses : \n"
 echo -e "- le nom du projet, sans utiliser de caractère espace. (par défaut : nouveau_projet)"
 echo -e "- la licence choisie (par défaut : GPL v2)"
 echo -e "- le nom de l'auteur du projet (par défaut Eric Bachard )\n"
 echo
 attente
}

function saisie_nom_du_projet()
{
  echo
  echo -e "Entrer le nom du projet :\n"
  read nom_du_projet
  nom_du_projet=`echo $nom_du_projet | tr -d " "`
  echo " Nom choisi pour le projet : $nom_du_projet"
  echo
  attente
}

function saisie_licence()
{
    local choix
    local saisie
    clear
    echo "*********************"
    PS3=`echo -e "\nchoisir la licence parmi les choix proposés : "`

    select choix in "GPL v2" "GPL v3" LGPL BSD "Apple Public Source License" "Apache License 1.1"
    do
      case $choix in
        "GPL v2")
           licence="GPL v2"
           licence_website="http://www.gnu.org/licenses/gpl-2.0.html"
           break
           ;;
         "GPL v3")
           licence="GPL v3"
           licence_website="http://www.gnu.org/licenses/gpl-3.0.html"
           break
           ;;
         LGPL)
           licence="LGPL"
           licence_website="http://www.gnu.org/licenses/lgpl-3.0.html"
           break
           ;;
         BSD)
           licence=BSD
           licence_website="http://directory.fsf.org/wiki/License:BSD_4Clause"
           break
           ;;
         "Apple Public Source License")
           licence="APSL"
           licence_website="http://www.opensource.apple.com/license/apsl/"
           break
           ;;
         "Apache License 1.1")
           licence="Apache 1.1"
           licence_website="http://www.gnu.org/licenses/license-list.html#apache1.1"
           break
           ;;
      esac
    done
    attente
}

function saisie_auteur()
{
  echo
  echo -e "Entrer le nom de l'auteur original :\n"
  read auteur
  echo " Auteur original : $auteur"
  echo
  attente
}

function afficher_parametres_actuels()
{
  echo
  echo "Licence actuellement choisie          : $licence"
  echo "Site web de référence pour la licence : $licence_website"
  echo "Nom projet actuel                     : $nom_du_projet"
  echo "Nom auteur original                   : $auteur"
  echo
  attente
}

function afficher_valeurs_par_defaut()
{
  auteur="Eric Bachard"
  nom_du_projet="nouveau_projet"
  licence="GPL v2"
  licence_website="http://www.gnu.org/licenses/gpl-2.0.html"
  echo -e "Choix par défaut : \n"
  echo $auteur
  echo $nom_du_projet
  echo -e "$licence\n"
  attente
}


function choix_parametres()
{
    local reponse
    local saisie
    clear
    echo "*********************"
    PS3=`echo -e "\nEntrer une valeur pour saisir un paramètre, créer le projet ou quitter : "`

    select reponse in "Nom du Projet" Licence Auteur "Appliquer les valeurs par défaut" "Afficher paramètres actuels" "Créer le nouveau projet et quitter" "Quitter"
    do
        case $reponse in
          "Nom du Projet")
             saisie_nom_du_projet
           break
           ;;

          Licence)
             saisie_licence
           break
           ;;

          Auteur)
            saisie_auteur
           break
           ;;

         "Appliquer les valeurs par défaut")
             afficher_valeurs_par_defaut
           break
           ;;

         "Afficher paramètres actuels")
             afficher_parametres_actuels
           break
           ;;

         "Créer le nouveau projet et quitter")
             #cosmetic
             creation_projet
             exit
           break
           ;;
         "Quitter")
             exit
           break
           ;;

          *)
             if test  "x$REPLY" = x0 ; then break ; fi
             echo "$REPLY n'est pas une reponse valide"
             echo
           ;;
        esac

    done
}


function creation_arborescence()
{
  for directory in build sources inc ressources images sound doc
  do
    mkdir -p $nom_du_projet/$directory
  done
}


function creation_Makefile_Linux()
{

cat > $nom_du_projet/Makefile-Linux << EOF
# Makefile pour le projet $nom_du_projet
# Auteur : $auteur  / $date
# Ce document est sous Licence $licence
# voir : $licence_website

BUILD_DIR = build
VERSION_MAJOR = 0
VERSION_MINOR = 7
VERSION = \${VERSION_MAJOR}.\${VERSION_MINOR}

SOURCES_DIR = sources
APPLICATION_NAME = FIXME
BINARY_NAME = \${BUILD_DIR}/\${APPLICATION_NAME}
CC = gcc
CC_FLAGS = -Wall -ansi -pedantic
CC_STD = -std=c99
OS_FLAGS =
OUTBIN = \${BUILD_DIR}/\${APPLICATION_NAME}
OUTBIN_DEBUG = \${BUILD_DIR}/\${APPLICATION_NAME}_debug
OUTBIN_ALL = \
	\$(OUTBIN) \
	\$(OUTBIN_DEBUG)

SDL_INCLUDE_DIR = /usr/include/SDL
INCLUDE_DIR = inc
FILES = *.c
DEPS = \$^

SDL_FLAGS =
# use this when building graphical applications
#SDL_FLAGS = -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf \$(sdl-config --static-libs)

LD_FLAGS = -lm \${SDL_FLAGS}

GCC_SECURITY_FLAGS = -fstack-protector -pie -fPIE -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security

# every new function must be tested separately
QA_TESTS = 1

CFLAGS = \${CC_FLAGS} \${CC_STD} \${OS_FLAGS} -DUNIT_TESTS=\${QA_TESTS}
CFLAGS_DEBUG = -g -DDEBUG -DUNIT_TESTS=\${QA_TESTS}

OBJS = \${SOURCES_DIR}/\${FILES}


#\${BINARY_NAME}: \${OBJS}
#	\${CC} \${CFLAGS} \${GCC_SECURITY_FLAGS} -o \$@ \$^ \${LD_FLAGS}

#\${BINARY_NAME}_debug: \${OBJS}
#	\${CC} \${CFLAGS} \${GCC_SECURITY_FLAGS} \${CFLAGS_DEBUG} -o \$@ \$^ \${LD_FLAGS}

#clean:
#	\${RM} *.o \${BINARY_NAME} \${BINARY_NAME}_debug
#	\${RM} -rf \${BINARY_NAME}_debug.dSYM


ARCHIVE_EXT = .tar.gz

TO_BE_ZIPPED = \\
	sound \\
	images \\
	ressources \\
	doc \\
	inc \\
	sources \\
	Makefile-Linux \\
	Makefile-MacOSX \\
	Makefile \\
	create_header.sh \\
	en_tete.c \\
	select_OS.sh

TO_BE_ZIPPED_BINARIES = \\
	\${BUILD_DIR}


# ici commence la creation

all : \$(OUTBIN_ALL)


\$(OUTBIN) : \$(OBJS)
	\$(CC) \$(CFLAGS) \${GCC_SECURITY_FLAGS} -o \$@ \$(DEPS) -I\$(INCLUDE_DIR) \$(LD_FLAGS)

\$(OUTBIN_DEBUG) : \$(OBJS)
	\$(CC) \$(CFLAGS) \${GCC_SECURITY_FLAGS} \$(CFLAGS_DEBUG) -o \$(OUTBIN_DEBUG) \$(DEPS) -I\$(INCLUDE_DIR) \$(LD_FLAGS)

clean :
	rm -rf \$(OUTBIN) \$(OUTBIN_DEBUG) \${EXEC_NAME}_\${VERSION} \${EXEC_NAME}_\${VERSION}\${ARCHIVE_EXT}
	rm -rf \$(BUILD_DIR)/dbg*.dSYM
	rm -rf \${APPLICATION_NAME}_*
	echo Fichiers binaires supprimés.

devel: clean
	mkdir \${APPLICATION_NAME}_\${VERSION}
	mkdir -p \${APPLICATION_NAME}_\${VERSION}/build
	cp -R \${TO_BE_ZIPPED} \${APPLICATION_NAME}_\${VERSION}
	tar cvzf \${APPLICATION_NAME}_\${VERSION}\${ARCHIVE_EXT} \${APPLICATION_NAME}_\${VERSION}

archive : all
	mkdir \${APPLICATION_NAME}_\${VERSION}
	cp -R \${TO_BE_ZIPPED} \${APPLICATION_NAME}_\${VERSION}
	cp -R \${TO_BE_ZIPPED_BINARIES} \${APPLICATION_NAME}_\${VERSION}
	tar cvzf \${APPLICATION_NAME}_\${VERSION}\${ARCHIVE_EXT} \${APPLICATION_NAME}_\${VERSION}

real_clean : clean
	rm -rf \${APPLICATION_NAME}_*\${ARCHIVE_EXT}


EOF

}

function creation_Makefile_MacOSX()
{

cat > $nom_du_projet/Makefile-MacOSX << EOF
# Makefile pour le projet $nom_du_projet
# Auteur : $auteur  / $date
# Ce document est sous Licence $licence
# voir : $licence_website

APPLICATION_NAME = $nom_du_projet
VERSION = 1.1
BUILD_DIR = build
SOURCES_DIR = sources
OS_FLAGS = -DMACOSX
CC = gcc
GCC_SECURITY_FLAGS = -fstack-protector -pie -fPIE -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security
OUTBIN = \$(APPLICATION_NAME)
OUTBIN_DEBUG = dbg_\$(APPLICATION_NAME)
BINARY_NAME = \${BUILD_DIR}/\${APPLICATION_NAME}
FILES = *.c
DEPS = \$^ \$(SOURCES_DIR)/SDLmain.m
#LD_LIBRARY_PATH = \$LD_LIBRARY_PATH:/usr/local/lib

SDL_INCLUDE_DIR = \\
	-I/Library/Frameworks/SDL.framework/Versions/Current/Headers \\
	-I/Library/Frameworks/SDL_ttf.framework/Versions/Current/Headers \\
	-I/Library/Frameworks/SDL_image.framework/Versions/Current/Headers \\
	-I/Library/Frameworks/SDL_mixer.framework/Versions/Current/Headers

INCLUDE_DIR = inc

# every new function must be tested separately
QA_TESTS = 1

#CFLAGS = -I\${INCLUDE_DIR} -Wall -ansi -pedantic -std=c99 \${OS_FLAGS} \${GCC_SECURITY_FLAGS}
CFLAGS = -Wall -ansi -std=c99 \${OS_FLAGS} -DUNIT_TESTS=\${QA_TESTS}
CFLAGS_DEBUG = -g -DDEBUG -DUNIT_TESTS=\${QA_TESTS}

FRAMEWORKS =
# only needed when building graphical applications
#FRAMEWORKS = -framework Cocoa -framework SDL -framework SDL_mixer -framework SDL_image -framework SDL_ttf

#LD_FLAGS = -lm

OUTBIN_ALL = \\
	\$(OUTBIN) \\
	\$(OUTBIN_DEBUG)

ARCHIVE_EXT = .tar.gz

TO_BE_ZIPPED = \\
	sound \\
	images \\
	ressources \\
	doc \\
	inc \\
	sources \\
	Makefile-Linux \\
	Makefile-MacOSX \\
	Makefile \\
	create_header.sh \\
	en_tete.c \\
	select_OS.sh

TO_BE_ZIPPED_BINARIES = \\
        \${BUILD_DIR}

# ici commence la creation

all : \$(OUTBIN_ALL)

\$(OUTBIN) : \$(SOURCES_DIR)/\$(FILES)
	\$(CC) \$(FRAMEWORKS) \$(CFLAGS) \${GCC_SECURITY_FLAGS} -o \$(BUILD_DIR)/\$(OUTBIN) \$(DEPS) -I\$(INCLUDE_DIR) \$(SDL_FLAGS) 

\$(OUTBIN_DEBUG) : \$(SOURCES_DIR)/\$(FILES)
	\$(CC) \$(FRAMEWORKS) \$(CFLAGS) \${GCC_SECURITY_FLAGS} \$(CFLAGS_DEBUG) -o \$(BUILD_DIR)/\$(OUTBIN_DEBUG) \$(DEPS) -I\$(INCLUDE_DIR) \$(SDL_FLAGS) 

clean : archive_clean
	rm -rf \$(BUILD_DIR)/\$(OUTBIN) \$(BUILD_DIR)/\$(OUTBIN_DEBUG) \${EXEC_NAME}_\${VERSION} \${EXEC_NAME}_\${VERSION}\${ARCHIVE_EXT}
	rm -rf \$(BUILD_DIR)/dbg*.dSYM
	rm -rf \${APPLICATION_NAME}_\${VERSION}
	@echo -n "Fichiers binaires supprimés \n"

devel: clean
	mkdir \${APPLICATION_NAME}_\${VERSION}
	mkdir -p \${APPLICATION_NAME}_\${VERSION}/\$(BUILD_DIR)
	cp -R \${TO_BE_ZIPPED} \${APPLICATION_NAME}_\${VERSION}
	tar cvzf \${APPLICATION_NAME}_\${VERSION}\${ARCHIVE_EXT} \${APPLICATION_NAME}_\${VERSION}

archive : all
	mkdir \${APPLICATION_NAME}_\${VERSION}
	mkdir -p \${APPLICATION_NAME}_\${VERSION}/\$(BUILD_DIR)
	cp -R \${TO_BE_ZIPPED} \${APPLICATION_NAME}_\${VERSION}
	cp -R \${TO_BE_ZIPPED_BINARIES} \${APPLICATION_NAME}_\${VERSION}
	tar cvzf \${APPLICATION_NAME}_\${VERSION}\${ARCHIVE_EXT} \${APPLICATION_NAME}_\${VERSION}

archive_clean :
	rm -rf \${APPLICATION_NAME}_\${VERSION}\${ARCHIVE_EXT}

real_clean : clean
	rm -rf ${APPLICATION_NAME}_*${ARCHIVE_EXT}

EOF

}

function creation_select_OS.sh()
{
  echo -e "Création en-tete de select_OS.sh \n"
  cat > $nom_du_projet/select_OS.sh << EOF_3

#!/bin/bash

echo -e "Choisissez votre OS (Linux ou MacOSX) \n"

read un_choix

if test "x\$un_choix" = "xLinux"
  then
    rm -f Makefile
    ln -s Makefile-Linux Makefile
fi

if test "x\$un_choix" = "xMacOSX"
  then
    rm -f Makefile
    ln -s Makefile-MacOSX Makefile
fi

EOF_3
}

function creation_en_tete()
{
  echo -e "Création en-tete de fichier .c \n"
  cat > $nom_du_projet/en_tete.c << EOF2
/* fichier .c (fait partie de $nom_du_projet)
 * Auteur:  $auteur  / $date
 * Ce document est sous Licence : $licence
 * voir : $licence_website
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  return EXIT_SUCCESS;
}

EOF2

}


function link_Makefile()
{
 cd $nom_du_projet
 ln -s Makefile-$my_OS Makefile
 cd ..
}

function creation_projet()
{
  creation_arborescence
  creation_Makefile_Linux
  creation_Makefile_MacOSX
  link_Makefile
  creation_en_tete
  create_create_header
  make_create_header_executable
  creation_select_OS.sh
  make_select_OS_executable
  echo -e "Création du nouveau projet terminée ... \n"
}

function create_create_header()
{

cat > $nom_du_projet/create_header.sh << EOF3_create_header
#!/bin/bash

# Auteur de ce script : Eric Bachard / 1er Avril 2015
# Licence : GPL v2
# voir : voir : http://www.gnu.org/licenses/gpl-2.0.html
#
# Ce script permet de créer un nouveau fichier d'en-tête
# - choix du nom du fichier
# - choix de la licence
# - choix de l'auteur original
# - inclusion de la date de création
# - inclusion de la protection d'inclusion multiple
# - création du fichier d'en-tête .h

######################
# valeurs par défaut #
######################

# on utilise le nom du répertoire parent comme nom de projet
nom_du_projet=\`basename \`pwd\`\`
#nom_du_projet=\$nom_du_projet

#nom du fichier d'en-tête par défaut my_header$RANDOM.h
nom_du_fichier=my_header\${RANDOM}

# licence par défaut // il faut que cette licence coïncide
# avec la licence choisie pour le reste du projet
licence="GPL v2"
licence_website="http://www.gnu.org/licenses/gpl-2.0.html"

# répertoire contenant les fichier d'en-tête ( inc par défaut)
# en cas de modification, il faudra ajouter 
# ce nouveau répertoire dans la liste "$INCLUDE_DIR" dans le Makefile
include=inc

# mettez votre nom
auteur="Eric Bachard"
date=\`date\`

###############
#  Fonctions  #
###############

function NOM_DU_FICHIER()
{
  __NOM_FICHIER_H__="__\`echo \${nom_du_fichier} | tr -s [a-z] [A-Z]\`__H__"
}

# debug purpose // comment me
#  __NOM_FICHIER_H__="__`echo ${nom_du_fichier} | tr -s [a-z] [A-Z]`__"
# echo "__NOM_FICHIER_H__ =  ${__NOM_FICHIER_H__}"
# exit

function creer_fichier()
{

  echo -e "Création du fichier d'en tête \${nom_du_fichier}.h ... \n"
  NOM_DU_FICHIER
  if !(test -f "\${include}/\${nom_du_fichier}.h") ; then 
cat > \${include}/\${nom_du_fichier}.h << EOF3
/*
 * Fichier d'en tête \${nom_du_fichier}.h pour le projet $nom_du_projet
 * Auteur : $auteur  / \$date
 * Ce document est sous Licence \$licence
 * voir : \$licence_website
 */

#ifndef \${__NOM_FICHIER_H__}
#define \${__NOM_FICHIER_H__}


#endif /* \${__NOM_FICHIER_H__} */

EOF3

echo -e "Terminé ... "
  else
    echo -e "Ce fichier existe. Il faut régler ce problème avant de continuer. Stop".
    echo
  fi
}


function attente()
{
 echo "appuyer sur la touche entrée pour continuer ..."
 read
 clear
}

function afficher_valeurs_initiales()
{
 echo
 echo -e "Ce script permet de créer un nouveau fichier d'en-tête"
 echo
 echo -e "Pour cela, il faut définir plusieurs choses : \n"
 echo -e "- le nom du fichier à créer, sans utiliser de caractère espace. (par défaut : \${include}/\${nom_du_fichier}.h)"
 echo -e "- la licence choisie (par défaut : GPL v2)"
 echo -e "- le nom de l'auteur original du fichier (par défaut \$auteur )\n"
 echo
 attente
}

function saisie_nom_du_fichier()
{
  echo
  echo -e "Entrer le nom du fichier d'en-tête à créer :\n"
  read nom_du_fichier
  nom_du_fichier=\`echo \$nom_du_fichier | tr -d " "\`
  echo " Nom choisi pour le fichier à créer : \${nom_du_fichier}.h"
  echo
  attente
}

function saisie_licence()
{
    local choix
    local saisie
    clear
    echo "*********************"
    PS3=`echo -e "\nchoisir la licence parmi les choix proposés : "`

    select choix in "GPL v2" "GPL v3" LGPL BSD "Apple Public Source License" "Apache License 1.1"
    do
      case \$choix in
        "GPL v2")
           licence="GPL v2"
           licence_website="http://www.gnu.org/licenses/gpl-2.0.html"
           break
           ;;
         "GPL v3")
           licence="GPL v3"
           licence_website="http://www.gnu.org/licenses/gpl-3.0.html"
           break
           ;;
         LGPL)
           licence="LGPL"
           licence_website="http://www.gnu.org/licenses/lgpl-3.0.html"
           break
           ;;
         BSD)
           licence=BSD
           licence_website="http://directory.fsf.org/wiki/License:BSD_4Clause"
           break
           ;;
         "Apple Public Source License")
           licence="APSL"
           licence_website="http://www.opensource.apple.com/license/apsl/"
           break
           ;;
         "Apache License 1.1")
           licence="Apache 1.1"
           licence_website="http://www.gnu.org/licenses/license-list.html#apache1.1"
           break
           ;;
      esac
    done
    attente
}

function saisie_auteur()
{
  echo
  echo -e "Entrer le nom de l'auteur original :\n"
  read auteur
  echo " Auteur original : \$auteur"
  echo
  attente
}

function afficher_parametres_actuels()
{
  echo
  echo "Licence actuellement choisie          : \${licence}"
  echo "Site web de référence pour la licence : \${licence_website}"
  echo "Nom du fichier à créer                : \${nom_du_fichier}.h"
  echo "Nom auteur original                   : \${auteur}"
  echo
  attente
}

function afficher_valeurs_par_defaut()
{
  auteur="Eric Bachard"
  nom_du_fichier="\${nom_du_fichier}"
  licence="GPL v2"
  licence_website="http://www.gnu.org/licenses/gpl-2.0.html"
  echo -e "Choix par défaut : \n"
  echo \$auteur
  echo \$nom_du_fichier
  echo -e "\$licence\n"
  attente
}


function choix_parametres()
{
    local reponse
    local saisie
    clear
    echo "*********************"
    PS3=\`echo -e "\nEntrer une valeur pour saisir un paramètre, créer un fichier d'en tête ou quitter : "\`

    select reponse in "Nom du fichier à créer" Licence Auteur "Appliquer les valeurs par défaut" "Afficher paramètres actuels" "Créer le nouveau fichier et quitter" "Quitter"
    do
        case \$reponse in
          "Nom du fichier à créer")
             saisie_nom_du_fichier
           break
           ;;

          Licence)
             saisie_licence
           break
           ;;

          Auteur)
            saisie_auteur
           break
           ;;

         "Appliquer les valeurs par défaut")
             afficher_valeurs_par_defaut
           break
           ;;

         "Afficher paramètres actuels")
             afficher_parametres_actuels
           break
           ;;

         "Créer le nouveau fichier et quitter")
             #cosmetic
             creer_fichier
             exit
           break
           ;;
         Quitter)
             exit
           break
           ;;

          *)
             if test  "x\$REPLY" = x0 ; then break ; fi
             echo "\$REPLY n'est pas une reponse valide"
             echo
           ;;
        esac

    done
}


#######################
# Programme principal #
#######################

# une seule fois
clear
afficher_valeurs_initiales

while choix_parametres ; do : ; done

EOF3_create_header

}

function make_create_header_executable()
{
 chmod a+x $nom_du_projet/create_header.sh
}

function make_select_OS_executable()
{
 chmod a+x $nom_du_projet/select_OS.sh
}

# une seule fois
clear
afficher_valeurs_initiales

while choix_parametres ; do : ; done

#