//---------------------------------------------------------------------------
#include <Windows.h>
#pragma hdrstop

#include "PCIE.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

__fastcall PCIE::PCIE():
    m_hDLL(NULL),
    m_hPCIe(NULL)
{
    LoadDll();
}

__fastcall PCIE::~PCIE(){
    FreeDll();
    Close();
}


bool __fastcall PCIE::LoadDll(void){
	bool bSuccess = false;
	
	//check OS 
	BOOL bIsWow64 = FALSE;
	typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
	LPFN_ISWOW64PROCESS fnIsWow64Process;

	fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress( GetModuleHandle("kernel32"),"IsWow64Process");
	if (NULL != fnIsWow64Process)
	{
		fnIsWow64Process(GetCurrentProcess(),&bIsWow64);
	}

	if(bIsWow64)
	{
		m_hDLL = ::LoadLibrary("TERASIC_PCIEx64.DLL");
	}
	else
	{
		m_hDLL = ::LoadLibrary("TERASIC_PCIE.dll");
	}
	
	if (m_hDLL) {
		m_PCIE_ScanCard  = (LPPCIE_ScanCard)::GetProcAddress(m_hDLL, "PCIE_ScanCard");
		m_PCIE_Open  = (LPPCIE_Open)::GetProcAddress(m_hDLL, "PCIE_Open");
		m_PCIE_Close  = (LPPCIE_Close)::GetProcAddress(m_hDLL, "PCIE_Close");
		m_PCIE_Read32  = (LPPCIE_Read32)::GetProcAddress(m_hDLL, "PCIE_Read32");
		m_PCIE_Write32  = (LPPCIE_Write32)::GetProcAddress(m_hDLL, "PCIE_Write32");
		m_PCIE_DmaWrite  = (LPPCIE_DmaWrite)::GetProcAddress(m_hDLL, "PCIE_DmaWrite");
		m_PCIE_DmaRead  = (LPPCIE_DmaRead)::GetProcAddress(m_hDLL, "PCIE_DmaRead");
		m_PCIE_DmaFifoWrite  = (LPPCIE_DmaFifoWrite)::GetProcAddress(m_hDLL, "PCIE_DmaFifoWrite");
		m_PCIE_DmaFifoRead  = (LPPCIE_DmaFifoRead)::GetProcAddress(m_hDLL, "PCIE_DmaFifoRead");
		m_PCIE_IntEnable  = (LPPCIE_IntEnable)::GetProcAddress(m_hDLL, "PCIE_IntEnable");
		m_PCIE_IntDisable  = (LPPCIE_IntDisable)::GetProcAddress(m_hDLL, "PCIE_IntDisable");

		if (!m_PCIE_ScanCard ||
            !m_PCIE_Open || !m_PCIE_Close || !m_PCIE_Read32 || !m_PCIE_Write32 ||
            !m_PCIE_DmaWrite || !m_PCIE_DmaRead ||
            !m_PCIE_DmaFifoWrite || !m_PCIE_DmaFifoRead ||
            !m_PCIE_IntEnable || !m_PCIE_IntDisable){
			//strMsg.printf("load TERASIC_DOWNLOAD.DLL fail. Cannot find all of desired API");
			//MessageDlg(strMsg, mtError , TMsgDlgButtons() << mbOK, 0);
		}else{
			bSuccess = true;
		}
	}else{
		//strMsg.printf("fail to load dll - %s", strDLL.c_str());
		//MessageDlg(strMsg, mtError , TMsgDlgButtons() << mbOK, 0);
	}

	if (!bSuccess && m_hDLL) {
        FreeDll();
	}
	return true;
}

void __fastcall PCIE::FreeDll(void){
    if (m_hDLL){
        ::FreeLibrary(m_hDLL);
        m_hDLL = NULL;
    }
}


bool __fastcall PCIE::IsDriverAvailable(void){
    return m_hDLL?true:false;
}


bool __fastcall PCIE::ScanCard(WORD wVendorID, WORD wDeviceID, DWORD *pdwDeviceNum, PCIE_CONFIG szConfigList[]){
    if (!m_hDLL || !m_PCIE_ScanCard)
        return false;
    return m_PCIE_ScanCard(wVendorID, wDeviceID, pdwDeviceNum, szConfigList);
}

bool __fastcall PCIE::Open(WORD wVendorID, WORD wDeviceID, WORD wCardIndex){
    if (!m_hDLL || !m_PCIE_Open)
        return false;
    m_hPCIe = m_PCIE_Open(wVendorID, wDeviceID, wCardIndex);
    if (m_hPCIe)
        return true;
    return false;
}

void __fastcall PCIE::Close(void){
    if (m_hDLL && m_hPCIe && m_PCIE_Close){
       m_PCIE_Close(m_hPCIe);
       m_hPCIe = NULL;
    }   
}

bool __fastcall PCIE::Read32(PCIE_BAR PcieBar, PCIE_ADDRESS PcieAddress, DWORD *pData32){
    if (!m_hDLL || !m_hPCIe)
        return false;
    return m_PCIE_Read32(m_hPCIe, PcieBar, PcieAddress, pData32);
}

bool __fastcall PCIE::Write32(PCIE_BAR PcieBar, PCIE_ADDRESS PcieAddress, DWORD Data32){
    if (!m_hDLL || !m_hPCIe)
        return false;
    return m_PCIE_Write32(m_hPCIe, PcieBar, PcieAddress, Data32);
}

bool __fastcall PCIE::DmaWrite(PCIE_LOCAL_ADDRESS LocalAddress, void *pData, DWORD DataByteLen){
    if (!m_hDLL || !m_hPCIe)
        return false;
    return m_PCIE_DmaWrite(m_hPCIe, LocalAddress, pData, DataByteLen);
}

bool __fastcall PCIE::DmaRead(PCIE_LOCAL_ADDRESS LocalAddress, void *pBuffer, DWORD DataByteLen){
    if (!m_hDLL || !m_hPCIe)
        return false;
    return m_PCIE_DmaRead(m_hPCIe, LocalAddress, pBuffer, DataByteLen);
}

bool __fastcall PCIE::DmaFifoWrite(PCIE_LOCAL_FIFO_ID LocalFifoId, void *pData, DWORD DataByteLen){
    if (!m_hDLL || !m_hPCIe)
        return false;
    return m_PCIE_DmaFifoWrite(m_hPCIe, LocalFifoId, pData, DataByteLen);
}

bool __fastcall PCIE::DmaFifoRead(PCIE_LOCAL_FIFO_ID LocalFifoId, void *pBuffer, DWORD DataByteLen){
    if (!m_hDLL || !m_hPCIe)
        return false;
    return m_PCIE_DmaFifoRead(m_hPCIe, LocalFifoId, pBuffer, DataByteLen);
}

bool __fastcall PCIE::IntEnable (TERASIC_INT_HANDLER funcIntHandler){
    if (!m_hDLL || !m_hPCIe)
        return false;
    return m_PCIE_IntEnable(m_hPCIe, funcIntHandler);
}

void __fastcall PCIE::IntDisable (void){
    if (!m_hDLL || !m_hPCIe)
        return;
    return m_PCIE_IntDisable(m_hPCIe);
}

bool __fastcall PCIE::IsOpened(void){
    if (m_hPCIe)
        return true;
    return false;
}

