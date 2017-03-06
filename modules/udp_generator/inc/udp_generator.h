// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef UDP_GENERATOR_H
#define UDP_GENERATOR_H

#include "module.h"

#ifdef __cplusplus
extern "C"
{
#endif

MODULE_EXPORT const MODULE_API* MODULE_STATIC_GETAPI(GENERATOR_DEVICE_MODULE)(MODULE_API_VERSION gateway_api_version);

#ifdef __cplusplus
}
#endif

#endif /*UDP_GENERATOR_H*/
