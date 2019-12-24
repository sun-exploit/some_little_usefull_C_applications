* Copyright Eric Bachard  24 décembre 2019

 licence GPL V2


* Algorithme du programme

    booléen bQuit vaut FAUX

    entier court offset (vaut 3 par défaut)
    tableau de caractères chaine_a_chiffrer    // longueur maxi = 512
    tableau de caractères chaine_modifiee  // de même longueur que chaine_saisie
    affecter 3 à offset

    DÉBUT sous-programme créer chaîne modifiée
        TANT QUE caractère lu dans chaine_a_chiffrer est un caractère
            FAIRE :
                ajouter offset à la valeur décimale de caractère
                ÉCRIRE le caractère dans chaine_modifiée
        FIN TANT QUE
    FIN sous-programme


    DÉBUT sous-programme rafraichir l'affichage
        effacer l'écran
        ECRIRE chaine_a_chiffrer
        ÉCRIRE la valeur du DÉCALAGE
        créer chaine_modifiée
        ECRIRE chaine_modifiee
    FIN sous-programme

    DÉBUT sous-programme saisir_nouvelle_chaine
        LIRE chaine_a_chiffrer
        rafraichir- l'affichage
    FIN sous-programme


    DÉBUT PROGRAMME PRINCIPAL

        LIRE chaine_a_chiffrer
        rafraichir l'affichage

        FAIRE :
            caractère au clavier vaut 0  // chaine vide
            attendre caractère au clavier

            TESTER caractère :

                DANS LE CAS OÙ caractère vaut ESC
                     FAIRE : bQuit vaut VRAI
                TERMINÉ

                DANS LE CAS OÙ caractère vaut ALT
                     FAIRE : saisir_nouvelle_chaine()
                TERMINÉ

                DANS LE CAS OÙ caractère vaut " +"
                    FAIRE :
                        incrémenter offset
                        rafraichir l'affichage()
                    TERMINÉ

                DANS LE CAS OÙ caractère vaut " - "
                    FAIRE :
                        décrémenter offset
                        rafraichir l'affichage()
                TERMINÉ

                PAR DÉFAUT:
                    FAIRE:
                TERMINÉ

            FIN TEST caractère

        TANT QUE bQuit vaut FAUX

    FIN PROGRAMME PRINCIPAL


