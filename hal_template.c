/**************************************************************************************************/
/**
 * @addtogroup MODULE_TEMPLATE
 * @{
 *
 * @file       hal_module_template.c
 * @date
 * @author
 * @copyright
 *
 * @note
 * Refer to header
 *
 **************************************************************************************************/

/*==================================================================================================
 = INCLUDE FILES
 =================================================================================================*/
#include "hal_module_template.h"
#include "srv_log.h"
#include "std_c2t3.h"
#include "hal_malloc.h"

/* Standard header files */

/* Library header files */

/* User header files */

/*==================================================================================================
 = DEFINITIONS
 =================================================================================================*/
/**
 * @struct hal_module_template_descriptor_t
 *     Structure that store handle information
 */
typedef struct
{
  handle_t h_drv;
  hal_module_template_intf_t intf;
} hal_module_template_descriptor_t;

/*==================================================================================================
 = GLOBAL VARIABLES
 =================================================================================================*/

/*==================================================================================================
 = PRIVATE FUNCTION PROTOTYPES
 =================================================================================================*/

/*==================================================================================================
 = PUBLIC FUNCTIONS
 =================================================================================================*/
/**************************************************************************************************/
/**
 *
 **************************************************************************************************/
retcode_t hal_module_template_open (hal_module_template_handle_t* ph_hal, hal_module_template_conn_func_t conn_func)
{
  if (ph_hal) return SRV_LOG_PUB(MODULE_TEMPLATE_INVALID_PARAMS);
  if (!conn_func) return SRV_LOG_PUB(MODULE_TEMPLATE_INVALID_PARAMS);

  *ph_hal = hal_malloc_malloc(sizeof(hal_module_template_descriptor_t));
  retcode_t retcode = *ph_hal ? OK : SRV_LOG_PUB(MODULE_TEMPLATE_MALLOC_ERROR);
  hal_module_template_descriptor_t* p_obj = (hal_module_template_descriptor_t*)*ph_hal;
  if (RET_SUCCESS(retcode))
  {
    retcode = p_obj->intf.open(&((hal_module_template_descriptor_t*)*ph_hal)->h_drv, recursive);
  }
  if (RET_SUCCESS(retcode))
  {
    retcode = STD_VALIDATE_INTF(p_obj->intf, MODULE_TEMPLATE_INTERFACE_NULL);
    SRV_LOG_PUB(retcode);
  }
  return retcode;
}

/**************************************************************************************************/
/**
 *
 **************************************************************************************************/
retcode_t hal_module_template_close (hal_module_template_handle_t h_hal)
{
  if (!h_hal) return SRV_LOG_PUB(MODULE_TEMPLATE_INVALID_PARAMS);
  hal_module_template_descriptor_t* p_obj = (hal_module_template_descriptor_t*)h_hal;
  retcode_t retcode = p_obj->intf.close ? p_obj->intf.close(p_obj->h_drv) : SRV_LOG_PUB(MODULE_TEMPLATE_INTERFACE_NULL);
  if (RET_SUCCESS(retcode))
  {
    hal_malloc_free(h_hal);
  }
  return retcode;

}

/**
 * End group
 * @}
 */
