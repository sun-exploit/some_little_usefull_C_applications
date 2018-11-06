#include <stdio.h>
#include <stdlib.h>

#include "recuperationQR.h"
#include "recuperationFORMAT.h"
#include "transcription.h"

int main(void)
{
    init_tableau_QR();
    recuperation_QR();
    affich_tableau_QR();

    initialisation_MASK_FORMAT();
    recuperation_FORMAT();
    application_MASK_FORMAT();

    trans_taux_correction();
    trans_masque();

    init_tableau_MASK_QR();
    recuperation_MASK_QR();
    application_MASK_QR();

    trans_modeencod();
    trans_taillemessage();
    trans_message();

    affich_tableau_QR();

    return EXIT_SUCCESS;
}
