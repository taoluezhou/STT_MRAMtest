// --------------------------------------------------------------------
// Copyright (c) 2010 by Terasic Technologies Inc. 
// --------------------------------------------------------------------
//
// Permission:
//
//   Terasic grants permission to use and modify this code for use
//   in synthesis for all Terasic Development Boards and Altera Development 
//   Kits made by Terasic.  Other use of this code, including the selling 
//   ,duplication, or modification of any portion is strictly prohibited.
//
// Disclaimer:
//
//   This VHDL/Verilog or C/C++ source code is intended as a design reference
//   which illustrates how these types of functions can be implemented.
//   It is the user's responsibility to verify their design for
//   consistency and functionality through the use of formal
//   verification methods.  Terasic provides no warranty regarding the use 
//   or functionality of this code.
//
// --------------------------------------------------------------------
//           
//                     Terasic Technologies Inc
//                     356 Fu-Shin E. Rd Sec. 1. JhuBei City,
//                     HsinChu County, Taiwan
//                     302
//
//                     web: http://www.terasic.com/
//                     email: support@terasic.com
//
// --------------------------------------------------------------------
//

#ifndef _INC_TERASIC_PCIE_H
#define _INC_TERASIC_PCIE_H

#include <windows.h>

#ifdef __cplusplus
extern "C"{
#endif

#define PCIE_API FAR PASCAL
typedef void *PCIE_HANDLE;
typedef DWORD PCIE_ADDRESS;
typedef DWORD PCIE_LOCAL_ADDRESS;
typedef DWORD PCIE_LOCAL_FIFO_ID;


typedef enum
{
    PCIE_BAR0 = 0,  // do not change it
    PCIE_BAR1,
    PCIE_BAR2,
    PCIE_BAR3,
    PCIE_BAR4,
    PCIE_BAR5
}PCIE_BAR;

typedef enum{
    DMA_ALTERA_AN223=0x01
}DMA_ENGINE_TYPE;

typedef struct
{
    DWORD dwCounter;   // number of interrupts received
    DWORD dwLost;      // number of interrupts not yet dealt with
    BOOL fStopped;     // was interrupt disabled during wait
} PCIE_INT_RESULT;

//================================================================================
// PCI Bus Function
#pragma pack(push, 1)
typedef struct {
    USHORT  VendorID;                   // (ro)
    USHORT  DeviceID;                   // (ro)
    USHORT  Command;                    // Device control
    USHORT  Status;
    UCHAR   RevisionID;                 // (ro)
    UCHAR   ProgIf;                     // (ro)
    UCHAR   SubClass;                   // (ro)
    UCHAR   BaseClass;                  // (ro)
    UCHAR   CacheLineSize;              // (ro+)
    UCHAR   LatencyTimer;               // (ro+)
    UCHAR   HeaderType;                 // (ro)
    UCHAR   BIST;                       // Built in self test

    union {
        struct _MYPCI_HEADER_TYPE_0 {
            ULONG   BaseAddresses[6];
            ULONG   CIS;
            USHORT  SubVendorID;
            USHORT  SubSystemID;
            ULONG   ROMBaseAddress;
            UCHAR   CapabilitiesPtr;
            UCHAR   Reserved1[3];
            ULONG   Reserved2;
            UCHAR   InterruptLine;      //
            UCHAR   InterruptPin;       // (ro)
            UCHAR   MinimumGrant;       // (ro)
            UCHAR   MaximumLatency;     // (ro)
        } type0;


    } u;
    UCHAR   DeviceSpecific[192];
} PCIE_CONFIG;

#pragma pack(pop)


typedef void (PCIE_API *TERASIC_INT_HANDLER)( PCIE_HANDLE hALTERA, PCIE_INT_RESULT *intResult);


//================================================================================
// function prototype used for "static load DLL"
BOOL  PCIE_API PCIE_ScanCard(WORD wVendorID, WORD wDeviceID, DWORD *pdwDeviceNum, PCIE_CONFIG szConfigList[]); // PciVID/PciPID=0/0--> scan all pci card
PCIE_HANDLE PCIE_API PCIE_Open(WORD wVendorID, WORD wDeviceID, WORD wCardNum);
void PCIE_API PCIE_Close(PCIE_HANDLE hFPGA);
BOOL PCIE_API PCIE_Read32 (PCIE_HANDLE hFPGA, PCIE_BAR PciBar, PCIE_ADDRESS PciAddress, DWORD *pdwData);
BOOL PCIE_API PCIE_Write32 (PCIE_HANDLE hFPGA, PCIE_BAR PciBar, PCIE_ADDRESS PciAddress, DWORD dwData);
BOOL PCIE_API PCIE_DmaRead (PCIE_HANDLE hFPGA, PCIE_LOCAL_ADDRESS LocalAddress, void *pBuffer, DWORD dwBufSize);
BOOL PCIE_API PCIE_DmaWrite (PCIE_HANDLE hFPGA, PCIE_LOCAL_ADDRESS LocalAddress, void *pData, DWORD dwDataSize);
BOOL PCIE_API PCIE_DmaFifoRead (PCIE_HANDLE hFPGA, PCIE_LOCAL_FIFO_ID LocalFifoId, void *pBuffer, DWORD dwBufSize);
BOOL PCIE_API PCIE_DmaFifoWrite (PCIE_HANDLE hFPGA, PCIE_LOCAL_FIFO_ID LocalFifoId, void *pData, DWORD dwDataSize);

// interrupt
BOOL PCIE_API PCIE_IntIsEnabled (PCIE_HANDLE hFPGA);
BOOL PCIE_API PCIE_IntEnable (PCIE_HANDLE hFPGA, TERASIC_INT_HANDLER funcIntHandler);
void PCIE_API PCIE_IntDisable (PCIE_HANDLE hFPGA);

//================================================================================
// function prototype used for "dynamic load DLL"
typedef BOOL  (PCIE_API *LPPCIE_ScanCard)(WORD wVendorID, WORD wDeviceID, DWORD *pdwDeviceNum, PCIE_CONFIG szConfigList[]);
typedef PCIE_HANDLE (PCIE_API *LPPCIE_Open)(WORD wVendorID, WORD wDeviceID, WORD wCardNum);
typedef void (PCIE_API *LPPCIE_Close)(PCIE_HANDLE hFPGA);
typedef BOOL (PCIE_API *LPPCIE_Read32)(PCIE_HANDLE hFPGA, PCIE_BAR PciBar, PCIE_ADDRESS PciAddress, DWORD *pdwData);
typedef BOOL (PCIE_API *LPPCIE_Write32)(PCIE_HANDLE hFPGA, PCIE_BAR PciBar, PCIE_ADDRESS PciAddress, DWORD dwData);
typedef BOOL (PCIE_API *LPPCIE_DmaRead) (PCIE_HANDLE hFPGA, PCIE_LOCAL_ADDRESS LocalAddress, void *pBuffer, DWORD dwBufSize);
typedef BOOL (PCIE_API *LPPCIE_DmaWrite) (PCIE_HANDLE hFPGA, PCIE_LOCAL_ADDRESS LocalAddress, void *pData, DWORD dwDataSize);
typedef BOOL (PCIE_API *LPPCIE_DmaFifoRead) (PCIE_HANDLE hFPGA, PCIE_LOCAL_FIFO_ID LocalFifoId, void *pBuffer, DWORD dwBufSize);
typedef BOOL (PCIE_API *LPPCIE_DmaFifoWrite) (PCIE_HANDLE hFPGA, PCIE_LOCAL_FIFO_ID LocalFifoId, void *pData, DWORD dwDataSize);
// interrupt
typedef BOOL (PCIE_API *LPPCIE_IntIsEnabled) (PCIE_HANDLE hFPGA);
typedef BOOL (PCIE_API *LPPCIE_IntEnable) (PCIE_HANDLE hFPGA, TERASIC_INT_HANDLER funcIntHandler);
typedef void (PCIE_API *LPPCIE_IntDisable) (PCIE_HANDLE hFPGA);





#ifdef __cplusplus
}
#endif



#endif /* _INC_TERASIC_PCIE_H */

