/*
 *  PROGRAM:   JQCPIC -- John Q's Portable CPI-C Abuser
 *
 *  MODULE:    BUILD.C -- one procedure for each CPI-C call/state entry
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
 *  05/12/92   - Added prologue.
 *             - Provided default values for Set calls.
 *  06/20/92   - Added check_receive() & check_rts() calls.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jqcpic.h"
#include "calls.h"



CM_CONVERSATION_STATE build_cmaccp (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Accept Conversation
     *=======================================================================*/

#ifndef NOCPIC
    cmaccp(current->conversation_ID,
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmallc (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Allocate
     *=======================================================================*/

#ifndef NOCPIC
    cmallc(current->conversation_ID,
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmcfm  (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Confirm
     *=======================================================================*/

#ifndef NOCPIC
    cmcfm(current->conversation_ID,
          &(current->request_to_send_received),
          &(current->return_code));
#endif

    /* validate the returned request_to_send_received value */
    (void)check_rts(current);

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmcfmd (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Confirmed
     *=======================================================================*/

#ifndef NOCPIC
    cmcfmd(current->conversation_ID,
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmdeala(CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Deallocate Abend
     *=======================================================================*/

    current->deallocate_type = CM_DEALLOCATE_ABEND;

#ifndef NOCPIC
    cmsdt (current->conversation_ID,
           &(current->deallocate_type),
           &(current->return_code));
    cmdeal(current->conversation_ID,
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmdealc(CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Deallocate Confirm
     *=======================================================================*/

    current->deallocate_type = CM_DEALLOCATE_CONFIRM;

#ifndef NOCPIC
    cmsdt (current->conversation_ID,
           &(current->deallocate_type),
           &(current->return_code));
    cmdeal(current->conversation_ID,
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmdealf(CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Deallocate Flush
     *=======================================================================*/

    current->deallocate_type = CM_DEALLOCATE_FLUSH;

#ifndef NOCPIC
    cmsdt (current->conversation_ID,
           &(current->deallocate_type),
           &(current->return_code));
    cmdeal(current->conversation_ID,
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmdeals(CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Deallocate Sync Level
     *=======================================================================*/

    current->deallocate_type = CM_DEALLOCATE_SYNC_LEVEL;

#ifndef NOCPIC
    cmsdt (current->conversation_ID,
           &(current->deallocate_type),
           &(current->return_code));
    cmdeal(current->conversation_ID,
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmecs  (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Extract Conversation State
     *=======================================================================*/

#ifndef NOCPIC
    cmecs (current->conversation_ID,
           &(current->conversation_state),
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmect  (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Extract Conversation Type
     *=======================================================================*/

#ifndef NOCPIC
    cmect (current->conversation_ID,
           &(current->conversation_type),
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmemn  (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Extract Mode Name
     *=======================================================================*/

#ifndef NOCPIC
    cmemn (current->conversation_ID,
           current->mode_name,
           &(current->mode_name_length),
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmepln (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Extract Partner LU Name
     *=======================================================================*/

#ifndef NOCPIC
    cmepln(current->conversation_ID,
           current->partner_LU_name,
           &(current->partner_LU_name_length),
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmesl  (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Extract Sync Level
     *=======================================================================*/

#ifndef NOCPIC
    cmesl (current->conversation_ID,
           &(current->sync_level),
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmflus (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Flush
     *=======================================================================*/

#ifndef NOCPIC
    cmflus(current->conversation_ID,
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cminit (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Initialize Conversation
     *=======================================================================*/

    unsigned char local_sym_dest_name[SYM_DEST_NAME_LENGTH];

    if (TRUE == generate_valid_parm()) {
        unsigned i;
        for (i = 0; i < SYM_DEST_NAME_LENGTH; i++)
            local_sym_dest_name[i] = current->sym_dest_name[i];
    }
    else {
        /* fill the field with random data */
        fill_field((char *)local_sym_dest_name,
                   (size_t)SYM_DEST_NAME_LENGTH);
    }

#ifndef NOCPIC
    cminit(current->conversation_ID,
           local_sym_dest_name,
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmptrc (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Prepare To Receive Confirm
     *=======================================================================*/

    current->prepare_to_receive_type = CM_PREP_TO_RECEIVE_CONFIRM;

#ifndef NOCPIC
    cmsptr(current->conversation_ID,
           &(current->prepare_to_receive_type),
           &(current->return_code));

    cmptr (current->conversation_ID,
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmptrf (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Prepare To Receive Flush
     *=======================================================================*/

    current->prepare_to_receive_type = CM_PREP_TO_RECEIVE_FLUSH;

#ifndef NOCPIC
    cmsptr(current->conversation_ID,
           &(current->prepare_to_receive_type),
           &(current->return_code));

    cmptr (current->conversation_ID,
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmptrs (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Prepare To Receive Sync Level
     *=======================================================================*/

    current->prepare_to_receive_type = CM_PREP_TO_RECEIVE_SYNC_LEVEL;

#ifndef NOCPIC
    cmsptr(current->conversation_ID,
           &(current->prepare_to_receive_type),
           &(current->return_code));

    cmptr (current->conversation_ID,
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmrcvi (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Receive Immediate
     *=======================================================================*/

    unsigned char *local_buffer = (unsigned char *)NULL;

    if (TRUE == generate_valid_parm()) {
        current->requested_length = (CM_INT32)rand() % 32768;
    }
    else {
        current->requested_length = get_random_CM_INT32();
    }

    local_buffer = (unsigned char *)
                       get_memory((size_t)current->requested_length);
    current->receive_type = CM_RECEIVE_IMMEDIATE;

#ifndef NOCPIC
    cmsrt (current->conversation_ID,
           &(current->receive_type),
           &(current->return_code));

    cmrcv (current->conversation_ID,
           (unsigned char CM_PTR)local_buffer,
           &(current->requested_length),
           &(current->data_received),
           &(current->received_length),
           &(current->status_received),
           &(current->request_to_send_received),
           &(current->return_code));
#endif

    free_memory((void *)local_buffer);

    /* validate the returned request_to_send_received value */
    (void)check_rts(current);

    /* validate whether everything returned by the Receive was right */
    (void)check_receive(current);

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmrcvw (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Receive and Wait
     *=======================================================================*/

    unsigned char *local_buffer = (unsigned char *)NULL;

    if (TRUE == generate_valid_parm()) {
        current->requested_length = (CM_INT32)rand() % 32768;
    }
    else {
        current->requested_length = get_random_CM_INT32();
    }

    local_buffer = (unsigned char *)
                      get_memory((size_t)current->requested_length);

    current->receive_type = CM_RECEIVE_AND_WAIT;

#ifndef NOCPIC
    cmsrt (current->conversation_ID,
           &(current->receive_type),
           &(current->return_code));

    cmrcv (current->conversation_ID,
           (unsigned char CM_PTR)local_buffer,
           &(current->requested_length),
           &(current->data_received),
           &(current->received_length),
           &(current->status_received),
           &(current->request_to_send_received),
           &(current->return_code));
#endif

    free_memory((void *)local_buffer);

    /* validate the returned request_to_send_received value */
    (void)check_rts(current);

    /* validate whether everything returned by the Receive was right */
    (void)check_receive(current);

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmrts  (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Request To Send
     *=======================================================================*/

#ifndef NOCPIC
    cmrts (current->conversation_ID,
           &(current->return_code));
#endif

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmsct  (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Set Conversation Type
     *=======================================================================*/

    CM_CONVERSATION_TYPE local_conversation_type= 0;

    if (TRUE == generate_valid_parm()) {
        switch (rand() % 2) {
            case 0:
                local_conversation_type = CM_BASIC_CONVERSATION;
                break;
            case 1:
                local_conversation_type = CM_MAPPED_CONVERSATION;
                break;
        }
    }
    else {
        local_conversation_type = (CM_CONVERSATION_TYPE)get_random_CM_INT32();
    }

#ifndef NOCPIC
    cmsct (current->conversation_ID,
           (CM_INT32 CM_PTR)&(local_conversation_type),
           &(current->return_code));
#endif

    if (CM_OK == current->return_code)
        current->conversation_type = local_conversation_type;

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmsdt  (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Set Deallocate Type
     *=======================================================================*/

    CM_DEALLOCATE_TYPE local_deallocate_type;

    if (TRUE == generate_valid_parm()) {
        switch (rand() % 4) {
            case 1:
                local_deallocate_type = CM_DEALLOCATE_FLUSH;
                break;
            case 2:
                local_deallocate_type = CM_DEALLOCATE_CONFIRM;
                break;
            case 3:
                local_deallocate_type = CM_DEALLOCATE_ABEND;
                break;
            default:
                local_deallocate_type = CM_DEALLOCATE_SYNC_LEVEL;
                break;
        }
    }
    else {
        local_deallocate_type = (CM_DEALLOCATE_TYPE)get_random_CM_INT32();
    }

#ifndef NOCPIC
    cmsdt (current->conversation_ID,
           (CM_INT32 CM_PTR)&(local_deallocate_type),
           &(current->return_code));
#endif

    if (CM_OK == current->return_code)
        current->deallocate_type = local_deallocate_type;

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmsed  (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Set Error Direction
     *=======================================================================*/

    CM_ERROR_DIRECTION local_error_direction;

    if (TRUE == generate_valid_parm()) {
        switch (rand() % 2) {
            case 1:
                local_error_direction = CM_SEND_ERROR;
                break;
            default:
                local_error_direction = CM_RECEIVE_ERROR;
                break;
        }
    }
    else {
        local_error_direction = (CM_ERROR_DIRECTION)get_random_CM_INT32();
    }

#ifndef NOCPIC
    cmsed (current->conversation_ID,
           (CM_INT32 CM_PTR)&(local_error_direction),
           &(current->return_code));
#endif

    if (CM_OK == current->return_code)
        current->error_direction = local_error_direction;

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmsend (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Send Data
     *=======================================================================*/

    unsigned char *local_send_data;
    CM_INT32 local_send_data_length;

    if (TRUE == generate_valid_parm()) {
        local_send_data_length = (CM_INT32)rand();
    }
    else {
        local_send_data_length = get_random_CM_INT32();
    }

    local_send_data = (unsigned char *)
                         get_memory((size_t)local_send_data_length);

    /* fill the field with random data */
    fill_field((char *)local_send_data,
               (size_t)local_send_data_length);

#ifndef NOCPIC
    cmsend(current->conversation_ID,
           local_send_data,
           &(local_send_data_length),
           &(current->request_to_send_received),
           &(current->return_code));
#endif

    if (CM_OK == current->return_code)
        current->send_length = local_send_data_length;

    free_memory((void *)local_send_data);

    /* validate the returned request_to_send_received value */
    (void)check_rts(current);

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmserr (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Send Error
     *=======================================================================*/

#ifndef NOCPIC
    cmserr(current->conversation_ID,
           &(current->request_to_send_received),
           &(current->return_code));
#endif

    /* validate the returned request_to_send_received value */
    (void)check_rts(current);

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmsf   (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Set Fill (there is no Extract_Fill call)
     *=======================================================================*/

    CM_FILL local_fill;

    if (TRUE == generate_valid_parm()) {
        switch (rand() % 2) {
            case 1:
                local_fill = CM_FILL_BUFFER;
                break;
            default:
                local_fill = CM_FILL_LL;
                break;
        }
    }
    else {
        local_fill = (CM_FILL)get_random_CM_INT32();
    }

#ifndef NOCPIC
    cmsf  (current->conversation_ID,
           (CM_INT32 CM_PTR)&(local_fill),
           &(current->return_code));
#endif

    if (CM_OK == current->return_code)
        current->fill = local_fill;

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmsld  (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Set Log Data
     *=======================================================================*/

    unsigned char *local_log_data;
    CM_INT32 local_log_data_length;

    if (TRUE == generate_valid_parm()) {
        local_log_data_length = rand() % 513;
    }
    else {
        local_log_data_length = get_random_CM_INT32();
    }

    local_log_data = (unsigned char *)
                        get_memory((size_t)local_log_data_length);
    /* fill the field with random data */
    fill_field((char *)local_log_data,
               (size_t)local_log_data_length);

#ifndef NOCPIC
    cmsld (current->conversation_ID,
           local_log_data,
           &(local_log_data_length),
           &(current->return_code));
#endif

    if (CM_OK == current->return_code)
        current->log_data_length = local_log_data_length;

    free_memory((void *)local_log_data);

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmsmn  (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Set Mode Name
     *=======================================================================*/

    unsigned char *local_mode_name;
    CM_INT32 local_mode_name_length;

    if (TRUE == generate_valid_parm()) {
        CM_INT32 i;

#ifndef NOCPIC
        cmemn (current->conversation_ID,
               current->mode_name,
               &(current->mode_name_length),
               &(current->return_code));
#endif

        /* current was initialized to all zeros (if CMEMN fails) */
        local_mode_name_length = current->mode_name_length;
        local_mode_name = (unsigned char *)
                             get_memory((size_t)local_mode_name_length);
        for (i = 0; i < local_mode_name_length; i++)
            local_mode_name[i] = current->mode_name[i];
    }
    else {
        local_mode_name_length = get_random_CM_INT32();
        local_mode_name = (unsigned char *)
                             get_memory((size_t)local_mode_name_length);

        /* fill the field with random data */
        fill_field((char *)local_mode_name,
                   (size_t)local_mode_name_length);
    }


#ifndef NOCPIC
    cmsmn (current->conversation_ID,
           (unsigned char CM_PTR)local_mode_name,
           (CM_INT32 CM_PTR)&(local_mode_name_length),
           &(current->return_code));
#endif

    free_memory((void *)local_mode_name);

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmspln (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Set Partner LU Name
     *=======================================================================*/

    unsigned char *local_partner_LU_name;
    CM_INT32 local_partner_LU_name_length;

    if (TRUE == generate_valid_parm()) {
        CM_INT32 i;

#ifndef NOCPIC
        cmepln(current->conversation_ID,
               current->partner_LU_name,
               &(current->partner_LU_name_length),
               &(current->return_code));
#endif

        /* current was initialized to all zeros (if CMEPLN fails) */
        local_partner_LU_name_length = current->partner_LU_name_length;
        local_partner_LU_name = (unsigned char *)
                               get_memory((size_t)local_partner_LU_name_length);

        for (i = 0; i < local_partner_LU_name_length; i++)
            local_partner_LU_name[i] = current->partner_LU_name[i];
    }
    else {
        local_partner_LU_name_length = get_random_CM_INT32();
        local_partner_LU_name =
             (unsigned char *)get_memory((size_t)local_partner_LU_name_length);
        /* fill the field with random data */
        fill_field((char *)local_partner_LU_name,
                   (size_t)local_partner_LU_name_length);
    }


#ifndef NOCPIC
    cmspln(current->conversation_ID,
           (unsigned char CM_PTR)local_partner_LU_name,
           (CM_INT32 CM_PTR)&(local_partner_LU_name_length),
           &(current->return_code));
#endif

    free_memory((void *)local_partner_LU_name);

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmsptr (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Set Prepare To Receive Type
     *=======================================================================*/

    CM_PREPARE_TO_RECEIVE_TYPE local_prepare_to_receive_type;

    if (TRUE == generate_valid_parm()) {
        switch (rand() % 3) {
            case 1:
                local_prepare_to_receive_type = CM_PREP_TO_RECEIVE_FLUSH;
                break;
            case 2:
                local_prepare_to_receive_type = CM_PREP_TO_RECEIVE_CONFIRM;
                break;
            default:
                local_prepare_to_receive_type = CM_PREP_TO_RECEIVE_SYNC_LEVEL;
                break;
        }
    }
    else {
        local_prepare_to_receive_type =
                (CM_PREPARE_TO_RECEIVE_TYPE)get_random_CM_INT32();
    }

#ifndef NOCPIC
    cmsptr(current->conversation_ID,
           (CM_INT32 CM_PTR)&(local_prepare_to_receive_type),
           &(current->return_code));
#endif

    if (CM_OK == current->return_code)
        current->prepare_to_receive_type = local_prepare_to_receive_type;

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmsrc  (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Set Return Control
     *=======================================================================*/

    CM_RETURN_CONTROL local_return_control;

    if (TRUE == generate_valid_parm()) {
        switch (rand() % 2) {
            case 1:
                local_return_control = CM_IMMEDIATE;
                break;
            default:
                local_return_control = CM_WHEN_SESSION_ALLOCATED;
                break;
        }
    }
    else {
        local_return_control = (CM_RETURN_CONTROL)get_random_CM_INT32();
    }

#ifndef NOCPIC
    cmsrc (current->conversation_ID,
           (CM_INT32 CM_PTR)&(local_return_control),
           &(current->return_code));
#endif

    if (CM_OK == current->return_code)
        current->return_control = local_return_control;

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmsrt  (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Set Receive Type
     *=======================================================================*/

    CM_RECEIVE_TYPE local_receive_type;

    if (TRUE == generate_valid_parm()) {
        switch (rand() % 2) {
            case 1:
                local_receive_type = CM_RECEIVE_IMMEDIATE;
                break;
            default:
                local_receive_type = CM_RECEIVE_AND_WAIT;
                break;
        }
    }
    else {
        local_receive_type = (CM_RECEIVE_TYPE)get_random_CM_INT32();
    }

#ifndef NOCPIC
    cmsrt (current->conversation_ID,
           (CM_INT32 CM_PTR)&(local_receive_type),
           &(current->return_code));
#endif

    if (CM_OK == current->return_code)
        current->receive_type = local_receive_type;

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmssl  (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Set Sync Level
     *=======================================================================*/

    CM_SYNC_LEVEL local_sync_level;

    if (TRUE == generate_valid_parm()) {
        switch (rand() % 3) {
            case 1:
                local_sync_level = CM_CONFIRM;
                break;
            case 2:
                local_sync_level = CM_SYNC_POINT;
                break;
            default:
                local_sync_level = CM_NONE;
                break;
        }
    }
    else {
        local_sync_level = (CM_SYNC_LEVEL)get_random_CM_INT32();
    }

#ifndef NOCPIC
    cmssl (current->conversation_ID,
           (CM_INT32 CM_PTR)&(local_sync_level),
           &(current->return_code));
#endif

    if (CM_OK == current->return_code)
        current->sync_level = local_sync_level;

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmsst  (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Set Send Type
     *=======================================================================*/

    CM_SEND_TYPE local_send_type;

    if (TRUE == generate_valid_parm()) {
        switch (rand() % 5) {
            case 1:
                local_send_type = CM_SEND_AND_FLUSH;
                break;
            case 2:
                local_send_type = CM_SEND_AND_CONFIRM;
                break;
            case 3:
                local_send_type = CM_SEND_AND_PREP_TO_RECEIVE;
                break;
            case 4:
                local_send_type = CM_SEND_AND_DEALLOCATE;
                break;
            default:
                local_send_type = CM_BUFFER_DATA;
                break;
        }
    }
    else {
        local_send_type = (CM_SEND_TYPE)get_random_CM_INT32();
    }

#ifndef NOCPIC
    cmsst (current->conversation_ID,
           (CM_INT32 CM_PTR)&(local_send_type),
           &(current->return_code));
#endif

    if (CM_OK == current->return_code)
        current->send_type = local_send_type;

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmstpn (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Set TP Name
     *=======================================================================*/

    void *local_TP_name = (void *)NULL;
    CM_INT32 local_TP_name_length = 0;

    if (TRUE == generate_valid_parm()) {
        local_TP_name = get_memory((size_t)local_TP_name_length);
    }
    else {
        local_TP_name_length = get_random_CM_INT32();
        local_TP_name = get_memory((size_t)local_TP_name_length);
        /* fill the field with random data */
        fill_field((char *)local_TP_name,
                   (size_t)local_TP_name_length);
    }


#ifndef NOCPIC
    cmstpn(current->conversation_ID,
           (unsigned char CM_PTR)local_TP_name,
           (CM_INT32 CM_PTR)&(local_TP_name_length),
           &(current->return_code));
#endif

    free_memory((void *)local_TP_name);

    return get_new_conversation_state(current);
}


CM_CONVERSATION_STATE build_cmtrts (CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Test Request To Send
     *=======================================================================*/

#ifndef NOCPIC
    cmtrts(current->conversation_ID,
           &(current->request_to_send_received),
           &(current->return_code));
#endif

    /* validate the returned request_to_send_received value */
    (void)check_rts(current);

    return get_new_conversation_state(current);

}


void fetch_conversation_state(CPIC_CONV_ATTRIB *current)
{
    /*=========================================================================
     * Determine the current conversation state.
     *=======================================================================*/

#ifdef NOCPIC
    /* Randomly generate the next state */
    current->conversation_state = (CM_CONVERSATION_STATE)
                                  (rand() % (NUM_CPIC_STATES));
#else
    /* Extract the current conversation state, trusting CPI-C to return
     * the correct answer.  This call has potential portability
     * problems, since Extract Conversation State is not implemented on
     * all platforms.
     */
    cmecs (current->conversation_ID,
           &(current->conversation_state),
           &(current->return_code));
#endif
}
