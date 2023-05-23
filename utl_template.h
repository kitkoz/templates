/**************************************************************************************************/
/**
 * @addtogroup RTOS
 * @{
 * @defgroup MODULE_TEMPLATE module_template
 * @{
 * @brief
 * Utility file of a module exploiting module_template.
 *
 * @file       utl_module_template.h
 * @date
 * @author
 * @copyright
 *
 * @note
 * None
 **************************************************************************************************/

#ifndef UTL_MODULE_TEMPLATE_H_
#define UTL_MODULE_TEMPLATE_H_

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

/* User header files */

/*==================================================================================================
 = DEFINITIONS
 =================================================================================================*/
enum module_template_retcode
{
  MODULE_TEMPLATE_MALLOC_ERROR = RET_GENERATE_CODE(RET_SEVERITY_ERROR, RET_MODULE_MODULE_TEMPLATE, 0x0000),
  MODULE_TEMPLATE_FREE_ERROR = RET_GENERATE_CODE(RET_SEVERITY_ERROR, RET_MODULE_MODULE_TEMPLATE, 0x0001),
  MODULE_TEMPLATE_INVALID_PARAMS = RET_GENERATE_CODE(RET_SEVERITY_ERROR, RET_MODULE_MODULE_TEMPLATE, 0x0002),
  MODULE_TEMPLATE_INTERFACE_NULL = RET_GENERATE_CODE(RET_SEVERITY_ERROR, RET_MODULE_MODULE_TEMPLATE, 0x0003),
  MODULE_TEMPLATE_IS_IN_ISR = RET_GENERATE_CODE(RET_SEVERITY_ERROR, RET_MODULE_MODULE_TEMPLATE, 0x0004),
  MODULE_TEMPLATE_GENERIC_DRV_ERROR = RET_GENERATE_CODE(RET_SEVERITY_ERROR, RET_MODULE_MODULE_TEMPLATE, 0x0005),
} module_template_retcode_t;

#ifdef __cplusplus
}
#endif

#endif // HAL_MODULE_TEMPLATE_H_

/**
 * End group
 * @}
 */
