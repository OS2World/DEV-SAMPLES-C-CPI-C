/*
 *  PROGRAM:   JQCPIC -- John Q's Portable CPI-C Abuser
 *
 *  MODULE:    JQCPIC.C -- main procedures, both client and server side
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
 *  06/24/92   Converted all malloc() and printf() calls, for
 *             future portability.
 */

#include <conio.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "jqcpic.h"

/* global variables */
char *program_version = "1.04";
char *program_name;

unsigned char sym_dest_name[MAX_SYM_DEST_NAME];
time_t tStartTime;          /* start time of this run */
time_t tEndTime;            /* completion time of this run */

static unsigned long total_call_count;

/* depending upon which side is being compiled, define what the reset
 * conversation state should be.
 */
#ifdef SERVER_SIDE
#define CM_RESET_STATE  CM_ACCP_STATE
#else
#define CM_RESET_STATE  CM_INIT_STATE
#endif

/* local function prototypes */
static void handler(int);
static void set_up_control_block(CPIC_CONV_ATTRIB *);


void main(int argc, char **argv)
{
    /*=========================================================================
     * This is the main procedure.
     *=======================================================================*/

    FILE *copyright_output = stderr;    /* send the header here */
    int keystroke = 0;                  /* pressed key */

    CPIC_CONV_ATTRIB local;             /* one conversation instance */
    CM_CONVERSATION_STATE conv_state;   /* current conversation state */


    program_name = get_program_name(argv[0]);

    if ((1 < argc) &&
        (QUESTION_MARK  == argv[1][0]) &&
        (NULL_CHARACTER == argv[1][1]))
        copyright_output = stdout;

    /* Print the title and copyright notices. */
    write_error(
#ifdef SERVER_SIDE
       "%s: Portable CPI-C Abuser (Server side)  version %s\n"
#else
       "%s: Portable CPI-C Abuser (Client side)  version %s\n"
#endif
       "by Dr. John Q. Walker II (johnq@ralvm6.vnet.ibm.com)\n"
       "Copyright (c) IBM Corporation 1992.\n\n"
       "\tPress \"Q\" to quit this program\n\n",
       program_name, program_version);

    if (copyright_output == stdout) {
        usage();
        exit(EXIT_SUCCESS);
    }

    /* Save the start time.  Must be before the signal handler. */
    time(&tStartTime);

    /* set up a signal handler, to clean up upon exit */
    if (SIG_DFL == signal(SIGINT, SIG_IGN))
        signal(SIGINT, handler);

    /* initialize to all ones, not zeros */
    memset((void *)&local, (int)(-1), sizeof(local));

    /* set the initial values in the conversation control block */
    set_up_control_block(&local);

#ifndef SERVER_SIDE
    /* process command line arguments */
    command_line(argc, argv);

    {
    /* this is how the most important parm gets set! */
    unsigned i;                     /* local loop counter */
    for (i = 0; i < SYM_DEST_NAME_LENGTH; i++)
        local.sym_dest_name[i] = sym_dest_name[i];
    }
#endif

    /* set the seed for all future random calls */
    srand((unsigned)tStartTime);

    /*-------------------------------------------------------------------------
     * Loop forever, until an unexpected CPI-C return code or the letter
     * Q is pressed.
     *-----------------------------------------------------------------------*/

    total_call_count = 0;
    while (((int)'q' != keystroke) &&
           ((int)'Q' != keystroke)) {
        while (!kbhit()) {  /* keep going until any keystroke */
            /* Given the local conversation state, make a random CPI-C
             * call that is valid in that state -- returning the new
             * conversation state.
             */
            conv_state = issue_cpic_call(&local);
            total_call_count++;
            if ((CM_CONVERSATION_STATE)(-1) == conv_state) {
                /* unexpected return code on Extract Conversation State */
                write_error("\n\tThe preceding return code is invalid for"
                            " the verb and state!\n");
                all_done(EXIT_FAILURE); /* this does an exit() */
            }
        }

        keystroke = getch();  /* grab the keystroke */
    }

    /* we get here only upon pressing the right key */
    all_done(EXIT_SUCCESS);
}


void all_done(const int status)
{
    /*=========================================================================
     * This procedure is called upon exit or when Ctrl+Break is invoked.
     *=======================================================================*/

    time_t tTotalTime;

    flushall();

    time(&tEndTime);          /* save the end time */

    tTotalTime = tEndTime - tStartTime; /* calculate how long it took */

    /* output the elapsed time */
    write_error("\n%s: %lu calls, %lu calls/second"
                "\n\telapsed time was ",
                program_name, total_call_count,
                (tTotalTime > 0) ? total_call_count/tTotalTime : 0);

    /* calculate the hours */
    if ((time_t)0 < tTotalTime/3600) {
        /* A non-zero number of minutes */
        if ((time_t)1 == tTotalTime/3600)
            (void)write_error("%ld hour, ", tTotalTime/3600);
        else
            (void)write_error("%ld hours, ", tTotalTime/3600);

        /* reduce to the minutes that are left */
        tTotalTime = tTotalTime % 3600;
    }

    /* calculate the minutes */
    if ((time_t)0 < tTotalTime/60) {
        /* A non-zero number of minutes */
        if ((time_t)1 == tTotalTime/60)
            (void)write_error("%ld minute, ", tTotalTime/60);
        else
            (void)write_error("%ld minutes, ", tTotalTime/60);

        /* reduce to the minutes that are left */
        tTotalTime = tTotalTime % 60;
    }

    /* calculate the seconds */
    if ((time_t)1 == tTotalTime)
        (void)write_error("%ld second\n", tTotalTime);
    else
        (void)write_error("%ld seconds\n", tTotalTime);


    exit(status);
}


CM_CONVERSATION_STATE get_new_conversation_state(CPIC_CONV_ATTRIB *this)
{
    /*=========================================================================
     * Given the current conversation status, return the current conversation
     * state.
     *=======================================================================*/

    /* Show the return code from the last call issued. */
    show_return_code(this);

    fetch_conversation_state(this);

    switch (this->return_code) {
        case CM_OK:
            return this->conversation_state;
            break;

        case CM_PROGRAM_PARAMETER_CHECK:
            /* the conversation_ID is no good; it's time to reset */
#ifdef SERVER_SIDE
            /* exit when the conversation ID is no longer valid */
            all_done(EXIT_SUCCESS);
#else
            /* on the client side, go back to issue CMINIT */
            return CM_RESET_STATE;
#endif
            break;

        case CM_TAKE_BACKOUT:
            /* what's this return code mean here?? */
            return this->conversation_state;
            break;

        case CM_PRODUCT_SPECIFIC_ERROR:
            /* what's this return code mean here?? */
            return this->conversation_state;
            break;

        default:
#ifdef NOCPIC
            return this->conversation_state;
#else
            return unexpected_rc(this);
#endif
            break;
    }
}


BOOL generate_valid_parm(void)
{
    /*=========================================================================
     * Decide whether to generate a valid parameter.
     * Constant VALID_PARM_PERCENTAGE should be a number from 0 to 100.
     * Returns TRUE is the parameter should be valid,
     * otherwise returns FALSE.
     *=======================================================================*/

    if (VALID_PARM_PERCENTAGE > (rand() % 100))
        return TRUE;
    else
        return FALSE;
}


void fill_field(char *name, size_t length)
{
    /*=========================================================================
     * Fill the field with random characters (anything from 0 to 255).
     *=======================================================================*/

    memset((void *)name, rand()%256, length);
}


CM_INT32 get_random_CM_INT32(void)
{
    /*=========================================================================
     * Returns a random 32-bit integer.
     * Usually large (32k Squared is its median value).
     *=======================================================================*/

    return (CM_INT32)((CM_INT32)rand() * (CM_INT32)rand());
}


static
void set_up_control_block(CPIC_CONV_ATTRIB *local_ptr)
{
    /*=========================================================================
     * Set up the single control block.
     *=======================================================================*/

    local_ptr->conversation_ID = (unsigned char CM_PTR)
                                    get_memory(CONVERSATION_ID_LENGTH);
    local_ptr->sym_dest_name   = (unsigned char CM_PTR)
                                    get_memory(MAX_SYM_DEST_NAME);
    local_ptr->mode_name       = (unsigned char CM_PTR)
                                    get_memory(MAX_MODE_NAME);
    local_ptr->partner_LU_name = (unsigned char CM_PTR)
                                    get_memory(MAX_FQPLU_NAME);
    local_ptr->TP_name         = (unsigned char CM_PTR)
                                    get_memory(MAX_TP_NAME);

/* this is the trick I use to determine the initial state */
#ifdef SERVER_SIDE
    local_ptr->conversation_state = 1;   /* start with CMACCP */
#else
    local_ptr->conversation_state = 0;   /* start with CMINIT */
#endif
}


void usage(void)
{
    /*=========================================================================
     * Display usage information.
     *=======================================================================*/

#ifdef SERVER_SIDE
    write_error("Server side:\n"
                "\tShould be started by an incoming Attach.\n");
#else
    write_error("Usage:\n"
                "\t%s sym_dest_name\n\n"
                "\tRuns until the letter \"Q\" is pressed.\n"
                , program_name);
#endif
}


static
void handler(int sig)
{
    /*=========================================================================
     * This is the signal handler.
     * Input parameter "sig" is not used, but required by the
     * function prototype for the signal() library call.
     *=======================================================================*/
    (void)signal(SIGINT, SIG_IGN);  /* ignore the signal */
    all_done(EXIT_SUCCESS);
}
