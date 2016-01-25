
#ifndef _INERTIAL3D_SPIN_
#define _INERTIAL3D_SPIN_

#include "messaging/static_messaging.h"
#include <stdint.h>
#include "../_GeneralModuleFiles/attGuidOut.h"


/*! \addtogroup ADCSAlgGroup
 * @{
 */

/*! @brief Top level structure for the sub-module routines. */
typedef struct {
    /* declare module private variables */
    double omega_RN_N[3];                           /*!< [r/s]  angular velocity vector of R relative to inertial N
                                                                in N-frame components */
    double sigma_RN[3];                             /*!<        MRP from inertial frame N to corrected reference frame R */
    uint64_t priorTime;                             /*!< [ns]   Last time the guidance module is called */

    
    /* declare module IO interfaces */
    char outputDataName[MAX_STAT_MSG_LENGTH];       /*!< The name of the output message*/
    int32_t outputMsgID;                            /*!< ID for the outgoing message */


    attRefOut attRefOut;                            /*!< -- copy of the output message */

}inertial3DSpinConfig;

#ifdef __cplusplus
extern "C" {
#endif
    
    void SelfInit_inertial3DSpin(inertial3DSpinConfig *ConfigData, uint64_t moduleID);
    void CrossInit_inertial3DSpin(inertial3DSpinConfig *ConfigData, uint64_t moduleID);
    void Update_inertial3DSpin(inertial3DSpinConfig *ConfigData, uint64_t callTime, uint64_t moduleID);
    void Reset_inertial3DSpin(inertial3DSpinConfig *ConfigData);

    void computeInertialSpinReference(inertial3DSpinConfig *ConfigData,
                                      int    integrateFlag,
                                      double dt,
                                      double sigma_RN[3],
                                      double omega_RN_N[3],
                                      double domega_RN_N[3]);

#ifdef __cplusplus
}
#endif

/*! @} */

#endif