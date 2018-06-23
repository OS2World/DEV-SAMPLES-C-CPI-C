/*
 *  PROGRAM:   JQCPIC -- John Q's Portable CPI-C Abuser
 *
 *  MODULE:    CALLS.H -- state table probabilities
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

/*
    This table matches the table in the CPI-C reference manual, with the
    following attributes:
    -   There's an extra state: 0.  I use it to indicate that the only
        allowable call is CMINIT.  In state 1, the only allowable call
        is CMACCP.  This makes it easy to distinguish between the client
        and server sides.
    -   The numbers in the table indicate the suggested probability for
        issuing each call.  0 indicates "don't make this call in this
        state."  I've initially put a value of 1 for all the state-check
        cells; allow state check approximately 1 out of 100 times.  I've
        lowered the values on the Extract calls, since they're just not
        very interesting.
    -   The values for DEALLOCATE are low, in an attempt to get
        something useful done before the conversation goes away.
    -   The values for Set_Mode_Name, Set_Partner_LU_Name, and Set_TP_Name
        are low, since setting them messes up the conversation.
*/


static unsigned cpic_state_table[NUM_CPIC_CALLS][NUM_CPIC_STATES] = {
    /*                  0   1   2   3   4   5   6   7   8 */
  { /* CMACCP   0  */   0,100,  0,  0,  0,  0,  0,  0,  0  },
  { /* CMALLC   1  */   0,  0,100,  1,  1,  1,  1,  1,  1  },
  { /* CMCFM    2  */   0,  0,  1,100,  1,100,  1,  1,  1  },
  { /* CMCFMD   3  */   0,  0,  1,  1,  1,  1,100,100,100  },
  { /* CMDEALa  4  */   0,  0,  2,  2,  2,  2,  2,  2,  2  },
  { /* CMDEALc  5  */   0,  0,  1,  2,  1,  2,  1,  1,  1  },
  { /* CMDEALf  6  */   0,  0,  1,  2,  1,  2,  1,  1,  1  },
  { /* CMDEALs  7  */   0,  0,  1,  2,  1,  2,  1,  1,  1  },
  { /* CMECS    8  */   0,  0, 10, 10, 10, 10, 10, 10, 10  },
  { /* CMECT    9  */   0,  0, 10, 10, 10, 10, 10, 10, 10  },
  { /* CMEMN   10  */   0,  0, 10, 10, 10, 10, 10, 10, 10  },
  { /* CMEPLN  11  */   0,  0, 10, 10, 10, 10, 10, 10, 10  },
  { /* CMESL   12  */   0,  0, 10, 10, 10, 10, 10, 10, 10  },
  { /* CMFLUS  13  */   0,  0,  1,100,  1,100,  1,  1,  1  },
  { /* CMINIT  14  */ 100,  0,  0,  0,  0,  0,  0,  0,  0  },
  { /* CMPTRc  15  */   0,  0,  1,100,  1,100,  1,  1,  1  },
  { /* CMPTRf  16  */   0,  0,  1,100,  1,100,  1,  1,  1  },
  { /* CMPTRs  17  */   0,  0,  1,100,  1,100,  1,  1,  1  },
  { /* CMRCVi  18  */   0,  0,  1,  1,100,  1,  1,  1,  1  },
  { /* CMRCVw  19  */   0,  0,  1,100,100,100,  1,  1,  1  },
  { /* CMRTS   20  */   0,  0,  1,100,100,100,100,100,100  },
  { /* CMSCT   21  */   0,  0,100,  1,  1,  1,  1,  1,  1  },
  { /* CMSDT   22  */   0,  0,100,100,100,100,100,100,100  },
  { /* CMSED   23  */   0,  0,100,100,100,100,100,100,100  },
  { /* CMSEND  24  */   0,  0,  1,100,  1,100,  1,  1,  1  },
  { /* CMSERR  25  */   0,  0,  1,100,100,100,100,100,100  },
  { /* CMSF    26  */   0,  0,100,100,100,100,100,100,100  },
  { /* CMSLD   27  */   0,  0,100,100,100,100,100,100,100  },
  { /* CMSMN   29  */   0,  0,  2,  1,  1,  1,  1,  1,  1  },
  { /* CMSPLN  29  */   0,  0,  2,  1,  1,  1,  1,  1,  1  },
  { /* CMSPTR  30  */   0,  0,100,100,100,100,100,100,100  },
  { /* CMSRC   31  */   0,  0,100,  1,  1,  1,  1,  1,  1  },
  { /* CMSRT   32  */   0,  0,100,100,100,100,100,100,100  },
  { /* CMSSL   33  */   0,  0,100,  1,  1,  1,  1,  1,  1  },
  { /* CMSST   34  */   0,  0,100,100,100,100,100,100,100  },
  { /* CMSTPN  35  */   0,  0,  2,  1,  1,  1,  1,  1,  1  },
  { /* CMTRTS  36  */   0,  0,  1,100,100,100,  1,  1,  1  }
};
