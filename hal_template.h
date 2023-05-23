/**************************************************************************************************/
/**
 * @addtogroup RTOS
 * @{
 * @defgroup MODULE_TEMPLATE module_template
 * @{
 * @brief
 * Abstraction layer of a module exploiting module_template.
 *
 * @file       hal_module_template.h
 * @date
 * @author
 * @copyright
 *
 * @note
 * None
 **************************************************************************************************/

#ifndef HAL_MODULE_TEMPLATE_H_
#define HAL_MODULE_TEMPLATE_H_

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 = INCLUDE FILES
 =================================================================================================*/
/* Standard header files */

/* Library header files */
#include "std_c2t3.h"
#include "utl_return_codes.h"
#include "utl_module_template.h"

/* User header files */

/*==================================================================================================
 = DEFINITIONS
 =================================================================================================*/

/**
 * @struct hal_sem_descriptor
 *     Forward declaration of the internal handle for the compiler
 */
struct hal_module_template_descriptor;

/**
 * @typedef hal_module_template_handle_t
 *     User level handle of a module_template driver instance
 */
typedef struct hal_module_template_descriptor* hal_module_template_handle_t;

typedef struct
{
  retcode_t (*open) (handle_t* p_handle, bool recursive);
  retcode_t (*close) (handle_t handle);
} hal_module_template_intf_t;

typedef retcode_t (*hal_module_template_conn_func_t) (hal_module_template_intf_t* intf);

/*==================================================================================================
 = PUBLIC FUNCTION PROTOTYPES
 =================================================================================================*/
/**************************************************************************************************/
/**
 * Open module_template instance.
 *
 * @param [in,out] ph_hal
 *     Pointer to new and empty hal handle.
 *
 * @param [in,out] conn_func
 *     driver connect function
 *
 * @return
 *     Return OK for success.
 **************************************************************************************************/
retcode_t hal_module_template_open (hal_module_template_handle_t* ph_hal, hal_module_template_conn_func_t conn_func);

/**************************************************************************************************/
/**
 * Close module_template instance.
 *
 * @param [in,out] h_hal
 *     Pointer to hal handle.
 *
 * @return
 *     Return OK for success.
 **************************************************************************************************/
retcode_t hal_module_template_close (hal_module_template_handle_t h_hal);

#ifdef __cplusplus
}
#endif

#endif // HAL_MODULE_TEMPLATE_H_

/**
 * End group
 * @}
 */
