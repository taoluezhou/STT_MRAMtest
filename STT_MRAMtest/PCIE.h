//---------------------------------------------------------------------------

#ifndef PCIEH
#define PCIEH
//---------------------------------------------------------------------------

#include "TERASIC_PCIE.h"



class PCIE{
protected:
    HMODULE m_hDLL;
    PCIE_HANDLE m_hPCIe;
    bool __fastcall LoadDll(void);
    void __fastcall FreeDll(void);

    LPPCIE_ScanCard    m_PCIE_ScanCard;
    LPPCIE_Open        m_PCIE_Open;
    LPPCIE_Close       m_PCIE_Close;
    LPPCIE_Read32      m_PCIE_Read32;
    LPPCIE_Write32     m_PCIE_Write32;
    LPPCIE_DmaWrite    m_PCIE_DmaWrite;
    LPPCIE_DmaRead     m_PCIE_DmaRead;
    LPPCIE_DmaFifoWrite    m_PCIE_DmaFifoWrite;
    LPPCIE_DmaFifoRead     m_PCIE_DmaFifoRead;
    LPPCIE_IntEnable   m_PCIE_IntEnable;
    LPPCIE_IntDisable  m_PCIE_IntDisable;
public:
    __fastcall PCIE();
    __fastcall ~PCIE();

    bool __fastcall IsDriverAvailable(void);
    bool __fastcall IsOpened(void);

    bool __fastcall ScanCard(WORD wVendorID, WORD wDeviceID, DWORD *pdwDeviceNum, PCIE_CONFIG szConfigList[]);
    bool __fastcall Open(WORD wVendorID, WORD wDeviceID, WORD wCardIndex);
    void __fastcall Close(void);
    bool __fastcall Read32(PCIE_BAR PcieBar, PCIE_ADDRESS PcieAddress, DWORD *pData32);
    bool __fastcall Write32(PCIE_BAR PcieBar, PCIE_ADDRESS PcieAddress, DWORD Data32);
    bool __fastcall DmaWrite(PCIE_LOCAL_ADDRESS LocalAddress, void *pData, DWORD DataByteLen);
    bool __fastcall DmaRead(PCIE_LOCAL_ADDRESS LocalAddress, void *pBuffer, DWORD DataByteLen);
    bool __fastcall DmaFifoWrite(PCIE_LOCAL_FIFO_ID LocalFifoId, void *pData, DWORD DataByteLen);
    bool __fastcall DmaFifoRead(PCIE_LOCAL_FIFO_ID LocalFifoId, void *pBuffer, DWORD DataByteLen);
    bool __fastcall IntEnable (TERASIC_INT_HANDLER funcIntHandler);
    void __fastcall IntDisable (void);

};
#endif







