/* /////////////////////////////////////////////////////////////////////////// */
#ifndef __LOAD_DLL__
#define __LOAD_DLL__

#include "PlateformDefine.h"
#include "sm_api_type.h"
#include "sm_algo.h"

/* /////////////////////////////////////////////////////////////////////////// */
/*	Object class define                                                        */
/* /////////////////////////////////////////////////////////////////////////// */
#define SMO_PUBLIC_KEY              0x00000002
#define SMO_PRIVATE_KEY             0x00000003
#define SMO_SECRET_KEY              0x00000004

/* /////////////////////////////////////////////////////////////////////////// */
/*	Key attribute flags mask define                                            */
/* /////////////////////////////////////////////////////////////////////////// */
#define	SMKA_TOKEN                  0x00000001
#define SMKA_EXTRACTABLE            0x00000002
#define SMKA_MODIFIABLE             0x00000004
#define SMKA_ENCRYPT                0x00000008
#define SMKA_DECRYPT                0x00000010
#define SMKA_SIGN                   0x00000020
#define SMKA_VERIFY                 0x00000040
#define SMKA_WRAP                   0x00000080
#define SMKA_UNWRAP                 0x00000100

/* ///////////////////////////////////////////////////////////////////////// */
/* 
* define update key pair flag 
* used by SM_UpdateKeyPair
*/
/* ///////////////////////////////////////////////////////////////////////// */
#define SMKF_UPDATE_KEY_PAIR_SIGN             0
#define SMKF_UPDATE_KEY_PAIR_WRAP             1

/* ///////////////////////////////////////////////////////////////////////// */
/* 
* define config key identifiers
* used by SM_GetCfgKeyHandle
*/
/* ///////////////////////////////////////////////////////////////////////// */
#define SMCK_ECC_ENC_PUBLIC            0x105
#define SMCK_ECC_DEC_PRIVATE           0x106
#define SMCK_ECC_VERIFY_PUBLIC         0x205
#define SMCK_ECC_SIGN_PRIVATE          0x206
#define SMCK_SYMM                      0x1

/* /////////////////////////////////////////////////////////////////////////// */
/*	MechanismInfo flags mask define
    used by SM_GetMechanismInfo                                                */
/* /////////////////////////////////////////////////////////////////////////// */
#define SMMF_ENCRYPT                0x00000001
#define SMMF_DECRYPT                0x00000002
#define SMMF_DIGEST                 0x00000004
#define SMMF_SIGN                   0x00000008
#define SMMF_VERIFY                 0x00000010
#define SMMF_WRAP                   0x00000020
#define SMMF_UNWRAP                 0x00000040

/* /////////////////////////////////////////////////////////////////////////// */
/*	define the hardware type                                                   */
/* /////////////////////////////////////////////////////////////////////////// */
#define SMH_TYPE_PCI                0   /* Secure module type is PCI    */
#define SMH_TYPE_PCMCIA             1   /* Secure module type is PCMCIA */
#define SMH_TYPE_USB                2   /* Secure module type is USB    */
#define SMH_TYPE_RS232              3   /* Secure module type is RS232  */
#define SMH_TYPE_USBKEY             4   /* Secure module type is USBKEY */

/* ///////////////////////////////////////////////////////////////////////// */
/* 
* define Random Number 
* used by SM_GenRandom
*/
/* ///////////////////////////////////////////////////////////////////////// */
#define SMH_DEV_RND_NUM0             0
#define SMH_DEV_RND_NUM1             1
#define SMH_DEV_RND_NUM2             2
#define SMH_DEV_RND_NUM3             3
#define SMH_DEV_RND_ALL              0xFFFF

/* ///////////////////////////////////////////////////////////////////////// */
/* 
 * define current Hash process mode is normal or CP
 * used by Hash related API
 */
/* ///////////////////////////////////////////////////////////////////////// */
#define SMH_DEV_MODE_SD                      0
#define SMH_DEV_MODE_CP                      1

/* ///////////////////////////////////////////////////////////////////////// */
/* define some structure */
/* ///////////////////////////////////////////////////////////////////////// */
/*! struct SM_NVMEM_INFO. */
typedef struct _SM_NVMEM_INFO
{
   /*! 
    * A member variable.
    * the maximal size of the NVMem.
    */
    SM_UINT         uiMaxNVMemSize;
    /*! 
    * A member variable.
    * the sector size of the NVMem.
    */
    SM_UINT         uiNVMemSectorSize;
} SM_NVMEM_INFO;


/*! struct SM_ADMEM_INFO. */
typedef struct _SM_ADMEM_INFO
{
/*! 
* A member variable.
* the maximal size of the AuthDevMem1.
    */
    SM_UINT         uiMaxAuthDevMem1Size;
    /*! 
    * A member variable.
    * the maximal size of the AuthDevMem2.
    */
    SM_UINT         uiMaxAuthDevMem2Size;
} SM_ADMEM_INFO;

/*! struct SM_RESOURCE_INFO. */
typedef struct _SM_RESOURCE_INFO
{
   /*! 
    * A member variable.
    * the buffer size of the transfer.
    */
    SM_UINT         uiHPIBufSize;

    /*! 
    * A member variable.
    * the maximal number of pipe.
    */
    SM_WORD         wMaxPipeCount;
    /*! 
    * A member variable.
    * the left number of pipe.
    */
    SM_WORD         wFreePipeCount;
    /*! 
    * A member variable.
    * the maximal number of secret key object.
    * \n include token object and session object.
    */
    SM_WORD         wMaxSecretKeyCount;
    /*! 
    * A member variable.
    * the left number of secret key object.
    * \n include token object and session object.
    */
    SM_WORD         wFreeSecretKeyCount;
    /*! 
    * A member variable.
    * the maximal number of public key object.
    * \n include token object and session object.
    */
    SM_WORD         wMaxPublicKeyCount;
    /*! 
    * A member variable.
    * the left number of public key object.
    * \n include token object and session object.
    */
    SM_WORD         wFreePublicKeyCount;
    /*! 
    * A member variable.
    * the maximal number of private key object.
    * \n include token object and session object.
    */
    SM_WORD         wMaxPrivateKeyCount;
    /*! 
    * A member variable.
    * the left number of private key object.
    * \n include token object and session object.
    */
    SM_WORD         wFreePrivateKeyCount;

    /*! 
    * A member variable.
    * the maximal number of secret key token object.
    */
    SM_WORD         wMaxSecretKeyTokenCount;
    /*! 
    * A member variable.
    * the left number of secret key token object.
    */
    SM_WORD         wFreeSecretKeyTokenCount;
    /*! 
    * A member variable.
    * the maximal number of public key token object.
    */
    SM_WORD         wMaxPublicKeyTokenCount;
    /*! 
    * A member variable.
    * the left number of public key token object.
    */
    SM_WORD         wFreePublicKeyTokenCount;
    /*! 
    * A member variable.
    * the maximal number of private key token object.
    */
    SM_WORD         wMaxPrivateKeyTokenCount;
    /*! 
    * A member variable.
    * the left number of private key token object.
    */
    SM_WORD         wFreePrivateKeyTokenCount;

    /*! 
    * A member variable.
    * the device NVMem info.
    */
    SM_NVMEM_INFO   stNVMem;

	/*! 
    * A member variable.
    * the device ADMem info.
    */
    SM_ADMEM_INFO   stADMem;

    /*! 
    * A member variable.
    * the maximal length of user pin.
    */
    SM_WORD         wMaxPinLen;
    /*! 
    * A member variable.
    * the minimum length of user pin.
    */
    SM_WORD         wMinPinLen;
    /*! 
    * A member variable.
    * the maximal length of SO pin.
    */
    SM_WORD         wMaxSOPinLen;
    /*! 
    * A member variable.
    * the minimum length of SO pin.
    */
    SM_WORD         wMinSOPinLen;
    /*! 
    * A member variable.
    * the version of the device hardware.
    * \n the high 8bits is major version,
    * \n the low  8bits is minor version.
    * \n Example: 0102, the major is 1, the minor is 2.
    */
    SM_WORD         wHardwareVersion;
     /*! 
    * A member variable.
    * the version of the device firmware.
    * \n the high 8bits is major version,
    * \n the low  8bits is minor version.
    * \n Example: 0102, the major is 1, the minor is 2.
    */
    SM_WORD         wFirmwareVersion;
} SM_RESOURCE_INFO;

/*! struct SM_MANUFCT_INFO. */
typedef struct _SM_MANUFACTRUE_INFO
{
   /*! 
    * A member variable.
    * the model name of the device.
    */
    SM_BYTE         byModel[16];            
    /*! 
    * A member variable.
    * the product name of the device.
    */
    SM_BYTE         byManufacturerID[32];  
    /*! 
    * A member variable.
    * the product date of the device.
    */
    SM_BYTE         byManufactureDate[4];   
    /*! 
    * A member variable.
    * the batch of the device.
    */
    SM_BYTE         byBatch[4];                
    /*! 
    * A member variable.
    * the HUID of the device.
    */
    SM_BYTE         bySerial[16];           
    /*! 
    * A member variable.
    * the data time of the hardware.
    */
    SM_BYTE         byDateTime[8];          
} SM_MANUFCT_INFO;


/*! struct SM_DEVICE_INFO. */
typedef struct _SM_DEVICE_INFO
{
    /*! 
    * A member variable.
    * the struct resource info of device.
    */
    SM_RESOURCE_INFO    stDevResourceInfo;
    /*! 
    * A member variable.
    * the struct mechanism info of device.
    */
    SM_MANUFCT_INFO     stManufactureInfo;
    /*! 
    * A member variable.
    * the flags of the device, include
    * \n F_EXCLUSIVE                    0x00000001
    * \n F_DEV_LEVEL                    0x00000002
    * \n F_RNG                          0x00000004
    * \n F_CLOCK                        0x00000008
    * \n F_AUTHDEV_REQUIRED             0x00000010
    * \n F_LOGIN_REQUIRED               0x00000020
    * \n F_USER_PIN_INITIALIZED         0x00000040
    * \n F_RESTORE_KEY_NOT_NEEDED       0x00000080
    * \n F_RESOURCE_INITIALIZED         0x00000100
    * \n F_USER_PIN_COUNT_LOW           0x00000200
    * \n F_USER_PIN_LOCKED              0x00000400
    * \n F_SO_PIN_COUNT_LOW             0x00000800
    * \n F_SO_PIN_LOCKED                0x00001000
    * \n --	Bit[31:13]
    */
    SM_UINT             uiFlags;
    /*! 
    * A member variable.
    * the status of the device, include
    * \n F_PY_CHUCHANG               0x00000000
    * \n F_PY_GONGZUO                0x00000001
    * \n F_PY_RUKU                   0x00000002
    */
    SM_UINT             uiStatus;
} SM_DEVICE_INFO, *PSM_DEVICE_INFO;

/*! struct SM_DEVICE_INFO. */
typedef struct _SM_MECHANISM_INFO
{
    /*! 
    * A member variable.
    * The shortest block length of algorithm
    */
    SM_UINT uiMinBlockSize;   
    /*! 
    * A member variable.
    * The longest block length of algorithm
    */
    SM_UINT uiMaxBlockSize;    
    /*! 
    * A member variable.
    * The shortest length of key
    */
    SM_UINT uiMinKeySize;      
    /*! 
    * A member variable.
    * The longest length of key
    */
    SM_UINT uiMaxKeySize;     
    /*! 
    * A member variable.
    * The function of algorithm, include
    * 0x00000001, algorithm using for encrypt
    * 0x00000002, algorithm using for decrypt
    * 0x00000004, algorithm using for digest
    * 0x00000008, algorithm using for sign(mac)
    * 0x00000010, algorithm using for verify(mac)
    * 0x00000020, algorithm using for wrap
    * 0x00000040, algorithm using for unwrap
    */
    SM_UINT uiFlags;           
} SM_MECHANISM_INFO, *PSM_MECHANISM_INFO;


/*! struct SM_ALGORITHM. */
typedef struct  _SM_ALGORITHM{
    /*! 
    * A member variable.
    * The type of algorithm
    */
    SM_ALGORITHM_TYPE   AlgoType;
    /*! 
    * A member variable.
    * The parameter of algorithm
    */
    PSM_VOID            pParameter;
    /*! 
    * A member variable.
    * The length of parameter
    */
    SM_UINT             uiParameterLen; 
    /*! 
    * A member variable.
    * The reserve data of algorithm
    */
    SM_UINT             uiReserve;
} SM_ALGORITHM, *PSM_ALGORITHM;

/*! struct SM_KEY_ATTRIBUTE. */
typedef struct  _SM_KEY_ATTRIBUTE {
    /*! 
    * A member variable.
    * The type of object
    */
    SM_UINT         uiObjectClass;
    /*! 
    * A member variable.
    * The type of key
    */
    SM_KEY_TYPE     KeyType;
    /*! 
    * A member variable.
    * The label of key
    */
    SM_UINT         uiKeyLabel;
    /*! 
    * A member variable.
    * The start data of key
    */
    SM_BYTE         byStartDate[4];
    /*! 
    * A member variable.
    * The end data of key
    */
    SM_BYTE         byEndDate[4];
    /*! 
    * A member variable.
    * The attribute flag of key
    */
    SM_UINT         uiFlags;
    /*! 
    * A member variable.
    * The parameter of key
    */
    PSM_VOID        pParameter;
    /*! 
    * A member variable.
    * The parameter length of key
    */
    SM_UINT         uiParameterLen;  
} SM_KEY_ATTRIBUTE, *PSM_KEY_ATTRIBUTE;

/*! struct SM_ECC_PARAMETER. */
typedef struct _SM_ECC_PARAMETER
{
    /*! 
    * A member variable.
    * The modulus bit of ECC
    */
    SM_UINT         uiModulusBits;	
    /*! 
    * A member variable.
    * The parameter of ECC
    */
    PSM_VOID        pParameter;		
    /*! 
    * A member variable.
    * The parameter length of ECC
    */
    SM_UINT         uiParameterLen;	
} SM_ECC_PARAMETER, *PSM_ECC_PARAMETER;

/*! struct SM_BLOB_KEY. */
typedef struct _SM_BLOB_DATA
{
    /*! 
    * A member variable.
    * The length of data
    */
    SM_UINT         uiDataLen;
    /*! 
    * A member variable.
    * The pointer of data
    */
    PSM_BYTE        pbyData;
}SM_BLOB_KEY,      *PSM_BLOB_KEY,
 SM_BLOB_CONTEXT,  *PSM_BLOB_CONTEXT;

/*! struct SM_BLOB_ECCCIPHER. */
typedef struct _SM_BLOB_ECCCIPHER
{
    /*! 
    * A member variable.
    * The length of session key
    */
    SM_UINT         uiSessionKeyLen;
    /*! 
    * A member variable.
    * The length of cipher data
    */
    SM_UINT         uiCipherDataLen;
    /*! 
    * A member variable.
    * The length of check data
    */
    SM_UINT         uiCheckDataLen;
    /*! 
    * A member variable.
    * The pointer of data
    */
    PSM_BYTE        pbyData;
}SM_BLOB_ECCCIPHER, *PSM_BLOB_ECCCIPHER;

typedef struct _SM_RSA_PARAMETER
{
    SM_UINT         uiModulusBits;  /* In bits  */
    PSM_VOID        pParameter;
    SM_UINT         uiParameterLen; /* In bytes */
} SM_RSA_PARAMETER, *PSM_RSA_PARAMETER;
/* ///////////////////////////////////////////////////////////////////////// */
/* define the error code */
/* ///////////////////////////////////////////////////////////////////////// */
/*! 00, Operation success */
#define SM_ERR_FREE                     0  

/* normal(0x01-0x1f) */
/*! 01(0x01), Module cannot open with exclusive flag */
#define SM_ERR_EXCLUSIVE                1   
/*! 02(0x02), Module opened with exclusive flag */
#define SM_ERR_OCCUPY                   2   
/*! 03(0x03), Not enough resource */
#define SM_ERR_RESOURCE                 3   
/*! 04(0x04), self-test error */
#define SM_ERR_SELF_TEST                4   
/*! 05(0x05), Invalid pipe handle */
#define SM_ERR_PIPE_HANDLE              5   
/*! 06(0x06), Invalid key handle */
#define SM_ERR_KEY_HANDLE               6   
/*! 07(0x07), Access auth-device fail */
#define SM_ERR_ACCESS_AUTHDEV           7   
/*! 08(0x08), Resource information integrity error */
#define SM_ERR_RES_INFO_INTEGRITY       8   
/*! 09(0x09), Resource image integrity error */
#define SM_ERR_RES_IMAGE_INTEGRITY      9   
/*! 10(0x0a), Auth-device information integrity error */
#define SM_ERR_AUTHDEV_INFO_INTEGRITY   10  
/*! 11(0x0b), Invalid user password */
#define SM_ERR_USER_PASSWORD            11  
/*! 12(0x0c), Invalid system password */
#define SM_ERR_SYS_PASSWORD             12  
/*! 13(0x0d), Did not login */
#define SM_ERR_NOT_LOGIN                13  
/*! 14(0x0e), Invalid physical noise */
#define SM_ERR_RANDOM                   14  
/*! 15(0x0f), Mechanism type error */
#define SM_ERR_MECH_TYPE                15  
/*! 16(0x10), Key type error */
#define SM_ERR_KEY_TYPE                 16  
/*! 17(0x11), Object class error */
#define SM_ERR_OBJECT_CLASS             17  
/*! 18(0x12), Can not export */
#define SM_ERR_ATTRIB_EXTRACT           18  
/*! 19(0x13), Modify attribute error */
#define SM_ERR_ATTRIB_MODIFY            19  
/*! 20(0x14), Generate key pair error */
#define SM_ERR_GEN_KEYPAIR              20  
/*! 21(0x15), Did not support */
#define SM_ERR_FUNC_SUPPORT             21  
/*! 22(0x16), Unknown error */
#define SM_ERR_UNKNOWN                  22  
/*! 23(0x17), Memory malloc error */
#define SM_ERR_MALLOC                   23  
/*! 24(0x18), Rsa calc failed */
#define SM_ERR_RSA                      24  
/*! 25(0x19), Data for Rsa calc invalid */
#define SM_ERR_RSA_INPUTDATA            25  
/*! 26(0x1a), Memory location invalid */
#define SM_ERR_MEM_LOCATION             26
/*! 27(0x1b), Invalid data length */  
#define SM_ERR_DATA_LEN                 27  
/*! 28(0x1c), Invalid data type */
#define SM_ERR_DATA_TYPE                28  
/*! 29(0x1d), can not do resource initialize */
#define SM_ERR_DEVICE_INIT              29  

/* ecc(0x20-0x27) */
/*! 32(0x20), Invalid ecc curve */
#define SM_ERR_ECC_PARA                 32  
/*! 33(0x21), Generate keypair which with different modulus bits */
#define SM_ERR_KEY_PAIR_BITS            33  
/*! 34(0x22), Invalid public key data */
#define SM_ERR_PUBLICKEY_DATA           34  
/*! 35(0x23), ECC verify failed */
#define SM_ERR_ECC_VERIFY               35  
/*! 36(0x24), ECC modulus bits invalid */
#define SM_ERR_ECC_MODULES_BITS         36

/* algo status(0x28-0x2f) */
/*! 40(0x28), ECC disable */
#define SM_ERR_ECC_DISABLE              40   
/*! 43(0x2b), DEA disable */
#define SM_ERR_DEA_DISABLE              43  
/*! 44(0x2c), DHA disable */
#define SM_ERR_DHA_DISABLE              44  

/* other(0x50-0x7f) */
/*! 81(0x51), MAC check failed */
#define SM_ERR_MAC_CHECK                81  
/*! 82(0x52), Invalid IC card INS */
#define SM_ERR_ICC_INS                  82  
/*! 83(0x53), Invalid IC card type */
#define SM_ERR_ICC_TYPE                 83	
/*! 84(0x54), Can not login */
#define SM_ERR_LOGIN_DISABLE            84  
/*! 86(0x56), Key integrity error */
#define SM_ERR_KEY_INTERGRITY           86  
/*! 87(0x57), Object ID error */
#define SM_ERR_OBJECT_ID                87  
/*! 88(0x58), CRC error */
#define SM_ERR_CRC_VERIFY               88  
/*! 89(0x59), pad data error */
#define SM_ERR_PAD_WORD                 89  
/*! 90(0x5a), auth-code verify error */
#define SM_ERR_VERIFY_AUTHCODE          90  
/*! 91(0x5b), message verify error */
#define SM_ERR_MSG_VERIFY               91  
/*! 92(0x5c), can not use the key */
#define SM_ERR_KEY_DISABLED             92
/*! 93(0x5d), not do pin's initialize */  
#define SM_ERR_USERPIN_NOT_INIT         93
/*! 94(0x5e), can not do pin's initialize again */
#define SM_ERR_USERPIN_INIT_NEXT        94
/*! 97(0x61), not insert IC card */
#define SM_ERR_NO_ICC                   97
/*! 98(0x62), set RTC failed */
#define SM_ERR_RTC                      98
/*! 99(0x63), can not do encrypt operator with key attribute */
#define SM_ERR_ATTRIB_ENC               99
/*! 100(0x64), can not do decrypt operator with key attribute */
#define SM_ERR_ATTRIB_DEC               100
/*! 101(0x65), can not do signature operator with key attribute */
#define SM_ERR_ATTRIB_SIGN              101
/*! 102(0x66), can not do verify operator with key attribute */
#define SM_ERR_ATTRIB_VERIFY            102
/*! 103(0x67), key flag failed */
#define SM_ERR_ATTRIB_KEYFLAGS          103

/* API define(0x101-0x200) */
/*! 256(0x100), API operator error */
#define SM_ERR_OPERATOR                 256 
/*! 257(0x101), Device handle error */
#define SM_ERR_DEVICE_HANDLE            257 
/*! 258(0x102), Communicate with interface failed */
#define SM_ERR_COMMUNICATE              258 
/*! 259(0x103), Parameter error */
#define SM_ERR_PARAMETER                259 
/*! 260(0x104), Invalid operate mode */
#define SM_ERR_MODE                     260 
/*! 261(0x105), Buffer length error */
#define SM_ERR_BUFFER_LEN               261 
/*! 262(0x106), Operate time out */
#define SM_ERR_TIME_OUT                 262 
/*! 263(0x107), User abort operate */
#define SM_ERR_USER_ABORT               263 

/*! 273(0x111), Device serial number invalid */
#define SM_ERR_DEVICE_SN                273 
/*! 274(0x112), Password length error */
#define SM_ERR_PIN_LENGTH               274  
/*! 275(0x113), Invalid certificate type */
#define SM_ERR_CERT_TYPE                275 
/*! 276(0x114), Invalid certificate file */
#define SM_ERR_CERT_FILE                276 
/*! 277(0x115), API algo doesn`t match DSP algo */
#define SM_ERR_ALGO_MATCH               277 
/*! 278(0x116), Invalid RSA encode type */
#define SM_ERR_RSA_CODE_TYPE            278 
/*! 279(0x117), Encoding RSA error */
#define SM_ERR_RSA_ENCODE               279 
/*! 280(0x118), Verify decrypt error */
#define SM_ERR_DEC_VERIFY               280 
/*! 281(0x119), Verify signature error */
#define SM_ERR_SIGN_VERIFY              281 

/*! 21845(0x5555), Invalid command id */
#define SM_ERR_CMDNO                    21845 

/* /////////////////////////////////////////////////////////////////////////// */
/* Export Functions define                                                     */
/* /////////////////////////////////////////////////////////////////////////// */
typedef SM_RV (*SM_GetDeviceNum)(PSM_UINT);
typedef PSM_CHAR (*SM_GetErrorString)(SM_RV, SM_BOOL);
typedef PSM_CHAR (*SM_GetAPIVersion)();
typedef SM_RV (*SM_GetDeviceType)(PSM_UINT);

typedef SM_RV (*SM_OpenDevice)(SM_UINT, SM_BOOL, PSM_DEVICE_HANDLE);
typedef SM_RV (*SM_CloseDevice)(SM_DEVICE_HANDLE);
typedef SM_RV (*SM_GetMechanismList)(SM_DEVICE_HANDLE, PSM_UINT, PSM_WORD);
typedef SM_RV (*SM_GetMechanismInfo)(SM_DEVICE_HANDLE, SM_UINT, PSM_MECHANISM_INFO);
typedef SM_RV (*SM_TestDevice)(SM_DEVICE_HANDLE, PSM_UINT);
typedef SM_RV (*SM_GetDeviceInfo)(SM_DEVICE_HANDLE, PSM_DEVICE_INFO); 
typedef SM_RV (*SM_GetDeviceIndex)(SM_DEVICE_HANDLE, PSM_UINT);
/*
typedef SM_RV (*SM_ResetCard)(SM_DEVICE_HANDLE);
*/
typedef SM_RV (*SM_CommTest)(SM_DEVICE_HANDLE);
typedef SM_RV (*SM_InterfaceSpeedTest)(SM_DEVICE_HANDLE);
typedef SM_RV (*SM_DestroySensitiveInfo)(SM_DEVICE_HANDLE, SM_UINT);

typedef SM_RV (*SM_LockMem)(SM_DEVICE_HANDLE);
typedef SM_RV (*SM_UnlockMem)(SM_DEVICE_HANDLE);
typedef SM_RV (*SM_ReadNonVolatile)(SM_DEVICE_HANDLE,SM_UINT, SM_UINT, PSM_BYTE);
typedef SM_RV (*SM_WriteNonVolatile)(SM_DEVICE_HANDLE, SM_UINT, SM_UINT, PSM_BYTE);
typedef SM_RV (*SM_BuildAuthDev)(
					  SM_DEVICE_HANDLE  ,			  /* in  */
					  PSM_BYTE          ,			  /* in  */
					  SM_UINT           ,			  /* in  */
					  SM_WORD			  ,			  /* in  */
					  PSM_BYTE		  , /* out */
					  PSM_WORD		  ,  /* out */
					  PSM_BYTE		  ,   /* out */
					  PSM_WORD);		       /* out */
typedef SM_RV (*SM_ReadAuthDevMem)(
						SM_DEVICE_HANDLE    hDevice,        /* in  */
						SM_UINT             uiLocation,     /* in  */
						SM_UINT             uiDataOutLen,   /* in  */
						PSM_BYTE            pbyDataOut      /* out */
						);

typedef SM_RV (*SM_WriteAuthDevMem)(
						 SM_DEVICE_HANDLE    hDevice,        /* in  */
						 SM_UINT             uiLocation,     /* in  */
						 SM_UINT             uiDataInLen,    /* in  */
						 PSM_BYTE            pbyDataIn       /* in  */
						 );

typedef SM_RV (*SM_ReadAuthDevMem_PIN)(
							SM_DEVICE_HANDLE    hDevice,        /* in  */
							SM_UINT             uiLocation,     /* in  */
							SM_UINT             uiDataOutLen,   /* in  */
							PSM_BYTE            pbyDataOut,     /* out */
							PSM_BYTE            pbyPin,		    /* in  */
							SM_UINT             uiPinLen 		/* in  */
							);

typedef SM_RV (*SM_WriteAuthDevMem_PIN)(
							 SM_DEVICE_HANDLE    hDevice,        /* in  */
							 SM_UINT             uiLocation,     /* in  */
							 SM_UINT             uiDataInLen,    /* in  */
							 PSM_BYTE            pbyDataIn,      /* in  */
							 PSM_BYTE            pbyPin,		    /* in  */
							 SM_UINT             uiPinLen		/* in  */
							 );

typedef SM_RV (*SM_UpdateKeyPair)(
					   SM_PIPE_HANDLE      hPipe,          /* in  */
					   PSM_BLOB_KEY        pstPublicKey,   /* in  */
					   PSM_BLOB_KEY        pstPrivateKey,  /* in  */
					   SM_WORD             wKeyFlag,       /* in  */
					   PSM_BYTE            pbyPin,         /* in  */
					   SM_UINT             uiPinLen        /* in  */
					   );

typedef SM_RV (*SM_UpdateKey)(
                      SM_PIPE_HANDLE      hPipe,          /* in  */
                      PSM_BLOB_KEY        pstPublicKey,   /* in  */
                      PSM_BYTE            pbyPin,         /* in  */
                      SM_UINT             uiPinLen        /* in  */
                      );

typedef SM_RV (*SM_OpenSecPipe)(SM_DEVICE_HANDLE, PSM_PIPE_HANDLE);
typedef SM_RV (*SM_CloseSecPipe)(SM_PIPE_HANDLE);
typedef SM_RV (*SM_CloseAllSecPipe)(SM_DEVICE_HANDLE);
typedef SM_RV (*SM_Login)(SM_PIPE_HANDLE, PSM_BYTE, SM_UINT, PSM_WORD);
typedef SM_RV (*SM_Logout)(SM_PIPE_HANDLE);
typedef SM_RV (*SM_ChangeUserPin)(SM_DEVICE_HANDLE, PSM_UCHAR, SM_UINT, PSM_UCHAR, SM_UINT, PSM_WORD);
typedef SM_RV (*SM_GenRandom)(SM_PIPE_HANDLE, SM_WORD, PSM_BYTE , SM_UINT);
/*
typedef SM_RV (*SM_GetCert)(SM_PIPE_HANDLE, SM_UINT, PSM_BYTE, PSM_UINT);
*/

typedef SM_RV (*SM_EncryptInit)(SM_PIPE_HANDLE, PSM_BLOB_KEY, PSM_ALGORITHM);
typedef SM_RV (*SM_EncryptUpdate)(SM_PIPE_HANDLE, PSM_BYTE, SM_UINT, PSM_BYTE, PSM_UINT);
typedef SM_RV (*SM_EncryptFinal)(SM_PIPE_HANDLE, SM_BOOL, PSM_BYTE, SM_UINT, PSM_BYTE, PSM_UINT);
typedef SM_RV (*SM_DecryptInit)(SM_PIPE_HANDLE, PSM_BLOB_KEY ,PSM_ALGORITHM);
typedef SM_RV (*SM_DecryptUpdate)(SM_PIPE_HANDLE, PSM_BYTE ,SM_UINT, PSM_BYTE, PSM_UINT);
typedef SM_RV (*SM_DecryptFinal)(SM_PIPE_HANDLE, SM_BOOL, PSM_BYTE, SM_UINT, PSM_BYTE, PSM_UINT);
typedef SM_RV (*SM_Encrypt)(SM_PIPE_HANDLE, PSM_BLOB_KEY, PSM_ALGORITHM, SM_BOOL,
                 PSM_BYTE, SM_UINT, PSM_BYTE, PSM_UINT);
typedef SM_RV (*SM_Decrypt)(SM_PIPE_HANDLE, PSM_BLOB_KEY, PSM_ALGORITHM, SM_BOOL, 
                 PSM_BYTE, SM_UINT, PSM_BYTE, PSM_UINT);
typedef SM_RV (*SM_DigestInit)(SM_PIPE_HANDLE, PSM_BLOB_KEY, PSM_ALGORITHM);
typedef SM_RV (*SM_DigestUpdate)(SM_PIPE_HANDLE, PSM_BYTE, SM_UINT);
typedef SM_RV (*SM_DigestFinal)(SM_PIPE_HANDLE, PSM_BYTE, SM_UINT,
                     PSM_BYTE, PSM_UINT);
typedef SM_RV (*SM_Digest)(SM_PIPE_HANDLE, PSM_BLOB_KEY, PSM_ALGORITHM,
                 PSM_BYTE, SM_UINT, PSM_BYTE, PSM_UINT);

typedef SM_RV (*SM_ECCEncrypt)(SM_PIPE_HANDLE, PSM_BLOB_KEY, PSM_ALGORITHM, 
                    PSM_BYTE, SM_UINT, PSM_BLOB_ECCCIPHER );
typedef SM_RV (*SM_ECCDecrypt)(SM_PIPE_HANDLE, PSM_BLOB_KEY, PSM_ALGORITHM,
                    PSM_BLOB_ECCCIPHER, PSM_BYTE, PSM_UINT);
typedef SM_RV (*SM_ECCSignature)(SM_PIPE_HANDLE, PSM_BLOB_KEY, PSM_ALGORITHM, 
                      PSM_BYTE, SM_UINT, PSM_BYTE, PSM_UINT);
typedef SM_RV (*SM_ECCVerify)(SM_PIPE_HANDLE, PSM_BLOB_KEY, PSM_ALGORITHM,  
                 PSM_BYTE, SM_UINT, PSM_BYTE, SM_UINT);
typedef SM_RV (*SM_BackupAuthDev)(SM_PIPE_HANDLE, PSM_BYTE, SM_UINT);

typedef SM_RV (*SM_ECCExchangeKey)(
				SM_PIPE_HANDLE		hPipe,
				SM_WORD				wFlag,
				PSM_BYTE			pSelfHashValue, 
				SM_UINT				uiSelfHashValueLen,
				SM_KEY_HANDLE		hSelfPriKey, 
				SM_KEY_HANDLE		hSelfTempPriKey, 
				PSM_BYTE			pOpposedHashValue, 
				SM_UINT				uiOpposedHashValueLen, 
				PSM_BYTE			pOpposedPubKey, 
				SM_UINT				uiOpposedPubKeyLen,
				PSM_BYTE			pOpposedTempPubKey, 
				SM_UINT				uiOpposedTempPubKeyLen,
				PSM_BYTE     		pbySymKey,
				PSM_UINT			puiSymKeyLen);

typedef SM_RV (*SM_GetCfgKeyHandle)(SM_PIPE_HANDLE, PSM_BLOB_KEY, PSM_KEY_HANDLE);
typedef SM_RV (*SM_CloseTokKeyHdl)(SM_PIPE_HANDLE, SM_KEY_HANDLE);
typedef SM_RV (*SM_GetKeyAttribute)(SM_PIPE_HANDLE, SM_KEY_HANDLE,  PSM_KEY_ATTRIBUTE);
typedef SM_RV (*SM_GetKeyHdlID)(SM_PIPE_HANDLE, SM_KEY_HANDLE, PSM_WORD);
typedef SM_RV (*SM_DuplicateKeyHandle)(SM_PIPE_HANDLE, SM_WORD, SM_WORD, PSM_KEY_HANDLE);

typedef SM_RV (*SM_GenerateKey)(SM_PIPE_HANDLE, PSM_KEY_ATTRIBUTE, PSM_KEY_HANDLE);

typedef SM_RV (*SM_ImportKey)(SM_PIPE_HANDLE, PSM_BYTE, SM_WORD, SM_KEY_HANDLE, PSM_ALGORITHM, 
                                     PSM_KEY_ATTRIBUTE, PSM_KEY_HANDLE);
typedef SM_RV (*SM_ExportKey)(SM_PIPE_HANDLE, SM_KEY_HANDLE, SM_KEY_HANDLE, PSM_ALGORITHM , 
                   PSM_BYTE, PSM_WORD);
typedef SM_RV (*SM_DestroyKey)(SM_PIPE_HANDLE, SM_KEY_HANDLE);

typedef SM_RV (*SM_GenerateKeyPair)(SM_PIPE_HANDLE, PSM_KEY_ATTRIBUTE, PSM_KEY_HANDLE, PSM_KEY_ATTRIBUTE, PSM_KEY_HANDLE);
typedef SM_RV (*SM_GenerateKeyPair_CP)(SM_PIPE_HANDLE, PSM_KEY_ATTRIBUTE, PSM_BYTE,PSM_WORD,PSM_KEY_ATTRIBUTE, PSM_BYTE,PSM_WORD);
typedef SM_RV (*SM_ImportPublicKey)(SM_PIPE_HANDLE, PSM_BYTE, SM_WORD, PSM_KEY_ATTRIBUTE, PSM_KEY_HANDLE);
typedef SM_RV (*SM_ImportPrivateKey)(SM_PIPE_HANDLE, PSM_BYTE, SM_WORD, SM_KEY_HANDLE, PSM_ALGORITHM, 
                         PSM_KEY_ATTRIBUTE, PSM_KEY_HANDLE);
typedef SM_RV (*SM_ExportPublicKey)(SM_PIPE_HANDLE, SM_KEY_HANDLE, PSM_BYTE, PSM_WORD); 
typedef SM_RV (*SM_ExportPrivateKey)(SM_PIPE_HANDLE, SM_KEY_HANDLE, SM_KEY_HANDLE, PSM_ALGORITHM,
                          PSM_BYTE, PSM_WORD);

typedef SM_RV (*SM_DestroyPublicKey)(SM_PIPE_HANDLE, SM_KEY_HANDLE);
typedef SM_RV (*SM_DestroyPrivateKey)(SM_PIPE_HANDLE, SM_KEY_HANDLE);

/*
typedef SM_RV (*SM_SetDeviceEventHandler)(SM_DEVICE_HANDLE,  PDEVICE_EVENT_HANDLER,  PSM_VOID);
typedef SM_RV (*SM_UnsetDeviceEventHandler)(SM_DEVICE_HANDLE, SM_UINT);
typedef SM_RV (*SM_GetModuleLabel)(SM_DEVICE_HANDLE, PSM_BYTE, PSM_BYTE);
typedef SM_RV (*SM_RSAPublicKeyCalc)(SM_PIPE_HANDLE, PSM_BLOB_KEY, PSM_ALGORITHM, PSM_BYTE, SM_UINT, PSM_BYTE, PSM_UINT );
typedef SM_RV (*SM_RSAPrivateKeyCalc)(SM_PIPE_HANDLE, PSM_BLOB_KEY, PSM_ALGORITHM, PSM_BYTE, SM_UINT, PSM_BYTE, PSM_UINT);
typedef SM_RV (*SM_GetTokKeyHdlByLabel)(SM_PIPE_HANDLE, SM_UINT, SM_WORD, PSM_KEY_HANDLE);
typedef SM_RV (*SM_DupTokKeyHdl)(SM_PIPE_HANDLE, SM_WORD, SM_WORD, PSM_KEY_HANDLE);
typedef SM_RV (*SM_ClearAllTokenKeys)(SM_DEVICE_HANDLE);

typedef SM_RV (*SM_SetKeyAttribute)(SM_KEY_HANDLE, PSM_KEY_ATTRIBUTE);

typedef SM_RV (*SM_UpdateProg)(SM_DEVICE_HANDLE, PSM_BYTE, SM_UINT, PSM_BYTE, SM_UINT);
typedef SM_RV (*SM_SetModuleLabel)(SM_DEVICE_HANDLE, PSM_BYTE, SM_UINT, PSM_BYTE, PSM_BYTE);
typedef SM_RV (*SM_SetManufactureInfo)(SM_DEVICE_HANDLE, PSM_BYTE, SM_UINT, SM_MANUFCT_INFO);
typedef SM_RV (*SM_SetRTC)(SM_DEVICE_HANDLE);
typedef SM_RV (*SM_SetSSOFlag)(SM_DEVICE_HANDLE, SM_WORD);
*/


/* /////////////////////////////////////////////////////////////////////////// */
/* SWKeyBasicDllMang functions define */
#define SWDLLMANGHANDLE         void*
/* ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,, */
typedef unsigned short (__cdecl * SW_DLLMANG_LOADAPI)
(
    SWDLLMANGHANDLE hDllMang,   /* in            */
    char*           pAPIPath    /* in, full path */
);

typedef unsigned short (__cdecl * SW_DLLMANG_UNLOADAPI)
(
    SWDLLMANGHANDLE hDllMang   /* in */
);

typedef SM_BOOL (__cdecl * SW_DLLMANG_ISLOAD)
(
    SWDLLMANGHANDLE hDllMang   /* in */
);

/* /////////////////////////////////////////////////////////////////////////// */
typedef struct _SWAPI50DllMang
{
    /* member functions */
    /* 1. load dll dynamic */
    SW_DLLMANG_LOADAPI          Dll_Load;
    /* 2. unload dll dynamic */
    SW_DLLMANG_UNLOADAPI        Dll_Unload;
    /* 3. check load status */
    SW_DLLMANG_ISLOAD           Dll_IsLoad;

    SM_GetDeviceNum         m_pfn_SM_GetDeviceNum;
    SM_GetErrorString       m_pfn_SM_GetErrorString;
    SM_GetAPIVersion        m_pfn_SM_GetAPIVersion;
    SM_GetDeviceType        m_pfn_SM_GetDeviceType;

    SM_OpenDevice           m_pfn_SM_OpenDevice;
    SM_CloseDevice          m_pfn_SM_CloseDevice;
    SM_GetMechanismList     m_pfn_SM_GetMechanismList;
    SM_GetMechanismInfo     m_pfn_SM_GetMechanismInfo;
    SM_TestDevice           m_pfn_SM_TestDevice;
    SM_GetDeviceInfo        m_pfn_SM_GetDeviceInfo;
    SM_GetDeviceIndex       m_pfn_SM_GetDeviceIndex;
/*
    SM_ResetCard            m_pfn_SM_ResetCard;
*/
    SM_CommTest             m_pfn_SM_CommTest;
    SM_InterfaceSpeedTest   m_pfn_SM_InterfaceSpeedTest;
    SM_DestroySensitiveInfo m_pfn_SM_DestroySensitiveInfo;

    SM_LockMem              m_pfn_SM_LockMem;
    SM_UnlockMem            m_pfn_SM_UnlockMem;
    SM_ReadNonVolatile      m_pfn_SM_ReadNonVolatile;
    SM_WriteNonVolatile     m_pfn_SM_WriteNonVolatile;
    SM_BuildAuthDev			m_pfn_SM_BuildAuthDev;
    SM_BackupAuthDev        m_pfn_SM_BackupAuthDev;
    SM_UpdateKeyPair        m_pfn_SM_UpdateKeyPair;
    SM_UpdateKey            m_pfn_SM_UpdateKey;
    SM_ReadAuthDevMem       m_pfn_SM_ReadAuthDevMem;
    SM_WriteAuthDevMem      m_pfn_SM_WriteAuthDevMem;
    SM_ReadAuthDevMem_PIN   m_pfn_SM_ReadAuthDevMem_PIN;
    SM_WriteAuthDevMem_PIN  m_pfn_SM_WriteAuthDevMem_PIN;


    SM_OpenSecPipe          m_pfn_SM_OpenSecPipe;
    SM_CloseSecPipe         m_pfn_SM_CloseSecPipe;
    SM_CloseAllSecPipe      m_pfn_SM_CloseAllSecPipe;
    SM_Login                m_pfn_SM_Login;
    SM_Logout               m_pfn_SM_Logout;
    SM_ChangeUserPin        m_pfn_SM_ChangeUserPin;
    SM_GenRandom            m_pfn_SM_GenRandom;
/*
    SM_GetCert              m_pfn_SM_GetCert;  
*/

    SM_EncryptInit          m_pfn_SM_EncryptInit;
    SM_EncryptUpdate        m_pfn_SM_EncryptUpdate;
    SM_EncryptFinal         m_pfn_SM_EncryptFinal;
    SM_DecryptInit          m_pfn_SM_DecryptInit;
    SM_DecryptUpdate        m_pfn_SM_DecryptUpdate;
    SM_DecryptFinal         m_pfn_SM_DecryptFinal;
    SM_Encrypt	            m_pfn_SM_Encrypt;
    SM_Decrypt              m_pfn_SM_Decrypt;
    SM_DigestInit           m_pfn_SM_DigestInit;
    SM_DigestUpdate         m_pfn_SM_DigestUpdate;
    SM_DigestFinal          m_pfn_SM_DigestFinal;
    SM_Digest               m_pfn_SM_Digest;

/*
    SM_RSAPublicKeyCalc     m_pfn_SM_RSAPublicKeyCalc;
    SM_RSAPrivateKeyCalc    m_pfn_SM_RSAPrivateKeyCalc;
*/
    SM_ECCEncrypt           m_pfn_SM_ECCEncrypt;
    SM_ECCDecrypt           m_pfn_SM_ECCDecrypt;
    SM_ECCSignature         m_pfn_SM_ECCSignature;
    SM_ECCVerify            m_pfn_SM_ECCVerify;
    SM_ECCExchangeKey       m_pfn_SM_ECCExchangeKey;

    SM_GetCfgKeyHandle      m_pfn_SM_GetCfgKeyHandle;
    SM_CloseTokKeyHdl       m_pfn_SM_CloseTokKeyHdl;
    SM_GetKeyAttribute      m_pfn_SM_GetKeyAttribute;
    SM_GetKeyHdlID          m_pfn_SM_GetKeyHdlID;
    SM_DuplicateKeyHandle   m_pfn_SM_DuplicateKeyHandle;
    SM_GenerateKey          m_pfn_SM_GenerateKey;
    SM_GenerateKeyPair_CP   m_pfn_SM_GenerateKeyPair_CP;
/*
    SM_GetTokKeyHdlByLabel  m_pfn_SM_GetTokKeyHdlByLabel;
    SM_DupTokKeyHdl	        m_pfn_SM_DupTokKeyHdl;
    SM_ClearAllTokenKeys    m_pfn_SM_ClearAllTokenKeys;

*/
    SM_ImportKey            m_pfn_SM_ImportKey;
    SM_ExportKey            m_pfn_SM_ExportKey;
    SM_DestroyKey           m_pfn_SM_DestroyKey;

    SM_GenerateKeyPair      m_pfn_SM_GenerateKeyPair;
    SM_ImportPublicKey      m_pfn_SM_ImportPublicKey;
    SM_ImportPrivateKey     m_pfn_SM_ImportPrivateKey;
    SM_ExportPublicKey      m_pfn_SM_ExportPublicKey;
    SM_ExportPrivateKey     m_pfn_SM_ExportPrivateKey;

    SM_DestroyPublicKey     m_pfn_SM_DestroyPublicKey;
    SM_DestroyPrivateKey    m_pfn_SM_DestroyPrivateKey;	

    /* cumstom functions */
/*
    SM_SetDeviceEventHandler    m_pfn_SM_SetDeviceEventHandler;
    SM_UnsetDeviceEventHandler  m_pfn_SM_UnsetDeviceEventHandler;
    SM_SetKeyAttribute          m_pfn_SM_SetKeyAttribute;
    SM_GetModuleLabel           m_pfn_SM_GetModuleLabel;

    SM_UpdateProg               m_pfn_SM_UpdateProg;
    SM_SetModuleLabel           m_pfn_SM_SetModuleLabel;
    SM_SetManufactureInfo       m_pfn_SM_SetManufactureInfo;
    SM_SetRTC                   m_pfn_SM_SetRTC;
    SM_SetSSOFlag               m_pfn_SM_SetSSOFlag;
*/

    /* member variable */
    SM_HMODULE         m_hDLLLib;
    SM_BOOL            m_bLoadDLL;

}SWAPI50DllMang;

SWAPI50DllMang* GetDllMangInterface();
void DelDllMangInterface(SWAPI50DllMang* pDllMang);

/* /////////////////////////////////////////////////////////////////////////// */
#endif
