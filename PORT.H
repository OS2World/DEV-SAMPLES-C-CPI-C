/*
 *  PROGRAM:   JQCPIC -- John Q's Portable CPI-C Abuser
 *
 *  MODULE:    PORT.H
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
 *  06/24/92   new.
 */

/* function prototypes */
void *get_memory(size_t);
void free_memory(void *);
void protocol_error(void);
void write_error(char *, ...);
void write_output(char *, ...);
