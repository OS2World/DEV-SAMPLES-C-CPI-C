/*
 *  PROGRAM:   JQCPIC -- John Q's Portable CPI-C Abuser
 *
 *  MODULE:    CPICDEFS.H -- CPI-C constants, typedefs, and enums
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

#define  MAX_LU_ALIAS       (8+1)
#define  MAX_PLU_ALIAS      (8+1)
#define  MAX_TP_NAME        (64+1)
#define  MAX_SYM_DEST_NAME  (8+1)
#define  MAX_FQPLU_NAME     (17+1)
#define  MAX_DESTINATION    (17+1)
#define  MAX_MODE_NAME      (8+1)
#define  MAX_USERID         (8+1)
#define  MAX_PASSWD         (8+1)

/* These two conversation states fill in the first two places in the array */
#define CM_NULL_STATE                    (CM_CONVERSATION_STATE) 0
#define CM_INIT_STATE                    (CM_CONVERSATION_STATE) 0
#define CM_ACCP_STATE                    (CM_CONVERSATION_STATE) 1


typedef enum {
    CMACCP  =  0,
    CMALLC  =  1,
    CMCFM   =  2,
    CMCFMD  =  3,
    CMDEALa =  4,
    CMDEALc =  5,
    CMDEALf =  6,
    CMDEALs =  7,
    CMECS   =  8,
    CMECT   =  9,
    CMEMN   = 10,
    CMEPLN  = 11,
    CMESL   = 12,
    CMFLUS  = 13,
    CMINIT  = 14,
    CMPTRc  = 15,
    CMPTRf  = 16,
    CMPTRs  = 17,
    CMRCVi  = 18,
    CMRCVw  = 19,
    CMRTS   = 20,
    CMSCT   = 21,
    CMSDT   = 22,
    CMSED   = 23,
    CMSEND  = 24,
    CMSERR  = 25,
    CMSF    = 26,
    CMSLD   = 27,
    CMSMN   = 28,
    CMSPLN  = 29,
    CMSPTR  = 30,
    CMSRC   = 31,
    CMSRT   = 32,
    CMSSL   = 33,
    CMSST   = 34,
    CMSTPN  = 35,
    CMTRTS  = 36
} CPIC_CALL_INDEX;

typedef enum {
    MSG_CMACCP =  0,
    MSG_CMALLC =  1,
    MSG_CMCFM  =  2,
    MSG_CMCFMD =  3,
    MSG_CMDEAL =  4,
    MSG_CMECS  =  5,
    MSG_CMECT  =  6,
    MSG_CMEMN  =  7,
    MSG_CMEPLN =  8,
    MSG_CMESL  =  9,
    MSG_CMFLUS = 10,
    MSG_CMINIT = 11,
    MSG_CMPTR  = 12,
    MSG_CMRCV  = 13,
    MSG_CMRTS  = 14,
    MSG_CMSCT  = 15,
    MSG_CMSDT  = 16,
    MSG_CMSED  = 17,
    MSG_CMSEND = 18,
    MSG_CMSERR = 19,
    MSG_CMSF   = 20,
    MSG_CMSLD  = 21,
    MSG_CMSMN  = 22,
    MSG_CMSPLN = 23,
    MSG_CMSPTR = 24,
    MSG_CMSRC  = 25,
    MSG_CMSRT  = 26,
    MSG_CMSSL  = 27,
    MSG_CMSST  = 28,
    MSG_CMSTPN = 29,
    MSG_CMTRTS = 30,
    MSG_XCSCSU = 31,
    MSG_XCSCST = 32,
    MSG_XCSCSP = 33
} CPIC_VERB_INDEX;

typedef struct cpicerr_message {
    CM_INT32 index;
    char     *message;
} CPICERR_MESSAGE;

typedef enum cpicerr_message_type {
    CPIC_SYNC_LEVELS  = 1,
    CPIC_CONV_TYPES   = 2,
    CPIC_STATES_CONV  = 3,
    CPIC_RC_CLASSES   = 4,
    CPIC_RETURN_CODES = 5,
    CPIC_VERBS_SHORT  = 6,
    CPIC_VERBS_LONG   = 7
} CPICERR_MESSAGE_TYPE;

typedef enum {
    ALL_ERRORS      ,
    CONTINUE        ,
    RETRY_VERB      ,
    ERROR_RECEIVED  ,
    RETRY_CONV      ,
    RETRY_CONV_BO   ,
    BACKOUT_RECEIVED,
    UNRECOVERABLE   ,
    UNRECOVERABLE_BO,
    NO_ERRORS
} CPIC_RC_HANDLING;

typedef struct cpicerr_message_list {
    CPICERR_MESSAGE_TYPE type;
    CPICERR_MESSAGE *    list;
} CPICERR_MESSAGE_LIST;

typedef struct cpic_conv_attrib {
    /*=========================================================================
     * Everything about one conversation.
     *=======================================================================*/
    CM_INT32                     call_index;
    unsigned char CM_PTR         buffer;
    unsigned char CM_PTR         conversation_ID;
    CM_CONVERSATION_STATE        conversation_state;
    CM_CONVERSATION_TYPE         conversation_type;
    CM_DATA_RECEIVED_TYPE        data_received;
    CM_DEALLOCATE_TYPE           deallocate_type;
    CM_ERROR_DIRECTION           error_direction;
    CM_FILL                      fill;
    unsigned char CM_PTR         log_data;
    CM_INT32                     log_data_length;
    unsigned char CM_PTR         mode_name;
    CM_INT32                     mode_name_length;
    unsigned char CM_PTR         partner_LU_name;
    CM_INT32                     partner_LU_name_length;
    CM_PREPARE_TO_RECEIVE_TYPE   prepare_to_receive_type;
    CM_RECEIVE_TYPE              receive_type;
    CM_INT32                     received_length;
    CM_INT32                     requested_length;
    CM_REQUEST_TO_SEND_RECEIVED  request_to_send_received;
    CM_RETURN_CODE               return_code;
    CM_RETURN_CONTROL            return_control;
    CM_INT32                     send_length;
    CM_SEND_TYPE                 send_type;
    CM_STATUS_RECEIVED           status_received;
    unsigned char CM_PTR         sym_dest_name;
    CM_SYNC_LEVEL                sync_level;
    unsigned char CM_PTR         TP_name;
    CM_INT32                     TP_name_length;
} CPIC_CONV_ATTRIB;


extern CPICERR_MESSAGE cpicerr_verbs_short[];
extern CPICERR_MESSAGE cpicerr_verbs_long[];
extern CPICERR_MESSAGE cpicerr_return_codes[];
extern CPICERR_MESSAGE cpicerr_rc_classes[];
extern CPICERR_MESSAGE cpicerr_states_conv[];
extern CPICERR_MESSAGE cpicerr_conv_types[];
extern CPICERR_MESSAGE cpicerr_sync_levels[];

extern CPIC_VERB_INDEX call_state_map[];

char *cpicerr_get_message(CPICERR_MESSAGE_TYPE, CM_INT32);
