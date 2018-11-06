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
nom_du_projet=`basename `pwd``
#nom_du_projet=$nom_du_projet

#nom du fichier d'en-tête par défaut my_header21868.h
nom_du_fichier=my_header${RANDOM}

# licence par défaut // il faut que cette licence coïncide
# avec la licence choisie pour le reste du projet
licence="GPL v2"
licence_website="http://www.gnu.org/licenses/gpl-2.0.html"

# répertoire contenant les fichier d'en-tête ( inc par défaut)
# en cas de modification, il faudra ajouter 
# ce nouveau répertoire dans la liste "" dans le Makefile
include=inc

# mettez votre nom
auteur="Eric Bachard"
date=`date`

###############
#  Fonctions  #
###############

function NOM_DU_FICHIER()
{
  __NOM_FICHIER_H__="__`echo ${nom_du_fichier} | tr -s [a-z] [A-Z]`__H__"
}

# debug purpose // comment me
#  __NOM_FICHIER_H__="____"
# echo "__NOM_FICHIER_H__ =  "
# exit

function creer_fichier()
{

  echo -e "Création du fichier d'en tête ${nom_du_fichier}.h ... \n"
  NOM_DU_FICHIER
  if !(test -f "${include}/${nom_du_fichier}.h") ; then 
cat > ${include}/${nom_du_fichier}.h << EOF3
/*
 * Fichier d'en tête ${nom_du_fichier}.h pour le projet OSS_Sans_Baguette
 * Auteur : BLARP  / $date
 * Ce document est sous Licence $licence
 * voir : $licence_website
 */

#ifndef ${__NOM_FICHIER_H__}
#define ${__NOM_FICHIER_H__}


#endif /* ${__NOM_FICHIER_H__} */

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
 echo -e "- le nom du fichier à créer, sans utiliser de caractère espace. (par défaut : ${include}/${nom_du_fichier}.h)"
 echo -e "- la licence choisie (par défaut : GPL v2)"
 echo -e "- le nom de l'auteur original du fichier (par défaut $auteur )\n"
 echo
 attente
}

function saisie_nom_du_fichier()
{
  echo
  echo -e "Entrer le nom du fichier d'en-tête à créer :\n"
  read nom_du_fichier
  nom_du_fichier=`echo $nom_du_fichier | tr -d " "`
  echo " Nom choisi pour le fichier à créer : ${nom_du_fichier}.h"
  echo
  attente
}

function saisie_licence()
{
    local choix
    local saisie
    clear
    echo "*********************"
    PS3=
choisir la licence parmi les choix proposés : 

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
  echo "Licence actuellement choisie          : ${licence}"
  echo "Site web de référence pour la licence : ${licence_website}"
  echo "Nom du fichier à créer                : ${nom_du_fichier}.h"
  echo "Nom auteur original                   : ${auteur}"
  echo
  attente
}

function afficher_valeurs_par_defaut()
{
  auteur="Eric Bachard"
  nom_du_fichier="${nom_du_fichier}"
  licence="GPL v2"
  licence_website="http://www.gnu.org/licenses/gpl-2.0.html"
  echo -e "Choix par défaut : \n"
  echo $auteur
  echo $nom_du_fichier
  echo -e "$licence\n"
  attente
}


function choix_parametres()
{
    local reponse
    local saisie
    clear
    echo "*********************"
    PS3=`echo -e "\nEntrer une valeur pour saisir un paramètre, créer un fichier d'en tête ou quitter : "`

    select reponse in "Nom du fichier à créer" Licence Auteur "Appliquer les valeurs par défaut" "Afficher paramètres actuels" "Créer le nouveau fichier et quitter" "Quitter"
    do
        case $reponse in
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
             if test  "x$REPLY" = x0 ; then break ; fi
             echo "$REPLY n'est pas une reponse valide"
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

