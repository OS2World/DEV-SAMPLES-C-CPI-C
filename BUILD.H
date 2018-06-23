/*
 *  PROGRAM:   JQCPIC -- John Q's Portable CPI-C Abuser
 *
 *  MODULE:    BUILD.H
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

/* function prototypes */
CM_CONVERSATION_STATE build_cmaccp (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmallc (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmcfm  (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmcfmd (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmdeala(CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmdealc(CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmdealf(CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmdeals(CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmecs  (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmect  (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmemn  (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmepln (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmesl  (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmflus (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cminit (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmptrc (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmptrf (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmptrs (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmrcvi (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmrcvw (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmrts  (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmsct  (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmsdt  (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmsed  (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmsend (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmserr (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmsf   (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmsld  (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmsmn  (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmspln (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmsptr (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmsrc  (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmsrt  (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmssl  (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmsst  (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmstpn (CPIC_CONV_ATTRIB *);
CM_CONVERSATION_STATE build_cmtrts (CPIC_CONV_ATTRIB *);
