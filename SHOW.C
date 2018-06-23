/*
 *  PROGRAM:   JQCPIC -- John Q's Portable CPI-C Abuser
 *
 *  MODULE:    SHOW.C -- write strings to stdout
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
 *  06/21/92   Added show_error()
 */

#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "jqcpic.h"



void show_end_of_line(void)
{
    /*=========================================================================
     * Print the end-of-line character.
     *=======================================================================*/

    write_output("\n");
}


void show_cpic_call_short(const CPIC_VERB_INDEX index)
{
    /*=========================================================================
     * Show the string representing the current CPI-C call (short).
     *=======================================================================*/

    write_output("%-6s ", cpicerr_verbs_short[index].message);
}


void show_cpic_call_long(const CPIC_VERB_INDEX index)
{
    /*=========================================================================
     * Show the string representing the current CPI-C call (long).
     *=======================================================================*/

    write_output("%-33s ", cpicerr_verbs_long [index].message);
}


void show_conv_state(const CM_CONVERSATION_STATE index)
{
    /*=========================================================================
     * Show the string representing the conversation state.
     *=======================================================================*/

    write_output("%-12.12s ", cpicerr_states_conv[index].message);
}


void show_cpic_call(CPIC_CONV_ATTRIB *this, const CPIC_VERB_INDEX index)
{
    /*=========================================================================
     * Show the string representing the current CPI-C call.
     *=======================================================================*/

    /* need to get an index into the right array */
    CPIC_VERB_INDEX true_index = call_state_map[index];

    this->call_index = (CM_INT32)true_index;

    show_cpic_call_short(true_index);
}


void show_return_code(CPIC_CONV_ATTRIB *this)
{
    /*=========================================================================
     * Show the string representing the return code from the last CPI-C call.
     *=======================================================================*/

#ifdef NOCPIC
    /* this is where we invent new return codes */
    this->return_code = (rand() % (NUM_CPIC_RETURN_CODES));
#endif

    write_output("%-29s ", cpicerr_get_message(CPIC_RETURN_CODES,
                                               this->return_code));
}


void show_error(char *fmt, ...)
{
    /*=========================================================================
     * Show the error string.
     *=======================================================================*/

    va_list args;
    va_start(args, fmt);

    write_output("* ");
    write_output(fmt, args);
    write_output(" ");

    va_end(args);
}
