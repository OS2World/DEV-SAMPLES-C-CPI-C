/*
 *  PROGRAM:   JQCPIC -- John Q's Portable CPI-C Abuser
 *
 *  MODULE:    JQCPIC.H -- common variables, typedefs, constants, and
 *                         function prototypes
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
 *  06/20/92   Added check_receive() & check_rts()
 *             Added const
 */

#include <cmc.h>

#include "cpicdefs.h"
#include "port.h"

/*=============================================================================
 * Typedefs and Enums
 *===========================================================================*/

typedef unsigned char UCHAR;
typedef unsigned int  UINT;
typedef   signed int  INTEGER;
typedef unsigned long ULONG;

typedef enum { FALSE, TRUE } BOOL;

/*=============================================================================
 * Definitions
 *===========================================================================*/

#define CONVERSATION_ID_LENGTH  (8)
#define SYM_DEST_NAME_LENGTH    (8)
#define NUM_CPIC_STATES         (9)
#define NUM_CPIC_CALLS          (37)
#define NUM_CPIC_RETURN_CODES   (35)
#define LOG_EXTENSION           ".LOG"
#define VALID_PARM_PERCENTAGE   (95)    /* only 1 in 20 is bad */

/* character constants */
#define BLANK           ((char)' ')
#define NULL_CHARACTER  ((char)'\0')
#define BACKSLASH       ((char)'\\')
#define SLASH           ((char)'/')
#define QUESTION_MARK   ((char)'?')
#define CRLF            ((char)'\n')
#define TAB             ((char)'\t')

/*=============================================================================
 * External definitions
 *===========================================================================*/

/* character constants */
extern unsigned char sym_dest_name[];
extern char *program_version;
extern char *program_name;

extern CPIC_VERB_INDEX cpic_state_map[];

/*=============================================================================
 * Function prototypes
 *===========================================================================*/

BOOL                  check_receive           (const CPIC_CONV_ATTRIB *);
BOOL                  check_rts               (const CPIC_CONV_ATTRIB *);
BOOL                  generate_valid_parm     (void);
char*                 get_program_name        (char *);
CM_CONVERSATION_STATE get_new_conversation_state (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE issue_cpic_call         (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE unexpected_rc           (CPIC_CONV_ATTRIB *);
CM_INT32              get_random_CM_INT32     (void);
void                  all_done                (const int);
void                  command_line            (int, char **);
void                  fetch_conversation_state(CPIC_CONV_ATTRIB *);
void                  fill_field              (char *, size_t);
void                  show_error              (char *, ...);
void                  show_conv_state         (const CM_CONVERSATION_STATE);
void                  show_cpic_call          (CPIC_CONV_ATTRIB *,
                                               const CPIC_VERB_INDEX);
void                  show_cpic_call_long     (const CPIC_VERB_INDEX);
void                  show_cpic_call_short    (const CPIC_VERB_INDEX);
void                  show_end_of_line        (void);
void                  show_return_code        (CPIC_CONV_ATTRIB *);
void                  usage                   (void);
