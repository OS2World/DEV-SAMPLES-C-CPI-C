/*
 *  PROGRAM:   JQCPIC -- John Q's Portable CPI-C Abuser
 *
 *  MODULE:    CALLS.C -- issue random CPI-C calls
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
 *  06/07/92   Faster get_call_index().
 *  06/20/92   Added check_receive() & check_rts()
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jqcpic.h"
#include "calls.h"
#include "build.h"


/* local function prototypes */
unsigned get_call_index(const CM_CONVERSATION_STATE);


#if 0
unsigned get_call_index(const CM_CONVERSATION_STATE conv_state)
{
    /*=========================================================================
     * Determine the index of the next CPI-C call, given the current state.
     *
     * ATTENTION: this procedure is a PIG!  It was written for laziness, not
     * efficiency.  Feel free to re-write it!
     *=======================================================================*/

    unsigned target_probability;
    int next_cpic_call;

    /* pick a target number between 1 and 100 */
    target_probability = (rand() % (100)) + 1;

    /*-------------------------------------------------------------------------
     * Now, find the index of a CPI-C call whose probability in this
     * state is greater than or equal to the target.
     * Note: This loop performs terribly!
     *-----------------------------------------------------------------------*/
    do {
        next_cpic_call = rand() % (NUM_CPIC_CALLS);
    }
    while (cpic_state_table[next_cpic_call][conv_state] <
           target_probability);

    return next_cpic_call;
}
#endif


unsigned get_call_index(const CM_CONVERSATION_STATE conv_state)
{
    /*=========================================================================
     * Get the index of the next CPI-C call.
     *=======================================================================*/

    /* pick a target number between 1 and 100 */
    unsigned target_probability = (rand() % (100)) + 1;
    unsigned target_count;

    {   /*---------------------------------------------------------------------
         * Find the number of calls that fit this probability.
         *-------------------------------------------------------------------*/
        unsigned ii;
        unsigned count = 0;
        for (ii = 0; ii < NUM_CPIC_CALLS; ii++) {
            if (cpic_state_table[ii][conv_state] >= target_probability) {
                count++;
            }
        }
        /* pick a target count between 1 and the count */
        target_count = (rand() % count) + 1;
    }

    {   /*---------------------------------------------------------------------
         * Find a call that randomly matches this probability.
         *-------------------------------------------------------------------*/
        unsigned ii;
        unsigned count = 0;
        for (ii = 0; ii < NUM_CPIC_CALLS; ii++) {
            if (cpic_state_table[ii][conv_state] >= target_probability) {
                if (target_count == ++count) {
                    break;
                }
            }
        }
        return ii;
    }
}


CM_CONVERSATION_STATE issue_cpic_call(CPIC_CONV_ATTRIB *this)
{
    /*=========================================================================
     * Issue the next CPI-C call, one that's valid for the current state.
     *=======================================================================*/

    CM_CONVERSATION_STATE old_conv_state;

    unsigned cpic_call_index =
        get_call_index(old_conv_state = this->conversation_state);

    show_cpic_call(this, cpic_call_index);
    show_conv_state(old_conv_state);

    switch(cpic_call_index) {
        case CMACCP :
            this->conversation_state = build_cmaccp (this);
            break;
        case CMALLC :
            this->conversation_state = build_cmallc (this);
            break;
        case CMCFM  :
            this->conversation_state = build_cmcfm  (this);
            break;
        case CMCFMD :
            this->conversation_state = build_cmcfmd (this);
            break;
        case CMDEALa:
            this->conversation_state = build_cmdeala(this);
            break;
        case CMDEALc:
            this->conversation_state = build_cmdealc(this);
            break;
        case CMDEALf:
            this->conversation_state = build_cmdealf(this);
            break;
        case CMDEALs:
            this->conversation_state = build_cmdeals(this);
            break;
        case CMECS  :
            this->conversation_state = build_cmecs  (this);
            break;
        case CMECT  :
            this->conversation_state = build_cmect  (this);
            break;
        case CMEMN  :
            this->conversation_state = build_cmemn  (this);
            break;
        case CMEPLN :
            this->conversation_state = build_cmepln (this);
            break;
        case CMESL  :
            this->conversation_state = build_cmesl  (this);
            break;
        case CMFLUS :
            this->conversation_state = build_cmflus (this);
            break;
        case CMINIT :
            this->conversation_state = build_cminit (this);
            break;
        case CMPTRc :
            this->conversation_state = build_cmptrc (this);
            break;
        case CMPTRf :
            this->conversation_state = build_cmptrf (this);
            break;
        case CMPTRs :
            this->conversation_state = build_cmptrs (this);
            break;
        case CMRCVi :
            this->conversation_state = build_cmrcvi (this);
            break;
        case CMRCVw :
            this->conversation_state = build_cmrcvw (this);
            break;
        case CMRTS  :
            this->conversation_state = build_cmrts  (this);
            break;
        case CMSCT  :
            this->conversation_state = build_cmsct  (this);
            break;
        case CMSDT  :
            this->conversation_state = build_cmsdt  (this);
            break;
        case CMSED  :
            this->conversation_state = build_cmsed  (this);
            break;
        case CMSEND :
            this->conversation_state = build_cmsend (this);
            break;
        case CMSERR :
            this->conversation_state = build_cmserr (this);
            break;
        case CMSF   :
            this->conversation_state = build_cmsf   (this);
            break;
        case CMSLD  :
            this->conversation_state = build_cmsld  (this);
            break;
        case CMSMN  :
            this->conversation_state = build_cmsmn  (this);
            break;
        case CMSPLN :
            this->conversation_state = build_cmspln (this);
            break;
        case CMSPTR :
            this->conversation_state = build_cmsptr (this);
            break;
        case CMSRC  :
            this->conversation_state = build_cmsrc  (this);
            break;
        case CMSRT  :
            this->conversation_state = build_cmsrt  (this);
            break;
        case CMSSL  :
            this->conversation_state = build_cmssl  (this);
            break;
        case CMSST  :
            this->conversation_state = build_cmsst  (this);
            break;
        case CMSTPN :
            this->conversation_state = build_cmstpn (this);
            break;
        case CMTRTS :
            this->conversation_state = build_cmtrts (this);
            break;
        default     :
            this->conversation_state = (CM_CONVERSATION_STATE)(-1);
            break;
    }

    show_end_of_line();

    return this->conversation_state;
}


CM_CONVERSATION_STATE unexpected_rc(CPIC_CONV_ATTRIB *this)
{
    /*=========================================================================
     * Handle an unexpected return code.
     *=======================================================================*/

    FILE *log_stream;

    char *log_name = (char *)get_memory((size_t)(strlen(program_name) + 1 +
                                                 strlen(LOG_EXTENSION)));
    if ((char *)NULL != log_name) {
        strcpy(log_name, program_name);
        strcat(log_name, LOG_EXTENSION);
        log_stream = fopen(log_name, "w");
        if ((FILE *)NULL != log_stream) {

            fprintf(log_stream, "call_index: %ld\n",
                                this->call_index);
            fprintf(log_stream, "conversation_state: %ld\n",
                                this->conversation_state);
            fprintf(log_stream, "conversation_type: %ld\n",
                                this->conversation_type);
            fprintf(log_stream, "data_received: %ld\n",
                                this->data_received);
            fprintf(log_stream, "deallocate_type: %ld\n",
                                this->deallocate_type);
            fprintf(log_stream, "error_direction: %ld\n",
                                this->error_direction);
            fprintf(log_stream, "fill: %ld\n",
                                this->fill);
            fprintf(log_stream, "log_data_length: %ld\n",
                                this->log_data_length);
            fprintf(log_stream, "mode_name_length: %ld\n",
                                this->mode_name_length);
            fprintf(log_stream, "partner_LU_name_length: %ld\n",
                                this->partner_LU_name_length);
            fprintf(log_stream, "prepare_to_receive_type: %ld\n",
                                this->prepare_to_receive_type);
            fprintf(log_stream, "receive_type: %ld\n",
                                this->prepare_to_receive_type);
            fprintf(log_stream, "received_length: %ld\n",
                                this->received_length);
            fprintf(log_stream, "request_to_send_received: %ld\n",
                                this->prepare_to_receive_type);
            fprintf(log_stream, "return_code: %ld\n",
                                this->return_code);
            fprintf(log_stream, "return_control: %ld\n",
                                this->return_control);
            fprintf(log_stream, "send_length: %ld\n",
                                this->send_length);
            fprintf(log_stream, "send_type: %ld\n",
                                this->send_type);
            fprintf(log_stream, "status_received: %ld\n",
                                this->status_received);
            fprintf(log_stream, "sync_level: %ld\n",
                                this->sync_level);
            fprintf(log_stream, "TP_name_length: %ld\n",
                                this->TP_name_length);


            fclose(log_stream);
        }
    }

    return (CM_CONVERSATION_STATE)(-1);
}


BOOL check_receive(const CPIC_CONV_ATTRIB *this)
{
    /*=========================================================================
     * Validate the values returned on a RECEIVE call.
     *=======================================================================*/

    BOOL result = FALSE;

    /* Check for valid data_received values */
    if ((CM_OK                 == this->return_code) ||
        (CM_DEALLOCATED_NORMAL == this->return_code)) {

        CPIC_CONV_ATTRIB local;             /* one conversation instance     */

#ifndef NOCPIC
        cmect(this->conversation_ID,
              &local.conversation_type,
              &local.return_code);
#endif

        switch (this->data_received) {
            case CM_NO_DATA_RECEIVED:
                if ((CM_INT32)0 != this->received_length) {
                    show_error("NO_DATA, but non-zero received length");
                    result = TRUE;
                }
                break;

            case CM_DATA_RECEIVED:
                if ((this->received_length > this->requested_length) ||
                    (this->received_length == 0) ||
                    (this->received_length > 32767)) {
                    show_error("Invalid received_length value");
                    result = TRUE;
                }
                if (CM_OK == local.return_code) {
                    if (CM_BASIC_CONVERSATION != local.conversation_type) {
                        show_error("DATA_RECEIVED on mapped conversation");
                        result = TRUE;
                    }
                }
                break;

            case CM_INCOMPLETE_DATA_RECEIVED:
                if ((CM_RECEIVE_AND_WAIT == this->receive_type) &&
                    (CM_MAPPED_CONVERSATION == local.conversation_type)) {
                    if (this->received_length < this->requested_length) {
                        show_error("INCOMPLETE_DATA_RECEIVED, but "
                                   "received_length < requested_length");
                        result = TRUE;
                    }
                }

                /* fall through */

            case CM_COMPLETE_DATA_RECEIVED:
                if ((this->received_length > this->requested_length) ||
                    (this->received_length == 0) ||
                    (this->received_length > 32767)) {
                    show_error("Invalid received_length value");
                    result = TRUE;
                }
                break;

            default:
                show_error("Invalid data_received value");
                result = TRUE;
                break;
        }
    }

    /* Check for valid status_received values */
    if (CM_OK == this->return_code) {

        CPIC_CONV_ATTRIB local;             /* one conversation instance     */

#ifndef NOCPIC
        cmecs(this->conversation_ID,
              &local.conversation_state,
              &local.return_code);
#endif

        if (CM_OK == local.return_code) {
            switch (this->status_received) {
                case CM_NO_STATUS_RECEIVED:
                    if (CM_NO_DATA_RECEIVED == this->data_received) {
                        show_error("No status AND no data received");
                        result = TRUE;
                    }
                    break;
                case CM_SEND_RECEIVED:
                    if ((CM_SEND_STATE           != local.conversation_state) &&
                        (CM_SEND_PENDING_STATE   != local.conversation_state)) {
                        show_error("SEND status received, but "
                                   "state = %lu",
                                   local.conversation_state);
                        result = TRUE;
                    }
                    break;
                case CM_CONFIRM_RECEIVED:
                    if (CM_CONFIRM_STATE         != local.conversation_state) {
                        show_error("CONFIRM status received, wrong state");
                        result = TRUE;
                    }
                    break;
                case CM_CONFIRM_SEND_RECEIVED:
                    if (CM_CONFIRM_SEND_STATE    != local.conversation_state) {
                        show_error("CONFIRM SEND status received, wrong state");
                        result = TRUE;
                    }
                    break;
                case CM_CONFIRM_DEALLOC_RECEIVED:
                    if (CM_CONFIRM_DEALLOCATE_STATE!=local.conversation_state){
                        show_error("CONFIRM DEAL status received, wrong state");
                        result = TRUE;
                    }
                    break;
                default:
                    show_error("Invalid status_received value");
                    result = TRUE;
                    break;
            }
        }
    }

    if (TRUE == result) protocol_error();

    return result;
}


BOOL check_rts(const CPIC_CONV_ATTRIB *this)
{
    /*=========================================================================
     * Validate the values returned for request_to_send_received.
     *=======================================================================*/

    BOOL result = FALSE;

    /* Check for valid rts_received values */
    if ((CM_PROGRAM_PARAMETER_CHECK != this->return_code) &&
        (CM_PROGRAM_STATE_CHECK     != this->return_code)) {
        if ((CM_REQ_TO_SEND_RECEIVED     != this->request_to_send_received) &&
            (CM_REQ_TO_SEND_NOT_RECEIVED != this->request_to_send_received)) {
            show_error("Invalid request_to_send_received value");
            result = TRUE;
        }
    }

    if (TRUE == result) protocol_error();

    return result;
}
