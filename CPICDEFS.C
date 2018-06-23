/*
 *  PROGRAM:   JQCPIC -- John Q's Portable CPI-C Abuser
 *
 *  MODULE:    CPICDEFS.C -- CPI-C constants, typedefs, and enums
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
#include "jqcpic.h"

#define MAXINT (32767)  /* used as an end marker for message arrays */

CPICERR_MESSAGE cpicerr_verbs_short[] = {
    MSG_CMACCP, "CMACCP",
    MSG_CMALLC, "CMALLC",
    MSG_CMCFM,  "CMCFM" ,
    MSG_CMCFMD, "CMCFMD",
    MSG_CMDEAL, "CMDEAL",
    MSG_CMECS,  "CMECS" ,
    MSG_CMECT,  "CMECT" ,
    MSG_CMEMN,  "CMEMN" ,
    MSG_CMEPLN, "CMEPLN",
    MSG_CMESL,  "CMESL" ,
    MSG_CMFLUS, "CMFLUS",
    MSG_CMINIT, "CMINIT",
    MSG_CMPTR,  "CMPTR" ,
    MSG_CMRCV,  "CMRCV" ,
    MSG_CMRTS,  "CMRTS" ,
    MSG_CMSCT,  "CMSCT" ,
    MSG_CMSDT,  "CMSDT" ,
    MSG_CMSED,  "CMSED" ,
    MSG_CMSEND, "CMSEND",
    MSG_CMSERR, "CMSERR",
    MSG_CMSF,   "CMSF"  ,
    MSG_CMSLD,  "CMSLD" ,
    MSG_CMSMN,  "CMSMN" ,
    MSG_CMSPLN, "CMSPLN",
    MSG_CMSPTR, "CMSPTR",
    MSG_CMSRC,  "CMSRC" ,
    MSG_CMSRT,  "CMSRT" ,
    MSG_CMSSL,  "CMSSL" ,
    MSG_CMSST,  "CMSST" ,
    MSG_CMSTPN, "CMSTPN",
    MSG_CMTRTS, "CMTRTS",
    MSG_XCSCSU, "XCSCSU",
    MSG_XCSCSP, "XCSCSP",
    MSG_XCSCST, "XCSCST",
    MAXINT,     "ERROR"
};

CPICERR_MESSAGE cpicerr_verbs_long[] = {
    MSG_CMACCP,  "Accept_Conversation"               ,
    MSG_CMALLC,  "Allocate"                          ,
    MSG_CMCFM,   "Confirm"                           ,
    MSG_CMCFMD,  "Confirmed"                         ,
    MSG_CMDEAL,  "Deallocate"                        ,
    MSG_CMECS,   "Extract_Conversation_State"        ,
    MSG_CMECT,   "Extract_Conversation_Type"         ,
    MSG_CMEMN,   "Extract_Mode_Name"                 ,
    MSG_CMEPLN,  "Extract_Partner_LU_Name"           ,
    MSG_CMESL,   "Extract_Sync_Level"                ,
    MSG_CMFLUS,  "Flush"                             ,
    MSG_CMINIT,  "Initialize_Conversation"           ,
    MSG_CMPTR,   "Prepare_To_Receive"                ,
    MSG_CMRCV,   "Receive"                           ,
    MSG_CMRTS,   "Request_To_Send"                   ,
    MSG_CMSCT,   "Set_Conversation_Type"             ,
    MSG_CMSDT,   "Set_Deallocate_Type"               ,
    MSG_CMSED,   "Set_Error_Direction"               ,
    MSG_CMSEND,  "Send_Data"                         ,
    MSG_CMSERR,  "Send_Error"                        ,
    MSG_CMSF,    "Set_Fill"                          ,
    MSG_CMSLD,   "Set_Log_Data"                      ,
    MSG_CMSMN,   "Set_Mode_Name"                     ,
    MSG_CMSPLN,  "Set_Partner_LU_Name"               ,
    MSG_CMSPTR,  "Set_Prepare_To_Receive_Type"       ,
    MSG_CMSRC,   "Set_Return_Control"                ,
    MSG_CMSRT,   "Set_Receive_Type"                  ,
    MSG_CMSSL,   "Set_Sync_Level"                    ,
    MSG_CMSST,   "Set_Send_Type"                     ,
    MSG_CMSTPN,  "Set_TP_Name"                       ,
    MSG_CMTRTS,  "Test_Request_To_Send_Received"     ,
    MSG_XCSCSU,  "Set Conversation Security Userid"  ,
    MSG_XCSCSP,  "Set Conversation Security Password",
    MSG_XCSCST,  "Set Conversation Security Type"    ,
    MAXINT,      "* Invalid verb name"
};

CPICERR_MESSAGE cpicerr_return_codes[] = {
    CM_OK,                          "CM_OK"                         ,
    CM_ALLOCATE_FAILURE_NO_RETRY,   "CM_ALLOCATE_FAILURE_NO_RETRY"  ,
    CM_ALLOCATE_FAILURE_RETRY,      "CM_ALLOCATE_FAILURE_RETRY"     ,
    CM_CONVERSATION_TYPE_MISMATCH,  "CM_CONVERSATION_TYPE_MISMATCH" ,
    CM_PIP_NOT_SPECIFIED_CORRECTLY, "CM_PIP_NOT_SPECIFIED_CORRECTLY",
    CM_SECURITY_NOT_VALID,          "CM_SECURITY_NOT_VALID"         ,
    CM_SYNC_LVL_NOT_SUPPORTED_LU,   "CM_SYNC_LVL_NOT_SUPPORTED_LU"  ,
    CM_SYNC_LVL_NOT_SUPPORTED_PGM,  "CM_SYNC_LVL_NOT_SUPPORTED_PGM" ,
    CM_TPN_NOT_RECOGNIZED,          "CM_TPN_NOT_RECOGNIZED"         ,
    CM_TP_NOT_AVAILABLE_NO_RETRY,   "CM_TP_NOT_AVAILABLE_NO_RETRY"  ,
    CM_TP_NOT_AVAILABLE_RETRY,      "CM_TP_NOT_AVAILABLE_RETRY"     ,
    CM_DEALLOCATED_ABEND,           "CM_DEALLOCATED_ABEND"          ,
    CM_DEALLOCATED_NORMAL,          "CM_DEALLOCATED_NORMAL"         ,
    CM_PARAMETER_ERROR,             "CM_PARAMETER_ERROR"            ,
    CM_PRODUCT_SPECIFIC_ERROR,      "CM_PRODUCT_SPECIFIC_ERROR"     ,
    CM_PROGRAM_ERROR_NO_TRUNC,      "CM_PROGRAM_ERROR_NO_TRUNC"     ,
    CM_PROGRAM_ERROR_PURGING,       "CM_PROGRAM_ERROR_PURGING"      ,
    CM_PROGRAM_ERROR_TRUNC,         "CM_PROGRAM_ERROR_TRUNC"        ,
    CM_PROGRAM_PARAMETER_CHECK,     "CM_PROGRAM_PARAMETER_CHECK"    ,
    CM_PROGRAM_STATE_CHECK,         "CM_PROGRAM_STATE_CHECK"        ,
    CM_RESOURCE_FAILURE_NO_RETRY,   "CM_RESOURCE_FAILURE_NO_RETRY"  ,
    CM_RESOURCE_FAILURE_RETRY,      "CM_RESOURCE_FAILURE_RETRY"     ,
    CM_UNSUCCESSFUL,                "CM_UNSUCCESSFUL"               ,
    CM_DEALLOCATED_ABEND_SVC,       "CM_DEALLOCATED_ABEND_SVC"      ,
    CM_DEALLOCATED_ABEND_TIMER,     "CM_DEALLOCATED_ABEND_TIMER"    ,
    CM_SVC_ERROR_NO_TRUNC,          "CM_SVC_ERROR_NO_TRUNC"         ,
    CM_SVC_ERROR_PURGING,           "CM_SVC_ERROR_PURGING"          ,
    CM_SVC_ERROR_TRUNC,             "CM_SVC_ERROR_TRUNC"            ,
#ifndef OS400
    CM_TAKE_BACKOUT,                "CM_TAKE_BACKOUT"               ,
    CM_DEALLOCATED_ABEND_BO,        "CM_DEALLOCATED_ABEND_BO"       ,
    CM_DEALLOCATED_ABEND_SVC_BO,    "CM_DEALLOCATED_ABEND_SVC_BO"   ,
    CM_DEALLOCATED_ABEND_TIMER_BO,  "CM_DEALLOCATED_ABEND_TIMER_BO" ,
    CM_RESOURCE_FAIL_NO_RETRY_BO,   "CM_RESOURCE_FAIL_NO_RETRY_BO"  ,
    CM_RESOURCE_FAILURE_RETRY_BO,   "CM_RESOURCE_FAILURE_RETRY_BO"  ,
    CM_DEALLOCATED_NORMAL_BO,       "CM_DEALLOCATED_NORMAL_BO"      ,
#endif
    MAXINT,                         "* Invalid Return Code value"
};

CPICERR_MESSAGE cpicerr_rc_classes[] = {
    BACKOUT_RECEIVED, "BACKOUT_RECEIVED"          ,
    CONTINUE,         "CONTINUE"                  ,
    ERROR_RECEIVED,   "ERROR_RECEIVED"            ,
    RETRY_CONV,       "RETRY_CONVERSATION"        ,
#ifndef OS400
    RETRY_CONV_BO,    "RETRY_CONVERSATION_BACKOUT",
#endif
    RETRY_VERB,       "RETRY_LAST_VERB"           ,
    UNRECOVERABLE,    "UNRECOVERABLE"             ,
#ifndef OS400
    UNRECOVERABLE_BO, "UNRECOVERABLE_BACKOUT"     ,
#endif
    MAXINT,           "* Invalid Return Code Class"
};

#ifndef OS400
CPICERR_MESSAGE cpicerr_states_conv[] = {
    0,                              "Null"                  ,
    1,                              "Reset"                 ,
    CM_INITIALIZE_STATE,            "Initialize"            ,
    CM_SEND_STATE,                  "Send"                  ,
    CM_RECEIVE_STATE,               "Receive"               ,
    CM_SEND_PENDING_STATE,          "Send pending"          ,
    CM_CONFIRM_STATE,               "Confirm"               ,
    CM_CONFIRM_SEND_STATE,          "Confirm send"          ,
    CM_CONFIRM_DEALLOCATE_STATE,    "Confirm deallocate"    ,
    CM_DEFER_RECEIVE_STATE,         "Defer receive"         ,
    CM_DEFER_DEALLOCATE_STATE,      "Defer deallocate"      ,
    CM_SYNC_POINT_STATE,            "Syncpoint"             ,
    CM_SYNC_POINT_SEND_STATE,       "Syncpoint send"        ,
    CM_SYNC_POINT_DEALLOCATE_STATE, "Syncpoint deallocate"  ,
    MAXINT,                         "Bad Conversation State"
};
#endif

CPICERR_MESSAGE cpicerr_sync_levels[] = {
    CM_NONE,       "None",
    CM_CONFIRM,    "Confirm",
#ifndef OS400
    CM_SYNC_POINT, "Sync Point",
#endif
    MAXINT,        "* Invalid Sync Level value"
};

CPICERR_MESSAGE cpicerr_conv_types[] = {
    CM_BASIC_CONVERSATION , "Basic",
    CM_MAPPED_CONVERSATION, "Mapped",
    MAXINT,                 "* Invalid Conversation Type value"
};


CPICERR_MESSAGE_LIST message_list[] = {
    CPIC_SYNC_LEVELS,  cpicerr_sync_levels,
    CPIC_CONV_TYPES,   cpicerr_conv_types,
#ifndef OS400
    CPIC_STATES_CONV,  cpicerr_states_conv,
#endif
    CPIC_RC_CLASSES,   cpicerr_rc_classes,
    CPIC_RETURN_CODES, cpicerr_return_codes,
    CPIC_VERBS_SHORT,  cpicerr_verbs_short,
    CPIC_VERBS_LONG,   cpicerr_verbs_long,
    MAXINT,            NULL
};

CPIC_VERB_INDEX call_state_map[NUM_CPIC_CALLS] = {
    MSG_CMACCP,
    MSG_CMALLC,
    MSG_CMCFM ,
    MSG_CMCFMD,
    MSG_CMDEAL,
    MSG_CMDEAL,
    MSG_CMDEAL,
    MSG_CMDEAL,
    MSG_CMECS ,
    MSG_CMECT ,
    MSG_CMEMN ,
    MSG_CMEPLN,
    MSG_CMESL ,
    MSG_CMFLUS,
    MSG_CMINIT,
    MSG_CMPTR ,
    MSG_CMPTR ,
    MSG_CMPTR ,
    MSG_CMRCV ,
    MSG_CMRCV ,
    MSG_CMRTS ,
    MSG_CMSCT ,
    MSG_CMSDT ,
    MSG_CMSED ,
    MSG_CMSEND,
    MSG_CMSERR,
    MSG_CMSF  ,
    MSG_CMSLD ,
    MSG_CMSMN ,
    MSG_CMSPLN,
    MSG_CMSPTR,
    MSG_CMSRC ,
    MSG_CMSRT ,
    MSG_CMSSL ,
    MSG_CMSST ,
    MSG_CMSTPN,
    MSG_CMTRTS
};


char *cpicerr_get_message(CPICERR_MESSAGE_TYPE message_type, CM_INT32 index)
{
    /*=========================================================================
     * Get the next string from the appropriate array.
     *=======================================================================*/

    unsigned int count;                     /* counter through the array     */

    CPICERR_MESSAGE *messages;

    for (count = 0; message_list[count].type < MAXINT ; count++ ) {
        if (message_list[count].type == message_type) break;
    }

    if (NULL == (messages = message_list[count].list)) {
        return "Message list not found.";
    }

    for (count = 0; messages[count].index < MAXINT; count++) {
       if (messages[count].index == index) break;
    }

    return messages[count].message;
}
