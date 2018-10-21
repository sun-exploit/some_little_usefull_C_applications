#include <stdlib.h>
#include <stdio.h>
#include "saisie.h"
#include "student_record.h"

int main(void)
{
    // autre possibilité :
    // struct record student1;
    RECORD student1;

    fprintf(stdout, "Nom de l'étudiant : \n");

    saisie_chaine_de_caracteres();
    strncpy(student1.identity, g_buf, sizeof(g_buf));

    fprintf(stdout, "Année de naissance ?\n");
    student1.birthdate = saisie_nombre_entier_court(0,2019);

    fprintf(stdout, "Moyenne en CS : \n");
    student1.moyenne = saisie_nombre_reel(0.0, 20.0);

    efface_ecran();

    fprintf (   stdout,
                "Le nom de l'etudiant est : %s\nSa date de naissance est : %d\nSa moyenne en CS est : %.2f\n",
                student1.identity,
                student1.birthdate,
                student1.moyenne
            );

  return EXIT_SUCCESS;
}
