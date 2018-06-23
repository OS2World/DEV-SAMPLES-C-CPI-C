/*
 *  PROGRAM:   JQCPIC -- John Q's Portable CPI-C Abuser
 *
 *  MODULE:    CMDLIN.C -- process the command line parameters
 *
 *  COPYRIGHTS:
 *             This module contains code made available by IBM
 *             Corporation on an AS IS basis.  Any one receiving the
 *             module is considered to be licensed under IBM copyrights
 *             to use the IBM-provided source code in any way he or she
 *             deems fit, including copying it, compiling it, modifying
 *             it, and redistributing it, with or without
 *             modifications.  No license under any IBM patents or
 *             patent applications is to be implied from this copyright
 *             license.
 *
 *             A user of the module should understand that IBM cannot
 *             provide technical support for the module and will not be
 *             responsible for any consequences of use of the program.
 *
 *             Any notices, including this one, are not to be removed
 *             from the module without the prior written consent of
 *             IBM.
 *
 *  AUTHOR:    Dr. John Q. Walker II
 *             IBM VNET: JOHNQ at RALVM6          IBM tie line: 444-4414
 *             Internet: johnq@vnet.ibm.com        phone: (919) 254-4414
 *
 *  RELATED FILES:
 *             See file JQCPIC.DOC for detailed information.
 *
 *  CHANGE HISTORY:
 *  Date       Description
 *  05/12/92   Added prologue.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jqcpic.h"

void command_line(int argc, char *argv[])
{
    /*=========================================================================
     * Process the command line arguments.
     *=======================================================================*/

    if (1 < argc) {
        if (strlen(argv[1]) < MAX_SYM_DEST_NAME) {
            memset((void *)sym_dest_name, (int)' ', MAX_SYM_DEST_NAME);
            strcpy(sym_dest_name, argv[1]);
            sym_dest_name[strlen(sym_dest_name)] = ' ';
        }
        else {
            write_error("destination name is longer than %u "
                        "characters\n", SYM_DEST_NAME_LENGTH);
            usage();
            exit(EXIT_FAILURE);
        }
    }
    else {
        usage();
        exit(EXIT_FAILURE);
    }

    return;
}


char *get_program_name(char *zInput)
{
    /*=========================================================================
     * Move from the right end of the input string (presumably a program
     * name) towards the left, looking for a slash or backslash.
     *=======================================================================*/

    char *zOutput = zInput;
    size_t nLength = strlen(zInput);

    for(; (*zInput != NULL_CHARACTER); zInput++) {
        *zInput = (char)toupper((int)*zInput);
    }
    for (; (--nLength); ) {
        if ((zOutput[nLength] == BACKSLASH) ||
            (zOutput[nLength] == SLASH)) {
            zOutput = &zOutput[nLength+1]; /* point past it */
            break;
        }
    }

    return zOutput;
}
